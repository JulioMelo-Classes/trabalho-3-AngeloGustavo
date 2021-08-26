#ifndef Player_h
#define Player_h

#include <vector>
#include <string>
#include "Pos.h"

using namespace std;

class Player{//Em comentário coisas só do Checkpoint 2
    public:
        Player();
        //bool find_solution(int l, int c, int dir, vector<string> mapa, int flinha, int fcoluna);
        int next_move(int linha, int coluna, int direcao, vector<string> mapa);
        int getSolucaoTam();
    private:
        Pos setFrente(Pos _atual, int dir);
        Pos setEsquerda(Pos _atual, int dir);
        Pos setDireita(Pos _atual, int dir);
        //bool naoVisitado(Pos local);
    
    private:
        vector<int> solucao;
        //vector<Pos> visitado;
        //Pos pos;
        //int direcao;
        //int movimento;
};

#endif