#ifndef Level_h
#define Level_h

#include <vector>
#include <string>

using namespace std;

struct Pos{
    int linha;
    int coluna;
};
class Level{
    public:
        Level(int lin, int col, int com, vector<string> map);
        Pos getInicio();
        void nextFood();
        Pos getPosComida();
        vector<string> getMapa();
    private:
        int linhas;
        int colunas;
        int comidas;
        Pos inicio;
        Pos comida;
        vector<string> mapa;
        vector<Pos> espacos;
        vector<Pos> posComidas;
};

#endif