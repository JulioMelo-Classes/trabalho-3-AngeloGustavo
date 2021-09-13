#include <iostream>
#include <sstream>
#include <string>
#include "SnakeGame.h"

using namespace std;

int main(int argc, char *argv[]){
    bool temRabo = false;
    if(argv[2])
        if(string(argv[2]) == "1") 
            temRabo = true;

    SnakeGame game(argv[1], temRabo);    
    game.loop(); //bloqueia aqui e só saí quando o jogo termina
    
    return 0;
}