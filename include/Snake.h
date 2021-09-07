#ifndef Snake_h
#define Snake_h

#include <vector>
#include "Pos.h"

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
        void voltaInicio(Pos inicio);
        Pos getPos();
    private:
        int linha;//<! 
        int coluna;//<! 
        int direcao;//<! 
        int tamanho;//<! 
};
#endif