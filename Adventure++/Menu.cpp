#include "Menu.h"
#include "GerenciadorGrafico.h"

namespace Estados {

    Menu::Menu() : 
        Ente(), 
        selecionado(0), 
        min(0), 
        max(2), 
        ativo(false) { }

    Menu::~Menu() {
        ElementoGrafico::Botao* b = nullptr;
        while (vectorBotoes.size() != 0) {
            b = vectorBotoes.back();
            delete (b);
            b = nullptr;
            vectorBotoes.pop_back();
        }
        vectorBotoes.clear();
    }

    void Menu::atualizarVisao() { //atualmente usado para centralizar de volta a camera nos menus quando pause é invocado.
        Gerenciador::GerenciadorGrafico* pGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
        pGrafico->centralizarCamera(Matematica::CoordenadaF(600, 300));
    }

    void Menu::selecionarBaixo() {
        if (ativo) {
            vectorBotoes[selecionado]->selecionar(false);
            selecionado++;
            if (selecionado > max) {
                selecionado = min;
            }
            vectorBotoes[selecionado]->selecionar(true);
        }
    }

    void Menu::selecionarCima() {
        if (ativo) {
            vectorBotoes[selecionado]->selecionar(false);
            selecionado--;
            if (selecionado < min) {
                selecionado = max;
            }
            vectorBotoes[selecionado]->selecionar(true);
        }
    }
}