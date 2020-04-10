#include "barscontroller.h"

BarsController::BarsController(QObject *parent) : QObject(parent)
{
    barsStatus->fill(0);
    barsVect->clear();
    barsVect->fill(nullptr);
}

BarsController::BarsController(Bars *b0, Bars *b1, Bars *b2, Bars *b3, Bars *b4, Bars *b5, Bars *b6, Bars *b7, Bars *b8, Bars *b9, Bars *b10, Bars *b11, Bars *b12, Bars *b13, Bars *b14, Bars *b15, Bars *b16)
{
    barsStatus->fill(0);
    barsVect->clear();
    barsVect->append(b0);
    barsVect->append(b1);
    barsVect->append(b2);
    barsVect->append(b3);
    barsVect->append(b4);
    barsVect->append(b5);
    barsVect->append(b6);
    barsVect->append(b7);
    barsVect->append(b8);
    barsVect->append(b9);
    barsVect->append(b10);
    barsVect->append(b11);
    barsVect->append(b12);
    barsVect->append(b13);
    barsVect->append(b14);
    barsVect->append(b15);
    barsVect->append(b16);

    for(int i=0; i<barsVect->length(); i++)
    {
        connect((*barsVect)[i],SIGNAL(barChanged()), this, SLOT(checkBars()));
    }
}

void BarsController::setBarsController(Bars *b0, Bars *b1, Bars *b2, Bars *b3, Bars *b4, Bars *b5, Bars *b6, Bars *b7, Bars *b8, Bars *b9, Bars *b10, Bars *b11, Bars *b12, Bars *b13, Bars *b14, Bars *b15, Bars *b16)
{
    barsStatus->fill(0);
    barsVect->clear();
    barsVect->append(b0);
    barsVect->append(b1);
    barsVect->append(b2);
    barsVect->append(b3);
    barsVect->append(b4);
    barsVect->append(b5);
    barsVect->append(b6);
    barsVect->append(b7);
    barsVect->append(b8);
    barsVect->append(b9);
    barsVect->append(b10);
    barsVect->append(b11);
    barsVect->append(b12);
    barsVect->append(b13);
    barsVect->append(b14);
    barsVect->append(b15);
    barsVect->append(b16);

    for(int i=0; i<barsVect->length(); i++)
    {
        connect((*barsVect)[i],SIGNAL(barChanged()), this, SLOT(checkBars()));
    }
}

Bars *BarsController::getBar(int i)
{
    return (*barsVect)[i];
}

int BarsController::getLength()
{
    return barsVect->length();
}

QVector<std::string>* BarsController::getChordsName()
{
    return data.getChordsName();
}

int BarsController::getChordsListSize()
{
    return data.getChordsListSize();
}

void BarsController::checkBars()
{
    for (int i=0; i<barsVect->size(); i++)
    {
        (*barsStatus)[i] = barsVect->value(i)->getBarValue();

    }
    emit barChanged();

    checkChords();
}

void BarsController::checkChords()
{
    if(data.findChords(barsStatus))
    {
        emit chordsFound();
    }
    else
    {
        emit chordsNotFound();
    }
}

void BarsController::unCheck()
{
    for(int i=0; i<barsVect->length(); i++)
    {
        disconnect((*barsVect)[i],SIGNAL(barChanged()), this, SLOT(checkBars()));
        (*barsVect)[i]->unCheck();
        connect((*barsVect)[i],SIGNAL(barChanged()), this, SLOT(checkBars()));
    }
}

void BarsController::saveBars(std::string name)
{
    data.saveChords(name, barsStatus);
}

void BarsController::setBarsValue(std::string name, int chordNumber)
{

    QVector<QVector<int>>* barValues = data.getChords(name);
    if(chordNumber>=barValues->size())
    {
        chordNumber=barValues->size()-1;
    }
    QVector<int> barValue = (*barValues)[chordNumber];

    for(int i=0; i<barsVect->length(); i++)
    {
        disconnect((*barsVect)[i],SIGNAL(barChanged()), this, SLOT(checkBars()));
        (*barsVect)[i]->setBarValue(barValue[i]);
        connect((*barsVect)[i],SIGNAL(barChanged()), this, SLOT(checkBars()));
    }
}
