#pragma once

#include "Goblin.h"
#include "Atirador.h"

#define DISTANCIA_PROJETIL_GOBLIN 500.f

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            class AtiraGoblin: public Goblin, public Atirador
            {
            public:
                AtiraGoblin(Matematica::CoordenadaF posInicio, Jogador::Oriana* pOriana, Lista::ListaEntidade* ListaEntidadeMovimento);
                ~AtiraGoblin();
                void inicializacao();
                void atualizar(const float tempo);
                void atualizarImagem(const float tempo);
            };
        }
    }
}

