#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <ctime>
#include "Ship.h"

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

    /*std::thread ships[10];
    for (int i = 0; i < 10; ++i) {
        ships[i] = std::thread(unloadCargo, i, 100);
    }
    for (int i = 0; i < 10; ++i) {
        ships[i].join();
    }
*/

    return 0;
}