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
	int vidas; //Variable para almacenar las vidas.
	bool gameOver; //Variable booleana para saber cuando termina el juego.

	Font fuente; //Variable Font para la fuente.
	Text textoPuntaje; //Variable Text para el texto.
	Text textoVidas; //Variable Text para las vidas.
	Text textoGameOver; //Variable Text para fin de juego.
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

	//M�todo para la configuraci�n de los textos.
	void ConfigTextos();

	//M�todo para actualizar el puntaje.
	void ActualizarPuntaje();

	//M�todo para actualizar las vidas.
	void ActualizarVidas();

	//M�todo para la condici�n de Game Over.
	void GameOver();
};