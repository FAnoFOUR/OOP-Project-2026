#ifndef TASKEDITWINDOW_H
#define TASKEDITWINDOW_H

#include "GUI/GuiVisitors/EditVisitor.h"
#include "Model/Headers/AbstractTask.h"
#include "ConfirmPopup.h"

#include <QWidget>
#include <QPushButton>
#include <QScrollArea>

class TaskEditWindow: public QFrame{
    Q_OBJECT

private:

    EditVisitor visitor;

    QFrame *frame = nullptr;
    QVBoxLayout *mainLayout = nullptr;
    QScrollArea *editScrollArea = nullptr;

    QHBoxLayout *lineForButtons = nullptr;

    void editButtonLine();

    void confirmSave();

signals:
    void emitClose();

public slots:
    void showTask(AbstractTask* task);

public:
    TaskEditWindow(QWidget *parent = nullptr);
};

#endif // TASKEDITWINDOW_H
