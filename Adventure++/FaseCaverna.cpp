#include "FaseCaverna.h"
#include "Principal.h"
#include "Obstaculo.h"

namespace Fase {

    FaseCaverna::FaseCaverna(Principal *principal):
            Fase(), Estados::Estado(static_cast<Estados::MaquinaEstados*>(principal), Estados::IDestado::jogandoCaverna)
    {
        pEvento = Gerenciador::GerenciadorEvento::getGerenciadorEvento();
        pGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
        ListaEntidadeEstatica = new Lista::ListaEntidade();
        ListaEntidadeMovimento = new Lista::ListaEntidade();
        pOriana = new Entidade::Personagem::Jogador::Oriana(Matematica::CoordenadaF(200.0f, 200.0f));
        pHideo = new Entidade::Personagem::Jogador::Hideo(Matematica::CoordenadaF(200.0f, 200.0f));
        pColisao = new Gerenciador::GerenciadorColisao(ListaEntidadeEstatica, ListaEntidadeMovimento);
        fundo = new Fundo(Ids::Ids::fase_caverna);
    }

    FaseCaverna::~FaseCaverna() { }

    void FaseCaverna::init() {

        if (iniciou) {
            return;
        }
        iniciou = true;
        //teste...
        if (doisJogadores) {
            pEvento->setJogadores(pOriana, pHideo);
        } else {
            if (pHideo)
                delete pHideo;
            pHideo = nullptr;
            pEvento->setJogadores(pOriana, nullptr);
        }

        ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(pOriana));
        if (doisJogadores) {
            ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade *>(pHideo));
        }

        srand(time(NULL));
        for (int i = 0; i < 15; i++) { //CHAO
            Matematica::CoordenadaF pos(i * 800.0f, 350.0f);
            Entidade::Obstaculo::Plataforma* plataforma = new Entidade::Obstaculo::Plataforma(pos);
            ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma));
        }
        for (int i = 0; i < 4; i++) {
            ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(600.0f, -50.0f * i), 6));

            ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(1000.0f, -50.0f * i), 6));
            ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(1600.0f, -50.0f * i), 6));

            ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(1650.0f + (50.0f * i), 0.0f), 11));

            ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(2400.0f, -50.0f * i), 6));
            ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(2850.0f, -50.0f * i), 6));

            ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(3600.0f, -50.0f * i), 6));
            ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(3350.0f, -50.0f * i), 6));

            ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(4000.0f, -50.0f * i), 6));
            ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(4000.0f, -50.0f * (i + 5)), 6));
            ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(3800.0f, -50.0f * i), 6));
        
            ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(4600.0f, -50.0f * i), 6));
            
            ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(4500.0f + 2100.0f, -50 * i), 6));
            ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(4500.0f + 2100.0f + 1000.0f, -50 * i), 6));
        }
        ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(4500.0f + 2100.0f, -50 * 5), 7));
        ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(4500.0f + 2100.0f + 1000.0f, -50 * 5), 7));
        ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(1000.0f + 300.0f, -50.0f * 5), 8));
        ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(2400.0f + 300.0f, -50.0f * 5), 8));
        ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(3400.0f, -50 * 5), 10));
        ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(3250.0f, -50.0f), 10));
        ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(3660.0f, -50.0f * 12), 10));
        ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(3600.0f, -50 * 7), 7));
        ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(4000.0f, -50 * 12), 7));
        ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(4600.0f, -50 * 5), 7));
        for (int i = 0; i < 2; i++) {
            ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(3600.0f, -50 * (i + 5)), 6));
            ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(2600.0f, -50.0f * (i + 6)), 9));
        
            ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(4400.0f, -50 * i), 6));
        
            ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(4500.0f + 1900.0f, 0.0f), 6));
        }
        //cria instancias aleatoriamente
        for (int i = 0; i < 5 + (rand() % 20); i++) {
            short tipo_obstaculo = (rand() % 3) + 9;
            for (int j = 0; j < rand() % 5; j++) {
                short tipo_inimigo = rand() % 4;
                ListaEntidadeMovimento->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(float(rand() % 7000) + 500.0f, -50.f * 12), tipo_inimigo));
            }
            ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(float(rand() % 2000) + 4500.0f, -50.f * i), tipo_obstaculo));
        }
        //boss noturno
        ListaEntidadeMovimento->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(7000.0f, 0.0f), 5));
    }
    void FaseCaverna::executar() { }

    void FaseCaverna::atualizar(const float tempo) {
        Matematica::CoordenadaF pos;
        Entidade::Personagem::Jogador::Jogador *j;
        tempoTroca += tempo;
        if (pOriana) {
            j = pOriana;
        } else {
            j = pHideo;
        }

        if (j->getPosicao().y < 315.f) {
            pos.operator=(Matematica::CoordenadaF(j->getPosicao().x, j->getPosicao().y));
        }
        else {
            pos.operator=(Matematica::CoordenadaF(j->getPosicao().x, 315.0f));
        }
        fundo->atualizar(pos);
        pGrafico->centralizarCamera(pos);

        for (int i = 0; i < (int)ListaEntidadeEstatica->getTamanho(); i++) {
            Entidade::Obstaculo::Obstaculo* aux = static_cast<Entidade::Obstaculo::Obstaculo*>(ListaEntidadeEstatica->operator[](i));
            aux->atualizar(tempo);
        }
        //float tempo = pGrafico->atualizartempo();
        int i = 0;
        int tam = (int)ListaEntidadeMovimento->getTamanho();
        while (i < tam) {
            Entidade::Entidade* pEnt = ListaEntidadeMovimento->operator[](i);
            if (pEnt != nullptr) {
                pEnt->atualizar(tempo);
                if (pEnt->podeRemover()) {
                    ListaEntidadeMovimento->removerEntidade(pEnt);
                    //delete(pEnt);
                    //pEnt = nullptr;
                    tam = (int)ListaEntidadeMovimento->getTamanho();
                }
            }
            i++;
        }
        pColisao->Colisao();
    }

    void FaseCaverna::renderizar() {

    }

    void FaseCaverna::resetEstado() {
        init();
        pEvento->setJogadores(pOriana, pHideo);
    }
} //namespace Fase
