#include "GerenciadorEvento.h"

//arrumar...teste
#include "AnimacaoMovimento.h"

namespace Gerenciador {

	GerenciadorEvento* GerenciadorEvento::pEvento = nullptr;

	GerenciadorEvento::GerenciadorEvento():
		pGrafico(GerenciadorGrafico::getGerenciadorGrafico()),
		window(nullptr), pOriana(nullptr)
	{
		if (pGrafico != nullptr) {
			window = pGrafico->getWindow();
		}
	}
	GerenciadorEvento::~GerenciadorEvento() {
		pEvento = nullptr;
		pGrafico = nullptr;
		window = nullptr;
	}
	
	GerenciadorEvento* GerenciadorEvento::getGerenciadorEvento() {
		if (pEvento == nullptr) {
			pEvento = new GerenciadorEvento();
		}
		return pEvento;
	}

	void GerenciadorEvento::setOriana(Entidade::Personagem::Oriana* pOriana) {
		this->pOriana = pOriana;
	}

	void GerenciadorEvento::pollEvents() {
		sf::Event evento;
		while (window->pollEvent(evento)) {
			if (evento.type == sf::Event::Closed) {
				pGrafico->fecharJanela();
			}
		}
	}
	void GerenciadorEvento::eventojogador(const float tempo) {
		//arrumar...
	}
}