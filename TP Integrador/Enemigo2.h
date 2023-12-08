#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Enemigo2 {
private:
	Texture texEnemigo2; //Textura del enemigo 2.
	Sprite sprEnemigo2; //Sprite del enemigo 2.

	Clock temp; //Variable Clock para reiniciar el temporizador.
public:
	//Constructor.
	Enemigo2();

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

	//Método para reiniciar el reloj.
	void ReiniciarReloj() { temp.restart(); }

	//Método Sprite para retornar el sprite del enemigo.
	const Sprite& GetSprite() const { return sprEnemigo2; }
};
