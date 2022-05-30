#include "Fase.h"
#include "EntidadeEstatica.h"

Fase::FaseGenerica::FaseGenerica() : pEvento(), pGrafico(), ListaEntidadeEstatica(), ListaEntidadeMovimento(),
pOriana(new Entidade::Personagem::Oriana(Matematica::CoordenadaF(200.0f, 200.0f))),
pPascal(new Entidade::Personagem::Pascal(Matematica::CoordenadaF(600.0f, 200.0f), pOriana)),
pColisao() {

}

Fase::FaseGenerica::~FaseGenerica() {
    //arrumar...
    //delete pOriana;
    //delete pPascal;
}

void Fase::FaseGenerica::executar() {
    while (pGrafico->isWindowOpen()) {
        float tempo = pGrafico->atualizartempo();
        pEvento->pollEvents();
        pGrafico->limpar();

        //arrumar... ineficiente
        for (int i = 0; i < (int) ListaEntidadeEstatica->getTamanho(); i++) {
            Entidade::EntidadeEstatica *aux = static_cast<Entidade::EntidadeEstatica *>(ListaEntidadeEstatica->operator[](i));
            aux->atualizar();
        }

        for (int i = 0; i < (int) ListaEntidadeMovimento->getTamanho(); i++) {
            ListaEntidadeMovimento->operator[](i)->atualizar(tempo);
        }

        pColisao->Colisao();
        pGrafico->mostrar();
    }
}