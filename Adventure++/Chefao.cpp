#include "Chefao.h"

#define TAMANHO_CHEFAO_X 100.0f
#define TAMANHO_CHEFAO_Y 100.0f
#define VIDA_CHEFAO 100
#define DANO_CHEFAO 20
#define VELOCIDADE_CHEFAO_X 80.0f
#define VELOCIDADE_CHEFAO_Y 80.0f
#define DISTANCIA_CHEFAO_RECONHECER_X 500.0f
#define DISTANCIA_CHEFAO_RECONHECER_Y 300.0f

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            Chefao::Chefao(Matematica::CoordenadaF posInicio, Jogador::Oriana* pOriana, Ids::Ids id) :
                Inimigo(posInicio,
                Matematica::CoordenadaF(TAMANHO_CHEFAO_X, TAMANHO_CHEFAO_Y),
                id, 
                pOriana, 
                Matematica::CoordenadaF(DISTANCIA_CHEFAO_RECONHECER_X, DISTANCIA_CHEFAO_RECONHECER_Y),
                VIDA_CHEFAO,
                DANO_CHEFAO),
                mudarAtaque(rand()%2)
            {
                //terminar...
            }
            Chefao::~Chefao() {

            }
            const float Chefao::getVelocidadeEspecifica() const {
                return VELOCIDADE_CHEFAO_X;
            }
        }
    }
}