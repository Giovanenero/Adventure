#pragma once

#define VIDA_GOBLIN 100
#define DANO_GOBLIN 20
#define TAMANHO_GOBLIN_X 50
#define TAMANHO_GOBLIN_Y 70
#define VELOCIDADE_GOBLIN_X 80.0f
#define VELOCIDADE_GOBLIN_Y 80.0f
#define DISTANCIA_GOBLIN_RECONHECER_X 200.0f
#define DISTANCIA_GOBLIN_RECONHECER_Y 150.0f

#include "Inimigo.h"
//#include "Oriana.h"

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            class Goblin: public Inimigo
            {
            private:
                short mudarAtaque = rand() % 2;
            public:
                Goblin(Matematica::CoordenadaF posInicio, Jogador::Oriana* pOriana);
                ~Goblin();
                void inicializacao();
                void atualizarImagem(const float tempo);
                void executar();
                const float getVelocidadeEspecifica() const {
                    return VELOCIDADE_GOBLIN_X;
                }
            };
        }
    }
}

