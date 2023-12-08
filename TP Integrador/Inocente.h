#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Inocente {
private:
	Texture texInocente; //Textura para el inocente.
	Sprite sprInocente; //Sprite para el inocente.

	Clock temp; //Variable Clock para reiniciar el temporizador.
	Clock relojInocente; //Variable Clock para la desaparición del inocente cada x tiempo.
public:
	//Constructor.
	Inocente();

	//Método para inicializar las texturas.
	void InicializarTexturas();

	//Método para dibujar los inocentes en la ventana.
	void DibujarInocente(RenderWindow& ven);

	//Método para establecer la posición inicial aleatoria.
	void PosicionInicial();

	//Método para verificar si el inocente fue clickeado.
	bool InocenteClick(float x, float y);

	void EliminarInocente();

	void ReiniciarReloj() { temp.restart(); }

	void DesaparecerInocente();

	Clock GetReloj() const;

	//Método Sprite para retornar el sprite del inocente.
	const Sprite& GetSprite() const { return sprInocente; }
};

