#ifndef Player_h
#define Player_h

#include <vector>
#include <string>
#include <map>
#include "Pos.h"

using namespace std;

class Player{
    public:
        Player();
        bool find_solution(Pos atual, int dir, vector<string> mapa);
        int next_move();
        int getSolucaoTam();
        void printSolucao();
        void clearSolucao();
        //void attMovimento();
        int movimento;
    private:
        Pos setFrente(Pos _atual, int dir);
        Pos setEsquerda(Pos _atual, int dir);
        Pos setDireita(Pos _atual, int dir);
        bool naoVisitado(Pos local);
    
    private:
        //vector<vector<int>> solucao;
        vector<int> solucao;
        vector<Pos> visitado;
        Pos pos;
        int direcao;
};

#endif