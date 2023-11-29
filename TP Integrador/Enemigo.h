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

	//M�todo para inicializar las texturas.
	virtual void InicializarTexturas() = 0;

	//M�todo para dibujar los enemigos en la ventana.
	virtual void DibujarEnemigos(RenderWindow& ven) = 0;

	//M�todo para establecer la posici�n inicial aleatoria.
	virtual void PosicionInicial() = 0;

	//M�todo para verificar si el enemigo fue clickeado.
	virtual bool EnemigoClick(float x, float y) const = 0;

	//M�todo para eliminar el enemigo.
	virtual void EliminarEnemigo() = 0;

	//M�todo para manejar la l�gica de aparic�n del enemigo.
	virtual void Actualizar() = 0;
};

