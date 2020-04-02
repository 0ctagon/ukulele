#ifndef STRINGS_H
#define STRINGS_H
#include "barscontroller.h"
#include <QObject>

class Strings : public QObject
{
    Q_OBJECT

private:
    QVector<Cases*>* strG = new QVector<Cases*>(17);
    QVector<Cases*>* strC = new QVector<Cases*>(17);
    QVector<Cases*>* strE = new QVector<Cases*>(17);
    QVector<Cases*>* strA = new QVector<Cases*>(17);
    QVector<QString>* strNotes = new QVector<QString>(4);

public:
    explicit Strings(QObject *parent = nullptr);
    Strings(BarsController* bc);

    void setStrings(BarsController* bc);

    QString getNotes(int i);

public slots:
    void setNotes();

signals:
    void notesSet();

};

#endif // STRINGS_H
