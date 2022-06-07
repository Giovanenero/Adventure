#include "Pedra.h"

#define TAMANHO_PEDRA_X 50.0f
#define TAMANHO_PEDRA_Y 50.0f

namespace Entidade {
    namespace Obstaculo {
        Pedra::Pedra(Matematica::CoordenadaF pos):
            Obstaculo(pos, Matematica::CoordenadaF(TAMANHO_PEDRA_X, TAMANHO_PEDRA_Y), Ids::Ids::pedra)
        {
            this->inicializacao();
        }
        Pedra::~Pedra() { }

        void Pedra::inicializacao() {
            pAnimacaoEstatica->novaAnimacao("textura/Obstaculos/pedra.png", Ids::Ids::pedra, posicao, tamanho, Matematica::CoordenadaF(1.0f, 1.2f));
        }
        void Pedra::atualizar() {
            pAnimacaoEstatica->atualizar(Ids::Ids::pedra);
            pAnimacaoEstatica->renderizar();
        }
    }
}