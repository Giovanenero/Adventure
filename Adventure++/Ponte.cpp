#include "Ponte.h"

#define TAMANHO_PONTE_PEQUENA_X 200.0f
#define TAMANHO_PONTE_GRANDE_X 600.0f
#define TAMANHO_PONTE_Y 20.0f

namespace Entidade {
    namespace Obstaculo {
        Ponte::Ponte(Matematica::CoordenadaF pos, short tipo_ponte):
            Obstaculo(pos, Matematica::CoordenadaF(TAMANHO_PONTE_PEQUENA_X, TAMANHO_PONTE_Y), Ids::Ids::ponte),
            tipo_ponte(tipo_ponte)
        {
            this->inicializacao();
        }

        Ponte::~Ponte() {

        }

        void Ponte::inicializacao() {
            if (tipo_ponte == 1) { //ponte pequena
                pAnimacaoEstatica->novaAnimacao("textura/Obstaculos/ponte.png", Ids::Ids::ponte, posicao, tamanho, Matematica::CoordenadaF(1.4f, 1.5f));
            }
            else if (tipo_ponte == 2) { //ponte grande
                tamanho = Matematica::CoordenadaF(TAMANHO_PONTE_GRANDE_X, TAMANHO_PONTE_Y);
                pAnimacaoEstatica->novaAnimacao("textura/Obstaculos/ponte.png", Ids::Ids::ponte, posicao, tamanho, Matematica::CoordenadaF(3.8f, 1.5f));
            }
            else {
                std::cout << "ERRO: tipo de ponte invalida!" << std::endl;
            }
        }

        void Ponte::atualizar() {
            pAnimacaoEstatica->atualizar(Ids::Ids::ponte, posicao);
            pAnimacaoEstatica->renderizar();
        }
    }
}