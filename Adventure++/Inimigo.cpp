#include "Inimigo.h"

namespace Entidade {
	namespace Personagem {
			Inimigo::Inimigo(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id, Oriana* pOriana, const float distanciaJogador) :
				Personagem(pos, tam, id), pOriana(pOriana),
				aleatorio(rand()%3), distanciaJogador(distanciaJogador),
				contAleatorio(0)
			{ }

			Inimigo::~Inimigo() { pOriana = nullptr; }

			void Inimigo::setOriana(Oriana* pOriana) { 
				if (pOriana == nullptr) {
					std::cout << "ponteiro pOriana vazio! - class Inimigo: setOriana" << std::endl;
					exit(1);
				}
				this->pOriana = pOriana;
			}
			Oriana* Inimigo::getOriana() { 
				if (pOriana == nullptr) {
					std::cout << "ponteiro pOriana vazio! - classe Inimigo: getOriana()" << std::endl;
					exit(1);
				}
				return pOriana; 
			}
			Matematica::CoordenadaF Inimigo::getDistanciaJogador() { return distanciaJogador; }

			void Inimigo::colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade) {
				switch (pEntidade->getID())
				{
				case Ids::Ids::plataforma:
				{
					colisaoPlataforma(intersecao, pEntidade);
					break;
				}
				case Ids::Ids::oriana:
				{
					if (pOriana != nullptr) {
						Matematica::CoordenadaF centro;
						centro.x = pEntidade->getPosicao().x - getPosicao().x;
						//terminar...
					}
					
					break;
				}
				default:
					break;
				}
			}
			void Inimigo::atualizar(const float tempo) {
				atualizarTempoAtaque(tempo);
				float distancia = getOriana()->getPosicao().x - posicao.x;
				//persegue o jogador...
				if (fabs(distancia) < distanciaJogador) {
					//p/ direito
					if (distancia > 0) {
						posicao.x += velocidade.x;
						olharEsquerda = false;
						distancia = getOriana()->getPosicao().x - posicao.x;
						if (distancia < 0) {
							posicao.x = pOriana->getPosicao().x;
						}
					}
					//p/ esquerda
					else {
						posicao.x -= velocidade.x;
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
						posicao.x += velocidade.x;
						olharEsquerda = false;
						ativarAndar(olharEsquerda);
					}
					//p/ esquerda
					else if (aleatorio == 1) {
						posicao.x -= velocidade.x;
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
				atualizarImagem(tempo);
				renderizar();
			}
	}
}