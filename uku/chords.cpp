#include "chords.h"
#include <sstream>
#include <iostream>

Chords::Chords()
{
    databaseName = "chords.txt";
    chordsName = "";
}

Chords::Chords(std::string data)
{
    databaseName = data;
    chordsName = "";
}

bool Chords::findChords(QVector<int>* barStatus)
{
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
            while(ss.good())
            {
                std::getline(ss, substr, ',');
                if(value == -999){chordsName = substr;}
                std::stringstream strint(substr);
                strint>>value;
                barChords.append(value);
            }
            barChords.removeFirst();
            if(barChords==(*barStatus))
            {
                database.close();
                return true;
            }
        }
    }
    chordsName = "";
    database.close();
    return false;
}

void Chords::saveChords(std::string name, QVector<int> *barStatus)
{
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

std::string Chords::getChords()
{
    return chordsName;
}
