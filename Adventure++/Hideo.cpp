#include "Hideo.h"

#define CARREGAR_ATAQUE_HIDEO 0.4f
#define TEMPO_ATAQUE_HIDEO 0.4f
#define CARREGAR_MORRER_HIDEO 0.8f
#define CARREGAR_TOMAR_DANO_HIDEO 0.4f

namespace Entidade {
    namespace Personagem {
        namespace Jogador {
            Hideo::Hideo(Matematica::CoordenadaF posInicio):
                Jogador(posInicio, Ids::Ids::hideo)
            {
                this->inicializacao();
            }
            Hideo::~Hideo() { }

            void Hideo::inicializacao() {
				pAnimacaoMovimento->novaAnimacao("textura/Jogador/Hideo/hideoAndando.png", 8, Ids::Ids::hideo_anda, tamanho, Matematica::CoordenadaF(2.0f, 2.0f));
                pAnimacaoMovimento->novaAnimacao("textura/Jogador/Hideo/hideoAtacando1.png", 7, Ids::Ids::hideo_ataca1, tamanho, Matematica::CoordenadaF(2.0f, 2.0f));
                pAnimacaoMovimento->novaAnimacao("textura/jogador/Hideo/hideoAtacando2.png", 7, Ids::Ids::hideo_ataca2, tamanho, Matematica::CoordenadaF(2.0f, 2.0f));
                pAnimacaoMovimento->novaAnimacao("textura/Jogador/Hideo/hideoAtacando3.png", 8, Ids::Ids::hideo_ataca3, tamanho, Matematica::CoordenadaF(2.0f, 2.0f));
                pAnimacaoMovimento->novaAnimacao("textura/Jogador/Hideo/hideoCaindo.png", 3, Ids::Ids::hideo_cai, tamanho, Matematica::CoordenadaF(2.0f, 2.0f));
                pAnimacaoMovimento->novaAnimacao("textura/jogador/Hideo/hideoDano.png", 3, Ids::Ids::hideo_tomaDano, tamanho, Matematica::CoordenadaF(2.0f, 2.0f));
                pAnimacaoMovimento->novaAnimacao("textura/jogador/Hideo/hideoMorrendo.png", 7, Ids::Ids::hideo_morre, tamanho, Matematica::CoordenadaF(2.0f, 2.0f));
                pAnimacaoMovimento->novaAnimacao("textura/jogador/Hideo/hideoParado.png", 10, Ids::Ids::hideo_para, tamanho, Matematica::CoordenadaF(2.0f, 2.0f));
                pAnimacaoMovimento->novaAnimacao("textura/jogador/Hideo/hideoPulando.png", 3, Ids::Ids::hideo_pula, tamanho, Matematica::CoordenadaF(2.0f, 2.0f));
				carregarAtaque = CARREGAR_ATAQUE_HIDEO;
				tempoAtaque = TEMPO_ATAQUE_HIDEO;
				carregarMorrer = CARREGAR_MORRER_HIDEO;
				carregarTomarDano = CARREGAR_TOMAR_DANO_HIDEO;
				mudarAtaque = rand() % 3;
			}

            void Hideo::atualizarImagem(const float tempo) {
				if (morrer) {
					desligarAndar();
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo * 0.6f, Ids::Ids::hideo_morre);
					carregandoMorrendo += tempo;
				}
				else if (tomarDano) {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo * 0.8f, Ids::Ids::hideo_tomaDano);
					carregaTomarDano(tempo);
				}
				else if (!noChao) {
					if (!caindo) {
						pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::hideo_pula);
					}
					else {
						pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::hideo_cai);
					}
				}
				else if (atacando) {
					desligarAndar();
					if (mudarAtaque == 0) {
						pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo + 0.5 * tempo, Ids::Ids::hideo_ataca1);
					}
					else if (mudarAtaque == 1) {
						pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo + 0.5 * tempo, Ids::Ids::hideo_ataca2);
					}
					else {
						pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo + 0.5 * tempo, Ids::Ids::hideo_ataca3);
					}
				}
				else if (andando) {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::hideo_anda);
					mudarAtaque = rand() % 3;
				}
				else {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::hideo_para);
				}
            }
        }
    }
}