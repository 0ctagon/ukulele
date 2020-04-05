#ifndef BARSCONTROLLER_H
#define BARSCONTROLLER_H
#include "bars.h"
#include "chords.h"

#include <QObject>

class BarsController : public QObject
{
    Q_OBJECT

private:
    QVector<int> * barsStatus = new QVector<int>(17);
    QVector<Bars*> * barsVect = new QVector<Bars*>(17);
    Chords data;

public:
    BarsController(QObject *parent = nullptr);
    BarsController(Bars *b0, Bars *b1, Bars *b2, Bars *b3, Bars *b4, Bars *b5, Bars *b6, Bars *b7, Bars *b8, Bars *b9, Bars *b10, Bars *b11, Bars *b12, Bars *b13, Bars *b14, Bars *b15, Bars *b16);

    void setBarsController(Bars *b0, Bars *b1, Bars *b2, Bars *b3, Bars *b4, Bars *b5, Bars *b6, Bars *b7, Bars *b8, Bars *b9, Bars *b10, Bars *b11, Bars *b12, Bars *b13, Bars *b14, Bars *b15, Bars *b16);

    Bars* getBar(int i);

    int getLength();
    QVector<std::string>* getChords();


public slots:
    void checkBars();
    void checkChords();

    void unCheck();

    void saveBars(std::string name);

signals:
    void barChanged();
    void chordsFound();
    void chordsNotFound();

};

#endif // BARSCONTROLLER_H
