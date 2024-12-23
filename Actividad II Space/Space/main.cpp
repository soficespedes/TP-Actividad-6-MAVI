#include <SFML/Window.hpp>
#include<SFML/Graphics.hpp>
using namespace sf;

int main() {

	RenderWindow App(VideoMode(800, 600), "Fast & Furious");

	Vector2f position(50.0f, 270.0f); //posición inicial del circulo
	float speed = 1.0f; //velocidad inicial
	const float acceleration = 1.0f; //incremento de la velocidad
	const float deceleration = 1.0f; //reducción de velocidad
	bool movingLeft = false; //indica si el objeto se mueve hacia la izquierda

	while (App.isOpen()) {
		//cargamos los eventos
		Event event;
		while (App.pollEvent(event)) {
			if (event.type == Event::Closed)
				App.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			//si presionamos la flecha derecha, aumentamos velocidad hacia la derecha
			if (speed < 0.0f) {
				//si se está moviendo hacia la izquierda, desaceleramos primero
				speed += deceleration * (1.0f / 60.0f);
				if (speed > 0.0f) speed = 0.0f; //detenemos primero antes de cambiar de dirección
			}
			else {
				speed += acceleration * (1.0f / 60.0f); //aumentamos la velocidad
			}
			movingLeft = false;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Left)) {
			//si presionamos la felcha izquierda y se esta moviendo hacia la derecha, reducimos la velocidad gradualmente
			if (speed > 0.0f) {
				speed -= deceleration * (1.0f / 60.0f);
				if (speed < 0.0f) speed = 0.0f; //detenemos antes de cambiar dirección
			}
			else {
				//incrementamos la velocidad hacia la izquierda 
				speed -= acceleration * (1.0f / 60.0f);
				movingLeft = true;
			}
		}
		float deltaTime = 1.0f / 60.0f;
		position.x += speed * deltaTime;

		if (position.x >= 800.0f) { //si el circulo sobrepasa el margen derecho de la ventana
			position.x = -60.0f; // reiniciamos su posicion por fuera del limite izquierdo para darle mas "dinamismo"
			
		}
		else if (position.x < -60.0f) { //sino, si el circulo sobrepasa el margen izquierdo de la ventana
			position.x = 800.0f; //reiniciamos al lado derecho
		}
		
		App.clear();

		CircleShape circle(30.0f);
		circle.setPosition(position);
		circle.setFillColor(Color::Green);
		App.draw(circle);

		App.display();
	}


	return 0;
}