//
// Created by marcin on 27.04.19.
//

#include "Cargo.h"

Cargo::Cargo(std::string name, int weight) {
    this->name = name;
    this->weight = weight;
}

Cargo::~Cargo() {

}

std::string Cargo::getName() {
    return name;
}

int Cargo::getWeight() {
    return weight;
}

void Cargo::setName(std::string name) {
    this->name = name;
}

void Cargo::setWeight(int weight) {
    this->weight = weight;
}
