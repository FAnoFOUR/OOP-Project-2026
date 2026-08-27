#ifndef REPEATABLETASK_H
#define REPEATABLETASK_H

#include <string>
#include <vector>
#include <QBitArray>
#include <QDate>
using std::string;
using std::vector;
#include "AbstractTask.h"



class RepeatableTask : virtual public AbstractTask {
private:

    QBitArray weekDays;
    QDate repeatEndDate;

public:
    RepeatableTask(string title, string description,
                   string assignee, QDate creationDate,
                   QBitArray weekDays,
                   QDate repeatEndDate);
    virtual ~RepeatableTask() override;

    QBitArray    getWeekDays()      const;
    int         getIntervalDays()  const;
    QDate      getRepeatEndDate() const;
    bool        isActive()         const;

    void setWeekDays     (const QBitArray& newWeekDays);
    void setIntervalDays (const int& newIntervalDays);
    void setRepeatEndDate(const QDate& newRepeatEndDate);
    void setActive       (const bool& newActive);
};

#endif // REPEATABLETASK_H
