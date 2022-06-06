#pragma once

#include "GerenciadorGrafico.h"
#include "Oriana.h"
#include "Hideo.h"

//teste...
#include "ListaEntidade.h"

class MenuPrincipal;
class Principal;

namespace Gerenciador {
	class GerenciadorEvento
	{
	private:
		GerenciadorGrafico* pGrafico;
		Entidade::Personagem::Jogador::Oriana* pOriana;
		Entidade::Personagem::Jogador::Hideo* pHideo;
		sf::RenderWindow* window;
        MenuPrincipal *pMenuPrincipal;

		static GerenciadorEvento* pEvento;
		GerenciadorEvento();
	public:
		~GerenciadorEvento();
		static GerenciadorEvento* getGerenciadorEvento();
		void setJogadores(Entidade::Personagem::Jogador::Oriana* pOriana = nullptr, Entidade::Personagem::Jogador::Hideo* pHideo = nullptr);
        void setMenuPrincipal(MenuPrincipal *pMenu);
		void moverJogadores();
		void moverOriana();
		void moverHideo();
		void pollEvents(Principal *pPrincipal);
        void notificarMenu();
	};
}
