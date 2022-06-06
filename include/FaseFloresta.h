#pragma once

#include "Fase.h"
#include "Obstaculo.h"
#include "Estado.h"

namespace Fase {

class FaseFloresta : public Fase, public Estados::Estado
    {
    public:
        FaseFloresta(Principal *principal);
        ~FaseFloresta() override;

        void init();
        void executar();
        void atualizar(const float tempo);
        void renderizar();
        void resetEstado();
    };
} // namespace Fase
