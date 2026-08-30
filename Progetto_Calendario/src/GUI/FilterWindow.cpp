#include "FilterWindow.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QCheckBox>
#include <QSpacerItem>


FilterWindow::FilterWindow(QWidget *parent): QWidget(parent) {

    startDateSelect = new QDateEdit();
    endDateSelect = new QDateEdit();
    typeSelect = new QComboBox();

    startDateSelect->setCalendarPopup(true);
    endDateSelect->setCalendarPopup(true);

    typeSelect->addItem("All");
    typeSelect->addItem("Activity");
    typeSelect->addItem("Work");
    typeSelect->addItem("Bill");
    typeSelect->addItem("Project");
    typeSelect->addItem("Reminder");

    startDateSelect->setMinimumSize(90,25);
    endDateSelect->setMinimumSize(90,25);
    typeSelect->setMinimumSize(80,25);

    startDateSelect->setMaximumSize(90,25);
    endDateSelect->setMaximumSize(90,25);
    typeSelect->setMaximumSize(80,25);

    startDateSelect->setDate(QDate(2026,1,1));
    endDateSelect->setDate(QDate(2026,12,31));

    QGridLayout *hGrid = new QGridLayout(this);

    QLabel *startDateLabel = new QLabel("From Date :");
    QLabel *endDateLabel = new QLabel("To Date :");
    QLabel *typeLabel = new QLabel("Type :");

    QVBoxLayout *col1 = new QVBoxLayout();
    QVBoxLayout *col2 = new QVBoxLayout();
    QVBoxLayout *col3 = new QVBoxLayout();



    col1->addWidget(startDateLabel);
    col1->addWidget(startDateSelect);

    col2->addWidget(endDateLabel);
    col2->addWidget(endDateSelect);

    col3->addWidget(typeLabel);
    col3->addWidget(typeSelect);

    hGrid->addLayout(col1,0,1);
    hGrid->addLayout(col2,0,2);
    hGrid->addLayout(col3,0,3);

    hGrid->setSpacing(0);

    setMinimumWidth(290);

}

void FilterWindow::setStartDate(QDate newDate){
    startDateSelect->setDate(newDate);
}

void FilterWindow::setEndDate(QDate newDate){
    endDateSelect->setDate(newDate);
}

void FilterWindow::setType(int i){
    if(i<6&&i>=0)typeSelect->setCurrentIndex(i);
    else qDebug()<<"Invalid value";
}

QDate* FilterWindow::getStartDate(){
    return new QDate(startDateSelect->date());
}

QDate* FilterWindow::getEndDate(){
    return new QDate(endDateSelect->date());
}

int FilterWindow::getType(){
    return typeSelect->currentIndex();
}
