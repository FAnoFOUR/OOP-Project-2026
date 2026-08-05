#ifndef STACKEDWINDOW_H
#define STACKEDWINDOW_H

#include "GUI/GuiVisitors/DetailVisitor.h"
#include "GUI/GuiVisitors/EditVisitor.h"
#include "Model/Headers/AbstractTask.h"
#include <QWidget>
#include <QStackedLayout>
#include <QCalendarWidget>
#include <QPushButton>
#include <QScrollArea>

//#include "WeekScollMenuBar" //opzionale se troppo complicato
#include "TaskDetailWindow.h"
#include "TaskEditWindow.h"

class StackedWindow: public QWidget{
    Q_OBJECT

private:
    AbstractTask *savedTask = nullptr;

    QStackedLayout *stack = nullptr;
    QCalendarWidget *calendar = nullptr;


    TaskDetailWindow *detail = nullptr;
    TaskEditWindow *edit = nullptr;

    void close();

    DetailPage* createDetailPage();
    EditPage* createEditPage();

signals:
    void unselectTaskBlock();

public slots:
    void showDetailWindow(AbstractTask *task);
    void showEditWindow(AbstractTask* task);

public:
    StackedWindow(QWidget *parent = nullptr);
};

#endif // STACKEDWINDOW_H
