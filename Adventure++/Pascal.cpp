#include "Pascal.h"

namespace Entidade {
	namespace Personagem {
        namespace Inimigo {
            Pascal::Pascal(Matematica::CoordenadaF posInicio, Jogador::Oriana* pOriana) :
                Inimigo(posInicio,
                    Matematica::CoordenadaF(TAM_X_PASCAL, TAM_Y_PASCAL),
                    Ids::Ids::pascal,
                    pOriana, 
                    DISTANCIA_PASCAL_RECONHECER)
            {
                vida = VIDA_PASCAL;
                velocidade = Matematica::CoordenadaF(VELOCIDADE_X_PASCAL, VELOCIDADE_Y_PASCAL);
                inicializacao();
            }
            Pascal::~Pascal() {

            }
            void Pascal::inicializacao() {
                pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Pascal/pascalAndando.png", 6, Ids::Ids::pascal_anda, tamanho, Matematica::CoordenadaF(2.8f, 1.15f));
                pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Pascal/pascalMorrendo.png", 4, Ids::Ids::pascal_morre, tamanho, Matematica::CoordenadaF(2.8f, 2.15f));
                pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Pascal/pascalAtacando.png", 4, Ids::Ids::pascal_ataca, tamanho, Matematica::CoordenadaF(2.8f, 2.15f));
                pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Pascal/pascalDano.png", 2, Ids::Ids::pascal_tomaDano, tamanho, Matematica::CoordenadaF(2.8f, 2.15f));
                pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Pascal/pascalParado.png", 4, Ids::Ids::pascal_para, tamanho, Matematica::CoordenadaF(2.8f, 1.15f));
            }
            void Pascal::atualizarImagem(const float tempo) {
                if (atacando) {
                    pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::pascal_ataca);
                }
                else if (andando) {
                    pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::pascal_anda);
                }
                else {
                    pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::pascal_para);
                }
            }
            void Pascal::executar() {
                //???
            }
        } //namespace Inimigo
	} //namespace Personagem
} //namespace Entidade