#include "Menu.h"
#include "GerenciadorGrafico.h"

Menu::Menu() : Ente(), selecionado(0), min(0), max(2), ativo(false) {

}

Menu::~Menu() {
    ElementoGrafico::Botao *b = nullptr;
    while (vectorBotoes.size() != 0) {
        b = vectorBotoes.back();
        delete (b);
        vectorBotoes.pop_back();
    }
    vectorBotoes.clear();
}

void Menu::atualizarVisao() {
    Gerenciador::GerenciadorGrafico *pGrafico =  Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
    pGrafico->centralizarCamera(Matematica::CoordenadaF (pGrafico->getWindow()->getSize().x, pGrafico->getWindow()->getSize().y));
}

void Menu::selecionarBaixo() {
    if (ativo) {
        vectorBotoes[selecionado]->selecionar(false);
        selecionado++;
        if (selecionado > max) {
            selecionado = max;
        }
        vectorBotoes[selecionado]->selecionar(true);
    }
}

void Menu::selecionarCima() {
    if (ativo) {
        vectorBotoes[selecionado]->selecionar(false);
        selecionado--;
        if (selecionado < min) {
            selecionado = min;
        }
        vectorBotoes[selecionado]->selecionar(true);
    }
}