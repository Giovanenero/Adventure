#include "Jogador.h"

namespace Entidade {
	namespace Personagem {
			Jogador::Jogador(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id) :
				Personagem(pos, tam, id)
			{ }
			Jogador::~Jogador() { }

			void Jogador::atualizar(float tempo) {
				this->tempo += tempo;
				if (this->tempo < 3) {
					//parametro(pos, EhEsquerda, tempo, id)
					Matematica::CoordenadaF escala(2.0f, 2.0f);
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::andar, escala);
					posicao.x += 0.025;
				}
				else {
					Matematica::CoordenadaF escala(1.5f, 2.0f);
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::parar, escala);
				}
			}
			void Jogador::colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade) {
				switch (pEntidade->getID())
				{
				case Ids::Ids::plataforma:
				{
					colisaoPlataforma(intersecao, pEntidade);
					break;
				}
				//colisao com todas as entidades...
				//terminar...
				default:
					break;
				}
			}
	}
}