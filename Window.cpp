//
// Created by marcin on 31.05.19.
//

#include <iostream>
#include "Window.h"

Window::Window(int height, int width) {
    this->height = height;
    this->width = width;
    this->symbol = 'o';
    createCargoVectors();
    initscr();      //inicjuje ncurses
    curs_set(FALSE);    //nie wyswietla kursora
    noecho();       //nie wyswietla inputu
    nodelay(stdscr,TRUE);      //nie czeka na getchar
    this->window = newwin(height, width, 0, 0);    //inicjalizuje okno

    refresh();
    box(window, 0,0);   //inicjalizuje ramke dookoła okna
    wrefresh(window);
}

Window::~Window() {
    endwin();
}

void Window::createCargoVectors() {
    Cargo cargo("cargo", 0);
    cargoVec.push_back(cargo);

    /*for(int i = 100; i < 1000; i += 100){
        cargo.setWeight(i);
        for(int j = 0; j < 55; j++){
            cargoVec.push_back(cargo);
        }
    }*/
}

void Window::startWindow() {
    baseDraw();
    drawDock();
    std::vector<std::thread> threadVect;
    int i = 0;
    queueCondition.push_back(new std::condition_variable);
    do{
        std::condition_variable condVar;
        shipVector.push_back(new Ship(144));
        queueCondition.push_back(new std::condition_variable);
        threadsOnCheck.push_back(true);
        threadVect.push_back(std::thread([&](){useShipWithThreads(i);}));
        sleep(5);
        for(long unsigned int j = 0; j < threadsOnCheck.size(); j++){
            if(!threadsOnCheck[j])
                if(threadVect[j].joinable())
                    threadVect[j].join();
        }
        symbol = getch();
        i++;
        mvwprintw(window,11,144,"%i ", (i % 15) + 1);
        wrefresh(window);
        if((i % 15) == 0){
            supplyDelivery();
            drawDock();
        }

    }while(symbol != 'q');

    for(auto& t : threadVect){
        if(t.joinable())
            t.join();
    }
}

void Window::baseDraw() {
    drawMutex.lock();
    //pionowe ściany półek
    for(int j = 3; j < 144; j = j + 14){
        for(int i = 3; i < 8; i++)
            mvwprintw(window, i, j, "|");
    }

    //pozioma sciana
    for(int i = 3; i < 144; i++)
        mvwprintw(window, 8, i, "-");

    //dok
    for (int k = 9; k < 15 ; ++k) {
        mvwprintw(window, k, 25, "|");
    }
    for (int k = 9; k < 15 ; ++k) {
        mvwprintw(window, k, 55, "|");
    }
    for(int i = 26; i < 55; i++){

        mvwprintw(window, 11, i, "-");
        mvwprintw(window, 14, i, "_");
    }

    mvwprintw(window, 15, 30, "\\");
    mvwprintw(window, 15, 50, "/");
    for (int l = 31; l < 49; ++l) {
        mvwprintw(window, 15, l, "=");
    }


    drawMutex.unlock();
    wrefresh(window);

}

void Window::drawShip(int shipId) {
    int x = shipVector[shipId]->getPositionX();
    drawMutex.lock();
    //          ___/|\___
    //          \___|___/
    mvwprintw(window, 16, x, "|");
    mvwprintw(window, 17, x, "|");
    mvwprintw(window, 16, x - 1, "/");
    mvwprintw(window, 16, x + 1, "\\");
    mvwprintw(window, 16, x + 2, "___");
    mvwprintw(window, 16, x - 4, "___");
    mvwprintw(window, 17, x + 4, "/");
    mvwprintw(window, 17, x - 4, "\\");
    mvwprintw(window, 17, x + 1, "__");
    mvwprintw(window, 17, x - 3, "__");


    drawMutex.unlock();
    wrefresh(window);
}

void Window::eraseShip(int shipId) {
    int x = shipVector[shipId]->getPositionX();
    drawMutex.lock();
    mvwprintw(window, 16, x, " ");
    mvwprintw(window, 17, x, " ");
    mvwprintw(window, 16, x - 1, " ");
    mvwprintw(window, 16, x + 1, "   ");
    mvwprintw(window, 16, x + 2, "   ");
    mvwprintw(window, 16, x - 4, " ");
    mvwprintw(window, 17, x + 4, " ");
    mvwprintw(window, 17, x - 4, " ");
    mvwprintw(window, 17, x + 1, " ");
    mvwprintw(window, 17, x - 3, " ");
    drawMutex.unlock();
    wrefresh(window);
}

void Window::drawDock() {
    drawMutex.lock();
    for(int i = 0, j = 5; i < 10; i++, j = j + 14){
        clearCargo(j);
        drawCargo(j,cargoVec);
    }
    drawMutex.unlock();
}

void Window::drawCargo(int startingPointX, std::vector<Cargo> cargos) {
    if (cargos.size() > 0) {
        drawSomeCargo(startingPointX, 7, '#', 0);
    }
}

void Window::drawSomeCargo(int startX, int startY, char cargo, int cargoNum) {
    int lastRow = cargoNum - 11;
    drawRow(startX, startY, cargo, 11);
    drawRow(startX, startY - 1, cargo, lastRow);
    wrefresh(window);
}

void Window::drawRow(int startX, int startY, char cargoChar, int cargoNum) {
    const char *cargo = new char(cargoChar);
        mvwprintw(window, startY, startX, cargo);
}

void Window::clearCargo(int startingPointX) {
    for(int i = startingPointX; i < startingPointX + 12; i++){
        for(int j = 7; j >= 3; j--){
            mvwprintw(window, j, i, " ");
        }
    }
    wrefresh(window);
}

void Window::deliveryThread() {

}


void Window::eraseDelivery(int x) {

}

void Window::supplyDelivery() {

}

void Window::useShipWithThreads(int threadId) {
    while(threadsOnCheck[threadId]){

        if(symbol == 'q'){
            for(long unsigned int i = 0; i < queueCondition.size(); i++)
                queueCondition[i]->notify_one();
            break;
        }

        std::unique_lock<std::mutex> lock(shipVectMutex);
        if(shipVector[threadId]->getPositionX() >= 3){
            if(shipVector[threadId]->getPositionX() == 40){
                if(canDoUnload(threadId)){
                    unload(threadId);
                    drawDock();
                    baseDraw();
                    lock.unlock();
                    std::this_thread::sleep_for (std::chrono::milliseconds(shipVector[threadId]->getDockingTime()));
                    eraseShip(threadId);
                    shipVector[threadId]->setPositionX(shipVector[threadId]->getPositionX() - 1);
                    drawShip(threadId);
                }

            }else{
                if(canShipSwim(threadId)){
                    eraseShip(threadId);
                    shipVector[threadId]->setPositionX(shipVector[threadId]->getPositionX() - 1);
                    drawShip(threadId);
                    queueCondition[threadId + 1]->notify_one();
                    lock.unlock();
                }
                else{
                    queueCondition[threadId]->wait(lock);
                }
            }
            std::this_thread::sleep_for (std::chrono::milliseconds(shipVector[threadId]->getSwimmingSpeed()));
        }else{
            eraseShip(threadId);
            shipVector[threadId]->setPositionX(0);
            threadsOnCheck[threadId] = false;
        }
    }
}

bool Window::canDoUnload(int shipId) {
    cargoMutex.lock();
    if(shipVector[shipId]->getCargo()->getWeight() + cargoVec.size() > 15000){
        cargoMutex.unlock();
        return false;
    }
    cargoMutex.unlock();
    return true;
}

void Window::unload(int shipId) {
    cargoMutex.lock();
        cargoVec.push_back(*shipVector[shipId]->getCargo());
    cargoMutex.unlock();
}

bool Window::canShipSwim(int shipId) {
    if(shipId > 0){
        if(shipVector[shipId - 1]->getPositionX() > 3){
            if(shipVector[shipId]->getPositionX() >= shipVector[shipId - 1]->getPositionX() + 10){
                return true;
            }else{
                return false;
            }
        }else{
            return true;
        }
    }else{
        return true;
    }}
