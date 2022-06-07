#include "MenuColocacao.h"
#include "GerenciadorEvento.h"

#include <fstream>
#include <sstream>

#define LEADERBOARD_PATH "saves/colocacao.txt"

namespace Estados {

    MenuColocacao::MenuColocacao(Estados::MaquinaEstados *pSM) :
            Menu(),
            Estados::Estado(pSM, Estados::IDestado::colocacao) {
        //Gerenciador::GerenciadorGrafico *GM = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
        ElementoGrafico::Botao *bt = NULL;

        bt = new ElementoGrafico::Botao(Matematica::CoordenadaF(600, 300), "MENU PRINCIPAL");
        bt->selecionar(true);
        vectorBotoes.push_back(bt);

        max = 0;
    }

    MenuColocacao::~MenuColocacao() {
    }

    void MenuColocacao::atualizar(float dt) {
        ativo = true;
    }

/* Menu operation to render all it's objects. */
    void MenuColocacao::renderizar() {
        //atualizarVisao();
        //back.render();
        for (it = vectorBotoes.begin(); it != vectorBotoes.end(); ++it)
            (*it)->renderizar();

        for (itr = allPoints.begin(); itr != allPoints.end(); ++itr)
            (*itr)->renderizar();
    }

    void MenuColocacao::executar() {
        if (ativo) {
            ativo = false;
            mudarEstado(Estados::IDestado::menuPrincipal);
        }
    }

    void MenuColocacao::resetEstado() {
        vectorBotoes[0]->selecionar(true);
        for (itr = allPoints.begin(); itr != allPoints.end(); ++itr)
            delete (*itr);
        allPoints.clear();
        criarColocacao();
        Gerenciador::GerenciadorEvento::getGerenciadorEvento()->setMenu(this);
    }

    void MenuColocacao::criarColocacao() {
        std::ifstream file;

        file.open(LEADERBOARD_PATH, std::ios::binary | std::ios::in);

        if (!file) {
            std::ofstream writeFile(LEADERBOARD_PATH, std::ios::out | std::ios::trunc);
            writeFile.close();
        }

        std::string str;
        std::string nome;
        std::string word;

        ElementoGrafico::Texto *txt;

        for (int i = 0; i < 5; i++) {
            str = "";

            std::getline(file, str);
            if (str.empty()) {
                break;
            }
            std::istringstream iss(str);

            iss >> word;
            nome = word;
            iss >> word;
            //points = std::stoi(word);

            str = nome + " -- " + word;
            txt = new ElementoGrafico::Texto(Matematica::CoordenadaF(200, 100.f + 40.f * i), str);
            txt->setTamanhoFonte(38);
            txt->setAlinhamento(ElementoGrafico::AlinhamentoTexto::centro);
            txt->setCor(77, 68, 44);
            allPoints.push_back(txt);
        }

        for (int i = 0; i < 5; i++) {   //para pontuacao da segunda fase
            str = "";

            std::getline(file, str);
            if (str.empty()) {
                break;
            }
            std::istringstream iss(str);

            iss >> word;
            nome = word;
            iss >> word;
            //points = std::stoi(word);

            str = nome + " -- " + word;
            txt = new ElementoGrafico::Texto(Matematica::CoordenadaF(600, 100.f + 40.f * i), str);
            txt->setTamanhoFonte(38);
            txt->setAlinhamento(ElementoGrafico::AlinhamentoTexto::centro);
            txt->setCor(77, 68, 44);
            allPoints.push_back(txt);
        }

        file.close();
    }
}
