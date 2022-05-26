#include "Oriana.h"

namespace Entidade {
	namespace Personagem {
		Oriana::Oriana(Matematica::CoordenadaF posInicio) :
			Jogador(posInicio, 
			Matematica::CoordenadaF(TAM_X_ORIANA, TAM_Y_ORIANA), 
			Ids::Ids::oriana, 
			TAMANHO_PULO_ORIANA),
			EhJogador1(true)
		{
			vida = VIDA_ORIANA;
			velocidade = Matematica::CoordenadaF(VELOCIDADE_X_ORIANA, VELOCIDADE_Y_ORIANA);
			inicializacao();
		}

		Oriana::~Oriana() { }

		//inicializa as animacoes
		void Oriana::inicializacao() {
			//parametro(caminhoTexto, contaImagem, id, escala)
			pAnimacaoMovimento->novaAnimacao("textura/Jogador/orianaParada.png", 15, Ids::Ids::oriana_para);
			pAnimacaoMovimento->novaAnimacao("textura/jogador/orianaMorrendo.png", 15, Ids::Ids::oriana_morre);
			pAnimacaoMovimento->novaAnimacao("textura/Jogador/orianaPulando.png", 15, Ids::Ids::oriana_pula);
			pAnimacaoMovimento->novaAnimacao("textura/jogador/orianaAtacando.png", 22, Ids::Ids::oriana_ataca);
			pAnimacaoMovimento->novaAnimacao("textura/jogador/orianaAndando.png", 8, Ids::Ids::oriana_anda);
		}
		void Oriana::atualizar(const float tempo) {
			atualizarTempoAtaque(tempo);

			if (andando) {
				velocidade.x = VELOCIDADE_X_ORIANA;
				if (olharEsquerda) {
					velocidade.x = -velocidade.x;
				}
			}
			else {
				velocidade.x *= 0.5;
			}
			velocidade.y += GRAVIDADE * tempo;

			posicao.x += velocidade.x;
			//posicao.y += velocidade.y * tempo;

			atualizarImagem(tempo);
			//carregandoDano += tempo;
			renderizar();
		}
		
		void Oriana::atualizarImagem(const float tempo) {
			if (atacando) {
				desligarAndar();
				Matematica::CoordenadaF escala(6.2f, 3.1f);
				pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::oriana_ataca, escala);
			}
			else if (andando) {
				Matematica::CoordenadaF escala(5.2f, 3.0f);
				pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::oriana_anda, escala);
			}
			else {
				Matematica::CoordenadaF escala(3.0f, 3.0f);
				pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::oriana_para, escala);
			}
		}
	}
}