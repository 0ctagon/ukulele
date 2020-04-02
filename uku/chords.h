#ifndef CHORDS_H
#define CHORDS_H

#include <iostream>
#include <fstream>
#include <string>
#include <QVector>

class Chords
{
protected:
    std::string databaseName;
    std::string chordsName;
    std::fstream database;

public:
    Chords();
    Chords(std::string data);

    bool findChords(QVector<int> *barStatus);
    void saveChords(std::string name, QVector<int> *barStatus);
    std::string getChords();
};

#endif // CHORDS_H
