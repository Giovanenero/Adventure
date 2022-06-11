#include "GerenciadorEvento.h"

//arrumar...teste
#include "AnimacaoMovimento.h"
#include "Menu.h"
#include "MenuPausa.h"
#include "MenuColocacao.h"
#include "Principal.h"

namespace Gerenciador {

	GerenciadorEvento* GerenciadorEvento::pEvento = nullptr;

	GerenciadorEvento::GerenciadorEvento():
            pGrafico(GerenciadorGrafico::getGerenciadorGrafico()),
            window(nullptr),
            pOriana(nullptr),
            pHideo(nullptr),
            pMenu(nullptr)
	{
		if (pGrafico != nullptr) {
			window = pGrafico->getWindow();
		}
	}
	GerenciadorEvento::~GerenciadorEvento() {
		pOriana = nullptr;
		pHideo = nullptr;
		window = nullptr;
		pGrafico = nullptr;
		/*
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
		*/
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

    void GerenciadorEvento::setMenu(Estados::Menu *pMenu) {
        this->pMenu = pMenu;
    }

    Estados::Menu *GerenciadorEvento::getPMenu() {
        return this->pMenu;
    }

	void GerenciadorEvento::moverJogadores() {
		if (pOriana != nullptr) {
			moverOriana();
		}
		if (pHideo != nullptr) {
			moverHideo();
		}
	}

    void GerenciadorEvento::notificarMenu() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            pMenu->selecionarCima();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			pMenu->selecionarBaixo();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			pMenu->executar();
        }
    }


	void GerenciadorEvento::pollEvents(Principal *pPrincipal) {
		sf::Event evento;
		while (window->pollEvent(evento)) {
			if (evento.type == sf::Event::Closed) {
				pGrafico->fecharJanela();
			}
            Estados::IDestado es = pPrincipal->getIDEstadoAtual();
            if (es == Estados::IDestado::menuPrincipal || es == Estados::IDestado::colocacao
            || es == Estados::IDestado::menuPausa || es == Estados::IDestado::menuJogadorFloresta
            || es == Estados::IDestado::menuJogadorCaverna) {
                notificarMenu();
                if (es == Estados::IDestado::colocacao && evento.type == sf::Event::TextEntered && evento.text.unicode < 128) {
                    //Notificar  menu de colocacao que texto foi colocado (<128 para ter certeza que seja uma letra)
                    Estados::MenuColocacao *mc = dynamic_cast<Estados::MenuColocacao*>(pMenu);
                    if (mc) {
                        mc->aceitarLetra(static_cast<char>(evento.text.unicode));
                    }
                }
            }
            if (es == Estados::IDestado::jogandoFloresta || es == Estados::IDestado::jogandoCaverna) {
				moverJogadores();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    pPrincipal->mudarEstadoAtual(Estados::IDestado::menuPausa);
                    Estados::MenuPausa *mp = dynamic_cast<Estados::MenuPausa*>(pMenu);
                    if (mp) {
                        mp->setIDFase(es); //notificar menu de pause qual fase pausou, e os pontos
                        if (pHideo)
						    mp->setPontos(pOriana->getPontuacao() + pHideo->getPontuacao());
                        else
                            mp->setPontos(pOriana->getPontuacao());
                    }
                }
            }
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