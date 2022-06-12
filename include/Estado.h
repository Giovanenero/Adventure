#pragma once

namespace Estados {

    class MaquinaEstados;

    enum IDestado {
        desconhecido = -1,
        menuPrincipal = 0,
        novoJogo,
        menuJogadorFloresta,
        menuJogadorCaverna,
        jogandoFloresta,
        jogandoCaverna,
        menuPausa,
        configuracoes,
        colocacao,
        fimDeJogo
    };
    //Baseado em tutorial de Matheus Burda: https://www.youtube.com/watch?v=2vFLfO-PKcw&list=PLSPev71NbUEBIQlT2QCd-gN6l_mNVw1cJ&index=13
    class Estado {

    protected:
        MaquinaEstados *pSM;
        IDestado id;
    public:
        Estado(MaquinaEstados *pSM = nullptr, Estados::IDestado id = desconhecido);

        virtual ~Estado();

        void setMaquinaEstado(MaquinaEstados *pSM);

        void mudarEstado(Estados::IDestado id);

        Estados::IDestado getID() const;

        virtual void atualizar(const float dt) = 0;

        virtual void renderizar() = 0;

        virtual void resetEstado() = 0;
    };
}
