#pragma once

#include "Obstaculo.h"

namespace Entidade {
    namespace Obstaculo {
        class Fundo : public Obstaculo
        {
        public:
            Fundo(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id);
            ~Fundo();
            void inicializacao();
            void atualizar();
            void executar();
        };
    } //namespace Obstaculo
} //namespace Entidade

