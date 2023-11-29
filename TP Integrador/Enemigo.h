#pragma once
#include <iostream>
#include <cstdlib>

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Enemigo {
private:
	Texture texEnemigo1;
	Sprite sprEnemigo1;

	//Variables para definir el tiempo de las apariciones de los enemigos.
	Clock temp;
	float tiempo;
public:
	//Constructor.
	Enemigo();

	//Método para inicializar las texturas.
	void InicializarTexturas();

	//Método para dibujar los enemigos en la ventana.
	void DibujarEnemigos(RenderWindow& ven);

	//Método para establecer la posición inicial aleatoria.
	void PosicionInicial();

	//Método para verificar si el enemigo fue clickeado.
	bool EnemigoClick(float x, float y) const;

	//Método para eliminar el enemigo.
	void EliminarEnemigo();

	//Método para manejar la lógica de aparicón del enemigo.
	void Actualizar();
};

