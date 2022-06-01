#pragma once

#define VIDA_GOBLIN 100
#define DANO_GOBLIN 20
#define DANO_GOBLIN_PROJETIL 20
#define TAMANHO_GOBLIN_X 50
#define TAMANHO_GOBLIN_Y 70
#define VELOCIDADE_GOBLIN_X 80.0f
#define VELOCIDADE_GOBLIN_Y 80.0f
#define DISTANCIA_GOBLIN_RECONHECER_X 400.0f
#define DISTANCIA_GOBLIN_RECONHECER_Y 100.0f

#include "Inimigo.h"
//#include "Oriana.h"

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            class Goblin: public Inimigo
            {
            protected:
                short mudarAtaque = rand() % 2;
            public:
                Goblin(Matematica::CoordenadaF posInicio, Jogador::Oriana* pOriana, Ids::Ids id);
                ~Goblin();
                void inicializacao();
                virtual void atualizarImagem(const float tempo) = 0;

                const float getVelocidadeEspecifica() const {
                    return VELOCIDADE_GOBLIN_X;
                }
            };
        }
    }
}

