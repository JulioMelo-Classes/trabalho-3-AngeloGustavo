#ifndef Snake_h
#define Snake_h

#include <vector>

class Snake{
    public:
        Snake();
        void setPos(int l, int c);
        void turnLeft();
        void turnRight();
        
        int linha;
        int coluna;
        int direcao;
        
        void Move(int movimento);
    private:
};
#endif