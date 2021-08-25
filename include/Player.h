#ifndef Player_h
#define Player_h

#include <vector>
#include <string>

using namespace std;

struct Posicao{
    int linha;
    int coluna;
};
class Player{//Em comentário coisas só do Checkpoint 2
    public:
        Player();
        //bool find_solution(int l, int c, int dir, vector<string> mapa, int flinha, int fcoluna);
        int next_move(int linha, int coluna, int direcao, vector<string> mapa);
    private:
        Posicao setFrente(Posicao _atual, int dir);
        Posicao setEsquerda(Posicao _atual, int dir);
        Posicao setDireita(Posicao _atual, int dir);
        //bool naoVisitado(Posicao local);
    
    private:
        //vector<int> solucao;
        //vector<Posicao> visitado;
        //Posicao pos;
        //int direcao;
        //int movimento;
};

#endif