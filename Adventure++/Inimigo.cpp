#include "Inimigo.h"

namespace Entidade {
	namespace Personagem {
			Inimigo::Inimigo(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id, Oriana* pOriana, const int vida, Matematica::CoordenadaF vel) :
				Personagem(pos, tam, id, vida, vel), distanciaJogador(0.f), pOriana(pOriana)
			{ }

			Inimigo::~Inimigo() { pOriana = nullptr; }

			void Inimigo::setOriana(Oriana* pOriana) { this->pOriana = pOriana; }
			Oriana* Inimigo::getOriana() { return pOriana; }

			Matematica::CoordenadaF Inimigo::getDistanciaJogador() { return distanciaJogador; }

			void Inimigo::colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade) {
				switch (pEntidade->getID())
				{
				case Ids::Ids::plataforma:
					colisaoPlataforma(intersecao, pEntidade);
					break;
				case Ids::Ids::oriana:
					//apenas para texte;
					std::cout << "colisao com jogador!" << std::endl;
					exit(1);
					break;
				default:
					break;
				}
			}

			void Inimigo::atualizar(float tempo) {
				this->tempo += tempo;
				if (this->tempo < 2.0f) {
					Matematica::CoordenadaF escala(1.0f, 1.0f);
					pAnimacaoMovimento->atualizar(posicao, true, tempo, Ids::Ids::pascal_ataca, escala);
				}
				else if(this->tempo < 4.0f) {
					Matematica::CoordenadaF escala(1.0f, 1.0f);
					pAnimacaoMovimento->atualizar(posicao, true, tempo, Ids::Ids::pascal_anda, escala);
				}
				else if (this->tempo < 6.0f) {
					Matematica::CoordenadaF escala(1.0f, 1.0f);
					pAnimacaoMovimento->atualizar(posicao, true, tempo, Ids::Ids::pascal_morre, escala);
				}
				else if (this->tempo < 8.0f) {
					Matematica::CoordenadaF escala(1.0f, 1.0f);
					pAnimacaoMovimento->atualizar(posicao, true, tempo, Ids::Ids::pascal_tomaDano, escala);
				}
				else {
					this->tempo = 0.f;
				}
			}
	}
}