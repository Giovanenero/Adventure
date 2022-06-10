#pragma once
#include "Obstaculo.h"

namespace Entidade {
	namespace Obstaculo{
		class Plataforma : public Obstaculo
		{
		public:
			Plataforma(Matematica::CoordenadaF pos);
			~Plataforma();
			void atualizar();
			void inicializacao();
		};
	} //namespace Obstaculo
} //namespace Entidade

