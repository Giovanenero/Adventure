#include "Ponte.h"

#define TAMANHO_PONTE_X 200.0f
#define TAMANHO_PONTE_Y 30.0f

namespace Entidade {
    namespace Obstaculo {
        Ponte::Ponte(Matematica::CoordenadaF pos):
            Obstaculo(pos, Matematica::CoordenadaF(TAMANHO_PONTE_X, TAMANHO_PONTE_Y), Ids::Ids::ponte)
        {
            this->inicializacao();
        }
        Ponte::~Ponte() {

        }
        void Ponte::inicializacao() {
            pAnimacaoEstatica->novaAnimacao("textura/Obstaculos/ponte.png", Ids::Ids::ponte, posicao, tamanho, Matematica::CoordenadaF(1.4f, 1.8f));
        }
        void Ponte::atualizar() {
            pAnimacaoEstatica->atualizar(Ids::Ids::ponte, posicao);
            pAnimacaoEstatica->renderizar();
        }
    }
}