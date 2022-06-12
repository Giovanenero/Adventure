#include "Principal.h"
#include "FaseFloresta.h"
#include "MenuPrincipal.h"
#include "MenuColocacao.h"
#include "MenuPausa.h"
#include "MenuJogadores.h"

using namespace Gerenciador;

Principal::Principal():
        faseFloresta(new Fase::FaseFloresta(this)),
        faseCaverna(new Fase::FaseCaverna(this))
{
    Estados::Estado* states = faseFloresta;
    inserirEstado(states);

    Estados::MenuPrincipal *mp = new Estados::MenuPrincipal(this);
    states = static_cast<Estados::Estado*>(mp);
    GerenciadorEvento::getGerenciadorEvento()->setMenu(mp);
    inserirEstado(states);

    states = static_cast<Estados::Estado*>(new Estados::MenuPausa(this));
    inserirEstado(states);

    states = faseCaverna;
    inserirEstado(states);

    states = static_cast<Estados::Estado*>(new Estados::MenuColocacao(this));
    inserirEstado(states);

    states = static_cast<Estados::Estado*>(new Estados::MenuJogadores(this, faseFloresta, Estados::IDestado::menuJogadorFloresta));
    inserirEstado(states);

    states = static_cast<Estados::Estado*>(new Estados::MenuJogadores(this, faseCaverna, Estados::IDestado::menuJogadorCaverna));
    inserirEstado(states);

    mudarEstadoAtual(Estados::IDestado::menuPrincipal);
	Executar();
}

Principal::~Principal() {
    if (faseFloresta != nullptr) {
        delete(faseFloresta);
        faseFloresta = nullptr;
    }
    if (faseCaverna != nullptr) {
        delete faseCaverna;
        faseCaverna = nullptr;
    }
}

void Principal::Executar() {
    GerenciadorGrafico *pGrafico = GerenciadorGrafico::getGerenciadorGrafico();
    GerenciadorEvento *pEvento = GerenciadorEvento::getGerenciadorEvento();
    while (pGrafico->isWindowOpen()) {
        if (getIDEstadoAtual() == Estados::IDestado::jogandoCaverna)
            pEvento->pollEvents(this, faseCaverna);
        else
            pEvento->pollEvents(this, faseFloresta);
        pGrafico->limpar();

        atualizarEstadoAtual(pGrafico->atualizartempo()); //dt passado
        renderizarEstadoAtual();
        pGrafico->mostrar();
    }
}