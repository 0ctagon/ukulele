#ifndef BARS_H
#define BARS_H
#include <QVector>
#include <QObject>
#include "cases.h"

class Bars : public QObject
{
    Q_OBJECT

private:
    QVector<Cases*> *barCase = new QVector<Cases*>(4);

public:
    Bars(QObject *parent = nullptr);
    Bars(Cases* c0, Cases* c1, Cases* c2, Cases* c3);

    void setBars(Cases* c0, Cases* c1, Cases* c2, Cases* c3);

    Cases* getCase(int i);
    void setBarValue(int barValue);

    int getBarValue();

    void unCheck();

public slots:
    void emitBarChanged();

signals:
    void barChanged();

};

#endif // BARS_H
