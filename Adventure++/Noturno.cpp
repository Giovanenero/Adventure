#include "Noturno.h"

#define VELOCIDADE_NOTURNO_X 90.0f
#define PONTUACAO_NOTURNO 5000
#define CARREGAR_TOMAR_DANO_NOTURNO 0.7f
#define CARREGAR_MORRER_NOTURNO 2.0f
#define CARREGAR_ATAQUE_NOTURNO 2.5f
#define TEMPO_ATAQUE_NOTURNO 0.5f

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            Noturno::Noturno(Matematica::CoordenadaF posInicio, Jogador::Oriana* pOriana, Jogador::Hideo* pHideo):
                Chefao(posInicio, pOriana, pHideo, Ids::Ids::noturno)
            {
                this->inicializacao();
            }

            Noturno::~Noturno() { }

            void Noturno::inicializacao() {
                pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Noturno/noturnoAndando.png", 6, Ids::Ids::noturno_anda, tamanho, Matematica::CoordenadaF(3.5f, 8.0f));
                pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Noturno/noturnoAtacando.png", 12, Ids::Ids::noturno_ataca, tamanho, Matematica::CoordenadaF(4.5f, 5.8f));
                pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Noturno/noturnoDano.png", 5, Ids::Ids::noturno_tomaDano, tamanho, Matematica::CoordenadaF(4.5f, 7.0f));
                pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Noturno/noturnoMorrendo.png", 23, Ids::Ids::noturno_morre, tamanho, Matematica::CoordenadaF(4.4 , 6.8f));
                pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Noturno/noturnoParado.png", 9, Ids::Ids::noturno_para, tamanho, Matematica::CoordenadaF(3.5f, 8.0f));
                carregarTomarDano = CARREGAR_TOMAR_DANO_NOTURNO;
                carregarMorrer = CARREGAR_MORRER_NOTURNO;
                carregarAtaque = CARREGAR_ATAQUE_NOTURNO;
                tempoAtaque = TEMPO_ATAQUE_NOTURNO;
            }

            void Noturno::atualizarImagem(const float tempo) {
                if (morrer) {
                    pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo * 0.8f, Ids::Ids::noturno_morre);
                    carregandoMorrendo += tempo;
                }
                else if (tomarDano) {
                    pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo * 0.5f, Ids::Ids::noturno_tomaDano);
                    carregaTomarDano(tempo);
                }
                else if (atacando) {
                    pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::noturno_ataca);
                    desligarAtacar();
                }
                else if (andando) {
                    pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::noturno_anda);
                }
                else {
                    pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::noturno_para);
                }
            }

            const float Noturno::getVelocidadeEspecifica() const {
                return VELOCIDADE_NOTURNO_X;
            }

            const short Noturno::getPontuacao() const {
                return PONTUACAO_NOTURNO;
            }
        }
    }
}