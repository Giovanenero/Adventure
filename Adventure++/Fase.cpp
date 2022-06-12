#include "Fase.h"

#define TEMPO_TROCA_MIN 5

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
        tempoTroca(60) { }

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

    Entidade::Entidade* Fase::instaciaEntidade(Matematica::CoordenadaF pos, short tipo) {
        switch (tipo)
        {
            case 0:
            {
                Entidade::Personagem::Inimigo::AtiraGoblin* a = new Entidade::Personagem::Inimigo::AtiraGoblin(pos, pOriana, pHideo, ListaEntidadeMovimento);
                return static_cast<Entidade::Entidade*>(a);
            }
            case 1:
            {
                Entidade::Personagem::Inimigo::BateGoblin* a = new Entidade::Personagem::Inimigo::BateGoblin(pos, pOriana, pHideo);
                return static_cast<Entidade::Entidade*>(a);
            }
            case 2:
            {
                Entidade::Personagem::Inimigo::AtiraEsqueleto* a = new Entidade::Personagem::Inimigo::AtiraEsqueleto(pos, pOriana, pHideo, ListaEntidadeMovimento);
                return static_cast<Entidade::Entidade*>(a);
                break;
            }
            case 3:
            {
                Entidade::Personagem::Inimigo::BateEsqueleto* a = new Entidade::Personagem::Inimigo::BateEsqueleto(pos, pOriana, pHideo);
                return static_cast<Entidade::Entidade*>(a);
            }
            case 4: 
            {
                Entidade::Personagem::Inimigo::Animagus* a = new Entidade::Personagem::Inimigo::Animagus(pos, pOriana, pHideo);
                return static_cast<Entidade::Entidade*>(a);
            }
            case 5:
            {
                Entidade::Personagem::Inimigo::Noturno* a = new Entidade::Personagem::Inimigo::Noturno(pos, pOriana, pHideo);
                return static_cast<Entidade::Entidade*>(a);
            }
            case 6:
            {
                Entidade::Obstaculo::Andaime* a = new Entidade::Obstaculo::Andaime(pos);
                return static_cast<Entidade::Entidade*>(a);
            }
            case 7:
            {
                Entidade::Obstaculo::Ponte* a = new Entidade::Obstaculo::Ponte(pos, 1);
                return static_cast<Entidade::Entidade*>(a);
            }
            case 8:
            {
                Entidade::Obstaculo::Ponte* a = new Entidade::Obstaculo::Ponte(pos, 2);
                return static_cast<Entidade::Entidade*>(a);
            }
            case 9:
            {
                Entidade::Obstaculo::Caixa* a = new Entidade::Obstaculo::Caixa(pos);
                return static_cast<Entidade::Entidade*>(a);
            }
            case 10: 
            {
                Entidade::Obstaculo::Pedra* a = new Entidade::Obstaculo::Pedra(pos);
                return static_cast<Entidade::Entidade*>(a);
            }
            case 11:
            {
                Entidade::Obstaculo::Espinhos* a = new Entidade::Obstaculo::Espinhos(pos);
                return static_cast<Entidade::Entidade*>(a);
            }
            default:
                break;
            }
        return nullptr;
    }
} //namespace Fase