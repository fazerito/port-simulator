#include <utility>

//
// Created by marcin on 27.04.19.
//

#include "Dock.h"

Dock::Dock(int id, int currentLoad, int capacity, std::vector<Cargo*> cargoList,
           bool isBusy) : id(id), currentLoad(currentLoad), capacity(capacity)
                           {}

Dock::~Dock() {

}
