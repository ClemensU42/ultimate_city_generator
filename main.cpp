#include <iostream>
#include "app/Application.h"

int main() {
    Application app;
    app.setup();
    while(!app.window.shouldClose()){
        app.update();
        app.render();
    }
    app.end();
}
