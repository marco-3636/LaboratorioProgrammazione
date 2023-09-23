//
// Created by m36 on 08/09/23.
//

#ifndef LABORATORIOPROGRAMMAZIONE_SIANIMARCO_SETCOLLEZIONI_H
#define LABORATORIOPROGRAMMAZIONE_SIANIMARCO_SETCOLLEZIONI_H
#include "Notebook.h"
#include "Note.h"
#include "Subject.h"
#include <iostream>

class SetCollezioni : public Subject{
private:
    Notebook* Col;
    int TotNotesCount, TotLockNotesCount, ColNotesCount, ColLockNotesCount;
    std::list<Observer*> observers;

public:
    //costruttore
    explicit SetCollezioni(Notebook* c): Col(c), TotNotesCount(0), TotLockNotesCount(0), ColLockNotesCount(0), ColNotesCount(0){}

    //getters & setters
    int getTotNotesCount() const;
    int getTotLockNotesCount() const;
    int getColNotesCount() const;
    int getColLockNotesCount() const;

    void setCol(Notebook *col);
    Notebook *getCol() const;

    /*void setTotNotesCount(int totNotesCount);
    void setTotLockNotesCount(int totLockNotesCount);
    void setColNotesCount(int colNotesCount);
    void setColLockNotesCount(int colLockNotesCount);*/

    //metodi inerenti alla classe
    //TODO la classe dovrà occuparsi di gestire le collezioni, aggiungere attributo al metodo (non dal main)
    void ViewCol () const;
    void AddNote(const Note &NewNote);
    void RemoveNote(int i);
    void ViewNote(int i) const;
    bool IsNoteLocked(int i) const;
    bool ModifyNote(int i, int choice,const std::string& t);
    //TODO cerca note per titolo su tutte le collezioni
    //metodi subject
    void notify() override;
    void addObserver(Observer *o) override;
    void removeObserver(Observer *o) override;
};
#endif //LABORATORIOPROGRAMMAZIONE_SIANIMARCO_SETCOLLEZIONI_H
