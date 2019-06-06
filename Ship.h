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
    Cargo *cargo;
    int capacity;

    int positionX;
    int dockingTime;
    int swimmingSpeed;


public:
    Ship(int x);


    ~Ship();

    Cargo* getCargo();
    int getId();

    int getCapacity();
    int getPositionX();
    int getDockingTime();
    int getSwimmingSpeed();
    void setCargo(Cargo *cargo);

    void setCapacity(int capacity);
    void setPositionX(int x);
    void checkCapacity(Cargo cargo);
};


#endif //PORTSO_SHIP_H