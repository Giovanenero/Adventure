#include "Fundo.h"

Fundo::Fundo(Ids::Ids id) :
    Ente(id), 
    pAnimacaoEstatica(new ElementoGrafico::AnimacaoEstatica())
{
    this->inicializacao();
}
Fundo::~Fundo() { }

void Fundo::inicializacao() {
    Matematica::CoordenadaF posicao(0.0f, 0.0f);
    Matematica::CoordenadaF tamanho(Gerenciador::GerenciadorGrafico::getGerenciadorGrafico()->getWindow()->getPosition().x, Gerenciador::GerenciadorGrafico::getGerenciadorGrafico()->getWindow()->getPosition().y);
    pAnimacaoEstatica->novaAnimacao("textura/Fundo/fundoFloresta.png", Ids::Ids::fundo_floresta, posicao, tamanho, Matematica::CoordenadaF(1.9f, 1.9f));
    pAnimacaoEstatica->novaAnimacao("textura/Fundo/fundoCaverna.jpg", Ids::Ids::fundo_caverna, posicao, tamanho, Matematica::CoordenadaF(2.0f, 1.9f));
}
void Fundo::atualizar(Matematica::CoordenadaF pos) {
    pAnimacaoEstatica->setPosicao(pos);
    pAnimacaoEstatica->atualizar(Ids::Ids::fundo_floresta, pos);
    pAnimacaoEstatica->renderizar();
}

void Fundo::executar() { }