#pragma once

#include "Ente.h"
#include "Coordenada.h"
#include "Animacao.h"

namespace Entidade {
	class Entidade: public Ente
	{
	protected:
		Matematica::CoordenadaF posicao;
		Matematica::CoordenadaF tamanho;
	public:
		Entidade(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id);
		virtual ~Entidade();

		void setPosicao(Matematica::CoordenadaF pos);
		Matematica::CoordenadaF getPosicao() const;

		void setTamanho(Matematica::CoordenadaF tam);
		Matematica::CoordenadaF getTamanho() const;

		Ids::Ids getID() const;
		
		virtual void renderizar() = 0;
		virtual void inicializacao() = 0;
		virtual void colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade) = 0;

		virtual void atualizar(const float tempo) = 0;
		virtual void executar() = 0;
	};
}

