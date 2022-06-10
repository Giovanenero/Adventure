#pragma once

#define GRAVIDADE 998.0F


#include "Ente.h"
#include "Coordenada.h"
#include "Animacao.h"

/*
	classe abstrata
*/

namespace Entidade {
	class Entidade: public Ente
	{
	protected:
		Matematica::CoordenadaF posicao;
		Matematica::CoordenadaF tamanho;

		Matematica::CoordenadaF velocidade;
	public:
		Entidade(Matematica::CoordenadaF pos = Matematica::CoordenadaF(0.f, 0.f), Matematica::CoordenadaF tam = Matematica::CoordenadaF(0.f, 0.f), Ids::Ids id = Ids::Ids::vazio);
		virtual ~Entidade();

		void setPosicao(Matematica::CoordenadaF pos);
		Matematica::CoordenadaF getPosicao() const;

		void setTamanho(Matematica::CoordenadaF tam);
		Matematica::CoordenadaF getTamanho() const;

		void setVelocidade(Matematica::CoordenadaF velocidade);
		Matematica::CoordenadaF getVelocidade() const;

		Ids::Ids getID() const;
		
		virtual void renderizar() = 0;
		virtual void inicializacao() = 0;
		virtual void colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade) = 0;
		virtual void atualizar(const float tempo) = 0;
		virtual void atualizarImagem(const float tempo) = 0;
		virtual const bool podeRemover() const = 0;

		void executar() { }
		void colisaoPlataforma(Matematica::CoordenadaF intersecao, Entidade* pEntidade);
	};
}

