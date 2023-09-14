//
// Created by m36 on 14/09/23.
//

#ifndef TEST_SUBJECT_H
#define TEST_SUBJECT_H

#include "Observer.h"


class Subject{
public:
    virtual ~Subject();
    virtual void notify() = 0;
    virtual void addObserver(Observer* o) = 0;
    virtual void removeObserver(Observer* o) = 0;

};
#endif //TEST_SUBJECT_H
