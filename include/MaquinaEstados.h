#pragma once

#include "Estado.h"
#include <map>

namespace Estados {
    //Baseado em tutorial de Matheus Burda: https://www.youtube.com/watch?v=2vFLfO-PKcw&list=PLSPev71NbUEBIQlT2QCd-gN6l_mNVw1cJ&index=13
    class MaquinaEstados {
    protected:
        Estados::IDestado IDatual;
        Estados::IDestado IDultimo;

        std::map<IDestado, Estado*> mapaEstados;

    public:
        MaquinaEstados();

        virtual ~MaquinaEstados();

        void mudarEstadoAtual(Estados::IDestado id);

        void atualizarEstadoAtual(const float dt);

        void renderizarEstadoAtual();

        Estados::IDestado getIDEstadoAtual() const;

        void inserirEstado(Estados::Estado *pState);

        Estados::IDestado getIDUltimoEstado() const;
    };
}