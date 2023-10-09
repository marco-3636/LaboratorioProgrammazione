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
    //TO-DO la classe dovrà occuparsi di gestire le collezioni, aggiungere attributo al metodo (non dal main) FATTO,  LE COLLEZIONI LE RICERCO ALL?INTERNO DEL SET NON PIU NEL MAIN
    void ViewCol () const;
    void AddNote(const Note &NewNote,Notebook &notebook);
    void SetNoteImportance (const Note &n, Notebook &c, SetCollezioni &ctrl);
    void RemoveNote(int i, Notebook &notebook);
    void ViewNote(int i, Notebook &notebook) const;
    bool IsNoteLocked(int i, const Notebook &notebook) const;
    bool ModifyNote(int i, int choice,const std::string& t, const Notebook &notebook);
    // FATTO TO-DO cerca note per titolo su tutte le collezioni
    void SearchNoteByTitle(std::vector<Notebook*> notebook,const std::string& t) const; //TO-DO da usare nel main FATTO CASE 7
    int ricercaCollezione(std::vector<Notebook*> notebook,const std::string& t) const;

    //metodi subject
    void notify() override;
    void addObserver(Observer *o) override;
    void removeObserver(Observer *o) override;

};
#endif //LABORATORIOPROGRAMMAZIONE_SIANIMARCO_SETCOLLEZIONI_H
