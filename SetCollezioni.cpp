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
//TODO delaegare il lavoro ad un metodo della classe collezione addNote (fatto), removeNote(fatto), viewNote(fatto), isNoteLocked(fatto) ecc
void SetCollezioni::AddNote(const Note &NewNote, Notebook &n) {
    /*std::vector<Note> vec = Col->getCollection();
    vec.push_back(NewNote);
    Col->setCollection(vec);*/
    n.addNote(NewNote);
    TotNotesCount ++;
    //Col->setTotalNotes(Col->getTotalNotes()+1);
    ColNotesCount=Col->getTotalNotes();
    if(NewNote.isLocked()) {
        TotLockNotesCount++;
        Col->setTotalLockedNotes(Col->getTotalLockedNotes()+1);
        ColLockNotesCount=Col->getTotalLockedNotes();
    }
    notify();
}

void SetCollezioni::RemoveNote(int i, Notebook &n) {
    //std::vector<Note> vec = Col->getCollection();
    bool bloccata = n.getNote(i)->isLocked();
    n.removeNote(i);
    TotNotesCount --;
    //Col->setTotalNotes(Col->getTotalNotes()-1);
    ColNotesCount=Col->getTotalNotes();
    if(bloccata){
        TotLockNotesCount --;
        Col->setTotalLockedNotes(Col->getTotalLockedNotes()-1);
        ColLockNotesCount=Col->getTotalLockedNotes();
    }
    //vec.erase(vec.begin()+i);
    //Col->setCollection(vec);
    notify();
}

void SetCollezioni::ViewNote(int i, Notebook &n) const {

    n.viewNote(i);
}

bool SetCollezioni::IsNoteLocked(int i, Notebook &n) const {
    //Note *nota = Col->getNote(i);
    bool locked = n.noteIsLocked(i);
    //return nota->isLocked();
    return locked;
}

bool SetCollezioni::ModifyNote(int i, int choice, const std::string& t) {
    Note nota(" ", " ", false);
    nota.setTitle(Col->getNote(i)->getTitle());
    nota.setText(Col->getNote(i)->getText());
    if (IsNoteLocked(i)){
        std::cout<<"la nota è bloccata, impossibile modificarla"<<std::endl;
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

int SetCollezioni::ricercaCollezione(std::vector<Notebook*> notebook ,const std::string &t) const {

    for(int i = 0; i<notebook.size(); i++){
        if(notebook[i]->getTitolo() == t){
            return i;
        }
    }
    return -1;
}

void SetCollezioni::SearchNoteByTitle(std::vector<Notebook*> notebook, const std::string &t) const {
    bool trovata = false;
    for(int i = 0; i < notebook.size(); i++){
        for(int j = 0; j < notebook[i]->CollectionSize(); j++){
            if(notebook[i]->getNote(j)->getTitle() == t){
                std::cout << "Notebook contenente la nota: " << notebook[i]->getTitolo() << std::endl;
                trovata = true;
            }
        }
    }
    if(!trovata){
        std::cout << "Nessuna nota con quel nome trovata" << std::endl;
    }
}

void SetNoteImportance (const Note &n, Notebook &c, SetCollezioni &ctrl){
    int s;
    ctrl.setCol(&c);
    std::cout << "\nQuesta nota è importante? (0=yes / 1=no)" << std::endl;
    do {
        std::cin >> s;
    } while (s > 1 || s < 0);
    if (s == 0){
        ctrl.AddNote(n, c);
    }
}