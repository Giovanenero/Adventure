#include "Jogador.h"

namespace Entidade {
	namespace Personagem {
			Jogador::Jogador(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id) :
				Personagem(pos, tam, id), pular(true)
			{ }
			Jogador::~Jogador() { }

			void Jogador::colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade) {
				switch (pEntidade->getID())
				{
				case Ids::Ids::plataforma:
				{
					colisaoPlataforma(intersecao, pEntidade);
					break;
				}
				case Ids::Ids::pascal:
				{
					//terminar...
					break;
				}
				default:
					break;
				}
			}
	}
}