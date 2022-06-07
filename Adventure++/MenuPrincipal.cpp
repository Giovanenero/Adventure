#include "MenuPrincipal.h"
#include "Botao.h"

namespace Estados {

    MenuPrincipal::MenuPrincipal(Principal* principal) : Menu(),
                                                         Estados::Estado(static_cast<Estados::MaquinaEstados*>(principal), Estados::IDestado::menuPrincipal), pPrincipal(principal),
                                                         titulo() {
        Gerenciador::GerenciadorGrafico* GM = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
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

        max = 3;
    }

    MenuPrincipal::~MenuPrincipal() {
    }

    void MenuPrincipal::atualizar(const float dt) {
        ativo = true;
        //if (title.getPosicao().y < 200)
            //title.setPosicao(Matematica::CoordenadaF(title.getPosicao().x, title.getPosicao().y + 1));
    }

    /* Menu operation to render all it's objects. */
    void MenuPrincipal::renderizar() {
        //atualizarVisao();
        //back.render();
        for (it = vectorBotoes.begin(); it != vectorBotoes.end(); ++it)
            (*it)->renderizar();
        titulo.renderizar();
    }

    void MenuPrincipal::executar() {
        if (ativo) {
            ativo = false;
            switch (selecionado) {
            case 0:
                mudarEstado(Estados::IDestado::jogandoFloresta);
                break;
            case 1:
                //mudarEstado(Estados::IDestado::jogandoCaverna);
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
        //titulo.setPosicao(Matematica::CoordenadaF(titulo.getPosicao().x, titulo.getPosicao().y));
        Gerenciador::GerenciadorEvento::getGerenciadorEvento()->setMenu(this);
    }
}

