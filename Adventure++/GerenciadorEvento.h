#pragma once

#include "GerenciadorGrafico.h"
#include "Oriana.h"

namespace Gerenciador {
	class GerenciadorEvento
	{
	private:
		GerenciadorGrafico* pGrafico;
		Entidade::Personagem::Oriana* pOriana;
		sf::RenderWindow* window;

		static GerenciadorEvento* pEvento;
		GerenciadorEvento();
	public:
		~GerenciadorEvento();
		static GerenciadorEvento* getGerenciadorEvento();
		void setOriana(Entidade::Personagem::Oriana* pOriana);
		void pollEvents();
		void eventojogador(const float tempo);
	};
}
