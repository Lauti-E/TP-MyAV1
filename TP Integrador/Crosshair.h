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

	//M�todo para inicializar la textura/sprite del crosshair y configurarlo.
	void Inicializar();

	//M�todo para dibujar el crosshair.
	void Dibujar(RenderWindow& ven);

	//M�todo para posicionar el centro del sprite en el mouse.
	void CentroCrosshair(RenderWindow& ven);
};
