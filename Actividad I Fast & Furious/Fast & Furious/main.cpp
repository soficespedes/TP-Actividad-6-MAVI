#include <SFML/Window.hpp>
#include<SFML/Graphics.hpp>
using namespace sf; 

int main() {

	RenderWindow App(VideoMode(800, 600), "Fast & Furious");

	Vector2f position(50.0f, 270.0f);
	float speed = 3.0f;
	const float speedIncrement = 1.0f;

	while (App.isOpen()) {

		Event event; 
		while (App.pollEvent(event)) {
			if (event.type == Event::Closed)
				App.close();
		}

		float deltaTime = 1.0f / 60.0f;
		position.x += speed * deltaTime;

		if (position.x >= 800.0f) {
			position.x = -60.0f;
			speed += speedIncrement;
		}
		if (speed == 50.0f) {
			App.close();
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