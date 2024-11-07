#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;
using namespace sf;

int main() 
{
	Texture texturaRojo, texturaAzul;

	texturaRojo.loadFromFile("C:/SFML/imagenes/rcircle.png");
	texturaAzul.loadFromFile("C:/SFML/imagenes/rcircleb.png");

	vector<Sprite> sirculos;

	RenderWindow window(VideoMode(800, 600), "los sirculos en la pantalla");

	while (window.isOpen()) 
	{
		Event evento;

		while (window.pollEvent(evento))
		{
			if (evento.type == Event::Closed)
				window.close();

			if (evento.type == Event::MouseButtonPressed)
			{
				Sprite nuevosirculo;
				Vector2f mousepos = window.mapPixelToCoords(Mouse::getPosition(window));
				
				if (evento.mouseButton.button == Mouse::Left)
				{
					nuevosirculo.setTexture(texturaRojo);
				}
				else if (evento.mouseButton.button == Mouse::Right)
				{
					nuevosirculo.setTexture(texturaAzul);
				}

				float offsettX = nuevosirculo.getLocalBounds().width / 2.0f;
				float offsettY = nuevosirculo.getLocalBounds().height / 2.0f;
				nuevosirculo.setPosition(mousepos.x - offsettX, mousepos.y - offsettY);

				sirculos.push_back(nuevosirculo);
			}
		}
		window.clear();

		for(const auto& sirculo:sirculos)
		{
			window.draw(sirculo);
		}
		window.display();

	}

	return 0;
}