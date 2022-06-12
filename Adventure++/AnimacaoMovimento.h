#pragma once

#include "Animacao.h"
#include "LinhaAnimacaoMovimento.h"

namespace ElementoGrafico {

	class LinhaAnimacaoMovimento;

	class AnimacaoMovimento: public Animacao
	{
	private:
		std::map<Ids::Ids, LinhaAnimacaoMovimento*> mapAnimacaoMovimento;
	public:
		AnimacaoMovimento();
		~AnimacaoMovimento();

		void novaAnimacao(const char* caminhoTextura, unsigned int contaImagem, Ids::Ids id, Matematica::CoordenadaF tam, Matematica::CoordenadaF escala);
		void atualizar(Matematica::CoordenadaF pos, const bool Esquerda, const float tempo, Ids::Ids id);
	};
}
