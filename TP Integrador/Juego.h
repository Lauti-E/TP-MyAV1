#pragma once
#include <SFML/Graphics.hpp>

#include "Crosshair.h"
#include "Enemigo.h"

using namespace sf;

class Juego {
private:
	RenderWindow ventana;
	Texture texFondo;
	Sprite sprFondo;

	Crosshair crosshair;
	Enemigo enemigo;
public:
	//Constructor.
	Juego();

	//Método para guardar todas las funciones.
	void General();

	//Método para manejar los eventos.
	void ProcesarEventos();

	//Método para dibujar en la ventana.
	void Dibujar();
};