#pragma once

#include "FaseFloresta.h"
#include "MaquinaEstados.h"

class Principal : public Estados::MaquinaEstados {
private:
    Fase::FaseFloresta *fase;
public:
	Principal();
	~Principal();

	void Executar();
};

