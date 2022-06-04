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
		Entidade(Matematica::CoordenadaF pos = Matematica::CoordenadaF(0.f, 0.f), Matematica::CoordenadaF tam = Matematica::CoordenadaF(0.f, 0.f), Ids::Ids id = Ids::Ids::vazio);
		virtual ~Entidade();

		void setPosicao(Matematica::CoordenadaF pos);
		Matematica::CoordenadaF getPosicao();

		void setTamanho(Matematica::CoordenadaF tam);
		Matematica::CoordenadaF getTamanho() const;

		Ids::Ids getID() const;
		
		virtual void renderizar() = 0;
		virtual void inicializacao() = 0;
		virtual void colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade) = 0;
		virtual void atualizar(const float tempo) = 0;
		virtual void atualizarImagem(const float tempo) = 0;

		void executar() { }
		virtual const bool podeRemover() const = 0;
	};
}

