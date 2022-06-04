#pragma once
#include "Jogador.h"

namespace Entidade {
    namespace Personagem {
        namespace Jogador {
            class Hideo: public Jogador
            {
            private:
                //teste...
                short mudarAtaque = rand() % 3;
            public:
                Hideo(Matematica::CoordenadaF posInicio);
                ~Hideo();
                void inicializacao();
                void atualizarImagem(const float tempo);
            };
        }
    }
}

