#include "TaskDetailWindow.h"
#include <QMessageBox>

TaskDetailWindow::TaskDetailWindow(QWidget *parent):QFrame(parent){

    mainLayout = new QVBoxLayout(this);

    QHBoxLayout *lineForCloseButton = new QHBoxLayout();
    QPushButton *closeButton = new QPushButton("Close");
    lineForCloseButton->setAlignment(Qt::AlignRight);
    lineForCloseButton->addWidget(closeButton);
    connect(closeButton, &QPushButton::clicked, this, &TaskDetailWindow::emitClose);
    mainLayout->addLayout(lineForCloseButton);

    detailScrollArea = new QScrollArea();
    mainLayout->addWidget(detailScrollArea);
    detailScrollArea->setWidgetResizable(true);

    detailButtonLine();
    mainLayout->addLayout(lineForButtons);
}

void TaskDetailWindow::detailButtonLine(){

    lineForButtons = new QHBoxLayout;
    QPushButton *editButton = new QPushButton("Edit");
    QPushButton *RemoveButton = new QPushButton("Remove");
    lineForButtons->setAlignment(Qt::AlignRight);
    lineForButtons->addWidget(editButton);
    lineForButtons->addWidget(RemoveButton);

    connect(editButton, &QPushButton::clicked, this, &TaskDetailWindow::showEditWindow);
    connect(RemoveButton, &QPushButton::clicked, this, &TaskDetailWindow::confirmRemove); //! SERVER POPUP PER CONFERMA ELIMINAZIONE
}

void TaskDetailWindow::showTask(AbstractTask* task){
    savedTask = task;
    if(task){
        task->accept(visitor);
        detailScrollArea->setWidget(visitor.getDetailPage());
    }
}

void TaskDetailWindow::showEditWindow(){
    emit editTask(savedTask);
}

void TaskDetailWindow::confirmRemove(){
    QMessageBox *confirmResetPopup = new QMessageBox(this);
    confirmResetPopup->setText("Do you want to Remove/Delete this task?");
    confirmResetPopup->setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    confirmResetPopup->setAttribute(Qt::WA_DeleteOnClose, true);
    if (confirmResetPopup->exec() == QMessageBox::Yes){
        qDebug()<<"Accepted Remove";
        emit emitClose();

        detailScrollArea->widget()->deleteLater();
        delete detailScrollArea->widget();
        detailScrollArea->setWidget(nullptr);

        emit removeTask(savedTask);
        savedTask = nullptr;
    }
}
