#include "Jogador.h"

namespace Entidade {
	namespace Personagem {
			Jogador::Jogador(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id, const float tamPulo) :
				Personagem(pos, tam, id), pular(true), tamPulo(tamPulo), caindo(true)
			{ }
			Jogador::~Jogador() { }

			void Jogador::colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade) {
				switch (pEntidade->getID())
				{
					case Ids::Ids::plataforma:
					{
						colisaoPlataforma(intersecao, pEntidade);
						pular = true;
						noChao = true;
						caindo = false;
						break;
					}
					default:
					{
						break;
					}
				}
			}
			void Jogador::podePular() {
				if (pular) {
					velocidade.y = -sqrt(2.0f * GRAVIDADE * tamPulo);
					pular = false;
					noChao = false;
				}
			}
	}
}