#include "Jogador.h"

namespace Entidade {
	namespace Personagem {
			Jogador::Jogador(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id, const float tamPulo) :
				Personagem(pos, tam, id), pulando(true), tamPulo(tamPulo)
			{ }
			Jogador::~Jogador() { }

			void Jogador::colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade) {
				colisaoPlataforma(intersecao, pEntidade);
				switch (pEntidade->getID())
				{
				case Ids::Ids::plataforma:
				{
					pulando = true;
					break;
				}
				default:
					break;
				}
			}
	}
}