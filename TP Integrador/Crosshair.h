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

	//Función para dibujar el sprite en la ventana.
	void DibujarCrosshair(RenderWindow* ven) {
		ven->draw(sprCrosshair);
	}
	
	//Función para centrar el mouse en el centro del crosshair.
	void CentroCrosshair(float x, float y) {
		sprCrosshair.setPosition(x, y);
	}

	//Función declarada como Vector2f para obtener la posición del crosshair.
	Vector2f Posicion() {
		return sprCrosshair.getPosition();
	}
};
