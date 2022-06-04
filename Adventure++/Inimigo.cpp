#include "Inimigo.h"

namespace Entidade {
	namespace Personagem {
		namespace Inimigo {
			Inimigo::Inimigo(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id, Jogador::Oriana* pOriana, Jogador::Hideo* pHideo, Matematica::CoordenadaF distanciaJogador, const int vida, const int dano) :
				Personagem(pos, tam, id, vida, dano), 
				pOriana(pOriana),
				pHideo(pHideo),
				aleatorio(rand() % 3), 
				distanciaJogador(distanciaJogador),
				contAleatorio(0)
			{ }

			Inimigo::~Inimigo() {
				/*
				if (pOriana) {
					//delete(pOriana);
					std::cout << "a ";
					pOriana = nullptr;
				}
				*/
			}

			void Inimigo::setOriana(Jogador::Oriana* pOriana) {
				if (pOriana == nullptr) {
					std::cout << "ponteiro pOriana vazio! - class Inimigo: setOriana" << std::endl;
					exit(1);
				}
				this->pOriana = pOriana;
			}
			Jogador::Oriana* Inimigo::getOriana() {
				if (pOriana == nullptr) {
					std::cout << "ponteiro pOriana vazio! - classe Inimigo: getOriana()" << std::endl;
					exit(1);
				}
				return pOriana;
			}
			Matematica::CoordenadaF Inimigo::getDistanciaJogador() { return distanciaJogador; }

			void Inimigo::colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade) {
				//colisaoPlataforma(intersecao, pEntidade);
				if (pEntidade->getID() == Ids::Ids::plataforma) {
					noChao = true;
					colisaoPlataforma(intersecao, pEntidade);
				}
				else if (pEntidade->getID() == Ids::Ids::oriana) {
					if (pOriana->podeAtacar()) {
						podeTomarDano(pOriana->valorDano());
					}
				}
				else if (pEntidade->getID() == Ids::Ids::hideo) {
					if (pHideo->podeAtacar()) {
						podeTomarDano(pHideo->valorDano());
					}
				}
			}
			void Inimigo::atualizar(const float tempo) {
				if (posicao.y > 2000.0f) {
					morrer = true;
				}
				atualizarTempoAtaque(tempo);
				float distancia_x = getOriana()->getPosicao().x - posicao.x;
				float distancia_y = getOriana()->getPosicao().y - posicao.y;

				//arrumar velocidade.x ...
				velocidade.x = getVelocidadeEspecifica();
				//persegue o jogador...
				if (!morrer && !tomarDano && !atacando) {
					if (fabs(distancia_x) < distanciaJogador.x && fabs(distancia_y) < distanciaJogador.y) {
						//p/ direito
						if (distancia_x > 0) {
							posicao.x += velocidade.x * tempo;
							olharEsquerda = false;
							distancia_x = getOriana()->getPosicao().x - posicao.x;
							if (distancia_x < 0) {
								posicao.x = pOriana->getPosicao().x;
							}
						}
						//p/ esquerda
						else {
							posicao.x -= velocidade.x * tempo;
							olharEsquerda = true;
							distancia_x = getOriana()->getPosicao().x - posicao.x;
							if (distancia_x > 0) {
								posicao.x = pOriana->getPosicao().x;
							}
						}
						if (posicao.x != pOriana->getPosicao().x) {
							ativarAndar(olharEsquerda);
						}
						else {
							desligarAndar();
						}
					}
					else {
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
		} //namespace Inimigo
	} //namespace Personagem
} //namespace Entidade