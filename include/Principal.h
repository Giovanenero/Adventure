#pragma once

#include "GerenciadorGrafico.h"
#include "GerenciadorEvento.h"
#include "GerenciadorColisao.h"
#include "Oriana.h"
#include "Pascal.h"

//teste...
#include "EntidadeEstatica.h"
#include "Fase.h"

class Principal
{
private:
	Gerenciador::GerenciadorGrafico* pGrafico;
	Gerenciador::GerenciadorEvento* pEvento;
    Fase::FaseGenerica *fase;
public:
	Principal();
	~Principal();

	void Executar();
};

