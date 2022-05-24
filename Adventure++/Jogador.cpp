#include "Jogador.h"

namespace Entidade {
	namespace Personagem {
			Jogador::Jogador(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id, const int vida, Matematica::CoordenadaF vel) :
				Personagem(pos, tam, id, vida, vel)
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
				//colisao com todas as entidades...
				//terminar...
				default:
					break;
				}
			}
			void Jogador::andar(const bool paraEsquerda, const float tempo) {
				this->tempo += tempo;
				olharEsquerda = paraEsquerda;
				Matematica::CoordenadaF escala(4.0f, 3.0f);
				pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::oriana_anda, escala);
				posicao += (olharEsquerda) ? -getVelocidade().x : getVelocidade().x;
			}
			
			void Jogador::atacar(const float tempo) {
				this->tempo += tempo;
				Matematica::CoordenadaF escala(6.0f, 3.0f);
				pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::oriana_ataca, escala);
			}
			void Jogador::parar(const float tempo) {
				this->tempo += tempo;
				Matematica::CoordenadaF escala(3.0f, 3.0f);
				pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::oriana_para, escala);
			}
	}
}