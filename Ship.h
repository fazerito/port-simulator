//
// Created by marcin on 27.04.19.
//

#ifndef PORTSO_SHIP_H
#define PORTSO_SHIP_H


#include <thread>
#include "Dock.h"
#include "Cargo.h"

class Ship {
private:
    int id;
    std::string name;
    Cargo cargo;
    int capacity;
    std::thread shipThread;



public:
    Ship(int id, std::string name, Cargo cargo, int capacity);
    ~Ship();

    Cargo getCargo();
    int getId();
    std::string getName();
    int getCapacity();

    void setCargo(Cargo cargo);
    void setName(std::string name);
    void setCapacity(int capacity);

    void checkCapacity(Cargo cargo);
    Cargo unloadCargo();
    void move();
    void loadCargo(Cargo cargo);
    void startThread();
};


#endif //PORTSO_SHIP_H
