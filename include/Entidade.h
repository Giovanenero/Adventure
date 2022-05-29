#pragma once

#include "Coordenada.h"
#include "Ids.h"
#include "Animacao.h"

// classe abstrata

namespace Entidade {
	class Entidade
	{
	protected:
		Matematica::CoordenadaF posicao;
		Matematica::CoordenadaF tamanho;
		Ids::Ids ID;
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
	};
}

