#include "Fase.h"

namespace Fase {
    Fase::Fase() :
        Ente(Ids::Ids::fase_floresta),
        pEvento(), 
        pGrafico(), 
        ListaEntidadeEstatica(), 
        ListaEntidadeMovimento(),
        pOriana(new Entidade::Personagem::Jogador::Oriana(Matematica::CoordenadaF(200.0f, 0.0f))),
        pHideo(new Entidade::Personagem::Jogador::Hideo(Matematica::CoordenadaF(200.0f, 0.0f))),
        pColisao(),
        fundo(nullptr)
    { 
        
    }

    Fase::~Fase() {
        /*
        if (ListaEntidadeEstatica) {
            delete(ListaEntidadeEstatica);
            ListaEntidadeEstatica = nullptr;
        }
        if (ListaEntidadeMovimento) {
            delete(ListaEntidadeMovimento);
            ListaEntidadeMovimento = nullptr;
        }
        */
        if (pColisao) {
            delete(pColisao);
            pColisao = nullptr;
        }
        /*
        if (pOriana) {
            delete(pOriana);
            pOriana = nullptr;
        }
        if (fundo) {
            delete(fundo);
            fundo = nullptr;
        }
        if (pHideo) {
            delete(pHideo);
            pHideo = nullptr;
        }
        */
        /*
        if (pGrafico) {
            delete(pGrafico);
            pGrafico = nullptr;
        }
        */
        if (pEvento) {
            delete(pEvento);
            pEvento = nullptr;
        }
    }
} //namespace Fase