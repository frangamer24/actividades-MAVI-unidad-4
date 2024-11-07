#include <SFML/window.hpp>
#include <SFML/graphics.hpp>
using namespace sf;

Texture circulo;
Texture textura;
Sprite sprite;
Sprite circulorojo;
Sprite circulorojo1;
Sprite circulorojo2;
Sprite circulorojo3;

bool arrastrando= false;
Sprite* sirculoseleccionado= nullptr;
Vector2f offset;

int main()
{
	circulo.loadFromFile("C:/SFML/imagenes/rcircle.png");

	circulorojo.setTexture(circulo);
	circulorojo1.setTexture(circulo);
	circulorojo2.setTexture(circulo);
	circulorojo3.setTexture(circulo);

	circulorojo.setPosition(0, 0);
	circulorojo1.setPosition(0, 400);
	circulorojo2.setPosition(400, 0);
	circulorojo3.setPosition(400, 400);

	sf::RenderWindow App(sf::VideoMode(800, 600, 32), " arrastrar circulos rojos");

	while (App.isOpen())
	{
		Event evento;
		while (App.pollEvent(evento))
		{
			if (evento.type == Event::Closed)
				App.close();

			if (evento.type == Event::MouseButtonPressed && evento.mouseButton.button == Mouse::Left)
			{
				Vector2f mousepos = App.mapPixelToCoords(Mouse::getPosition(App));

				if (circulorojo.getGlobalBounds().contains(mousepos))
				{
					arrastrando = true;
					sirculoseleccionado = &circulorojo;
					offset = circulorojo.getPosition() - mousepos;

				}
				else if (circulorojo1.getGlobalBounds().contains(mousepos))
				{
					arrastrando = true;
					sirculoseleccionado = &circulorojo1;
					offset = circulorojo1.getPosition() - mousepos;
				}
				else if (circulorojo2.getGlobalBounds().contains(mousepos))
				{
					arrastrando = true;
					sirculoseleccionado = &circulorojo2;
					offset = circulorojo2.getPosition() - mousepos;
				}
				else if (circulorojo3.getGlobalBounds().contains(mousepos))
				{
					arrastrando = true;
					sirculoseleccionado = &circulorojo3;
					offset = circulorojo3.getPosition() - mousepos;
				}
			}

			if (evento.type == Event::MouseButtonReleased && evento.mouseButton.button == Mouse::Left) {
				arrastrando = false;
				sirculoseleccionado = nullptr;

			}
		}

		if (arrastrando && sirculoseleccionado) {
			Vector2f mousePos = App.mapPixelToCoords(Mouse::getPosition(App));
			sirculoseleccionado->setPosition(mousePos + offset);
		}

		App.clear();

		App.draw(circulorojo);
		App.draw(circulorojo1);
		App.draw(circulorojo2);
		App.draw(circulorojo3);

		App.display();
	}
	return 0;
}