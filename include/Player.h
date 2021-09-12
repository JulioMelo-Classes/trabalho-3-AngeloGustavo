#ifndef Player_h
#define Player_h

#include <vector>
#include <string>
#include <map>
#include "Pos.h"

using namespace std;

class Player{
    public:
        bool find_solution(Pos atual, vector<string> mapa);
        int next_move();
        int getSolucaoTam();
        void printSolucao();
        void clearSolucao();
        int movimento;
    private:
        Pos setFrente(Pos atual);
        Pos setEsquerda(Pos atual);
        Pos setDireita(Pos atual);
        bool naoVisitado(Pos local);
    
    private:
        vector<int> solucao;
        vector<Pos> visitado;
};

#endif