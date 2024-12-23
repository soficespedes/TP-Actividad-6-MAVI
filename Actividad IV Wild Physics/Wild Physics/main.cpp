#include "lib.h"

#include "juego.h"
int main() {
    //creamos la ventana principal
    RenderWindow App(VideoMode(800, 600), "Bounce");

    //llamamos a los métodos de la clase juego configurada anteriormente
    Juego juego(&App);
    juego.cargarAssets();
    juego.run();
    return 0;
}
