#pragma once

#include "Coordenada.h"
#include "Jogador.h"

#define VIDA_ORIANA 100
#define DANO_ORIANA 50
#define TAM_X_ORIANA 50.f
#define TAM_Y_ORIANA 80.f
#define VELOCIDADE_X_ORIANA 160.0f
#define VELOCIDADE_Y_ORIANA 0.0f
#define TAMANHO_PULO_ORIANA 140.0f
//teste...
#define TEMPO_ATAQUE_ORIANA 0.4f
#define TEMPO_DANO_ORIANA 0.6f
#define TEMPO_MORRE_ORIANA 0.6f


namespace Entidade {
	namespace Personagem {
		namespace Jogador {
			class Oriana : public Jogador
			{
			private:
				const bool EhJogador1;
			public:
				Oriana(Matematica::CoordenadaF posInicio);
				~Oriana();
				void inicializacao();

				void atualizar(const float tempo);
				void atualizarImagem(const float tempo);
				void executar();
			};
		}
	}
}

