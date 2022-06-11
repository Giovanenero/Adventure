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

        //arrumar ineficiente...
        //Matematica::CoordenadaF tam(100.0f, 30.0f);


        srand(time(NULL));
        for (int i = 0; i < 50; i++) { //CHAO
            Matematica::CoordenadaF pos(i * 100.0f, 350.0f);
            Entidade::Obstaculo::Plataforma* plataforma = new Entidade::Obstaculo::Plataforma(pos);
            ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma));
        }

        int pedras = rand() % 15 + 3; // ao menos 3 pedras obstaculos e espinhos
        for (int i = 0; i < pedras; i++) {
            Entidade::Obstaculo::Pedra *pe1 = new Entidade::Obstaculo::Pedra(Matematica::CoordenadaF(((rand() % 4) * 100.f) + 400.0f + ((rand() % 5) * 400.0f), 250.0f - 50.0f));
            ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade *>(pe1));

            Entidade::Obstaculo::Espinhos* esp = new Entidade::Obstaculo::Espinhos(Matematica::CoordenadaF(650.0f + ((rand() % 4) * 100.f) + ((rand() % 7) * 400.0f), 100.f));
            ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(esp));
        }

        Entidade::Obstaculo::Pedra* pe2 = new Entidade::Obstaculo::Pedra(Matematica::CoordenadaF((8 * 100.f) + 500.0f, 350.0f - 50.0f));
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(pe2));

        for (int i = 0; i < 4; i++) {
            Entidade::Obstaculo::Andaime *pAndEsq = new Entidade::Obstaculo::Andaime(Matematica::CoordenadaF(200.0f - 100.0f, 350.0f - 50.0f - i*50.f));
            ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade *>(pAndEsq));
        }

        for (int i = 0; i < 2; i++) {
            Matematica::CoordenadaF pos(i * 100.0f, 350.0f - 50.0f - 3*50.f);
            Entidade::Obstaculo::Ponte* plataforma = new Entidade::Obstaculo::Ponte(pos, 1);
            ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma));
        }

        int atiradores = rand() % 6 + 3; //ao menos 3 bate atiradores
        for (int i = 0; i < atiradores; i++) {
            Entidade::Personagem::Inimigo::AtiraEsqueleto* pAtiraEsqueleto = new Entidade::Personagem::Inimigo::AtiraEsqueleto(Matematica::CoordenadaF((float)(rand() % 5000), 150.0f), pOriana, pHideo, ListaEntidadeMovimento);
            ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(pAtiraEsqueleto));
        }

        int esq = rand() % 15 + 3; // ao menos 3 bate esqueletos
        for (int i = 0; i < esq; i++) {
            Entidade::Personagem::Inimigo::BateEsqueleto* pBateEsqueleto = new Entidade::Personagem::Inimigo::BateEsqueleto(Matematica::CoordenadaF((float)(rand()%5000), 50.f), pOriana, pHideo);
            ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(pBateEsqueleto));
        }

        for (int i = 0; i < 4; i++) {
            Entidade::Obstaculo::Andaime* a = new Entidade::Obstaculo::Andaime(Matematica::CoordenadaF(1200.0f - 300.0f, 100.0f - 50.f*(i + 1)));
            ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(a));

            Entidade::Obstaculo::Andaime* b = new Entidade::Obstaculo::Andaime(Matematica::CoordenadaF(1200.0f + 300.0f, 100.0f - 50.0f* (i + 1)));
            ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(b));
        }

        Entidade::Obstaculo::Ponte* ponte = new Entidade::Obstaculo::Ponte(Matematica::CoordenadaF(1200.0f, 100.0f - 50.0f * 4 - 20.0f), 2);
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(ponte));

        //boss
        Entidade::Personagem::Inimigo::Noturno* noturno = new Entidade::Personagem::Inimigo::Noturno(Matematica::CoordenadaF(4500, 100.f), pOriana, pHideo);
        ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(noturno));

        //mais plataforma para pular
        for (int i = 0; i < 4; i++) {
            Entidade::Obstaculo::Andaime* a = new Entidade::Obstaculo::Andaime(Matematica::CoordenadaF(3200.0f - 300.0f, 100.0f - 50.f*(i + 1)));
            ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(a));

            Entidade::Obstaculo::Andaime* b = new Entidade::Obstaculo::Andaime(Matematica::CoordenadaF(3200.0f + 300.0f, 100.0f - 50.0f* (i + 1)));
            ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(b));
        }

        Entidade::Obstaculo::Ponte* ponte2 = new Entidade::Obstaculo::Ponte(Matematica::CoordenadaF(3200.0f, 100.0f - 50.0f * 4 - 20.0f), 2);
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(ponte2));

        for (int i = 0; i < 4; i++) {
            Entidade::Obstaculo::Andaime* a = new Entidade::Obstaculo::Andaime(Matematica::CoordenadaF(3300.0f - 300.0f, -110.f - 50.f*(i + 1)));
            ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(a));

        }


        //bloqueio final da fase para nao cair
        for (int i = 0; i < 4; i++) {
            Entidade::Obstaculo::Andaime *pAndEsq = new Entidade::Obstaculo::Andaime(Matematica::CoordenadaF(4800.f, 350.0f - 50.0f - i*50.f));
            ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade *>(pAndEsq));
        }

        for (int i = 0; i < 2; i++) {
            Matematica::CoordenadaF pos(i * 100.0f + 4800.f, 350.0f - 50.0f - 3*50.f);
            Entidade::Obstaculo::Ponte* plataforma = new Entidade::Obstaculo::Ponte(pos, 1);
            ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma));
        }

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
