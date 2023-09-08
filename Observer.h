//
// Created by m36 on 08/09/23.
//

#ifndef LABORATORIOPROGRAMMAZIONE_SIANIMARCO_OBSERVER_H
#define LABORATORIOPROGRAMMAZIONE_SIANIMARCO_OBSERVER_H
class Observer {
public:
    virtual ~Observer();
    virtual void attachObserver()=0;
    virtual void deAttachObserver()=0;
    virtual void update() = 0;
};
#endif //LABORATORIOPROGRAMMAZIONE_SIANIMARCO_OBSERVER_H
