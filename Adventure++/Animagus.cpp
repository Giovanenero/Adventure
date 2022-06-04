#include "Animagus.h"

#define VELOCIDADE_ANIMAGUS_X 80.0f

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            Animagus::Animagus(Matematica::CoordenadaF posInicio, Jogador::Oriana* pOriana) :
                Chefao(posInicio, pOriana, Ids::Ids::animagus)
            {
                this->inicializacao();
            }
            Animagus::~Animagus() {

            }
            void Animagus::inicializacao() {
                pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Animagus/animagusAndando.png", 8, Ids::Ids::animagus_anda, tamanho, Matematica::CoordenadaF(1.8f, 1.25f));
                pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Animagus/animagusAtacando1.png", 8, Ids::Ids::animagus_ataca1, tamanho, Matematica::CoordenadaF(1.8f, 1.25f));
                pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Animagus/animagusAtacando2.png", 8, Ids::Ids::animagus_ataca2, tamanho, Matematica::CoordenadaF(1.8f, 1.25f));
                pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Animagus/animagusDano.png", 3, Ids::Ids::animagus_tomaDano, tamanho, Matematica::CoordenadaF(1.8f, 1.25f));
                pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Animagus/animagusMorrendo.png", 7, Ids::Ids::animagus_morre, tamanho, Matematica::CoordenadaF(1.8f, 1.25f));
                pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Animagus/animagusParado.png", 8, Ids::Ids::animagus_para, tamanho, Matematica::CoordenadaF(1.8f, 1.25f));
				carregarTomarDano = 0.5f;
				carregarMorrer = 0.35f;
				carregarAtaque = 2.5f;
				tempoAtaque = 0.5f;
            }
            void Animagus::atualizarImagem(const float tempo) {
				if (morrer) {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::animagus_morre);
					carregandoMorrendo += tempo;
				}
				else if (tomarDano) {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo * 0.5f, Ids::Ids::animagus_tomaDano);
					carregaTomarDano(tempo);
				}
				else if (atacando) {
					if (mudarAtaque == 0) {
						pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::animagus_ataca1);
					}
					else {
						pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::animagus_ataca2);
					}
					desligarAtacar();
				}
				else if (andando) {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::animagus_anda);
				}
				else {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::animagus_para);
					mudarAtaque = rand() % 2;
				}
            }
			const float Animagus::getVelocidadeEspecifica() const {
				return VELOCIDADE_ANIMAGUS_X;
			}
        }
    }
}