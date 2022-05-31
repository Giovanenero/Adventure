#pragma once
#include "Inimigo.h"
#include "Oriana.h"

#define VIDA_PASCAL 100
#define DANO_PASCAL 10
#define TAM_X_PASCAL 60.0f
#define TAM_Y_PASCAL 60.0f
#define DANO_ATAQUE_PASCAL 20.0f;
#define VELOCIDADE_X_PASCAL 80.f
#define VELOCIDADE_Y_PASCAL 80.0f
#define DISTANCIA_PASCAL_RECONHECER_EIXO_X 200.0f
#define DISTANCIA_PASCAL_RECONHECER_EIXO_Y 150.0f

//Pascal eh um inimigo de pequeno porte e que esta presente em todas as fases

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            class Pascal : public Inimigo
            {
            public:
                Pascal(Matematica::CoordenadaF posInicio, Jogador::Oriana* pOriana);
                ~Pascal();
                void inicializacao();

                void atualizarImagem(const float tempo);
                void executar();

                //arrumar...
                const float getVelocidadeEspecifica() const {
                    return VELOCIDADE_X_PASCAL;
                }
            };
        }
    }
}

