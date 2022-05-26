#pragma once

#include "GerenciadorGrafico.h"
#include "GerenciadorEvento.h"
#include "GerenciadorColisao.h"
#include "Oriana.h"
#include "Pascal.h"

//teste...
#include "EntidadeEstatica.h"


class Principal
{
private:
	Gerenciador::GerenciadorGrafico* pGrafico;
	Gerenciador::GerenciadorEvento* pEvento;
	Entidade::Personagem::Oriana *pOriana;
	Entidade::Personagem::Pascal* pPascal;
public:
	Principal();
	~Principal();

	void Executar();
};

