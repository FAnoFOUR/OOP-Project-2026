#include "TaskEditWindow.h"

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

}

void TaskEditWindow::showTask(AbstractTask* task){
    task->accept(visitor);
    editScrollArea->setWidget(visitor.getEditPage());
}

void TaskEditWindow::confirmSave(){
    ConfirmPopup *confirmSavePopup = new ConfirmPopup(this);
    confirmSavePopup->setAttribute(Qt::WA_DeleteOnClose, true);
}
