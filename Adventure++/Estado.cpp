#include "Estado.h"
#include "MaquinaEstados.h"

namespace Estados {

    Estado::Estado(MaquinaEstados* pSM, Estados::IDestado id) :
            pSM(pSM),
            id(id) { }

    Estado::~Estado() {
        pSM = nullptr;
    }

    void Estado::setMaquinaEstado(MaquinaEstados* pSM) {
        this->pSM = pSM;
    }

    void Estado::mudarEstado(Estados::IDestado id) {
        pSM->mudarEstadoAtual(id);
    }

    Estados::IDestado Estado::getID() const {
        return id;
    }

} // namespace States