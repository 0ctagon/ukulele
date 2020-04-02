#ifndef CASES_H
#define CASES_H

#include <QObject>
#include <QCheckBox>
#include <QLabel>
#include "note.h"


class Cases : public QObject
{
    Q_OBJECT

private:
    QCheckBox* cb;
    QLabel* label;
    bool state;
    Notes note;

public:
    explicit Cases(QObject *parent = nullptr);
    explicit Cases(QCheckBox* c0, QLabel* l0, Notes a0);

    bool getState();
    Notes getNote();
    QString getStrNote();

public slots:
    void switchState();

signals:
    void stateChanged();
};

#endif // CASES_H
