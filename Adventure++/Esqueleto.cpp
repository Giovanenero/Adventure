#include "Esqueleto.h"

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            Esqueleto::Esqueleto(Matematica::CoordenadaF posInicio, Jogador::Oriana* pOriana, Jogador::Hideo* pHideo, Ids::Ids id) :
                Inimigo(posInicio,
                Matematica::CoordenadaF(TAMANHO_ESQUELETO_X, TAMANHO_ESQUELETO_Y),
                id,
                pOriana,
                pHideo,
                Matematica::CoordenadaF(DISTANCIA_ESQUELETO_RECONHECER_X, DISTANCIA_ESQUELETO_RECONHECER_Y),
                VIDA_ESQUELETO,
                DANO_ESQUELETO) 
            { 
                this->inicializacao();
            }
            
            Esqueleto::~Esqueleto() {
            }
            void Esqueleto::inicializacao() {
                pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Esqueleto/esqueletoAndando.png", 4, Ids::Ids::esqueleto_anda, tamanho, Matematica::CoordenadaF(2.5f, 1.2f));
                pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Esqueleto/esqueletoDano.png", 4, Ids::Ids::esqueleto_tomaDano, tamanho, Matematica::CoordenadaF(2.5f, 1.2f));
                pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Esqueleto/esqueletoMorrendo.png", 4, Ids::Ids::esqueleto_morre, tamanho, Matematica::CoordenadaF(2.5f, 1.2f));
                pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Esqueleto/esqueletoParado.png", 4, Ids::Ids::esqueleto_para, tamanho, Matematica::CoordenadaF(2.5f, 1.2f));
            }   

            const float Esqueleto::getVelocidadeEspecifica() const {
                return VELOCIDADE_ESQUELETO_X;
            }
        }
    }
}