//
// Created by m36 on 14/09/23.
//

#ifndef TEST_NOTE_H
#define TEST_NOTE_H
#include <list>
#include <string>

class Note{
private:
    std::string Title;
    std::string Text;
    bool Locked;

public:
    //getter & setter
    const std::string &getTitle() const;
    void setTitle(const std::string &title);

    const std::string &getText() const;
    void setText(const std::string &text);

    bool isLocked() const;
    void setLocked(bool locked);

    //Costruttori e distruttori
    Note();
    Note(const std::string &Titolo,const std::string &Testo, bool Lock);

    //metodi inerenti alla classe
    std::string PrintLock () const;

};

#endif //TEST_NOTE_H
