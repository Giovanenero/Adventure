#pragma once

#include "Fase.h"
#include "Obstaculo.h"

namespace Fase {

    class FaseFloresta : public FaseGenerica
    {
    public:
        FaseFloresta();
        ~FaseFloresta() override;

        void init();
        void executar();
        void atualizar(const float tempo) {
            //???
        }
    };
} // namespace Fase
