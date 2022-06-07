#pragma once
#include "Chefao.h"

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            class Noturno: public Chefao
            {
            private:
            public:
                Noturno(Matematica::CoordenadaF posInicio, Jogador::Oriana* pOriana = nullptr, Jogador::Hideo* pHideo = nullptr);
                ~Noturno();
                void inicializacao();
                void atualizarImagem(const float tempo);
                const float getVelocidadeEspecifica() const;
                const short getPontuacao() const;
            };
        }
    }
}

