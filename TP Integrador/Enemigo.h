#pragma once
#include <iostream>
#include <cstdlib>

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Enemigo {
private:
	Texture texEnemigo1;
	Sprite sprEnemigo1;

	//Variables para definir el tiempo de las apariciones de los enemigos.
	Clock temp;
	float tiempo;
public:
	//Constructor.
	Enemigo();

	//M�todo para inicializar las texturas.
	void InicializarTexturas();

	//M�todo para dibujar los enemigos en la ventana.
	void DibujarEnemigos(RenderWindow& ven);

	//M�todo para establecer la posici�n inicial aleatoria.
	void PosicionInicial();

	//M�todo para verificar si el enemigo fue clickeado.
	bool EnemigoClick(float x, float y) const;

	//M�todo para eliminar el enemigo.
	void EliminarEnemigo();

	//M�todo para manejar la l�gica de aparic�n del enemigo.
	void Actualizar();
};

