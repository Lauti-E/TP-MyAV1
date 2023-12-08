#pragma once
#include <SFML/Graphics.hpp>

#include "Crosshair.h"
#include "Enemigo.h"
#include "Enemigo2.h"
#include "Inocente.h"

using namespace sf;

class Juego {
private:
	RenderWindow ventana; //Ventana.
	Texture texFondo; //Textura del fondo.
	Sprite sprFondo; //Sprite del fondo.

	//Objeto para el crosshair.
	Crosshair crosshair;

	//Objetos para llamar a los m�todos de los enemigos y el inocente.
	Enemigo enemigo;
	Enemigo2 enemigo2;
	Inocente inocente;

	Clock temp; //Variable Clock para reiniciar el temporizador.

	int puntaje; //Variable para almacenar el puntaje.
	Font fuente; //Variable Font para la fuente.
	Text textoPuntaje; //Variable Text para el texto.
public:
	//Constructor.
	Juego();

	//M�todo para guardar todas las funciones.
	void General();

	//M�todo para manejar los eventos.
	void ProcesarEventos();

	//M�todo para dibujar en la ventana.
	void Dibujar();

	//M�todos para detectar la colisi�n de los sprites.
	bool ColisionEnemigos(const Enemigo& e1, const Enemigo2& e2) const;

	bool ColisionInocenteEnemigo(const Inocente& in, const Enemigo& e1) const;

	bool ColisionInocenteEnemigo2(const Inocente& in, const Enemigo2& e2) const;
};