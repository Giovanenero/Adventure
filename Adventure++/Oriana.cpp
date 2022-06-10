#include "Oriana.h"

namespace Entidade {
	namespace Personagem {
		namespace Jogador {
			Oriana::Oriana(Matematica::CoordenadaF posInicio) :
				Jogador(posInicio, Ids::Ids::oriana)
			{ this->inicializacao(); }

			Oriana::~Oriana() { }

			//inicializa animacoes
			void Oriana::inicializacao() {
				pAnimacaoMovimento->novaAnimacao("textura/jogador/Oriana/orianaAndando.png", 10, Ids::Ids::oriana_anda, tamanho, Matematica::CoordenadaF(2.2f, 0.9f)); //certo
				pAnimacaoMovimento->novaAnimacao("textura/jogador/Oriana/orianaAtacando1.png", 7, Ids::Ids::oriana_ataca1, tamanho, Matematica::CoordenadaF(2.0f, 1.15f)); //certo
				pAnimacaoMovimento->novaAnimacao("textura/jogador/Oriana/orianaAtacando2.png", 21, Ids::Ids::oriana_ataca2, tamanho, Matematica::CoordenadaF(2.0f, 2.2f)); //certo
				pAnimacaoMovimento->novaAnimacao("textura/jogador/Oriana/orianaAtacando3.png", 27, Ids::Ids::oriana_ataca3, tamanho, Matematica::CoordenadaF(2.0f, 2.4f)); //certo
				pAnimacaoMovimento->novaAnimacao("textura/jogador/Oriana/orianaAtacando4.png", 32, Ids::Ids::oriana_ataca4, tamanho, Matematica::CoordenadaF(2.0f, 3.7f)); //certo
				pAnimacaoMovimento->novaAnimacao("textura/jogador/Oriana/orianaCaindo.png", 3, Ids::Ids::oriana_cai, tamanho, Matematica::CoordenadaF(2.0f, 1.45f)); //certo
				pAnimacaoMovimento->novaAnimacao("textura/jogador/Oriana/orianaDano.png", 7, Ids::Ids::oriana_tomaDano, tamanho, Matematica::CoordenadaF(2.0f, 2.25f));
				pAnimacaoMovimento->novaAnimacao("textura/jogador/Oriana/orianaMorrendo.png", 16, Ids::Ids::oriana_morre, tamanho, Matematica::CoordenadaF(2.2f, 0.9f));
				pAnimacaoMovimento->novaAnimacao("textura/jogador/Oriana/orianaParada.png", 8, Ids::Ids::oriana_para, tamanho, Matematica::CoordenadaF(2.2f, 0.9f)); //certo
				pAnimacaoMovimento->novaAnimacao("textura/jogador/Oriana/orianaPulando.png", 3, Ids::Ids::oriana_pula, tamanho, Matematica::CoordenadaF(2.0f, 1.0f)); //certo
				pAnimacaoMovimento->novaAnimacao("textura/jogador/Oriana/orianaSurf.png", 8, Ids::Ids::oriana_surf, tamanho, Matematica::CoordenadaF(1.0f, 1.0f));
				carregarAtaque = 0.4f;
				tempoAtaque = 0.4f;
				carregarMorrer = 1.5f;
				carregarTomarDano = 0.6f;
				mudarAtaque = rand() % 4;
			}

			void Oriana::atualizarImagem(const float tempo) {
				if (morrer) {
					desligarAndar();
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo * 0.8f, Ids::Ids::oriana_morre);
					carregandoMorrendo += tempo;
					//teste...
					if (carregandoMorrendo > carregarMorrer) {
						std::cout << "FIM DE JOGO!" << std::endl;
						exit(1);
					}
				}
				else if (!noChao) {
					if (!caindo) {
						pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::oriana_pula);
					}
					else {
						pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::oriana_cai);
					}
				}
				else if (tomarDano) {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::oriana_tomaDano);
					carregaTomarDano(tempo);
				}
				else if (atacando) {
					desligarAndar();
					if (mudarAtaque == 0) {
						pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo * 0.8f, Ids::Ids::oriana_ataca1);
					}
					else if (mudarAtaque == 1) {
						pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::oriana_ataca2);
					}
					else if (mudarAtaque == 2) {
						pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::oriana_ataca3);
					}
					else {
						pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::oriana_ataca4);
					}
				}
				else if (andando) {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::oriana_anda);
					mudarAtaque = rand() % 4;
				}
				else {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::oriana_para);
				}
			}
		} //namespace Jogador
	} //namespace Personagem
} //namespace Entidade