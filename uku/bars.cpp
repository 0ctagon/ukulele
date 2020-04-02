#include "bars.h"
#include <qsignalmapper.h>
#include <iostream>

Bars::Bars(QObject *parent) : QObject(parent)
{
    barCase->clear();
    barCase->append(nullptr);
    barCase->append(nullptr);
    barCase->append(nullptr);
    barCase->append(nullptr);
}


Bars::Bars(Cases *c0, Cases *c1, Cases *c2, Cases *c3)
{
    barCase->clear();
    barCase->append(c0);
    barCase->append(c1);
    barCase->append(c2);
    barCase->append(c3);

    connect(c0, SIGNAL(stateChanged()), this, SLOT(emitBarChanged())) ;
    connect(c1, SIGNAL(stateChanged()), this, SLOT(emitBarChanged())) ;
    connect(c2, SIGNAL(stateChanged()), this, SLOT(emitBarChanged())) ;
    connect(c3, SIGNAL(stateChanged()), this, SLOT(emitBarChanged())) ;
}

void Bars::setBars(Cases *c0, Cases *c1, Cases *c2, Cases *c3)
{
    barCase->clear();
    barCase->append(c0);
    barCase->append(c1);
    barCase->append(c2);
    barCase->append(c3);

    connect(c0, SIGNAL(stateChanged()), this, SLOT(emitBarChanged())) ;
    connect(c1, SIGNAL(stateChanged()), this, SLOT(emitBarChanged())) ;
    connect(c2, SIGNAL(stateChanged()), this, SLOT(emitBarChanged())) ;
    connect(c3, SIGNAL(stateChanged()), this, SLOT(emitBarChanged())) ;
}

Cases* Bars::getCase(int i)
{
    return (*barCase)[i];
}


int Bars::getBarValue()
{
    return (*barCase)[0]->getState() | ((*barCase)[1]->getState() << 1) | ((*barCase)[2]->getState() << 2) | ((*barCase)[3]->getState() << 3);
}

void Bars::emitBarChanged()
{
    emit barChanged();
}
