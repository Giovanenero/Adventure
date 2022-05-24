#pragma once

#include "AnimacaoEstatica.h"
#include "LinhaAnimacao.h"

namespace ElementoGrafico {
	class LinhaAnimacaoEstatica: public LinhaAnimacao
	{
	public:
		LinhaAnimacaoEstatica(const char* caminhoTextura);
		~LinhaAnimacaoEstatica();
	};
}

