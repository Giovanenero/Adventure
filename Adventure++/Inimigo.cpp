#include "Inimigo.h"

namespace Entidade {
	namespace Personagem {
		namespace Inimigo {
			Inimigo::Inimigo(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id, Jogador::Oriana* pOriana, Jogador::Hideo* pHideo, Matematica::CoordenadaF distanciaJogador, const int vida, const int dano) :
				Personagem(pos, tam, id, vida, dano), 
				pOriana(pOriana),
				pHideo(pHideo),
				aleatorio(rand() % 5), 
				distanciaJogador(distanciaJogador),
				contAleatorio(0)
			{ }

			Inimigo::~Inimigo() {
				if (pOriana != nullptr) {
					//delete(pOriana);
					pOriana = nullptr;
				}
				if (pHideo != nullptr) {
					//delete(pHideo);
					pHideo = nullptr;
				}
			}

			void Inimigo::setOriana(Jogador::Oriana* pOriana) {
				if (pOriana == nullptr) {
					std::cout << "ponteiro pOriana vazio! - class Inimigo: setOriana" << std::endl;
					exit(1);
				}
				this->pOriana = pOriana;
			}
			Jogador::Oriana* Inimigo::getOriana() { return pOriana; }

			Matematica::CoordenadaF Inimigo::getDistanciaJogador() { return distanciaJogador; }

			void Inimigo::colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade) {
				if (pEntidade->getID() == Ids::Ids::plataforma || pEntidade->getID() == Ids::Ids::pedra) {
					colisaoPlataforma(intersecao, pEntidade);
					if (velocidade.y == 0.0f) {
						noChao = true;
					}
				}
				else if (pEntidade->getID() == Ids::Ids::oriana) {
					if (pOriana->podeAtacar()) {
						podeTomarDano(pOriana->valorDano());
						if (morrer) {
							pOriana->setPontuacao(getPontuacao());
						}
					}
				}
				else if (pEntidade->getID() == Ids::Ids::hideo) {
					if (pHideo->podeAtacar()) {
						podeTomarDano(pHideo->valorDano());
						if (morrer) {
							pHideo->setPontuacao(getPontuacao());
						}
					}
				}
			}
			void Inimigo::atualizar(const float tempo) {
				if (posicao.y > 2000.0f) {
					morrer = true;
				}
				atualizarTempoAtaque(tempo);
				velocidade.x = getVelocidadeEspecifica();
				if (!morrer && !tomarDano && !atacando) {
					const bool moveu = perseguirJogadores(tempo);
					if (!moveu) {
						movimentoAleatorio(tempo);
					}
				}
				velocidade.y += GRAVIDADE * tempo;
				posicao.y += velocidade.y * tempo;  

				atualizarImagem(tempo);
				renderizar();
			}
			void Inimigo::movimentoAleatorio(const float tempo) {
				velocidade.x = getVelocidadeEspecifica();
				if (aleatorio == 0) {
					posicao.x += velocidade.x * tempo;
					ativarAndar(false);
				}
				else if (aleatorio == 1) {
					posicao.x -= velocidade.x * tempo;
					ativarAndar(true);
				}
				else {
					desligarAndar();
				}
				contAleatorio++;
				if (contAleatorio == 1000) {
					contAleatorio = 0;
					aleatorio = rand() % 3;
				}
			}
			const bool Inimigo::perseguirJogadores(const float tempo) {
				if (pOriana == nullptr) {
					return perseguirJogador(static_cast<Jogador::Jogador*>(pOriana), tempo);
				}
				else {
					if (fabs(pOriana->getPosicao().x - posicao.x) < fabs(pHideo->getPosicao().x - posicao.x)) {
						return perseguirJogador(static_cast<Jogador::Jogador*>(pOriana), tempo);					
					}
					else {
						return perseguirJogador(static_cast<Jogador::Jogador*>(pHideo), tempo);
					}
				}
			}
			const bool Inimigo::perseguirJogador(Jogador::Jogador* pJogador, const float tempo) {
				if (pJogador == nullptr) {
					std::cout << "pJogador nulo! - class Inimigo" << std::endl;
					exit(1);
				}
				Matematica::CoordenadaF posJogador = pJogador->getPosicao().x - posicao.x;
				if (fabs(posJogador.x) < distanciaJogador.x && fabs(posJogador.x) < distanciaJogador.y) {
					velocidade.x = getVelocidadeEspecifica();
					if (posJogador.x > 0){
						olharEsquerda = false;
						posicao.x = posicao.x + velocidade.x * tempo;
						posJogador = pJogador->getPosicao().x - posicao.x;
						if (posJogador.x < 0) {
							posicao.x = pJogador->getPosicao().x;
						}
					}
					else if (posJogador.x < 0) {
						olharEsquerda = true;
						posicao.x = posicao.x - velocidade.x * tempo;
						posJogador = pJogador->getPosicao().x - posicao.x;
						if (posJogador.x > 0) {
							posicao.x = pJogador->getPosicao().x;
						}
					}
					if (posicao.x != posJogador.x) {
						ativarAndar(olharEsquerda);
					}
					else {
						desligarAndar();
					}
					return true;
				}
				return false;
			}
		} //namespace Inimigo
	} //namespace Personagem
} //namespace Entidade