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
            posicao += ((olharEsquerda) ? -getPosicao().x : getPosicao().x);
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
	}
}