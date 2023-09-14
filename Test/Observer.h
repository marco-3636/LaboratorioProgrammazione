//
// Created by m36 on 14/09/23.
//

#ifndef TEST_OBSERVER_H
#define TEST_OBSERVER_H
class Observer {
public:
    virtual ~Observer();
    virtual void update() = 0;
};
#endif //TEST_OBSERVER_H
