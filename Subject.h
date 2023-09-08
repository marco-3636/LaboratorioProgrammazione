//
// Created by m36 on 08/09/23.
//

#ifndef LABORATORIOPROGRAMMAZIONE_SIANIMARCO_SUBJECT_H
#define LABORATORIOPROGRAMMAZIONE_SIANIMARCO_SUBJECT_H
#include "Observer.h"

class Subject{
public:
    virtual ~Subject();
    virtual void notify() = 0;
    virtual void addObserver(Observer* o) = 0;
    virtual void removeObserver(Observer* o) = 0;

};

#endif //LABORATORIOPROGRAMMAZIONE_SIANIMARCO_SUBJECT_H
