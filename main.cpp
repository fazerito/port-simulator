#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <ctime>
#include "Ship.h"
#include "Dock.h"

std::vector<Cargo> cargoList;
Dock *dock = new Dock(1, 0, 1000, cargoList, false);
/*int maxCap = 600;
int currentCap = 0;
std::mutex dock;

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

int main() {
    Cargo cargo1;
    std::vector<Ship*> ships;
    Ship *ship1 = new Ship(1, "Ricardo", cargo1, 100);
    Ship *ship2 = new Ship(2, "Milos", cargo1, 100);
    Ship *ship3 = new Ship(3, "Billy", cargo1, 100);
    Ship *ship4 = new Ship(4, "Herrington", cargo1, 100);
    ships.push_back(ship1);
    ships.push_back(ship2);
    ships.push_back(ship3);
    ships.push_back(ship4);

    //std::thread ships[10];
    for (int i = 0; i < 4; ++i) {
        ships[i]->shipThread = std::thread(&Ship::unloadCargo, dock);
    }
    for (int i = 0; i < 4; ++i) {
        ships[i]->shipThread.join();
    }

    return 0;
}