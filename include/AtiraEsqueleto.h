#pragma once
#include "Esqueleto.h"
#include "Atirador.h"

#define DISTANCIA_PROJETIL_ESQUELETO 300

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            class AtiraEsqueleto: public Esqueleto, public Atirador
            {
            public:
                AtiraEsqueleto(Matematica::CoordenadaF posInicio, Jogador::Oriana* pOriana, Jogador::Hideo* pHideo, Lista::ListaEntidade* ListaEntidadeMovimento);
                ~AtiraEsqueleto();
                void inicializacao();
                void atualizar(const float tempo);
                void atualizarImagem(const float tempo);
            };
        }
    }
}

