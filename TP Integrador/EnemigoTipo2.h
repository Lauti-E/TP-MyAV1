#pragma once
#include "Enemigo.h"

class EnemigoTipo2 : public Enemigo {
private:

public:
	EnemigoTipo2();

	//Implementación de las funciones virtuales puras de la clase padre.
	void InicializarTexturas() override;
	void DibujarEnemigos(RenderWindow& ven) override;
	void PosicionInicial() override;

	bool EnemigoClick(float x, float y) const override;

	void EliminarEnemigo() override;
	void Actualizar() override;
};