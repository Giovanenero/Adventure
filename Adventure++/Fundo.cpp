#include "Fundo.h"

namespace Entidade {
    namespace Obstaculo {
        Fundo::Fundo(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id) :
            Obstaculo(pos, tam, id)
        {
            inicializacao();
        }
        Fundo::~Fundo() {

        }
        void Fundo::inicializacao() {
            pAnimacaoEstatica->novaAnimacao("textura/Fundo/fundoFloresta.png", Ids::Ids::fundo_floresta, posicao, tamanho, Matematica::CoordenadaF(0.7f, 0.6f));
        }
        void Fundo::atualizar() {
            pAnimacaoEstatica->atualizar(Ids::Ids::fundo_floresta);
            pAnimacaoEstatica->renderizar();
        }
        void Fundo::executar() {
            //???
        }
    } //namespace Obstaculo
} //namespace Entidade