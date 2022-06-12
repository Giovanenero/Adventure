#include "MenuPausa.h"
#include "GerenciadorEvento.h"

namespace Estados {

    MenuPausa::MenuPausa(Estados::MaquinaEstados* pSM, IDestado idFase) :
            Menu(),
            Estados::Estado(pSM, Estados::IDestado::menuPausa),
            idFase(idFase) {

        ElementoGrafico::Botao* bt = NULL;

        bt = new ElementoGrafico::Botao(Matematica::CoordenadaF(600, 300), "RESUMIR");
        bt->selecionar(true);
        vectorBotoes.push_back(bt);

        bt = new ElementoGrafico::Botao(Matematica::CoordenadaF(600, 400), "MENU PRINCIPAL");
        vectorBotoes.push_back(bt);

        selecionado = 0;
        pontos = 0;
        max = 1;
    }

    MenuPausa::~MenuPausa() { }

    void MenuPausa::atualizar(float dt) { ativo = true;}

    /* Menu operation to render all it's objects. */
    void MenuPausa::renderizar() {
        for (it = vectorBotoes.begin(); it != vectorBotoes.end(); ++it)
            (*it)->renderizar();
    }

    void MenuPausa::executar() {
        if (ativo) {
            ativo = false;
            switch (selecionado) {
                case 0:
                    mudarEstado(idFase); //volta para a fase certa, sendo floresta ou caverna ou etc...
                    break;
                case 1:
                    mudarEstado(Estados::IDestado::menuPrincipal);
                    //plvl->endLevel();
                    break;
                default:
                    break;
            }
        }
    }

    void MenuPausa::resetEstado() {
        for (it = vectorBotoes.begin(); it != vectorBotoes.end(); ++it)
            (*it)->selecionar(false);
        selecionado = 0;
        vectorBotoes[selecionado]->selecionar(true);
        ativo = true;
        atualizarVisao();
        Gerenciador::GerenciadorEvento::getGerenciadorEvento()->setMenu(this);
    }

    void MenuPausa::setIDFase(IDestado id) {
        this->idFase = id;
    }

    IDestado MenuPausa::getIDFase() {
        return this->idFase;
    }

    void MenuPausa::setPontos(int pontos) {
        this->pontos = pontos;
    }

    int MenuPausa::getPontos() {
        return this->pontos;
    }

}