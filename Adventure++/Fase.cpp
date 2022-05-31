#include "Fase.h"

namespace Fase {
    FaseGenerica::FaseGenerica() : 
        Ente(Ids::Ids::fase_floresta),
        pEvento(), 
        pGrafico(), 
        ListaEntidadeEstatica(), 
        ListaEntidadeMovimento(),
        pOriana(new Entidade::Personagem::Jogador::Oriana(Matematica::CoordenadaF(200.0f, 0.0f))),
        pPascal(new Entidade::Personagem::Inimigo::Pascal(Matematica::CoordenadaF(600.0f, 0.0f), pOriana)),
        pColisao() { }

    FaseGenerica::~FaseGenerica() {
        if (pOriana) {
            delete(pOriana);
            pOriana = nullptr;
        }
        if (pPascal) {
            delete(pPascal);
            pPascal = nullptr;
        }
    }
} //namespace Fase