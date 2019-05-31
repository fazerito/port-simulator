//
// Created by marcin on 31.05.19.
//
#include <ncurses.h>
#include <vector>
#include <mutex>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <condition_variable>
#include "Ship.h"

#ifndef PORTSO_WINDOW_H
#define PORTSO_WINDOW_H


class Window {
private:
    WINDOW *window;
    int width;
    int height;
    char symbol;
    std::vector<Cargo> cargoVec;
    std::vector<bool> threadsOnCheck;
    std::vector<Ship *> shipVector;
    std::mutex shipVectMutex;
    std::mutex drawMutex;
    std::mutex cargoMutex;
    std::vector<std::condition_variable *> queueCondition;

public:
    Window(int height, int width);
    ~Window();
    void createCargoVectors();
    void startWindow();
    void baseDraw();
    void drawShip(int customerId);
    void eraseShip(int customerId);
    void drawDock();
    void drawCargo(int startingPointX, std::vector<Cargo> cargos);
    void drawSomeCargo(int startX, int startY, char vegetable, int vegeNumber);
    void drawRow(int startX, int startY, char vegetableChar, int vegeNumber);
    void clearCargo(int startingPointX);
    void deliveryThread();
    void drawDelivery(int x);
    void eraseDelivery(int x);
    void supplyDelivery();
    void useShipWithThreads(int threadId);
    bool canDoUnload(int customerId);
    void unload(int customerId);
    bool canShipSwim(int customerId);
};


#endif //PORTSO_WINDOW_H
