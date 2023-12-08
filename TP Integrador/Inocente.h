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
	Clock relojInocente; //Variable Clock para la desaparici�n del inocente cada x tiempo.
public:
	//Constructor.
	Inocente();

	//M�todo para inicializar las texturas.
	void InicializarTexturas();

	//M�todo para dibujar los inocentes en la ventana.
	void DibujarInocente(RenderWindow& ven);

	//M�todo para establecer la posici�n inicial aleatoria.
	void PosicionInicial();

	//M�todo para verificar si el inocente fue clickeado.
	bool InocenteClick(float x, float y);

	void EliminarInocente();

	void ReiniciarReloj() { temp.restart(); }

	void DesaparecerInocente();

	Clock GetReloj() const;

	//M�todo Sprite para retornar el sprite del inocente.
	const Sprite& GetSprite() const { return sprInocente; }
};

