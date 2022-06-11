#include "Fase.h"

namespace Fase {

    Fase::Fase() :
        Ente(Ids::Ids::fase_floresta),
        pEvento(), 
        pGrafico(), 
        ListaEntidadeEstatica(), 
        ListaEntidadeMovimento(),
        pOriana(),
        pHideo(),
        pColisao(),
        fundo(nullptr),
        iniciou(false),
        tempoTroca(60)
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

    void Fase::setDoisJogadores(bool dJ) {
        this->doisJogadores = dJ;
    }

    void Fase::trocarJogadores() {
        if (doisJogadores) return; //se for dois jogadores, nao trocamos, continua o principal
        if (tempoTroca < TEMPO_TROCA_MIN) return; //minimo de tempo para poder trocar personagem
        if (pOriana) {
            Matematica::CoordenadaF pos;
            pos = pOriana->getPosicao();
            ListaEntidadeMovimento->removerEntidade(pOriana);
            pOriana = nullptr;
            pHideo = new Entidade::Personagem::Jogador::Hideo(pos);
            ListaEntidadeMovimento->adicionarEntidade(pHideo);
        } else {
            Matematica::CoordenadaF pos;
            pos = pHideo->getPosicao();
            ListaEntidadeMovimento->removerEntidade(pHideo);
            pHideo = nullptr;
            pOriana = new Entidade::Personagem::Jogador::Oriana(pos);
            ListaEntidadeMovimento->adicionarEntidade(pOriana);
        }
        pEvento->setJogadores(pOriana, pHideo);
        tempoTroca = 0;
    }
} //namespace Fase