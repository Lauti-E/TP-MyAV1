#include "Crosshair.h"

//Constructor.
Crosshair::Crosshair() {
	
	//Cargamos la textura y el sprite del crosshair.
	texCrosshair.loadFromFile("Imagenes//Crosshair.png");

	sprCrosshair.setTexture(texCrosshair);

	//Ajustamos la escala del crosshair.
	sprCrosshair.setScale(0.1f, 0.1f);

	//Obtener el tamaño de la textura del crosshair.
	Vector2u tam = texCrosshair.getSize();

	//Centrar el origen del sprite.
	sprCrosshair.setOrigin(tam.x / 2.0f, tam.y / 2.0f);
}
