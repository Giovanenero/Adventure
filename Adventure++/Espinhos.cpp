#include "Espinhos.h"

#define DANO_ESPINHOS 20

namespace Entidade {
    namespace Obstaculo {
        Espinhos::Espinhos(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam):
            Obstaculo(pos, tam, Ids::Ids::espinhos)
        {
            this->inicializacao();
        }
        Espinhos::~Espinhos() {
           
        }
        void Espinhos::inicializacao() {
            pAnimacaoEstatica->novaAnimacao("textura/Obstaculos/espinhos.png", Ids::Ids::espinhos, posicao, tamanho, Matematica::CoordenadaF(1.0f, 0.2f));
        }
        void Espinhos::atualizar() {
            pAnimacaoEstatica->atualizar(Ids::Ids::espinhos);
            pAnimacaoEstatica->renderizar();
        }
        const int Espinhos::getDano() const {
            return DANO_ESPINHOS;
        }
    }
}