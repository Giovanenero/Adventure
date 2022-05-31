#include "Fundo.h"

Gerenciador::GerenciadorGrafico* Fundo::pGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();

Fundo::Fundo(Ids::Ids id, Entidade::Entidade* pJogador1) :
    Ente(id), 
    pJogador(pJogador1),
    pAnimacaoEstatica(new ElementoGrafico::AnimacaoEstatica())
{
    if (pJogador == nullptr) {
        std::cout << "ERRO: pJogador vazio - classe Fundo!" << std::endl;
        exit(1);
    }
    inicializacao();
}
Fundo::~Fundo() { }
void Fundo::inicializacao() {
    Matematica::CoordenadaF posicao(pJogador->getPosicao().x, pJogador->getPosicao().y);
    Matematica::CoordenadaF tamanho(pGrafico->getWindow()->getPosition().x, pGrafico->getWindow()->getPosition().y);
    pAnimacaoEstatica->novaAnimacao("textura/Fundo/fundoFloresta.png", Ids::Ids::fundo_floresta, posicao, tamanho, Matematica::CoordenadaF(0.7f, 0.6f));
}
void Fundo::atualizar() {
    pAnimacaoEstatica->setPosicao(Matematica::CoordenadaF(pJogador->getPosicao().x, pJogador->getPosicao().y));
    pAnimacaoEstatica->atualizar(Ids::Ids::fundo_floresta);
    pAnimacaoEstatica->renderizar();
}

void Fundo::executar() {
    //???
}