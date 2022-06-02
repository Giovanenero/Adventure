#include "Animagus.h"

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
            }
            void Animagus::atualizarImagem(const float tempo) {
				if (morrer) {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::animagus_morre);
					carregandoMorrendo += tempo;
				}
				else if (tomarDano) {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo * 0.5f, Ids::Ids::animagus_tomaDano);
					carregandoTomarDano += tempo;
					if (carregandoTomarDano > carregarTomarDano) {
						tomarDano = false;
						carregandoTomarDano = 0.0f;
					}
				}
				else if (atacando) {
					if (mudarAtaque == 0) {
						pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::animagus_ataca1);
					}
					else {
						pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::animagus_ataca2);
					}
				}
				else if (andando) {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::animagus_anda);
				}
				else {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::animagus_para);
					mudarAtaque = rand() % 2;
				}
            }
        }
    }
}