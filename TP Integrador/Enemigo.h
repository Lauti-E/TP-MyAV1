#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

#include <SFML/Graphics.hpp>

#include "Enemigo2.h"

using namespace sf;
using namespace std;

class Enemigo {
private:
	Texture texEnemigo;
	Sprite sprEnemigo;

	Clock temp;
public:
	//Constructor.
	Enemigo();

	//Método para inicializar las texturas.
	void InicializarTexturas();

	//Método para dibujar los enemigos en la ventana.
	void DibujarEnemigos(RenderWindow& ven);

	//Método para establecer la posición inicial aleatoria.
	void PosicionInicial();

	//Método para verificar si el enemigo fue clickeado.
	bool EnemigoClick(float x, float y) const;

	//Método para eliminar el enemigo.
	void EliminarEnemigo();

	void ReiniciarReloj() { temp.restart(); }

	const Sprite& GetSprite() const { return sprEnemigo; }
};

