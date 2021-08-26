#ifndef Level_h
#define Level_h

#include <vector>
#include <string>
#include "Pos.h"

using namespace std;

class Level{
    public:
        Level(int lin, int col, int com, vector<string> map);
        Pos getInicio();
        void nextFood(int solucaoTam);
        Pos getPosComida();
        vector<string> getMapa();
        int getComidaTotal();
        int getJaComidas();
        int getVidaTot();
        int getVidaRes();
        int getScore();
        void perdeuLife();
    private:
        int linhas; //<! linhas do mapa do nivel
        int colunas; //<! colunas do mapa do nivel
        int comidaTot; //<! comidas totais
        int comidaRes; //<! comidas restantes
        int vidaTot; //<! vidas totais
        int vidaRes; //<! vidas restantes
        int score; //<! pontuação do jogo
        Pos inicio; //<! posição do inicio do nivel
        Pos comida; //<! posicão atual da comida
        vector<string> mapa; //<! mapa do nivel
        vector<Pos> espacos; //<! espacos em branco do nivel
};

#endif