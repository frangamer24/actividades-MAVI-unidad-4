#include <SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(800, 600), ("tamaño de la ventana"));

	while (window.isOpen()) 
	{
		Event evento;
		while(window.pollEvent(evento))
		{
			if (evento.type == Event::Closed)
				window.close();
			if(evento.type==Event::Resized)
			{
				unsigned int nuevowindt = evento.size.width;
				unsigned int nuevoheight = evento.size.height;

				if (nuevowindt < 100) nuevowindt = 100;
				else if (nuevowindt > 1000) nuevowindt = 1000;

				if (nuevoheight < 100)nuevoheight = 100;
				else if (nuevoheight > 1000)nuevoheight = 1000;

				window.setSize(Vector2u(nuevowindt, nuevoheight));

				View view = window.getView();
				view.setSize(nuevowindt, nuevoheight);
				window.setView(view);
			}
		}
	}
	
	window.clear(Color::Black);
	window.display();

	return 0;
}
