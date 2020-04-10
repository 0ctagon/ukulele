#ifndef UKU_H
#define UKU_H
#include "barscontroller.h"
#include "strings.h"

#include <QMainWindow>

namespace Ui {
class uku;
}

class uku : public QMainWindow
{
    Q_OBJECT

public:
    explicit uku(QWidget *parent = nullptr);
    ~uku();

private:
    Ui::uku *ui;
    Bars* b0 = new Bars();
    Bars* b1 = new Bars();
    Bars* b2 = new Bars();
    Bars* b3 = new Bars();
    Bars* b4 = new Bars();
    Bars* b5 = new Bars();
    Bars* b6 = new Bars();
    Bars* b7 = new Bars();
    Bars* b8 = new Bars();
    Bars* b9 = new Bars();
    Bars* b10 = new Bars();
    Bars* b11 = new Bars();
    Bars* b12 = new Bars();
    Bars* b13 = new Bars();
    Bars* b14 = new Bars();
    Bars* b15 = new Bars();
    Bars* b16 = new Bars();
    BarsController* barsController = new BarsController();
    Strings* strings = new Strings();
    Chords* data = new Chords();

    void resetSetChords();

public slots:
    void saveChords();

    void displayChords();
    void eraseChords();
    void displayStrings();
    void setBarsValue(int chordNumber);

    void clearAll();

signals:
    void saveChordsSignal(std::string);
    void unCheck();
};

#endif // UKU_H
