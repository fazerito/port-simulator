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
    std::vector<Ship> ships;
    ships.emplace_back(1, "Ricardo", cargoList, 200);
    ships.emplace_back(2, "Ricardo", cargoList, 200);
    ships.emplace_back(3, "Ricardo", cargoList, 200);
    ships.emplace_back(4, "Ricardo", cargoList, 200);

    ships[0].shipThread.join();
    //std::thread ships[10];
    for (int i = 0; i < 10; ++i) {
        ships[i].shipThread = std::thread(&Ship::unloadCargo, &ships[i], &dock);
    }
    for (int i = 0; i < 10; ++i) {
        ships[i].shipThread.join();
    }

    return 0;
}