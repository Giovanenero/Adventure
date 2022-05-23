#pragma once

#include "GerenciadorGrafico.h"
#include "GerenciadorEvento.h"
#include "Oriana.h"
#include "Inimigo.h"


class Principal
{
private:
	Gerenciador::GerenciadorGrafico* pGrafico;
	Gerenciador::GerenciadorEvento* pEvento;
	Entidade::Personagem::Oriana *jogador1;
	Entidade::Personagem::Inimigo *dog;
public:
	Principal();
	~Principal();

	void Executar();
};

