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

	//Objetos para llamar a los métodos de los enemigos y el inocente.
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

	//Método para la configuración de los textos.
	void ConfigTextos();

	//Método para actualizar el puntaje.
	void ActualizarPuntaje();

	//Método para actualizar las vidas.
	void ActualizarVidas();

	//Método para la condición de Game Over.
	void GameOver();
};