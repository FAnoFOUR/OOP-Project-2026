#include "TaskDetailWindow.h"

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

    connect(editButton, &QPushButton::clicked, this, &TaskDetailWindow::sendSavedTask);
    //connect(RemoveButton, &QPushButton::clicked, ) //! SERVER POPUP PER CONFERMA ELIMINAZIONE
}

void TaskDetailWindow::showTask(AbstractTask* task){
    savedTask = task;
    task->accept(visitor);
    detailScrollArea->setWidget(visitor.getDetailPage());
}

void TaskDetailWindow::sendSavedTask(){
    emit editTask(savedTask);
}
