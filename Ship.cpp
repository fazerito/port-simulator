//
// Created by marcin on 27.04.19.
//

#include <iostream>
#include "Ship.h"

Ship::Ship(int id, const std::string &name, Cargo *cargo, int capacity) : id(id), name(name), cargo(cargo),
                                                                          capacity(capacity) {}


Ship::~Ship() {
    if (shipThread.joinable())
        shipThread.detach();
}

void Ship::move() {
    std::cout << "Swimming ship no: " << id;
}

Cargo* Ship::getCargo() {
    return cargo;
}

int Ship::getId() {
    return id;
}

std::string Ship::getName() {
    return name;
}

int Ship::getCapacity() {
    return capacity;
}

void Ship::setCargo(Cargo *cargo) {
    this->cargo = cargo;
}

void Ship::setName(std::string name) {
    this->name = name;
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

void Ship::unloadCargo(Dock &dock) {
    std::lock_guard<std::mutex> lockGuard(dock.dockMutex);
    if (this->cargo->getWeight() + dock.getCurrentLoad() <= dock.getCapacity()) {
        dock.setCurrentLoad(dock.getCurrentLoad() + this->cargo->getWeight());
        dock.getCargoList().push_back(this->cargo);
        std::cout << "Rozladowano statek: " << id << " towar: " << cargo->getName() << std::endl;
    }
    else
        std::cout << "Brak miejsca.\n";
}

void Ship::loadCargo(Cargo cargo) {
    checkCapacity(cargo);
}

void Ship::startThread() {

}