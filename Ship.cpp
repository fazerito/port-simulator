//
// Created by marcin on 27.04.19.
//

#include <iostream>
#include "Ship.h"

Ship::Ship(int x){
    srand(time(NULL));
    dockingTime = rand()%400 + 2400;
    swimmingSpeed = rand()%100 + 100;
    positionX = x;
    cargo = new Cargo("cargo", rand()%1000 + 100);
}




Cargo* Ship::getCargo() {
    return cargo;
}

int Ship::getId() {
    return id;
}


int Ship::getCapacity() {
    return capacity;
}

void Ship::setCargo(Cargo *cargo) {
    this->cargo = cargo;
}


void Ship::setCapacity(int capacity) {
    this->capacity = capacity;
}

void Ship::checkCapacity(Cargo cargo) {
    if (this->cargo->getWeight() + cargo.getWeight() <= capacity)
    {
        this->cargo->setWeight(this->cargo->getWeight() + cargo.getWeight());

        std::cout << "Zaladowano " << cargo.getName() << ", ilosc: " << cargo.getWeight() << "\n";
    } else
        std::cout << "Brak miejsca na statku\n";

}
int Ship::getPositionX() {
    return positionX;
}


int Ship::getDockingTime() {
    return dockingTime;
}

void Ship::setPositionX(int x) {
    this->positionX = x;
}

int Ship::getSwimmingSpeed() {
    return swimmingSpeed;
}
