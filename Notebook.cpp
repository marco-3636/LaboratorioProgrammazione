//
// Created by m36 on 08/09/23.
//
#include "Notebook.h"

//CTor & DTor
Notebook::Notebook() : Titolo("Titolo Stock"), TotalLockedNotes(0), TotalNotes(0) {}
Notebook::Notebook(const std::string &Tit)  : Titolo(Tit), TotalLockedNotes(0), TotalNotes(0) {}

Notebook::~Notebook() {
    std::cout << "\nLa collezione " << this->Titolo << " e' stata eliminata";
}

//getter & setter
const std::string &Notebook::getTitolo() const {
    return Titolo;
}

const std::vector<Note> &Notebook::getCollection() const {
    return Collection;
}
void Notebook::setCollection(const std::vector<Note> &collection) {
    Collection = collection;
}

int Notebook::getTotalNotes() const {
    return Collection.size();
}


int Notebook::getTotalLockedNotes() const {
    return TotalLockedNotes;
}
void Notebook::setTotalLockedNotes(int totalLockedNotes) {
    TotalLockedNotes = totalLockedNotes;
}

//metodi inerenti alla classe
int Notebook::CollectionSize() const {
    return Collection.size();
}

Note * Notebook::getNote(int i){
    return &(Collection[i]);
}