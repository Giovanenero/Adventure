#include "Fundo.h"

namespace Entidade {
    Fundo::Fundo(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id):
        EntidadeEstatica(pos, tam, id)
    {
        inicializacao();
    }
    Fundo::~Fundo() {

    }
    void Fundo::inicializacao() {
        pAnimacaoEstatica->novaAnimacao("textura/Fundo/fundoFloresta.png", Ids::Ids::fundo_floresta, Matematica::CoordenadaF(1.0f, 1.0f));
    }
    void Fundo::atualizar() {
        pAnimacaoEstatica->atualizar(Ids::Ids::fundo_floresta, posicao, tamanho);
        pAnimacaoEstatica->renderizar();
    }
}