#include "Principal.h"
#include "FaseFloresta.h"
#include "MenuPrincipal.h"

using namespace Gerenciador;

Principal::Principal(): 
    fase(new Fase::FaseFloresta(this))
{
    Estados::Estado* states = fase;
    inserirEstado(fase);

    //states = static_cast<Estados::Estado* *>(new Menus::PauseMenuState(this, dynamic_cast<States::Level*>(mapOfStates[stateID::playing])));
    //inserirEstado(states);
    Estados::MenuPrincipal *mp = new Estados::MenuPrincipal(this);
    states = static_cast<Estados::Estado*>(mp);
    GerenciadorEvento::getGerenciadorEvento()->setMenuPrincipal(mp);
    inserirEstado(states);

    //states = static_cast<Estados::Estado* *>(new Menus::SettingsMenu(this));
    //inserirEstado(states);

    //states = static_cast<Estados::Estado* *>(new Menus::LeaderboardMenu(this));
    //inserirEstado(states);

    //states = static_cast<Estados::Estado* *>(new Menus::GameOverMenu(this, dynamic_cast<States::Level*>(mapOfStates[stateID::playing])));
    //inserirEstado(states);

    mudarEstadoAtual(Estados::IDestado::menuPrincipal);
	Executar();
}
Principal::~Principal() {
    if (fase != nullptr) {
        delete(fase);
        fase = nullptr;
    }
}

void Principal::Executar() {
    //fase->init();
    GerenciadorGrafico *pGrafico = GerenciadorGrafico::getGerenciadorGrafico();
    GerenciadorEvento *pEvento = GerenciadorEvento::getGerenciadorEvento();
    while (pGrafico->isWindowOpen()) {

        pEvento->pollEvents(this);
        pGrafico->limpar();

        //fase->executar();
        atualizarEstadoAtual(pGrafico->atualizartempo()); //dt passado
        renderizarEstadoAtual();

        pGrafico->mostrar();
    }
}