#ifndef FILTERWINDOW_H
#define FILTERWINDOW_H

#include <QWidget>
#include <QDateEdit>
#include <QComboBox>
#include <QCheckBox>

class FilterWindow: public QWidget{
    Q_OBJECT

private:
    //select start date
    QDateEdit *startDateSelect = nullptr;
    //optional select end date
    QDateEdit *endDateSelect = nullptr;
    //type
    QComboBox *typeSelect = nullptr;
    //button to toggle start date
    QCheckBox *start_check=nullptr;

public slots:
    void toggleEndDateEdit(bool state);

public:
    FilterWindow(QWidget *parent = nullptr);

    void setStartDate(QDate newDate);
    void setEndDate(QDate newDate);
    void setType(int i);

    QDate* getStartDate();
    QDate* getEndDate();
    int getType();
};

#endif // FILTERWINDOW_H
