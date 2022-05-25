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
				{
					colisaoPlataforma(intersecao, pEntidade);
					break;
				}
				case Ids::Ids::oriana:
				{
					if (atacando) {
						std::cout << "atacando Oriana ";
					}
					break;
				}
				default:
					break;
				}
			}
	}
}