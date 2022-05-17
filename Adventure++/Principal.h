#pragma once

#include "GerenciadorGrafico.h"
#include "GerenciadorEvento.h"
#include "Oriana.h"


class Principal
{
private:
	Gerenciador::GerenciadorGrafico* pGrafico;
	Gerenciador::GerenciadorEvento* pEvento;
	Entidade::Personagem::Oriana jogador1;
public:
	Principal();
	~Principal();

	void Executar();
};

