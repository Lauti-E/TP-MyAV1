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
	Texture texEnemigo; //Textura del enemigo 1.
	Sprite sprEnemigo; //Sprite del enemigo 1.

	Clock temp; //Variable Clock para reiniciar el temporizador.
public:
	//Constructor.
	Enemigo();

	//M�todo para inicializar las texturas.
	void InicializarTexturas();

	//M�todo para dibujar los enemigos en la ventana.
	void DibujarEnemigos(RenderWindow& ven);

	//M�todo para establecer la posici�n inicial aleatoria.
	void PosicionInicial();

	//M�todo para verificar si el enemigo fue clickeado.
	bool EnemigoClick(float x, float y) const;

	//M�todo para eliminar el enemigo.
	void EliminarEnemigo();

	//M�todo para reiniciar el reloj.
	void ReiniciarReloj() { temp.restart(); }

	//M�todo Sprite para retornar el sprite del enemigo.
	const Sprite& GetSprite() const { return sprEnemigo; }
};

