#include "Espinhos.h"

#define DANO_ESPINHOS 20
#define TAMANHO_ESPINHOS_X 15.0f
#define TAMANHO_ESPINHOS_Y 10.0f

namespace Entidade {
    namespace Obstaculo {
        Espinhos::Espinhos(Matematica::CoordenadaF pos):
            Obstaculo(pos, Matematica::CoordenadaF(TAMANHO_ESPINHOS_X, TAMANHO_ESPINHOS_Y), Ids::Ids::espinhos)
        {
            this->inicializacao();
        }
        Espinhos::~Espinhos() {
           
        }
        void Espinhos::inicializacao() {
            pAnimacaoEstatica->novaAnimacao("textura/Obstaculos/espinhos.png", Ids::Ids::espinhos, posicao, tamanho, Matematica::CoordenadaF(0.4f, 0.2f));
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