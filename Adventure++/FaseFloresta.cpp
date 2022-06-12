#include "FaseFloresta.h"
#include "Principal.h"

namespace Fase {

    FaseFloresta::FaseFloresta(Principal *principal):
            Fase(), Estados::Estado(static_cast<Estados::MaquinaEstados*>(principal), Estados::IDestado::jogandoFloresta)
    {
        pEvento = Gerenciador::GerenciadorEvento::getGerenciadorEvento();
        pGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
        ListaEntidadeEstatica = new Lista::ListaEntidade();
        ListaEntidadeMovimento = new Lista::ListaEntidade();
        pOriana = new Entidade::Personagem::Jogador::Oriana(Matematica::CoordenadaF(200.0f, 200.0f));
        pHideo = new Entidade::Personagem::Jogador::Hideo(Matematica::CoordenadaF(200.0f, 200.0f));
        pColisao = new Gerenciador::GerenciadorColisao(ListaEntidadeEstatica, ListaEntidadeMovimento);
        fundo = new Fundo(Ids::Ids::fase_floresta);
    }

    FaseFloresta::~FaseFloresta() { }

    void FaseFloresta::init() {

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
            ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(pHideo));
        }

        for (int i = 0; i < 15; i++) {
            Entidade::Obstaculo::Plataforma* plat = new Entidade::Obstaculo::Plataforma(Matematica::CoordenadaF(800.0f * i, 600.0f));
            ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plat));
        }
        
        for (int i = 0; i < 4; i++) {
            ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(600.0f, -50.0f * i), 6));
            ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(1200.0f, -50.0f * i), 6));

            ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(1400.0f, -50.0f * i), 6));
            ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(2000.0f, -50.0f * i), 6));

            ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(2200.0f, -50.0f * i), 6));
            ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(2800.0f, -50.0f * i), 6));

            ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(1700.0f, -50.0f * (i + 6)), 6));
            ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(2300.0f, -50.0f * (i + 6)), 6));

            ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(3400.0f, -50.0f * i), 6));
            
            ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(4500.0f, -50.0f * i), 6));
            
        }
        ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(600.0f + 300.0f, -50.0f * 5), 8));
        ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(1400.0f + 300.0f, -50.0f * 5), 8));
        ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(2200.0f + 300.0f, -50.0f * 5), 8));
        ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(1700.0f + 300.0f, -50.0f * 12), 8));
        ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(2800.0f, -50.0f * 6), 10));
        
        ListaEntidadeMovimento->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(1000.0f, -50.f * 6), 1));
        ListaEntidadeMovimento->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(1600.0f, -50.f * 6), 1));
        ListaEntidadeMovimento->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(1900.0f, -50.f * 21), 1));
        ListaEntidadeMovimento->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(1900.0f, -50.f * 21), 2));
        //ListaEntidadeMovimento->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(1000.0f, -50.f * 6), 1));

        for (int i = 0; i < 2; i++) {
            ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(400.0f, -50.0f * i), 9));
            ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(1500.0f, -50.0f * (i + 6)), 9));
            ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(3000.0f, -50.0f * i), 9));
        }
        ListaEntidadeMovimento->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(3300.0f, -50.0f), 3));
        ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(3200.0f, -50.0f), 10));
        ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(3400.0f, -50.0f * 10), 7));
        

        for (int i = 0; i < 3; i++) {
            ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(1250.0f + 50.0f * i, 0.0f), 11));
            ListaEntidadeMovimento->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(3550.0f + 50.0f * i, 0.0f), 11));
        }
        ListaEntidadeMovimento->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF(4200.0f, -200.0f), 5));

        for (int i = 0; i < rand() % 5; i++) {
            ListaEntidadeEstatica->adicionarEntidade(instaciaEntidade(Matematica::CoordenadaF((float(rand() % 400) + 3700.0f), 0.0f), 10));
        }
        iniciou = true;
    }
    void FaseFloresta::executar() { }

    void FaseFloresta::atualizar(const float tempo) {
        Matematica::CoordenadaF pos;
        Entidade::Personagem::Jogador::Jogador *j = nullptr;
        tempoTroca += tempo;

        if (pOriana) {
            j = pOriana;
        } else {
            j = pHideo;
        }

        if (j->getPosicao().y < 315.0f) {
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
        int i = 0;
        int tam = (int)ListaEntidadeMovimento->getTamanho();
        while (i < tam) {
            Entidade::Entidade* pEnt = ListaEntidadeMovimento->operator[](i);
            pEnt->atualizar(tempo);
            if (pEnt->podeRemover()) {
                ListaEntidadeMovimento->removerEntidade(pEnt);
                tam = (int)ListaEntidadeMovimento->getTamanho();
            }
            i++;
        }
        pColisao->Colisao();
    }

    void FaseFloresta::renderizar() {

    }

    void FaseFloresta::resetEstado() {
        //TODO: remover todas as entidades e resetar tudo antes de possivelmente reinicar a fase.
        pEvento->setJogadores(pOriana, pHideo);
        init();
    }
} //namespace Fase
