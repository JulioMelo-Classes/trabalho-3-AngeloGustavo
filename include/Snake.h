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
        void addTamanho();
        void zeraTamanho();
        void setPos(int l, int c);
        void Move(int movimento);
        void voltaInicio(Pos inicio);
        Pos getPos();
    private:
        Pos local;//<!
        int tamanho;//<! 
};
#endif