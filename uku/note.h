#ifndef TOOLS_H
#define TOOLS_H
#include <map>
#include <QString>

enum Notes
{
    A,B,C,D,E,F,G,As,Cs,Ds,Fs,Gs
};

static std::map<Notes, QString> note2str = {
    {A, "A"},
    {B, "B"},
    {C, "C"},
    {D, "D"},
    {E, "E"},
    {F, "F"},
    {G, "G"},
    {As, "A#"},
    {Cs, "C#"},
    {Ds, "D#"},
    {Fs, "F#"},
    {Gs, "G#"}
};

#endif // TOOLS_H
