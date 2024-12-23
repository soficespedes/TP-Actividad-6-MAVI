#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
using namespace sf;

int main() {
    RenderWindow App(VideoMode(800, 600), "Bounce");
    //definimos la posición y velocidad inicial del objeto
    Vector2f position(100.0f, 100.0f);
    Vector2f velocity(200.0f, 0.0f); //velocidad inicial en x e y
    //constante de aceleración para el eje y
    const float acceleration = 400.0f;

    //reloj para calcular deltaTime
    Clock clock;

    while (App.isOpen()) {
        //procesamos los eventos
        Event event;
        while (App.pollEvent(event)) {
            if (event.type == Event::Closed)
                App.close();
        }
        //calculamos deltaTime
        float deltaTime = clock.restart().asSeconds();

        //actualizamos la velocidad del objeto en el eje y
        velocity.y += acceleration * deltaTime;

        //actualizamos la posición del objeto en función de la velocidad
        position += velocity * deltaTime;

        //comprobamos los límites y rebotamos en el eje y
        if (position.y > 550.0f) { //rebote en el suelo
            position.y = 550.0f;
            velocity.y = -velocity.y;
        }
        else if (position.y < 0.0f) { //rebote en el techo
            position.y = 0.0f;
            velocity.y = +velocity.y;
        }

        //comprobamos los límites y rebotamos en el eje x
        if (position.x > 750.0f) { //rebote en el borde derecho
            position.x = 750.0f;
            velocity.x = -velocity.x;
        }
        else if (position.x < 0.0f) { //rebote en el borde izquierdo
            position.x = 0.0f;
            velocity.x = -velocity.x;
        }

        
        App.clear();

        //dibujamos el objeto
        CircleShape ball(30.0f);
        ball.setPosition(position);
        ball.setFillColor(Color::White);
        App.draw(ball);

        App.display();
    }

    return 0;
}