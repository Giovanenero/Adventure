#include "Fase.h"

namespace Fase {
    FaseGenerica::FaseGenerica() : 
        Ente(Ids::Ids::fase_floresta),
        pEvento(), 
        pGrafico(), 
        ListaEntidadeEstatica(), 
        ListaEntidadeMovimento(),
        pOriana(new Entidade::Personagem::Jogador::Oriana(Matematica::CoordenadaF(200.0f, 0.0f))),
        pColisao(),
        fundo(nullptr)
    { }

    FaseGenerica::~FaseGenerica() {
        if (ListaEntidadeEstatica) {
            delete(ListaEntidadeEstatica);
            ListaEntidadeEstatica = nullptr;
        }
        if (ListaEntidadeMovimento) {
            delete(ListaEntidadeMovimento);
            ListaEntidadeMovimento = nullptr;
        }
        if (pColisao) {
            delete(pColisao);
            pColisao = nullptr;
        }
        if (pOriana) {
            delete(pOriana);
            pOriana = nullptr;
        }
        if (fundo) {
            delete(fundo);
            fundo = nullptr;
        }
    }
} //namespace Fase