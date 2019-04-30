#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <ctime>
#include <algorithm>
#include "Ship.h"
#include "Dock.h"
#include "Cargo.h"

Dock *dock;
//int maxCap = 600;
//int currentCap = 0;
//std::mutex dock;
/*
void unloadCargo(int id, int cargo)
{
    dock.lock();
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std:: cout << id << " tries to unload its cargo " << cargo << std::endl;
    if (currentCap + cargo <= maxCap) {
        currentCap += cargo;
        std::cout << "Current load is " << currentCap << std::endl;
    }
    else
    {
        std::cout << "Not enough space to unload cargo. " << std::endl;
        std::cout << "Current load is " << currentCap << std::endl;
    }
    dock.unlock();
}*/

void unloadCargo(Ship *ship, Dock *dock2) {
    std::lock_guard<std::mutex> lockGuard(dock2->dockMutex);
    if (ship->getCargo()->getWeight() + dock2->getCurrentLoad() <= dock2->getCapacity()) {
        dock2->setCurrentLoad(dock2->getCurrentLoad() + ship->getCargo()->getWeight());
        dock2->getCargoList().push_back(ship->getCargo());
        std::cout << "Rozladowano statek: " << ship->getId() << " towar: " << ship->getCargo()->getName() << std::endl;
    }
    else
        std::cout << "Brak miejsca.\n";
}

int main() {
    std::vector<Cargo*> cargoList;
    dock = new Dock(1, 0, 1000, cargoList, false);
    Cargo *cargo1 = new Cargo("Banany", 10);

    std::vector<Ship*> ships;
    Ship *ship1 = new Ship(1, "Ricardo", cargo1, 100);
    Ship *ship2 = new Ship(2, "Milos", cargo1, 100);
    Ship *ship3 = new Ship(3, "Billy", cargo1, 100);
    Ship *ship4 = new Ship(4, "Herrington", cargo1, 100);
    ships.push_back(ship1);
    ships.push_back(ship2);
    ships.push_back(ship3);
    ships.push_back(ship4);

    for (int i = 0; i < 4; ++i) {
        ships[i]->shipThread = std::thread(unloadCargo, std::ref(ships[i]), std::ref(dock));
    }
    for (int i = 0; i < 4; ++i) {
        ships[i]->shipThread.join();
    }
    return 0;
}