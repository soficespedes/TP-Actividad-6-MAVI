#pragma once
#include "lib.h"

#ifndef CROSSHAIR_H
#define CROSSHAIR_H

class Crosshair {
public:
    Crosshair();
    void cargarAssets(); //para cargar la textura
    void update(Vector2f mousePosition); //para actualizar posición
    void draw(RenderWindow& App); //para dibujarlo en pantalla

private:
    Texture crosshairTex; //textura
    Sprite crosshairSprite; //sprite

};

#endif
