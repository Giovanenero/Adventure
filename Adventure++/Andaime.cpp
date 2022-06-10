#include "Andaime.h"

#define TAMANHO_ANDAIME 50.0f

namespace Entidade {
    namespace Obstaculo {
        Andaime::Andaime(Matematica::CoordenadaF pos):
            Obstaculo(pos, Matematica::CoordenadaF(TAMANHO_ANDAIME, TAMANHO_ANDAIME), Ids::Ids::andaime)
        {
            this->inicializacao();
        }
        Andaime::~Andaime() {

        }
        void Andaime::inicializacao() {
            pAnimacaoEstatica->novaAnimacao("textura/Obstaculos/andaime.png", Ids::Ids::andaime, posicao, tamanho, Matematica::CoordenadaF(1.0f, 1.4f));
        }
        void Andaime::atualizar() {
            pAnimacaoEstatica->atualizar(Ids::Ids::andaime, posicao);
            pAnimacaoEstatica->renderizar();
        }
    }
}