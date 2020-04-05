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
    QVector<std::string>* chordsName = new QVector<std::string>;
    std::fstream database;

public:
    Chords();
    Chords(std::string data);

    bool findChords(QVector<int> *barStatus);
    void saveChords(std::string name, QVector<int> *barStatus);
    QVector<std::string>* getChords();
};

#endif // CHORDS_H
