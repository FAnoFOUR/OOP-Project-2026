#include "StackedWindow.h"

#include "Pages/DetailPage.h"
#include <QScrollArea>

//#include "../Model/Headers/TaskListManager.h"

#include <QPushButton>
#include <QFrame>

StackedWindow::StackedWindow(QWidget *parent): QWidget(parent) {

    stack = new QStackedLayout(this);

    QFrame *first = new QFrame();

    auto *layout = new QHBoxLayout(first);


    layout->addWidget(calendar = new QCalendarWidget()); //index 0

    stack->addWidget(first); // index 0

    detail = new TaskDetailWindow(this);
    edit = new TaskEditWindow(this);
    connect(detail, &TaskDetailWindow::emitClose, this, &StackedWindow::close);
    connect(detail, &TaskDetailWindow::editTask, this, &StackedWindow::showEditWindow);
    connect(edit, &TaskEditWindow::emitClose, this, &StackedWindow::close);

    stack->addWidget(detail); //index 1
    stack->addWidget(edit); //index 2
}

void StackedWindow::showDetailWindow(AbstractTask* task){

    detail->showTask(task);

    detail->show();

    stack->setCurrentIndex(1);
}

void StackedWindow::showEditWindow(AbstractTask* task){

    edit->showTask(task);

    stack->setCurrentIndex(2);
}

void StackedWindow::close(){
    stack->setCurrentIndex(stack->currentIndex()-1);
    if(stack->currentIndex() == 0){
        emit unselectTaskBlock();
    }
}
