#pragma once

#include "FaseFloresta.h"

class Principal
{
private:
    Fase::FaseFloresta *fase;
public:
	Principal();
	~Principal();

	void Executar();
};

