#pragma once

#include "Estado.h"
#include "Fase.h"

namespace Fase {

    class FaseCaverna : public Fase, public Estados::Estado
    {
    public:
        FaseCaverna(Principal *principal);
        ~FaseCaverna() override;

        void init();
        void executar();
        void atualizar(const float tempo);
        void renderizar();
        void resetEstado();

    };

}