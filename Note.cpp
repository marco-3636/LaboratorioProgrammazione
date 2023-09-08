//
// Created by m36 on 08/09/23.
//
#include "Note.h"

//Ctor & Dtor
Note::Note() : Title("Titolo stock"), Text("Test stock"), Locked(false) {}
Note::Note(const std::string &Titolo,const std::string &Testo, bool Lock) : Title(Titolo), Text(Testo), Locked(Lock) {
}

//getter and setter
const std::string &Note::getTitle() const {
    return Title;
}
void Note::setTitle(const std::string &title) {
    Title = title;
}

const std::string &Note::getText() const {
    return Text;
}
void Note::setText(const std::string &text) {
    Text = text;
}

bool Note::isLocked() const {
    return Locked;
}
void Note::setLocked(bool locked) {
    Locked = locked;

}

//metodi inerenti alla clase
std::string Notes::PrintLock() const {
    if(isLocked()){
        return "  -  (Lock)";
    }
    else{
        return " ";
    }
}