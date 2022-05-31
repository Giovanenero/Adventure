#pragma once
#include "Obstaculo.h"

namespace Entidade {
	namespace Obstaculo{
		class Plataforma : public Obstaculo
		{
		public:
			Plataforma(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id);
			~Plataforma();
			void atualizar();
			void inicializacao();
			void executar();
		};
	} //namespace Obstaculo
} //namespace Entidade

