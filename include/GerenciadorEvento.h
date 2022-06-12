#pragma once

#include "GerenciadorGrafico.h"
#include "Oriana.h"
#include "Hideo.h"

//teste...
#include "ListaEntidade.h"

class Principal;
namespace Estados {
	class Menu;
}

namespace Fase {
    class Fase;
}

namespace Gerenciador {	
	class GerenciadorEvento
	{
	private:
		GerenciadorGrafico* pGrafico;
		Entidade::Personagem::Jogador::Oriana* pOriana;
		Entidade::Personagem::Jogador::Hideo* pHideo;
		sf::RenderWindow* window;
		Estados::Menu *pMenu;

		static GerenciadorEvento* pEvento;
		GerenciadorEvento();
	public:
		~GerenciadorEvento();
		static GerenciadorEvento* getGerenciadorEvento();
		void setJogadores(Entidade::Personagem::Jogador::Oriana* pOriana = nullptr, Entidade::Personagem::Jogador::Hideo* pHideo = nullptr);
        void setMenu(Estados::Menu *pMenu);
        Estados::Menu *getPMenu();
		void moverJogadores();
		void moverOriana();
		void moverHideo();
		void pollEvents(Principal *pPrincipal, Fase::Fase *fase);
        void notificarMenu();
	};
}
