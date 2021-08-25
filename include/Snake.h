#ifndef Snake_h
#define Snake_h

#include <vector>

class Snake{
    public:
        Snake();
        int getLinha();
        int getColuna();
        int getDirecao();
        int getTamanho();
        void setTamanho(int t);
        void addTamanho();
        void zeraTamanho();
        void setPos(int l, int c);
        void turnLeft();
        void turnRight();
        void Move(int movimento);
    private:
        int linha;
        int coluna;
        int direcao;
        int tamanho;
};
#endif