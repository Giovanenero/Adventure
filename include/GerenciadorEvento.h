#pragma once

#include "GerenciadorGrafico.h"
#include "Oriana.h"

//teste...
#include "ListaEntidade.h"

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
	};
}
