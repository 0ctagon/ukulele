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

    connect(b0,SIGNAL(barChanged()), this, SLOT(checkBars()));
    connect(b1,SIGNAL(barChanged()), this, SLOT(checkBars()));
    connect(b2,SIGNAL(barChanged()), this, SLOT(checkBars()));
    connect(b3,SIGNAL(barChanged()), this, SLOT(checkBars()));
    connect(b4,SIGNAL(barChanged()), this, SLOT(checkBars()));
    connect(b5,SIGNAL(barChanged()), this, SLOT(checkBars()));
    connect(b6,SIGNAL(barChanged()), this, SLOT(checkBars()));
    connect(b7,SIGNAL(barChanged()), this, SLOT(checkBars()));
    connect(b8,SIGNAL(barChanged()), this, SLOT(checkBars()));
    connect(b9,SIGNAL(barChanged()), this, SLOT(checkBars()));
    connect(b10,SIGNAL(barChanged()), this, SLOT(checkBars()));
    connect(b11,SIGNAL(barChanged()), this, SLOT(checkBars()));
    connect(b12,SIGNAL(barChanged()), this, SLOT(checkBars()));
    connect(b13,SIGNAL(barChanged()), this, SLOT(checkBars()));
    connect(b14,SIGNAL(barChanged()), this, SLOT(checkBars()));
    connect(b15,SIGNAL(barChanged()), this, SLOT(checkBars()));
    connect(b16,SIGNAL(barChanged()), this, SLOT(checkBars()));
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

    connect(b0,SIGNAL(barChanged()), this, SLOT(checkBars()));
    connect(b1,SIGNAL(barChanged()), this, SLOT(checkBars()));
    connect(b2,SIGNAL(barChanged()), this, SLOT(checkBars()));
    connect(b3,SIGNAL(barChanged()), this, SLOT(checkBars()));
    connect(b4,SIGNAL(barChanged()), this, SLOT(checkBars()));
    connect(b5,SIGNAL(barChanged()), this, SLOT(checkBars()));
    connect(b6,SIGNAL(barChanged()), this, SLOT(checkBars()));
    connect(b7,SIGNAL(barChanged()), this, SLOT(checkBars()));
    connect(b8,SIGNAL(barChanged()), this, SLOT(checkBars()));
    connect(b9,SIGNAL(barChanged()), this, SLOT(checkBars()));
    connect(b10,SIGNAL(barChanged()), this, SLOT(checkBars()));
    connect(b11,SIGNAL(barChanged()), this, SLOT(checkBars()));
    connect(b12,SIGNAL(barChanged()), this, SLOT(checkBars()));
    connect(b13,SIGNAL(barChanged()), this, SLOT(checkBars()));
    connect(b14,SIGNAL(barChanged()), this, SLOT(checkBars()));
    connect(b15,SIGNAL(barChanged()), this, SLOT(checkBars()));
    connect(b16,SIGNAL(barChanged()), this, SLOT(checkBars()));
}


Bars *BarsController::getBar(int i)
{
    return (*barsVect)[i];
}


int BarsController::getLength()
{
    return barsVect->length();
}

std::string BarsController::getChords()
{
    return data.getChords();
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

void BarsController::saveBars(std::string name)
{
    data.saveChords(name, barsStatus);
}
