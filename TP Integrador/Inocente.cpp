#include "Inocente.h"

Inocente::Inocente() {
	srand(time(NULL));
}

void Inocente::InicializarTexturas() {
	//Cargamos la textura y el sprite del inocente.
	texInocente.loadFromFile("Imagenes//Inocente.png");

	sprInocente.setTexture(texInocente);

	//Ajustamos la escala del inocente.
	sprInocente.setScale(0.15f, 0.15f);

	//Obtener el tamaño de la textura del inocente.
	Vector2u tamInocente = texInocente.getSize();

	//Centrar el origen del inocente.
	sprInocente.setOrigin(tamInocente.x / 2.0f, tamInocente.y / 2.0f);
}

void Inocente::DibujarInocente(RenderWindow& ven) {
	ven.draw(sprInocente);
}

void Inocente::PosicionInicial() {
	//Definir 4 posiciones posibles.
	Vector2f posiciones[] = {
		
		{200.f, 200.f}, //Posición 1.
		{-1000.f, -1000.f}, //Posición para que no sea contínua la aparición en ventana.
		{600.f, 200.f}, //Posición 2.
		{-1001.f, -1001.f}, //Posición para que no sea contínua la aparición en ventana.
		{175.f, 410.f}, //Posición 3.
		{-1002.f, -1002.f}, //Posición para que no sea contínua la aparición en ventana.
		{640.f, 410.f}, //Posición 4.
		{-1003.f, -1003.f}, //Posición para que no sea contínua la aparición en ventana.
		{400.f, 450.f},  //Posición 5.
		{-1004.f, -1004.f} //Posición para que no sea contínua la aparición en ventana.
	};

	//Posición al azar.
	int indicePos = rand() % 5;

	//Establecer la posición del sprite del enemigo.
	sprInocente.setPosition(posiciones[indicePos]);

	temp.restart();
}

bool Inocente::InocenteClick(float x, float y) {
	//Verificar si las coordenadas (x, y) están dentro del sprite del inocente.
	return sprInocente.getGlobalBounds().contains(x, y);
}

void Inocente::EliminarInocente() {
	//Reiniciar el termporizador.
	temp.restart();

	//"Eliminar" al inocente, moverlo fuera de la ventana.
	sprInocente.setPosition(-1000.f, -1000.f);
}

void Inocente::DesaparecerInocente() {
	//Reiniciar el temporizador.
	temp.restart();

	//"Eliminar" al inocente, moverlo fuera de la ventana.
	sprInocente.setPosition(-1000.f, -1000.f);
}

Clock Inocente::GetReloj() const {
	return relojInocente;
}