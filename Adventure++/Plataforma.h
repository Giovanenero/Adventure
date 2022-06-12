#pragma once
#include "Obstaculo.h"

namespace Entidade {
	namespace Obstaculo{
		class Plataforma : public Obstaculo
		{
		public:
			Plataforma(Matematica::CoordenadaF pos);
			~Plataforma();
			void inicializacao();
			void atualizar();
		};
	} //namespace Obstaculo
} //namespace Entidade

