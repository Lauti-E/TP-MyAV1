#include <SFML/Graphics.hpp>
#include "Crosshair.h"

int main(int argc, const char* argv[]) {

	using namespace sf;

	//Objeto Crosshair.
	Crosshair crosshair;

	//Crear la ventana SFML.
	RenderWindow window(VideoMode(800, 600), "Trabajo práctico integrador.");

	//Cargar el fondo.
	Texture texFondo;
	texFondo.loadFromFile("Imagenes//Escenario.png");

	Sprite sprFondo(texFondo);

	//Ajustar el fondo con la ventana.
	sprFondo.setScale(800.f / texFondo.getSize().x, 600.f / texFondo.getSize().y);

	//Bucle principal.
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}

		window.clear(); //Limpia la ventana.

		window.draw(sprFondo); //Dibujar el fondo.

		window.display(); //Muestra el contenido en la ventana.
	}
	return 0;
}