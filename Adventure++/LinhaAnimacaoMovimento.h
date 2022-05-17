#pragma once

#include "AnimacaoMovimento.h"
#include "LinhaAnimacao.h"

namespace ElementoGrafico {

	class LinhaAnimacaoMovimento: public LinhaAnimacao
	{
	private:
		const unsigned int contaImagem;
		unsigned int imagemAtual;
		float tempoTotal;

		static const float trocaImagem;
	public:
		LinhaAnimacaoMovimento(const char* caminhoTextura, const unsigned int contaImagem);
		~LinhaAnimacaoMovimento();
		void atualizar(bool Esquerda, float tempo);
		void resetar();
	};
}

