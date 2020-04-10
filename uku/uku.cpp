#include "uku.h"
#include "ui_uku.h"

uku::uku(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::uku)
{
    ui->setupUi(this);
    ui->chordsLabel->setText("");

    b0->setBars(new Cases(ui->c01, ui->l01, Gs), new Cases(ui->c02, ui->l02, Cs), new Cases(ui->c03, ui->l03, F), new Cases(ui->c04, ui->l04, As));
    b1->setBars(new Cases(ui->c11, ui->l11, A), new Cases(ui->c12, ui->l12, D), new Cases(ui->c13, ui->l13, Fs), new Cases(ui->c14, ui->l14, B));
    b2->setBars(new Cases(ui->c21, ui->l21, As), new Cases(ui->c22, ui->l22, Ds), new Cases(ui->c23, ui->l23, G), new Cases(ui->c24, ui->l24, C));
    b3->setBars(new Cases(ui->c31, ui->l31, B), new Cases(ui->c32, ui->l32, E), new Cases(ui->c33, ui->l33, Gs), new Cases(ui->c34, ui->l34, Cs));
    b4->setBars(new Cases(ui->c41, ui->l41, C), new Cases(ui->c42, ui->l42, F), new Cases(ui->c43, ui->l43, A), new Cases(ui->c44, ui->l44, D));
    b5->setBars(new Cases(ui->c51, ui->l51, Cs), new Cases(ui->c52, ui->l52, Fs), new Cases(ui->c53, ui->l53, As), new Cases(ui->c54, ui->l54, Ds));
    b6->setBars(new Cases(ui->c61, ui->l61, D), new Cases(ui->c62, ui->l62, G), new Cases(ui->c63, ui->l63, B), new Cases(ui->c64, ui->l64, E));
    b7->setBars(new Cases(ui->c71, ui->l71, Ds), new Cases(ui->c72, ui->l72, Gs), new Cases(ui->c73, ui->l73, C), new Cases(ui->c74, ui->l74, F));
    b8->setBars(new Cases(ui->c81, ui->l81, E), new Cases(ui->c82, ui->l82, A), new Cases(ui->c83, ui->l83, Cs), new Cases(ui->c84, ui->l84, Fs));
    b9->setBars(new Cases(ui->c91, ui->l91, F), new Cases(ui->c92, ui->l92, As), new Cases(ui->c93, ui->l93, D), new Cases(ui->c94, ui->l94, G));
    b10->setBars(new Cases(ui->c101, ui->l101, Fs), new Cases(ui->c102, ui->l102, B), new Cases(ui->c103, ui->l103, Ds), new Cases(ui->c104, ui->l104, Gs));
    b11->setBars(new Cases(ui->c111, ui->l111, G), new Cases(ui->c112, ui->l112, C), new Cases(ui->c113, ui->l113, E), new Cases(ui->c114, ui->l114, A));
    b12->setBars(new Cases(ui->c121, ui->l121, Gs), new Cases(ui->c122, ui->l122, Cs), new Cases(ui->c123, ui->l123, F), new Cases(ui->c124, ui->l124, As));
    b13->setBars(new Cases(ui->c131, ui->l131, A), new Cases(ui->c132, ui->l132, D), new Cases(ui->c133, ui->l133, Fs), new Cases(ui->c134, ui->l134, B));
    b14->setBars(new Cases(ui->c141, ui->l141, As), new Cases(ui->c142, ui->l142, Ds), new Cases(ui->c143, ui->l143, G), new Cases(ui->c144, ui->l144, C));
    b15->setBars(new Cases(ui->c151, ui->l151, B), new Cases(ui->c152, ui->l152, E), new Cases(ui->c153, ui->l153, Gs), new Cases(ui->c154, ui->l154, Cs));
    b16->setBars(new Cases(ui->c161, ui->l161, C), new Cases(ui->c162, ui->l162, F), new Cases(ui->c163, ui->l163, A), new Cases(ui->c164, ui->l164, D));

    barsController->setBarsController(b0,b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15,b16);

    connect(barsController,SIGNAL(chordsFound()), this, SLOT(displayChords()));
    connect(barsController,SIGNAL(chordsNotFound()), this, SLOT(eraseChords()));

    connect(ui->resetButton,SIGNAL(clicked()), this, SLOT(clearAll()));
    connect(this,SIGNAL(unCheck()), barsController, SLOT(unCheck()));

    connect(ui->SaveButton, SIGNAL(clicked()), this, SLOT(saveChords()));
    connect(this, SIGNAL(saveChordsSignal(std::string)), barsController, SLOT(saveBars(std::string)));

    strings->setStrings(barsController);

    connect(barsController,SIGNAL(barChanged()), strings, SLOT(setNotes()));
    connect(strings,SIGNAL(notesSet()), this, SLOT(displayStrings()));

    connect(ui->selectChord,SIGNAL(valueChanged(int)), this, SLOT(setBarsValue(int)));
}



uku::~uku()
{
    delete ui;
}

void uku::resetSetChords()
{
    ui->numberFound->setText("");
    disconnect(ui->selectChord,SIGNAL(valueChanged(int)), this, SLOT(setBarsValue(int)));
    ui->selectChord->setMinimum(-1);
    ui->selectChord->setValue(-1);
    connect(ui->selectChord,SIGNAL(valueChanged(int)), this, SLOT(setBarsValue(int)));
}

void uku::saveChords()
{
    std::string name = ui->chordsLabel->text().toStdString();
    emit saveChordsSignal(name);
    ui->chordsLabel->setText(QString::fromStdString(name));
}

void uku::displayChords()
{
    QVector<std::string>* chordsName = barsController->getChordsName();
    std::string fullName = (*chordsName)[0];
    for(int i=1; i<chordsName->size(); i++)
    {
        fullName += "  ||  ";
        fullName += (*chordsName)[i];
    }
    ui->chordsLabel->setText(QString::fromStdString(fullName));
    resetSetChords();
}

void uku::eraseChords()
{
    ui->chordsLabel->setText("");
    resetSetChords();
}

void uku::displayStrings()
{
    ui->strG->setText(strings->getNotes(0));
    ui->strC->setText(strings->getNotes(1));
    ui->strE->setText(strings->getNotes(2));
    ui->strA->setText(strings->getNotes(3));
}

void uku::setBarsValue(int chordNumber)
{
    ui->selectChord->setMinimum(0);
    std::string chordName = ui->chordsLabel->text().toStdString();
    if(chordName=="")
    {
        ui->selectChord->setMaximum(0);
        ui->numberFound->setText("0 chord found");
        return;
    }
    barsController->setBarsValue(chordName, chordNumber);
    int maxValue = barsController->getChordsListSize()-1;
    if(chordNumber>=maxValue)
    {
        ui->selectChord->setValue(maxValue);
    }
    ui->selectChord->setMaximum(maxValue);
    ui->numberFound->setText(QString::number(maxValue)+" chords found");
}

void uku::clearAll()
{
    ui->strG->setText("G");
    ui->strC->setText("C");
    ui->strE->setText("E");
    ui->strA->setText("A");
    ui->chordsLabel->setText("");
    resetSetChords();
    emit unCheck();
}

