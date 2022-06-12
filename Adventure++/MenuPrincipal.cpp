#include "MenuPrincipal.h"
#include "MenuPausa.h"
#include "Botao.h"

namespace Estados {

    MenuPrincipal::MenuPrincipal(Principal* principal) : Menu(),
                                                         Estados::Estado(static_cast<Estados::MaquinaEstados*>(principal), Estados::IDestado::menuPrincipal),
                                                         iniciouCaverna(false), iniciouFloresta(false),
                                                         titulo() {
        ElementoGrafico::Botao* bt = nullptr;

        bt = new ElementoGrafico::Botao(Matematica::CoordenadaF(600.f, 200.f),
            "JOGAR FLORESTA");
        bt->selecionar(true);
        vectorBotoes.push_back(bt);

        bt = new ElementoGrafico::Botao(Matematica::CoordenadaF(600.f, 200.f + 100),
            "JOGAR CAVERNA");
        vectorBotoes.push_back(bt);

        bt = new ElementoGrafico::Botao(Matematica::CoordenadaF(600.f, 200.f + 200),
            "COLOCACAO");
        vectorBotoes.push_back(bt);

        bt = new ElementoGrafico::Botao(Matematica::CoordenadaF(600.f, 200.f + 300),
            "SAIR DO JOGO");
        vectorBotoes.push_back(bt);

        titulo.setInfo("Adventure");
        titulo.setTamanhoFonte(140);
        titulo.setCor(77, 68, 44);
        titulo.setAlinhamento(ElementoGrafico::AlinhamentoTexto::centro);

        titulo.setPosicao(Matematica::CoordenadaF(600.f, 100.f));

        pontos = 0;
        ultimaFase = IDestado::desconhecido;

        max = 3;
    }

    MenuPrincipal::~MenuPrincipal() { }

    void MenuPrincipal::atualizar(const float dt) {
        ativo = true;
    }

    /* Menu operation to render all it's objects. */
    void MenuPrincipal::renderizar() {
        for (it = vectorBotoes.begin(); it != vectorBotoes.end(); ++it)
            (*it)->renderizar();
        titulo.renderizar();
    }

    void MenuPrincipal::executar() {
        if (ativo) {
            ativo = false;
            switch (selecionado) {
            case 0:
                if (iniciouFloresta) {
                    mudarEstado(Estados::IDestado::jogandoFloresta);
                } else {
                    iniciouFloresta = true;
                    mudarEstado(Estados::IDestado::menuJogadorFloresta);
                }
                break;
            case 1:
                if (iniciouCaverna) {
                    mudarEstado(Estados::IDestado::jogandoCaverna);
                } else {
                    iniciouCaverna = true;
                    mudarEstado(Estados::IDestado::menuJogadorCaverna);
                }
                break;
            case 2:
                mudarEstado(Estados::IDestado::colocacao);
                break;
            case 3:
                //pGame->endGame();
                exit(0);
                break;
            default:
                break;
            }
        }
    }

    void MenuPrincipal::resetEstado() {
        vectorBotoes[selecionado]->selecionar(false);
        selecionado = 0;
        vectorBotoes[selecionado]->selecionar(true);
        if (pSM->getIDUltimoEstado() == IDestado::menuPausa) {
            MenuPausa* m = dynamic_cast<MenuPausa*>(Gerenciador::GerenciadorEvento::getGerenciadorEvento()->getPMenu());
            if (m) {
                pontos = m->getPontos();
                ultimaFase = m->getIDFase();
            }
        }
        //titulo.setPosicao(Matematica::CoordenadaF(titulo.getPosicao().x, titulo.getPosicao().y));
        Gerenciador::GerenciadorEvento::getGerenciadorEvento()->setMenu(this);
    }

    IDestado MenuPrincipal::getUltimaFase() {
        return ultimaFase;
    }

    int MenuPrincipal::getPontos() {
        return pontos;
    }
}

