#include "FaseFloresta.h"

namespace Fase {

    FaseFloresta::FaseFloresta():
        FaseGenerica()
    {
        pEvento = Gerenciador::GerenciadorEvento::getGerenciadorEvento();
        pGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
        ListaEntidadeEstatica = new Lista::ListaEntidade();
        ListaEntidadeMovimento = new Lista::ListaEntidade();
        pOriana = new Entidade::Personagem::Jogador::Oriana(Matematica::CoordenadaF(200.0f, 200.0f));
        pColisao = new Gerenciador::GerenciadorColisao(ListaEntidadeEstatica, ListaEntidadeMovimento);
        fundo = new Fundo(Ids::Ids::fase_floresta, static_cast<Entidade::Entidade*>(pOriana));
    }

    FaseFloresta::~FaseFloresta() { }

    void FaseFloresta::init() {
        //teste...
        Entidade::Personagem::Jogador::Hideo* pHideo = new Entidade::Personagem::Jogador::Hideo(Matematica::CoordenadaF(200.0f, 200.0f));
        pEvento->setJogadores(pOriana, pHideo);

        ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(pOriana));
        ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(pHideo));

        //arrumar ineficiente...
        Matematica::CoordenadaF tam(100.0f, 30.0f);
        srand(time(NULL));
        for (int i = 0; i < 10; i++) {
            if (i != 6 && i != 7) {
                Matematica::CoordenadaF pos(i * 100.0f, 350.0f);
                Entidade::Obstaculo::Plataforma* plataforma = new Entidade::Obstaculo::Plataforma(pos, tam);
                ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma));
            }
        }

        for (int i = 0; i < 2; i++) {
            Matematica::CoordenadaF pos3(200.f * (i + 1), 220.f);
            Entidade::Obstaculo::Plataforma* plataforma3 = new Entidade::Obstaculo::Plataforma(pos3, tam);
            ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma3));
        }

        Matematica::CoordenadaF pos3(500.f, 100.f);
        Entidade::Obstaculo::Plataforma* plataforma4 = new Entidade::Obstaculo::Plataforma(pos3, tam);
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma4));

        Matematica::CoordenadaF pos4(700.f, 100.f);
        Entidade::Obstaculo::Plataforma* plataforma5 = new Entidade::Obstaculo::Plataforma(pos4, tam);
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma5));


        for (int i = 0; i < 10; i++) {
            Matematica::CoordenadaF pos5(100.0f * i, 600.f);
            Entidade::Obstaculo::Plataforma* plataforma6 = new Entidade::Obstaculo::Plataforma(pos5, tam);
            ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma6));
        }

        Matematica::CoordenadaF pos5(-150.f, 480.f);
        Entidade::Obstaculo::Plataforma* plataforma7 = new Entidade::Obstaculo::Plataforma(pos5, tam);
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma7));

        Entidade::Obstaculo::Espinhos* pAux = new Entidade::Obstaculo::Espinhos(Matematica::CoordenadaF(200.0f, 330.0f));
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(pAux));
        
        Entidade::Obstaculo::Pedra* pPedra = new Entidade::Obstaculo::Pedra(Matematica::CoordenadaF(100.0f, 600.0f - 50.0f));
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(pPedra));
        
        /*
        Matematica::CoordenadaF pos3(1100.f, 250.f);
        Entidade::Obstaculo::Plataforma* plataforma5 = new Entidade::Obstaculo::Plataforma(pos3, tam, Ids::Ids::plataforma);
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma5));

        */

        /*
        for (int i = 0; i < 2; i++) {
            Entidade::Personagem::Inimigo::AtiraGoblin* pAtiraGoblin = new Entidade::Personagem::Inimigo::AtiraGoblin(Matematica::CoordenadaF((float)(rand()%1000), 100.f), pOriana, ListaEntidadeMovimento);
            ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(pAtiraGoblin));
        }
        */
        for (int i = 0; i < 5; i++) {
            Entidade::Personagem::Inimigo::AtiraEsqueleto* pAtiraEsqueleto = new Entidade::Personagem::Inimigo::AtiraEsqueleto(Matematica::CoordenadaF((float)(rand() % 1000), 100.f), pOriana, pHideo, ListaEntidadeMovimento);
            ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(pAtiraEsqueleto));
        }

        /*
        for (int i = 0; i < 2; i++) {
            Entidade::Personagem::Inimigo::BateGoblin* pBateGoblin = new Entidade::Personagem::Inimigo::BateGoblin(Matematica::CoordenadaF((float)(rand()%1000), 100.0f), pOriana, pHideo);
            ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(pBateGoblin));
        }
        for (int i = 0; i < 2; i++) {
            Entidade::Personagem::Inimigo::BateEsqueleto* pBateEsqueleto = new Entidade::Personagem::Inimigo::BateEsqueleto(Matematica::CoordenadaF((float)(rand()%1000), 100.f), pOriana, pHideo);
            ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(pBateEsqueleto));
        }
        */
        /*
        for (int i = 0; i < 2; i++) {
            Entidade::Personagem::Inimigo::Animagus* pAnimagus = new Entidade::Personagem::Inimigo::Animagus(Matematica::CoordenadaF((float)(rand() % 1000), 100.f), pOriana, pHideo);
            ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(pAnimagus));
        }
        */
        
    }
    void FaseFloresta::executar() {
        while (pGrafico->isWindowOpen()) {
            float tempo = pGrafico->atualizartempo();
            pEvento->pollEvents();
            pGrafico->limpar();

            //arrumar... ineficiente
            fundo->atualizar();
            for (int i = 0; i < (int)ListaEntidadeEstatica->getTamanho(); i++) {
                Entidade::Obstaculo::Obstaculo* aux = static_cast<Entidade::Obstaculo::Obstaculo*>(ListaEntidadeEstatica->operator[](i));
                aux->atualizar();
            }

            int i = 0;
            int tam = (int)ListaEntidadeMovimento->getTamanho();
            while (i < tam) {
                Entidade::Entidade* pEnt = ListaEntidadeMovimento->operator[](i);
                if (pEnt != nullptr) {
                    pEnt->atualizar(tempo);
                    if (pEnt->podeRemover()) {
                        pEnt = ListaEntidadeMovimento->removerEntidade(pEnt);
                        //delete(pEnt);
                        //pEnt = nullptr;
                        tam = (int)ListaEntidadeMovimento->getTamanho();
                    }
                }
                i++;
            }
            
            pGrafico->centralizarCamera(pOriana->getPosicao());

            pColisao->Colisao();
            pGrafico->mostrar();
        }
    }
} //namespace Fase
