//
// Created by m36 on 08/09/23.
//

#ifndef LABORATORIOPROGRAMMAZIONE_SIANIMARCO_DISPLAYER_H
#define LABORATORIOPROGRAMMAZIONE_SIANIMARCO_DISPLAYER_H
#include "Observer.h"
#include "Subject.h"
#include "SetCollezioni.h"

class Displayer : public Observer{
private:
    int TotalLockNotes, TotalNotes, CollectionNotes, CollectionLockNotes;
    SetCollezioni* pExecutive;
    //TO-DO mettere i metodi get privati e/o protected FATTO
    //getter
    int getTotalLockNotes() const;
    int getTotalNotes() const;
    int getCollectionNotes() const;
    int getCollectionLockNotes() const;
    Subject *getpExecutive() const;

public:
    //CTor & DTor
    explicit Displayer(SetCollezioni* c) : pExecutive(c), TotalLockNotes(0), TotalNotes(0), CollectionLockNotes(0), CollectionNotes(0){
        pExecutive->addObserver(this);
    }
    ~Displayer() override;


    //metodi inerenti alla classe
    void update() override;
    void ShowTotal() const;
    void ShowCol() const;

//protected:

};
#endif //LABORATORIOPROGRAMMAZIONE_SIANIMARCO_DISPLAYER_H
