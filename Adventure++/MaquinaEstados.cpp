#include "MaquinaEstados.h"
#include "Estado.h"
#include <iostream>

namespace Estados {

    MaquinaEstados::MaquinaEstados() {
        IDultimo = IDestado::desconhecido;
        IDatual = IDestado::desconhecido;
    }

    MaquinaEstados::~MaquinaEstados() {
        std::map<IDestado, Estado*>::iterator it;

        for (it = mapaEstados.begin(); it != mapaEstados.end(); ++it) {
            //teste...
            if (it->second) {
                delete (it->second);
            }
            //delete (it->second);
            //it->second = nullptr;
        }
    }

    void MaquinaEstados::mudarEstadoAtual(Estados::IDestado id) {
        IDultimo = IDatual;
        IDatual = id;
        mapaEstados[IDatual]->resetEstado();
    }

    void MaquinaEstados::atualizarEstadoAtual(const float dt) {
        mapaEstados[IDatual]->atualizar(dt);
    }

    void MaquinaEstados::renderizarEstadoAtual() {
        mapaEstados[IDatual]->renderizar();
    }

    IDestado MaquinaEstados::getIDEstadoAtual() const {
        return IDatual;
    }

    void MaquinaEstados::inserirEstado(Estados::Estado* pState) {
        if (pState == nullptr) {
            std::cout << "ERROR pointer to State NULL on StateMachine::inserirEstado()" << std::endl;
            exit(1);
        }
        mapaEstados.insert(std::pair<IDestado, Estado*>(pState->getID(), pState));
    }

    Estados::IDestado MaquinaEstados::getIDUltimoEstado() const {
        return IDultimo;
    }

} // namespace States