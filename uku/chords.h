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
    QVector<QVector<int>>* chordsList = new QVector<QVector<int>>;

public:
    Chords();
    Chords(std::string data);

    bool findChords(QVector<int> *barStatus);
    void saveChords(std::string name, QVector<int> *barStatus);
    QVector<std::string>* getChordsName();
    QVector<QVector<int>>* getChords(std::string name);
    int getChordsListSize();
};

#endif // CHORDS_H
