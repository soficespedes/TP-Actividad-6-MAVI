#include"lib.h"
#pragma once
#include "crosshair.h"

Crosshair::Crosshair() {} //cantidad de vidas

void Crosshair::cargarAssets() {
    //cargamos la textura del crosshair, ajustamos el tamaño
    crosshairTex.loadFromFile("../Recursos/crosshair.png");
    crosshairSprite.setTexture(crosshairTex);
    crosshairSprite.setScale(0.3f, 0.3f);
}

void Crosshair::update(Vector2f mousePosition) {
    //ajustamos la posición para centrar el crosshair en el puntero
    FloatRect bounds = crosshairSprite.getLocalBounds();
    crosshairSprite.setPosition(
        mousePosition.x - bounds.width * crosshairSprite.getScale().x / 2.0f,
        mousePosition.y - bounds.height * crosshairSprite.getScale().y / 2.0f
    );
}

//dibujamos el sprite en ventana
void Crosshair::draw(RenderWindow& App) {
    App.draw(crosshairSprite);
}
