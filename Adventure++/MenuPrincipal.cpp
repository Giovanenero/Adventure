#include "MenuPrincipal.h"
#include "Botao.h"

namespace Estados {

    MenuPrincipal::MenuPrincipal(Principal* principal) : Menu(),
        Estados::Estado(static_cast<Estados::MaquinaEstados*>(principal), Estados::IDestado::menuPrincipal), pPrincipal(principal),
        title() {
        Gerenciador::GerenciadorGrafico* GM = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
        ElementoGrafico::Botao* bt = nullptr;

        bt = new ElementoGrafico::Botao(Matematica::CoordenadaF(600, 200),
            "JOGAR FLORESTA");
        bt->selecionar(true);
        vectorBotoes.push_back(bt);

        bt = new ElementoGrafico::Botao(Matematica::CoordenadaF(600, 200 + 100),
            "RANQUEAMENTO");
        vectorBotoes.push_back(bt);

        bt = new ElementoGrafico::Botao(Matematica::CoordenadaF(600, 200 + 200),
            "CONFIGURACOES");
        vectorBotoes.push_back(bt);

        bt = new ElementoGrafico::Botao(Matematica::CoordenadaF(600, 200 + 300),
            "SAIR DO JOGO");
        vectorBotoes.push_back(bt);

        title.setInfo("Adventure");
        title.setTamanhoFonte(140);
        title.setCor(77.6, 68.2, 44.3);
        title.setAlinhamento(ElementoGrafico::AlinhamentoTexto::centro);

        title.setPosicao(Matematica::CoordenadaF(600, 100));

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
        title.renderizar();
    }

    void MenuPrincipal::executar() {
        if (ativo) {
            ativo = false;
            switch (selecionado) {
            case 0:
                mudarEstado(Estados::IDestado::jogandoFloresta);
                break;
            case 1:
                //mudarEstado(Estados::IDestado::ranqueamento);
                break;
            case 2:
                //mudarEstado(Estados::IDestado::configuracoes);
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
        title.setPosicao(Matematica::CoordenadaF(title.getPosicao().x, title.getPosicao().y));
    }
}

