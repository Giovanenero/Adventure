#include "Pascal.h"

namespace Entidade {
	namespace Personagem {
        Pascal::Pascal(Matematica::CoordenadaF posInicio, Oriana* pOriana):
            Inimigo(posInicio, 
            Matematica::CoordenadaF(TAM_X_PASCAL, TAM_Y_PASCAL), 
            Ids::Ids::pascal, 
            pOriana, 
            VIDA_PASCAL,
            Matematica::CoordenadaF(VELOCIDADE_X_PASCAL,VELOCIDADE_Y_PASCAL))
        {
            inicializacao();
        }
        Pascal::~Pascal() {

        }
        void Pascal::andar(const bool paraEsquerda, const float tempo) {
            olharEsquerda = paraEsquerda;
            this->tempo += tempo;
            Matematica::CoordenadaF escala(1.0f, 1.0f);
            pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::pascal_anda, escala);
            posicao += ((olharEsquerda) ? -getVelocidade().x : getVelocidade().x);
        }
        void Pascal::parar(const float tempo) {
            this->tempo += tempo;
            Matematica::CoordenadaF escala(1.0f, 1.0f);
            pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::pascal_para, escala);
        }
        void Pascal::atacar(const float tempo) {
            this->tempo += tempo;
            Matematica::CoordenadaF escala(1.0f, 1.0f);
            pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::pascal_ataca, escala);
        }
        void Pascal::inicializacao() {
            pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Pascal/pascalAndando.png", 6, Ids::Ids::pascal_anda);
            pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Pascal/pascalMorrendo.png", 4, Ids::Ids::pascal_morre);
            pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Pascal/pascalAtacando.png", 4, Ids::Ids::pascal_ataca);
            pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Pascal/pascalDano.png", 2, Ids::Ids::pascal_tomaDano);
            pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Pascal/pascalParado.png", 4, Ids::Ids::pascal_para);
        }
        void Pascal::mover(const float tempo) {
            if (pOriana == nullptr) {
                std::cout << "ponteiro pOriana vazio - classe Pascal.cpp" << std::endl;
                exit(1);
            }
            //teste...
            Matematica::CoordenadaF posJogador = pOriana->getPosicao();
            if (posJogador.x > posicao.x) {
                andar(false, tempo);
                if (posJogador.x < posicao.x) {
                    posicao.x = posJogador.x;
                }
            }
            else if (posJogador.x < posicao.x) {
                andar(true, tempo);
                if (posJogador.x > posicao.x) {
                    posicao.x = posJogador.x;
                }
            }
            else {
                atacar(tempo);
            }
            renderizar();
        }
	}
}