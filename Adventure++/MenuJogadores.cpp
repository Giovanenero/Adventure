#include "MenuJogadores.h"
#include "GerenciadorEvento.h"
#include "Fase.h"
#include "Principal.h"

namespace Estados {

    MenuJogadores::MenuJogadores(Principal *principal, Fase::Fase *f, IDestado id) : Menu(), fase(f),
    Estados::Estado(static_cast<Estados::MaquinaEstados*>(principal), id){
        ElementoGrafico::Botao* bt = NULL;

        bt = new ElementoGrafico::Botao(Matematica::CoordenadaF(600, 300), "1 JOGADOR");
        bt->selecionar(true);
        vectorBotoes.push_back(bt);

        bt = new ElementoGrafico::Botao(Matematica::CoordenadaF(600, 400), "2 JOGADORES");
        vectorBotoes.push_back(bt);

        selecionado = 0;
        max = 1;
    }

    MenuJogadores::~MenuJogadores() { }

    void MenuJogadores::atualizar(const float dt) { ativo = true; }

    void MenuJogadores::renderizar() {
        for (it = vectorBotoes.begin(); it != vectorBotoes.end(); ++it)
            (*it)->renderizar();
    }

    void MenuJogadores::resetEstado() {
        for (it = vectorBotoes.begin(); it != vectorBotoes.end(); ++it)
            (*it)->selecionar(false);
        selecionado = 0;
        vectorBotoes[selecionado]->selecionar(true);
        Gerenciador::GerenciadorEvento::getGerenciadorEvento()->setMenu(this);
    }

    void MenuJogadores::executar() {
        if (ativo) {
            ativo = false;
            Estados::Estado *es = dynamic_cast<Estados::Estado*>(fase);
            switch (selecionado) {
                case 0: //um jogador
                    fase->setDoisJogadores(false);
                    mudarEstado(es->getID()); //volta para a fase certa, sendo floresta ou caverna ou etc...
                    break;
                case 1: //dois jogadores
                    fase->setDoisJogadores(true);
                    mudarEstado(es->getID());
                    break;
                default:
                    break;
            }
        }
    }
} // Estados