#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Crosshair
{
private:
	//Atributos
	Texture texCrosshair;
	Sprite sprCrosshair;
public:
	//Constructor.
	Crosshair();

	//Funci�n para dibujar el sprite en la ventana.
	void DibujarCrosshair(RenderWindow* ven) {
		ven->draw(sprCrosshair);
	}
	
	//Funci�n para centrar el mouse en el centro del crosshair.
	void CentroCrosshair(float x, float y) {
		sprCrosshair.setPosition(x, y);
	}

	//Funci�n declarada como Vector2f para obtener la posici�n del crosshair.
	Vector2f Posicion() {
		return sprCrosshair.getPosition();
	}
};
