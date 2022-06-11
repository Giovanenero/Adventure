#pragma once

#include "FaseFloresta.h"
#include "FaseCaverna.h"
#include "MaquinaEstados.h"

class Principal : public Estados::MaquinaEstados {
private:
    Fase::FaseFloresta *faseFloresta;
    Fase::FaseCaverna *faseCaverna;
public:
	Principal();
	~Principal();

	void Executar();
};

