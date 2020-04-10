#include "chords.h"
#include <sstream>
#include <iostream>

Chords::Chords()
{
    databaseName = "../chords.txt";
    chordsName->clear();
    chordsName->append("");
    chordsList->clear();
}

Chords::Chords(std::string data)
{
    databaseName = data;
    chordsName->clear();
    chordsName->append("");
    chordsList->clear();
}

bool Chords::findChords(QVector<int>* barStatus)
{
    chordsList->clear();
    database.open(databaseName, std::ios::in);
    chordsName->clear();
    std::string line;
    bool found = false;
    if(database.is_open())
    {
        while(std::getline(database,line))
        {
            QVector<int> barChords;
            std::stringstream ss(line);
            std::string substr;
            int value = -999;
            std::string chordName;
            while(ss.good())
            {
                std::getline(ss, substr, ',');
                if(value == -999){chordName = substr;}
                std::stringstream strint(substr);
                strint>>value;
                barChords.append(value);
            }
            barChords.removeFirst();
            if(barChords==(*barStatus))
            {
                chordsName->append(chordName);
                found = true;
            }
        }
    }
    if(found==false)
    {
        chordsName->append("");
    }
    database.close();
    return found;
}

void Chords::saveChords(std::string name, QVector<int> *barStatus)
{
    chordsList->clear();
    database.open(databaseName, std::ios_base::app);
    database << "\n";
    database << name;
    for(int i=0; i<barStatus->length(); i++)
    {
        database << ",";
        database << (*barStatus)[i];
    }
    database.close();
}

QVector<std::string>* Chords::getChordsName()
{
    return chordsName;
}

QVector<QVector<int>> *Chords::getChords(std::string name)
{
    if(chordsList->size()>1 && (*chordsName)[0]==name)
    {
        return chordsList;
    }
    chordsList->clear();
    chordsName->clear(); chordsName->append(name);
    database.open(databaseName, std::ios::in);
    std::string line;
    if(database.is_open())
    {
        while(std::getline(database,line))
        {
            QVector<int> barChords;
            std::stringstream ss(line);
            std::string substr;
            int value = -999;
            std::string chordName;
            while(ss.good())
            {
                std::getline(ss, substr, ',');
                if(value == -999){chordName = substr;}
                std::stringstream strint(substr);
                strint>>value;
                barChords.append(value);
            }
            barChords.removeFirst();
            if(chordName==(*chordsName)[0])
            {
                chordsList->append(barChords);
            }
        }
    }
    if(chordsList->size()==0)
    {
        QVector<int> barsStatus = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        chordsList->append(barsStatus);
    }
    database.close();
    return chordsList;
}

int Chords::getChordsListSize()
{
    return chordsList->size();
}
