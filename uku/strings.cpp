#include "strings.h"

Strings::Strings(QObject *parent) : QObject(parent)
{
    strNotes->clear();
    strNotes->append("G");
    strNotes->append("C");
    strNotes->append("E");
    strNotes->append("A");
    strG->clear();
    strC->clear();
    strE->clear();
    strA->clear();
    strG->fill(nullptr);
    strC->fill(nullptr);
    strE->fill(nullptr);
    strA->fill(nullptr);
}

Strings::Strings(BarsController *bc)
{
    strNotes->clear();
    strNotes->append("G");
    strNotes->append("C");
    strNotes->append("E");
    strNotes->append("A");
    strG->clear();
    strC->clear();
    strE->clear();
    strA->clear();
    for(int i=0; i<bc->getLength(); i++)
    {
        strG->append(bc->getBar(i)->getCase(0));
        strC->append(bc->getBar(i)->getCase(1));
        strE->append(bc->getBar(i)->getCase(2));
        strA->append(bc->getBar(i)->getCase(3));
    }
}

void Strings::setStrings(BarsController *bc)
{
    strNotes->clear();
    strNotes->append("G");
    strNotes->append("C");
    strNotes->append("E");
    strNotes->append("A");
    strG->clear();
    strC->clear();
    strE->clear();
    strA->clear();
    for(int i=0; i<bc->getLength(); i++)
    {
        strG->append(bc->getBar(i)->getCase(0));
        strC->append(bc->getBar(i)->getCase(1));
        strE->append(bc->getBar(i)->getCase(2));
        strA->append(bc->getBar(i)->getCase(3));
    }
}

QString Strings::getNotes(int i)
{
    return (*strNotes)[i];
}

void Strings::setNotes()
{
    strNotes->clear();
    strNotes->append("G");
    strNotes->append("C");
    strNotes->append("E");
    strNotes->append("A");

    for(int i=0; i<strG->length(); i++)
    {
        if((*strG)[i]->getState()) { (*strNotes)[0] = (*strG)[i]->getStrNote();}
        if((*strC)[i]->getState()) { (*strNotes)[1] = (*strC)[i]->getStrNote();}
        if((*strE)[i]->getState()) { (*strNotes)[2] = (*strE)[i]->getStrNote();}
        if((*strA)[i]->getState()) { (*strNotes)[3] = (*strA)[i]->getStrNote();}
    }

    emit notesSet();
}
