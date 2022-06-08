#pragma once

#include "Menu.h"
#include "Estado.h"
#include "Fase.h"
#include "Principal.h"

namespace Estados {

    class MenuPrincipal : public Menu, public Estados::Estado {
    private:
        Principal* pPrincipal;
        ElementoGrafico::Texto titulo;
        IDestado ultimaFase;
        int pontos;
    public:
        MenuPrincipal(Principal* principal);
        ~MenuPrincipal();
        void atualizar(const float dt);
        void renderizar();
        void resetEstado();
        virtual void executar();

        IDestado getUltimaFase();
        int getPontos();
    };
}