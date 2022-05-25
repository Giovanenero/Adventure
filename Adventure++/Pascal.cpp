#include "Pascal.h"

namespace Entidade {
	namespace Personagem {
        Pascal::Pascal(Matematica::CoordenadaF posInicio, Oriana* pOriana):
            Inimigo(posInicio, 
            Matematica::CoordenadaF(TAM_X_PASCAL, TAM_Y_PASCAL), 
            Ids::Ids::pascal, 
            pOriana, DISTANCIA_PASCAL_RECONHECER)
        {
            vida = VIDA_PASCAL;
            velocidade = Matematica::CoordenadaF(VELOCIDADE_X_PASCAL, VELOCIDADE_Y_PASCAL);
            inicializacao();
        }
        Pascal::~Pascal() {

        }
        void Pascal::inicializacao() {
            pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Pascal/pascalAndando.png", 6, Ids::Ids::pascal_anda);
            pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Pascal/pascalMorrendo.png", 4, Ids::Ids::pascal_morre);
            pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Pascal/pascalAtacando.png", 4, Ids::Ids::pascal_ataca);
            pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Pascal/pascalDano.png", 2, Ids::Ids::pascal_tomaDano);
            pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Pascal/pascalParado.png", 4, Ids::Ids::pascal_para);
        }
        void Pascal::atualizarImagem(const float tempo) {
            Matematica::CoordenadaF escala(2.0f, 2.0f);
            if (atacando) {
                pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::pascal_ataca, escala);
            }
            else if (andando) {
                pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::pascal_anda, escala);
            }
            else {
                pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::pascal_para, escala);
            }
        }
	}
}