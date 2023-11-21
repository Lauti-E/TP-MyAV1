#include <SFML/Graphics.hpp>

int main(int argc, const char* argv[]) {

	using namespace sf;

	//Crear la ventana SFML.
	RenderWindow window(VideoMode(800, 600), "Trabajo práctico integrador.");

	//Bucle principal.
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}

		window.clear(); //Limpia la ventana.

		window.display(); //Muestra el contenido en la ventana.
	}
	return 0;
}