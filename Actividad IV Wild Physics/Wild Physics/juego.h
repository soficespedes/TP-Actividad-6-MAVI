#pragma once
#include "lib.h"
#include "crosshair.h"

#ifndef JUEGO_H
#define JUEGO_H

class Juego {
public:
    Juego(RenderWindow* App);
    void cargarAssets(); 
    void run (); 

private:
    RenderWindow* App;

    Font font;
    Text scoreText; 
    int score = 0;  

    Crosshair crosshair;  

};

#endif
