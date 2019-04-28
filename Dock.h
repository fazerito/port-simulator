//
// Created by marcin on 27.04.19.
//

#ifndef PORTSO_DOCK_H
#define PORTSO_DOCK_H

#include <mutex>
#include <vector>
#include "Cargo.h"
#include "Ship.h"

class Dock {
private:
    int id;
    int currentLoad;
    int capacity;
    std::vector<Cargo> cargoList;
    bool isBusy;
public:
    Dock(int id, int currentLoad, int capacity, std::vector<Cargo> cargoList, bool isBusy);

    ~Dock();
    std::mutex dockMutex;
    void loadToShip(Cargo cargo);
    void unloadFromShip(Cargo cargo);

    int getId();
    int getCurrentLoad();
    int getCapacity();
    std::vector<Cargo> getCargoList();
    bool getIsBusy();

    void setCurrentLoad(int currentLoad);
    void setCapacity(int capacity);
    void setCargoList(std::vector<Cargo> cargoList);
    void setIsBusy(bool isBusy);
};


#endif //PORTSO_DOCK_H
