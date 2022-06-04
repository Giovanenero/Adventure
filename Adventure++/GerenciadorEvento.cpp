#include "GerenciadorEvento.h"

//arrumar...teste
#include "AnimacaoMovimento.h"

namespace Gerenciador {

	GerenciadorEvento* GerenciadorEvento::pEvento = nullptr;

	GerenciadorEvento::GerenciadorEvento():
		pGrafico(GerenciadorGrafico::getGerenciadorGrafico()),
		window(nullptr), 
		pOriana(nullptr),
		pHideo(nullptr)
	{
		if (pGrafico != nullptr) {
			window = pGrafico->getWindow();
		}
	}
	GerenciadorEvento::~GerenciadorEvento() {
		if (pEvento) {
			delete(pEvento);
			pEvento = nullptr;
		}
		if (window) {
			delete(window);
			window = nullptr;
		}
		if (pGrafico) {
			delete(pGrafico);
			pGrafico = nullptr;
		}
	}
	GerenciadorEvento* GerenciadorEvento::getGerenciadorEvento() {
		if (pEvento == nullptr) {
			pEvento = new GerenciadorEvento();
		}
		return pEvento;
	}

	void GerenciadorEvento::setJogadores(Entidade::Personagem::Jogador::Oriana* pOriana, Entidade::Personagem::Jogador::Hideo* pHideo) {
		this->pOriana = pOriana;
		this->pHideo = pHideo;
	}
	void GerenciadorEvento::moverJogadores() {
		if (pOriana != nullptr) {
			moverOriana();
		}
		if (pHideo != nullptr) {
			moverHideo();
		}
	}


	void GerenciadorEvento::pollEvents() {
		sf::Event evento;
		while (window->pollEvent(evento)) {
			if (evento.type == sf::Event::Closed) {
				pGrafico->fecharJanela();
			}
			moverJogadores();
		}
	}
	void GerenciadorEvento::moverOriana() {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			pOriana->podePular();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			pOriana->ativarAndar(true);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			pOriana->ativarAndar(false);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			pOriana->ativarAtacar();
		}
		else {
			pOriana->desligarAndar();
		}
	}
	void GerenciadorEvento::moverHideo() {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			pHideo->podePular();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			pHideo->ativarAndar(true);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			pHideo->ativarAndar(false);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			pHideo->ativarAtacar();
		}
		else {
			pHideo->desligarAndar();
		}
	}
}