#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Enemigo {
private:
	Texture texEnemigo1;
	Sprite sprEnemigo1;

public:
	//Constructor.
	Enemigo();

	//Método para inicializar las texturas.
	void InicializarTexturas();

	//Método para dibujar los enemigos en la ventana.
	void DibujarEnemigos(RenderWindow& ven);

	//Método para verificar si el enemigo fue clickeado.
	bool EnemigoClick(float x, float y) const;

	//Método para eliminar el enemigo.
	void EliminarEnemigo();
};

