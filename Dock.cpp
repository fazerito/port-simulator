#include <utility>

//
// Created by marcin on 27.04.19.
//

#include "Dock.h"

Dock::Dock(int id, const std::mutex &dockMutex, int currentLoad, int capacity, std::vector<Cargo> cargoList,
           bool isBusy, Ship &servedShip) : id(id), currentLoad(currentLoad), capacity(capacity),
                                            cargoList(std::move(cargoList)), isBusy(isBusy), servedShip(servedShip) {}

Dock::~Dock() {

}


void Dock::unloadFromShip(Cargo cargo) {

}

void Dock::dockShip() {

}

void Dock::undockShip() {

}

void Dock::loadToShip(Cargo cargo) {

}

int Dock::getId() {
    return id;
}

int Dock::getCurrentLoad() {
    return currentLoad;
}

int Dock::getCapacity() {
    return capacity;
}

std::vector<Cargo> Dock::getCargoList() {
    return cargoList;
}

bool Dock::getIsBusy() {
    return isBusy;
}

void Dock::setCurrentLoad(int currentLoad) {
    this->currentLoad = currentLoad;
}

void Dock::setCapacity(int capacity) {
    this->capacity = capacity;
}

void Dock::setCargoList(std::vector<Cargo> cargoList) {
    this->cargoList = cargoList;
}

void Dock::setIsBusy(bool isBusy) {
    this->isBusy = isBusy;
}


