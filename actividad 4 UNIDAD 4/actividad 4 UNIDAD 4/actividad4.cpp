#include <SFML/Window.hpp>
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main()
{

	Texture cuadrado, circulo;
	cuadrado.loadFromFile("C:/SFML/imagenes/cuad_yellow.png");
	circulo.loadFromFile("C:/SFML/imagenes/rcircle.png");

	RenderWindow window (VideoMode(800, 600), "moverse y cambiar");

	Sprite sprite;
	sprite.setTexture(cuadrado);
	sprite.setScale(0.5f, 0.5f);
	sprite.setPosition(400, 300);

	bool usandocuadrado = true;
	float velocidad = 5.0f;

	while(window.isOpen())
	{
		Event evento;

		while (window.pollEvent(evento)) 
		{
			if (evento.type == Event::Closed)
				window.close();

			if (evento.type == Event::KeyPressed && evento.key.code == Keyboard::Space) 
			{
				usandocuadrado = !usandocuadrado;
				sprite.setTexture(usandocuadrado ? cuadrado : circulo);

			}

		}
		if (Keyboard::isKeyPressed(Keyboard::Left) && sprite.getPosition().x > 0)
			sprite.move(-velocidad, 0);
		if (Keyboard::isKeyPressed(Keyboard::Right) && sprite.getPosition().x + sprite.getGlobalBounds().width < window.getSize().x)
			sprite.move(velocidad, 0);
		if (Keyboard::isKeyPressed(Keyboard::Up) && sprite.getPosition().y > 0)
			sprite.move(0,-velocidad);
		if (Keyboard::isKeyPressed(Keyboard::Down) && sprite.getPosition().y + sprite.getGlobalBounds().height < window.getSize().y)
			sprite.move(0,velocidad);



		window.clear();
		window.draw(sprite);
		window.display();
	}

	return 0;
}