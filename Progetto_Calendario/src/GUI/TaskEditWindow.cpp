#include "TaskEditWindow.h"

#include <QMessageBox>

TaskEditWindow::TaskEditWindow(QWidget *parent):QFrame(parent){

    mainLayout = new QVBoxLayout(this);

    QHBoxLayout *lineForCloseButton = new QHBoxLayout();
    QPushButton *closeButton = new QPushButton("Close");
    lineForCloseButton->setAlignment(Qt::AlignRight);
    lineForCloseButton->addWidget(closeButton);
    connect(closeButton, &QPushButton::clicked, this, &TaskEditWindow::emitClose);
    mainLayout->addLayout(lineForCloseButton);

    editScrollArea = new QScrollArea();
    mainLayout->addWidget(editScrollArea);
    editScrollArea->setWidgetResizable(true);

    editButtonLine();
    mainLayout->addLayout(lineForButtons);
}

void TaskEditWindow::editButtonLine(){

    lineForButtons = new QHBoxLayout;
    QPushButton *saveButton = new QPushButton("Save");
    QPushButton *resetButton = new QPushButton("Reset");
    lineForButtons->setAlignment(Qt::AlignRight);
    lineForButtons->addWidget(saveButton);
    lineForButtons->addWidget(resetButton);

    connect(saveButton, &QPushButton::clicked, this, &TaskEditWindow::confirmSave);
    connect(resetButton, &QPushButton::clicked, this, &TaskEditWindow::confirmReset);

}

void TaskEditWindow::showTask(AbstractTask* task){
    savedTask = task;
    task->accept(visitor);
    editScrollArea->setWidget(visitor.getEditPage());
}

void TaskEditWindow::confirmSave(){
    QMessageBox *confirmSavePopup = new QMessageBox(this);
    confirmSavePopup->setText("Are you sure you want to Save your changes?");
    confirmSavePopup->setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    confirmSavePopup->setAttribute(Qt::WA_DeleteOnClose, true);
    if (confirmSavePopup->exec() == QMessageBox::Yes){
        qDebug()<<"Accepted Save";
        //connect(typePopup, &TypeSelectionPopup::createTaskSignal, TaskCreationWindowObject, &TaskCreationWindow::createTask);
    }
}

void TaskEditWindow::confirmReset(){
    QMessageBox *confirmResetPopup = new QMessageBox(this);
    confirmResetPopup->setText("Do you want to Reset your changes?");
    confirmResetPopup->setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    confirmResetPopup->setAttribute(Qt::WA_DeleteOnClose, true);
    if (confirmResetPopup->exec() == QMessageBox::Yes){
        qDebug()<<"Accepted Reset";
        showTask(savedTask);
        //emit emitClose();
    }
}
