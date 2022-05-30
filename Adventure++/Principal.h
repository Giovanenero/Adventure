#pragma once

#include "Fase.h"

class Principal
{
private:
    Fase::FaseGenerica *fase;
public:
	Principal();
	~Principal();

	void Executar();
};

