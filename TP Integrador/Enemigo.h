#pragma once
#include <iostream>
#include <cstdlib>

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Enemigo {
protected:
	Texture texEnemigo;
	Sprite sprEnemigo;

	//Variables para definir el tiempo de las apariciones de los enemigos.
	Clock temp;
	float tiempo;
public:
	//Constructor.
	Enemigo();

	//Método para inicializar las texturas.
	virtual void InicializarTexturas() = 0;

	//Método para dibujar los enemigos en la ventana.
	virtual void DibujarEnemigos(RenderWindow& ven) = 0;

	//Método para establecer la posición inicial aleatoria.
	virtual void PosicionInicial() = 0;

	//Método para verificar si el enemigo fue clickeado.
	virtual bool EnemigoClick(float x, float y) const = 0;

	//Método para eliminar el enemigo.
	virtual void EliminarEnemigo() = 0;

	//Método para manejar la lógica de aparicón del enemigo.
	virtual void Actualizar() = 0;
};

