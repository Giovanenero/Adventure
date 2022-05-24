#include "Oriana.h"

namespace Entidade {
	namespace Personagem {
		Oriana::Oriana(Matematica::CoordenadaF posInicio) :
			Jogador(posInicio, 
			Matematica::CoordenadaF(TAM_X_ORIANA, TAM_Y_ORIANA), 
			Ids::Ids::oriana, 
			VIDA_ORIANA, 
			Matematica::CoordenadaF(VELOCIDADE_X_ORIANA, VELOCIDADE_Y_ORIANA)),
			EhJogador1(true)
		{
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
	}
}