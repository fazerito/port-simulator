//
// Created by marcin on 27.04.19.
//

#ifndef PORTSO_DOCK_H
#define PORTSO_DOCK_H

#include <mutex>
#include <vector>
#include "Cargo.h"

class Dock {
private:
    int id;
    int currentLoad;
    int capacity;
public:
    Dock(int id, int currentLoad, int capacity, std::vector<Cargo*> cargoList, bool isBusy);

    ~Dock();

};


#endif //PORTSO_DOCK_H