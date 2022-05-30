#pragma once

#include "Fase.h"

namespace Fase {

    class FaseFloresta : public FaseGenerica
    {
    public:
        FaseFloresta();
        ~FaseFloresta() override;

        void init();
    };
} // Fase
