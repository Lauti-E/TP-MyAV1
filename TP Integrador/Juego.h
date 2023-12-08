#pragma once
#include <SFML/Graphics.hpp>

#include "Crosshair.h"
#include "Enemigo.h"
#include "Enemigo2.h"
#include "Inocente.h"

using namespace sf;

class Juego {
private:
	RenderWindow ventana;
	Texture texFondo;
	Sprite sprFondo;

	Crosshair crosshair;

	Enemigo enemigo;
	Enemigo2 enemigo2;
	Inocente inocente;

	Clock temp;
public:
	//Constructor.
	Juego();

	//Método para guardar todas las funciones.
	void General();

	//Método para manejar los eventos.
	void ProcesarEventos();

	//Método para dibujar en la ventana.
	void Dibujar();

	//Métodos para detectar la colisión de los sprites.
	bool ColisionEnemigos(const Enemigo& e1, const Enemigo2& e2) const;

	bool ColisionInocenteEnemigo(const Inocente& in, const Enemigo& e1) const;

	bool ColisionInocenteEnemigo2(const Inocente& in, const Enemigo2& e2) const;
};