#include "MenuColocacao.h"
#include "MenuPrincipal.h"
#include "GerenciadorEvento.h"

#include <fstream>
#include <sstream>

#define CAMINHO_FLORESTA "saves/colocacaoFloresta.txt"
#define CAMINHO_CAVERNA "saves/colocacaoCaverna.txt"

namespace Estados {

    MenuColocacao::MenuColocacao(Estados::MaquinaEstados *pSM) :
            Menu(),
            Estados::Estado(pSM, Estados::IDestado::colocacao) {
        //Gerenciador::GerenciadorGrafico *GM = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
        ElementoGrafico::Botao *bt = NULL;

        bt = new ElementoGrafico::Botao(Matematica::CoordenadaF(600, 300), "MENU PRINCIPAL");
        bt->selecionar(true);
        vectorBotoes.push_back(bt);

        texNome.setTamanhoFonte(35.f);

        texNome.setAlinhamento(ElementoGrafico::AlinhamentoTexto::centro);

        texNome.setCor(77, 68, 44);

        texNome.setPosicao(Matematica::CoordenadaF(450, 100));

        pontos = 0;
        fase = IDestado::desconhecido;
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
        texNome.renderizar();
    }

    void MenuColocacao::executar() {
        if (ativo) {
            ativo = false;
            escreverColocacao();
            mudarEstado(Estados::IDestado::menuPrincipal);
        }
    }

    void MenuColocacao::resetEstado() {
        vectorBotoes[0]->selecionar(true);
        for (itr = allPoints.begin(); itr != allPoints.end(); ++itr)
            delete (*itr);
        allPoints.clear();
        criarColocacao();
        if (pSM->getIDUltimoEstado() == IDestado::menuPrincipal) {
            MenuPrincipal* m = dynamic_cast<MenuPrincipal*>(Gerenciador::GerenciadorEvento::getGerenciadorEvento()->getPMenu());
            if (m) {
                pontos = m->getPontos();
                fase = m->getUltimaFase();
            }
        }
        Gerenciador::GerenciadorEvento::getGerenciadorEvento()->setMenu(this);
    }

    void MenuColocacao::criarColocacao() {
        std::ifstream file;

        file.open(CAMINHO_FLORESTA, std::ios::binary | std::ios::in);

        if (!file) {
            std::ofstream writeFile(CAMINHO_FLORESTA, std::ios::out | std::ios::trunc);
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
        file.close();

        file.open(CAMINHO_CAVERNA, std::ios::binary | std::ios::in);

        if (!file) {
            std::ofstream writeFile(CAMINHO_CAVERNA, std::ios::out | std::ios::trunc);
            writeFile.close();
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
            txt = new ElementoGrafico::Texto(Matematica::CoordenadaF(900, 100.f + 40.f * i), str);
            txt->setTamanhoFonte(38);
            txt->setAlinhamento(ElementoGrafico::AlinhamentoTexto::centro);
            txt->setCor(77, 68, 44);
            allPoints.push_back(txt);
        }

        file.close();
    }

    void MenuColocacao::aceitarLetra(char letra) {
        if (letra == 8) { //backspace
            if (!nome.empty()) {
                nome.pop_back(); //C++ 11 para isso compilar: apenas retira ultima letra da string
            }
        } else if ((letra >= 65 && letra <= 90) || (letra >= 97 && letra <= 122)) { // A-Z ou a-z
            if (nome.size() < 10)
                nome += letra;
        }
        texNome.setInfo(nome);
    }

    void MenuColocacao::escreverColocacao() {
        if (nome.empty()) return;
        //if (pontos == 0) return;

        std::ifstream file;
        std::string caminho;

        if (fase == IDestado::jogandoFloresta) {
            caminho = CAMINHO_FLORESTA;
        } else if (fase == IDestado::jogandoCaverna) {
            caminho = CAMINHO_CAVERNA;
        } else {
            return; //nao jogou alguma fase ainda
        }
        file.open(caminho, std::ios::binary | std::ios::in);

        if (!file) {
            std::ofstream writeFile(caminho, std::ios::out | std::ios::trunc);
            writeFile.close();
        }

        std::string str;
        std::string word;
        std::string n;
        std::map<int, std::string, std::greater<>> pontosArquivo; //usa std::greater para ser decrescente

        for (int i = 0; i < 5; i++) {
            str = "";

            std::getline(file, str);
            if (str.empty()) {
                break;
            }
            std::istringstream iss(str);

            iss >> word;
            n = word;
            iss >> word;
            try {
                pontosArquivo.insert(std::pair<int, std::string>(std::stoi(word), n));
            } catch (std::invalid_argument const &ex) {
                pontosArquivo.insert(std::pair<int, std::string>(0,  ""));
            }

        }
        pontosArquivo.insert(std::pair<int, std::string>(pontos, nome));

        file.close();

        std::ofstream outFile(caminho, std::ofstream::out | std::ofstream::trunc);

        if (outFile.is_open()) {
            std::map<int, std::string>::iterator iterador = pontosArquivo.begin();
            for (int i = 0; i < 5; i++) {
                if (i >= pontosArquivo.size()) break;
                outFile << iterador->second << " " << iterador->first << std::endl;
                std::advance(iterador, 1);
            }
            outFile.close();
        }

    }
}
