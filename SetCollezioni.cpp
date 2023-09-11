//
// Created by m36 on 08/09/23.
//
#include "SetCollezioni.h"

//getters & setter
int SetCollezioni::getTotNotesCount() const {
    return TotNotesCount;
}

int SetCollezioni::getTotLockNotesCount() const {
    return TotLockNotesCount;
}

void SetCollezioni::setCol(Notebook *col) {
    Col = col;
    ColNotesCount=Col->getTotalNotes();
    ColLockNotesCount=Col->getTotalLockedNotes();
    notify();
}

int SetCollezioni::getColNotesCount() const {
    return ColNotesCount;
}

int SetCollezioni::getColLockNotesCount() const {
    return ColLockNotesCount;
}

Notebook *SetCollezioni::getCol() const {
    return Col;
}

//metodi inerenti alla classe
void SetCollezioni::ViewCol() const {
    std::cout << Col->getTitolo() << std::endl;
    std::cout << "      Note: " << std::endl;
    for(int i = 0; i<Col->CollectionSize(); i++){
        Note* note = Col->getNote(i);
        std::cout << "         " << i << ") Title: " << note->getTitle() << note->PrintLock() << std::endl;
    }
}

void SetCollezioni::AddNote(const Note &NewNote) {
    std::vector<Note> vec = Col->getCollection();
    vec.push_back(NewNote);
    Col->setCollection(vec);
    TotNotesCount ++;
    Col->setTotalNotes(Col->getTotalNotes()+1);
    ColNotesCount=Col->getTotalNotes();
    if(NewNote.isLocked()) {
        TotLockNotesCount++;
        Col->setTotalLockedNotes(Col->getTotalLockedNotes()+1);
        ColLockNotesCount=Col->getTotalLockedNotes();
    }
    notify();
}

void SetCollezioni::RemoveNote(int i) {
    std::vector<Note> vec = Col->getCollection();
    TotNotesCount --;
    Col->setTotalNotes(Col->getTotalNotes()-1);
    ColNotesCount=Col->getTotalNotes();
    if(vec[i].isLocked()){
        TotLockNotesCount --;
        Col->setTotalLockedNotes(Col->getTotalLockedNotes()-1);
        ColLockNotesCount=Col->getTotalLockedNotes();
    }
    vec.erase(vec.begin()+i);
    Col->setCollection(vec);
    notify();
}

void SetCollezioni::ViewNote(int i) const {
    Note *nota = Col->getNote(i);
    std::cout << "Titolo: " << nota->getTitle() << "\nText: " << nota->getText() << std::endl;
}

bool SetCollezioni::IsNoteLocked(int i) const {
    Note *nota = Col->getNote(i);
    return nota->isLocked();
}

bool SetCollezioni::ModifyNote(int i, int choice, const std::string& t) {
    Note nota(" ", " ", false);
    nota.setTitle(Col->getNote(i)->getTitle());
    nota.setText(Col->getNote(i)->getText());
    if (IsNoteLocked(i)){
        return false;
    }
    else {
        if(choice == 1) {
            nota.setTitle(t);
        }
        else if(choice == 2){
            nota.setText(t);
        }
        /*else{
            nota.setLocked(!nota.isLocked());
            TotLockNotesCount++;
            Col->setTotalLockedNotes(Col->getTotalLockedNotes()+1);
            ColLockNotesCount=Col->getTotalLockedNotes();
            notify();
        }*/
        std::vector<Note> Vec = Col->getCollection();
        //auto itPos = Vec.begin()+i;
        Vec[i] = nota;
        Col->setCollection(Vec);
        return true;
    }


}

//metodi Subject
void SetCollezioni::notify() {
    for(auto & observer : observers){
        observer->update();
    }
}

void SetCollezioni::addObserver(Observer *o) {
    observers.push_back(o);
}

void SetCollezioni::removeObserver(Observer *o) {
    observers.remove(o);
}