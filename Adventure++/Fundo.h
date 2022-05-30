#pragma once
#include "EntidadeEstatica.h"

namespace Entidade {
    class Fundo :
        public EntidadeEstatica
    {
    public:
        Fundo(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id);
        ~Fundo();
        void inicializacao();
        void atualizar();
    };
}

