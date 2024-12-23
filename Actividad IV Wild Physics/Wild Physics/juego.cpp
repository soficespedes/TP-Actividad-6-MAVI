#include "juego.h"
#include "lib.h"

Juego::Juego(RenderWindow* App) : App(App) {}

void Juego::cargarAssets() { //cargamos todos los recursos que utilizaremos, 
    //en este caso, solo el sprite del crosshair definido en su propia clase y el texto del puntaje con sus especificaciones
    font.loadFromFile("../Recursos/Montserrat-SemiBold.ttf");

    scoreText.setFont(font);
    scoreText.setCharacterSize(20);
    scoreText.setFillColor(Color::White);
    scoreText.setPosition(350, 10);
    scoreText.setString("Puntaje: 0");

    crosshair.cargarAssets();
}
//bucle principal
void Juego::run() {
    Vector2f position(rand() % 700, rand() % 50);
    Vector2f velocity(200.0f, 0.0f);
    const float acceleration = 400.0f;  //gravedad

    Clock clock;
    App->setMouseCursorVisible(false);
    int score = 0;

    while (App->isOpen()) {
        Event event;
        while (App->pollEvent(event)) {
            if (event.type == Event::Closed) {
                App->close();
            }
        }

        float deltaTime = clock.restart().asSeconds();
        velocity.y += acceleration * deltaTime;  //la velocidad en el eje Y aumenta debido a la gravedad que generamos
        position += velocity * deltaTime; //la posición de la pelota se actualiza constantemente usando su velocidad 

        //rebote en el suelo (límite inferior)
        if (position.y > 550.0f) {
            position.y = 550.0f;
            velocity.y = -velocity.y * 0.7f; //al rebotar se reduce la velocidad
        }

        //límite superior: detiene la pelota sin invertir la dirección, esto nos permitirá que el desplazamiento sea fluido
        //y la pelota no quede "tildada" en el borde
        if (position.y < 0.0f) {
            position.y = 0.0f;
            velocity.y = 0.0f; //detiene la velocidad en Y y, por ende, vuelve a caer
        }

        //rebote en los bordes laterales
        if (position.x > 750.0f) {
            position.x = 750.0f;
            velocity.x = -velocity.x;
        }
        else if (position.x < 0.0f) {
            position.x = 0.0f;
            velocity.x = -velocity.x;
        }
        //evento que nos permite obtener puntos y que la pelota vuelva a aparecer en una posicion al azar cada vez que clickamos
        //con el clic izquierdo encima de ella
        if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
            Vector2f mousePosition = App->mapPixelToCoords(Mouse::getPosition(*App));

            if (mousePosition.x > position.x && mousePosition.x < position.x + 50 &&
                mousePosition.y > position.y && mousePosition.y < position.y + 50) {
                score++;
                position = Vector2f(rand() % 700, rand() % 50);
            }
        }
        //actualizamos el texto del puntaje
        scoreText.setString("Puntaje: " + to_string(score));

        Vector2f mousePosition = App->mapPixelToCoords(Mouse::getPosition(*App));
        crosshair.update(mousePosition); //actualizamos la posicion del puntero creado con respecto al puntero del mouse

        App->clear();
        //dibujamos todo
        CircleShape ball(30.0f);
        ball.setPosition(position);
        ball.setFillColor(Color::Green);
        App->draw(ball);
        App->draw(scoreText);
        crosshair.draw(*App);

        App->display();
    }
}
