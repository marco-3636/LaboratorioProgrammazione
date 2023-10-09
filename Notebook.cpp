//
// Created by m36 on 08/09/23.
//
#include "Notebook.h"

//CTor & DTor
Notebook::Notebook() : Titolo("Titolo Stock"), TotalLockedNotes(0) /*, TotalNotes(0)*/ {}
Notebook::Notebook(const std::string &Tit)  : Titolo(Tit), TotalLockedNotes(0) /*, TotalNotes(0)*/ {}

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

void Notebook::addNote(const Note &n) {
    Collection.push_back(n);
}

void Notebook::removeNote(int i) {

            Collection.erase(Collection.begin()+i);

}

void Notebook::viewNote(int i) {
    std::cout << "Title: " << Collection[i].getTitle() << std::endl;
    std::cout << "Text: " << Collection[i].getText() << std::endl;
    std::cout << "Locked: " << Collection[i].isLocked() << std::endl;
}

bool Notebook::noteIsLocked(int i) const {
    return Collection[i].isLocked();

}