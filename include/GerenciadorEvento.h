#pragma once

#include "GerenciadorGrafico.h"
#include "Oriana.h"
#include "Hideo.h"

//teste...
#include "ListaEntidade.h"

namespace Gerenciador {
	class GerenciadorEvento
	{
	private:
		GerenciadorGrafico* pGrafico;
		Entidade::Personagem::Jogador::Oriana* pOriana;
		Entidade::Personagem::Jogador::Hideo* pHideo;
		sf::RenderWindow* window;

		static GerenciadorEvento* pEvento;
		GerenciadorEvento();
	public:
		~GerenciadorEvento();
		static GerenciadorEvento* getGerenciadorEvento();
		void setJogadores(Entidade::Personagem::Jogador::Oriana* pOriana = nullptr, Entidade::Personagem::Jogador::Hideo* pHideo = nullptr);
		void moverJogadores();
		void moverOriana();
		void moverHideo();
		void pollEvents();
	};
}
