#ifndef Player_h
#define Player_h

#include <vector>
#include <string>

using namespace std;

struct Posicao{
    int linha;
    int coluna;
};
class Player{
    public:
        bool find_solution(vector<string> mapa);
        int next_move();
        void setPos(int l, int c);
        void setDir(int dir);
        Player();
    private:
        Posicao setDireita(int l, int c, int dir);
        Posicao setEsquerda(int l, int c, int dir);
        Posicao setFrente(int l, int c, int dir);
        int movimento;
        vector<int> solucao;
        vector<char> frente1;
        Posicao atual;
        int direcao;
};

#endif