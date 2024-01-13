//
// Created by m36 on 08/09/23.
//

#ifndef LABORATORIOPROGRAMMAZIONE_SIANIMARCO_OBSERVER_H
#define LABORATORIOPROGRAMMAZIONE_SIANIMARCO_OBSERVER_H
class Observer {
public:
    virtual ~Observer() = default; //TO-DO cancellare file.cpp FATTO
    virtual void update() = 0;
};
#endif //LABORATORIOPROGRAMMAZIONE_SIANIMARCO_OBSERVER_H
