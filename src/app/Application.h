//
// Created by Clemens on 19/01/2023.
//

#ifndef ULTIMATE_CITY_GENERATOR_APPLICATION_H
#define ULTIMATE_CITY_GENERATOR_APPLICATION_H

#include "graphics/Window.h"
#include "imgui.h"


class Application{
public:
    Window window;

public:
    void setup();
    void update();
    void render();
    void end();
};

#endif //ULTIMATE_CITY_GENERATOR_APPLICATION_H
