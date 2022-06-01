#pragma once

#include "Goblin.h"
#include "Projetil.h"
#include "ListaEntidade.h"

#define DISTANCIA_PROJETIL_GOBLIN 500.f

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            class AtiraGoblin: public Goblin
            {
            private:
                bool jaAtirou = false;
                Projetil* pProjetil;
                Lista::ListaEntidade* ListaEntidadeMovimento;
            public:
                AtiraGoblin(Matematica::CoordenadaF posInicio, Jogador::Oriana* pOriana, Lista::ListaEntidade* ListaEntidadeMovimento);
                ~AtiraGoblin();
                void inicializacao();
                void atualizar(const float tempo);
                void atualizarImagem(const float tempo);
                void colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade);
                void verificaProjetil();
            };
        }
    }
}

