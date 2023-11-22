#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Crosshair {
private:
	//Atributos
	Texture texCrosshair;
	Sprite sprCrosshair;
public:
	//Constructor.
	Crosshair();

	//Método para inicializar la textura/sprite del crosshair y configurarlo.
	void Inicializar();

	//Método para dibujar el crosshair.
	void Dibujar(RenderWindow& ven);

	//Método para posicionar el centro del sprite en el mouse.
	void CentroCrosshair(RenderWindow& ven);
};
