#include "Oriana.h"

namespace Entidade {
	namespace Personagem {
		namespace Jogador {
			Oriana::Oriana(Matematica::CoordenadaF posInicio) :
				Jogador(posInicio, Ids::Ids::oriana)
			{
				inicializacao();
				carregarAtaque = 0.4f;
				tempoAtaque = 0.4f;
				carregarMorrer = 1.5f;
				carregarTomarDano = 0.6f;
			}

			Oriana::~Oriana() { }

			//inicializa animacoes
			void Oriana::inicializacao() {
				pAnimacaoMovimento->novaAnimacao("textura/Jogador/Oriana/orianaParada.png", 15, Ids::Ids::oriana_para, tamanho, Matematica::CoordenadaF(1.5f, 3.0f));
				pAnimacaoMovimento->novaAnimacao("textura/jogador/Oriana/orianaMorrendo.png", 15, Ids::Ids::oriana_morre, tamanho, Matematica::CoordenadaF(2.5f, 3.0f));
				pAnimacaoMovimento->novaAnimacao("textura/Jogador/Oriana/orianaPulando.png", 1, Ids::Ids::oriana_pula, tamanho, Matematica::CoordenadaF(1.2f, 1.8f));
				pAnimacaoMovimento->novaAnimacao("textura/Jogador/Oriana/orianaCaindo.png", 1, Ids::Ids::oriana_cai, tamanho, Matematica::CoordenadaF(1.2f, 2.0f));
				pAnimacaoMovimento->novaAnimacao("textura/jogador/Oriana/orianaAtacando.png", 22, Ids::Ids::oriana_ataca, tamanho, Matematica::CoordenadaF(3.0f, 3.2f));
				pAnimacaoMovimento->novaAnimacao("textura/jogador/Oriana/orianaAndando.png", 8, Ids::Ids::oriana_anda, tamanho, Matematica::CoordenadaF(2.2f, 3.0f));
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
				else if (atacando) {
					desligarAndar();
					//arrumar tempo...
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo + 0.5 * tempo, Ids::Ids::oriana_ataca);
				}
				else if (andando) {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::oriana_anda);
				}
				else {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::oriana_para);
				}
			}
		} //namespace Jogador
	} //namespace Personagem
} //namespace Entidade