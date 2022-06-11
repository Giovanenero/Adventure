#pragma once

#include "Menu.h"
#include "Estado.h"
#include "Fase.h"
#include "Principal.h"

namespace Estados {

    class MenuPrincipal : public Menu, public Estados::Estado {
    private:
        ElementoGrafico::Texto titulo;
        IDestado ultimaFase;
        int pontos;
        bool iniciouFloresta;
        bool iniciouCaverna;
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