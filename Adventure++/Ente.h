#pragma once

#include "Ids.h"

class Ente
{
protected:
	Ids::Ids ID;
public:
	Ente(Ids::Ids id = Ids::Ids::vazio);
	~Ente();
	virtual void executar() = 0;
	virtual void atualizar(const float tempo) = 0;
};

