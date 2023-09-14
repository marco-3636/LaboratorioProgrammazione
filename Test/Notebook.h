//
// Created by m36 on 14/09/23.
//

#ifndef TEST_NOTEBOOK_H
#define TEST_NOTEBOOK_H
#include <iostream>
#include <vector>
#include "Note.h"
class Notebook{
private:
    std::string Titolo;
    std::vector<Note> Collection;
    int TotalNotes;
    int TotalLockedNotes;


public:
    //Ctor & Dtor
    Notebook();
    explicit Notebook(const std::string &Tit);
    ~Notebook();

    //getter & setter
    const std::string &getTitolo() const;

    const std::vector<Note> &getCollection() const;
    void setCollection(const std::vector<Note> &collection);

    int getTotalNotes() const;
    void setTotalNotes(int totalNotes);

    int getTotalLockedNotes() const;
    void setTotalLockedNotes(int totalLockedNotes);

    //metodi inerenti alla classe
    int CollectionSize() const;
    Note * getNote(int i);


};
#endif //TEST_NOTEBOOK_H
