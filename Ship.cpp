//
// Created by marcin on 27.04.19.
//

#include <iostream>
#include "Ship.h"



Ship::~Ship() {
    if (shipThread.joinable())
        shipThread.detach();
}

void Ship::move() {
    std::cout << "Swimming ship no: " << id;
}

Ship::Ship(int id, std::string name, int capacity) : cargo() {

}

Cargo Ship::getCargo() {
    return Cargo(__cxx11::basic_string(), 0);
}

int Ship::getId() {
    return id;
}

std::string Ship::getName() {
    return std::__cxx11::string();
}

int Ship::getCapacity() {
    return 0;
}

void Ship::setCargo(Cargo cargo) {

}

void Ship::setName(std::string name) {

}

void Ship::setCapacity(int capacity) {

}

void Ship::checkCapacity(Cargo cargo) {

}

Cargo Ship::unloadCargo() {
    return Cargo(__cxx11::basic_string(), 0);
}

void Ship::loadCargo(Cargo cargo) {

}

void Ship::startThread() {

}




