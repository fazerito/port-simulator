//
// Created by marcin on 27.04.19.
//

#ifndef PORTSO_CARGO_H
#define PORTSO_CARGO_H


#include <string>

class Cargo {
private:
    std::string name;
    int weight;

public:
    Cargo();
    Cargo(std::string name, int weight);
    ~Cargo();

    std::string getName();
    int getWeight();

    void setName(std::string name);
    void setWeight(int weight);
};


#endif //PORTSO_CARGO_H
