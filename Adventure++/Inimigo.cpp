#include "Inimigo.h"

namespace Entidade {
	namespace Personagem {
		namespace Inimigo {
			Inimigo::Inimigo(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id, Jogador::Oriana* pOriana, const float distanciaJogador) :
				Personagem(pos, tam, id), 
				pOriana(pOriana),
				aleatorio(rand() % 3), 
				distanciaJogador(distanciaJogador),
				contAleatorio(0)
			{ }

			Inimigo::~Inimigo() {
				if (pOriana) {
					delete(pOriana);
					pOriana = nullptr;
				}
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
						tomarDano(50);
						std::cout << "a ";
					}
				}
			}
			void Inimigo::atualizar(const float tempo) {
				atualizarTempoAtaque(tempo);
				float distancia = getOriana()->getPosicao().x - posicao.x;

				//arrumar velocidade.x ...
				velocidade.x = getVelocidadeEspecifica();
				//persegue o jogador...
				//OBS: tem q arrumar...
				if (!morrer && !dano) {
					if (fabs(distancia) < distanciaJogador) {
						//p/ direito
						if (distancia > 0) {
							posicao.x += velocidade.x * tempo;
							olharEsquerda = false;
							distancia = getOriana()->getPosicao().x - posicao.x;
							if (distancia < 0) {
								posicao.x = pOriana->getPosicao().x;
							}
						}
						//p/ esquerda
						else {
							posicao.x -= velocidade.x * tempo;
							olharEsquerda = true;
							distancia = getOriana()->getPosicao().x - posicao.x;
							if (distancia > 0) {
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
					//movimento aleatorio
					else if (fabs(distancia) > distanciaJogador) {
						//p/ direita
						if (aleatorio == 0) {
							posicao.x += velocidade.x * tempo;
							olharEsquerda = false;
							ativarAndar(olharEsquerda);
						}
						//p/ esquerda
						else if (aleatorio == 1) {
							posicao.x -= velocidade.x * tempo;
							olharEsquerda = true;
							ativarAndar(true);
						}
						//fica parado
						else {
							desligarAndar();
						}
						contAleatorio++;
						if (contAleatorio == 1000) {
							contAleatorio = 0;
							aleatorio = rand() % 3;
						}
					}
					else {
						//atarcar aqui -> terminar...
					}
				}
				velocidade.y += GRAVIDADE * tempo;

				posicao.y += velocidade.y * tempo;
				atualizarImagem(tempo);
				renderizar();
			}
		} //namespace Inimigo
	} //namespace Personagem
} //namespace Entidade