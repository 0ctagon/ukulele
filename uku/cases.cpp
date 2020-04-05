#include "cases.h"

Cases::Cases(QObject *parent) : QObject(parent)
{
    cb = nullptr;
    label = nullptr;
    state = false;
    note = A;
}

Cases::Cases(QCheckBox *c0, QLabel* l0, Notes a0)
{
    cb = c0;
    label = l0;
    state = false;
    note = a0;

    connect(c0,SIGNAL(stateChanged(int)), this, SLOT(switchState()));
}

bool Cases::getState()
{
    return state;
}

Notes Cases::getNote()
{
    return note;
}

QString Cases::getStrNote()
{
    return note2str[note];
}

void Cases::switchState()
{
    state = !state;
    if(state) { label->setText(note2str[note]);}
    else { label->setText("");}
    emit stateChanged();
}

void Cases::unCheck()
{
    cb->setChecked(false);
    state = false;
}
