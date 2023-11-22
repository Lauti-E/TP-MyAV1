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

	//M�todo para guardar todas las funciones.
	void General();

	//M�todo para manejar los eventos.
	void ProcesarEventos();

	//M�todo para dibujar en la ventana.
	void Dibujar();
};