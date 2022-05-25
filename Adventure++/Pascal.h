#pragma once
#include "Inimigo.h"
#include "Oriana.h"

#define VIDA_PASCAL 20
#define TAM_X_PASCAL 60.0f
#define TAM_Y_PASCAL 40.0f
#define DANO_ATAQUE_PASCAL 20.0f;
#define VELOCIDADE_X_PASCAL 0.05f
#define VELOCIDADE_Y_PASCAL 0.0f

//Pascal eh um inimigo de pequeno porte e que esta presente em todas as fases

namespace Entidade {
    namespace Personagem {
        class Pascal: public Inimigo
        {
        public:
            Pascal(Matematica::CoordenadaF posInicio, Oriana* pOriana);
            ~Pascal();
            void andar(const bool paraEsquerda, const float tempo);
            void parar(const float tempo);
            void atacar(const float tempo);
            void inicializacao();
            void mover(const float tempo);
        };
    }
}

