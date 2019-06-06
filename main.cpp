#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <ctime>
#include <algorithm>
#include "Ship.h"
#include "Dock.h"
#include "Cargo.h"
#include "Window.h"
#include <ncurses.h>

int main() {

    Window window(30,148);
    window.startWindow();

    return 0;
}