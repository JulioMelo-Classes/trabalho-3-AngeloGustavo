#include <iostream>
#include "SnakeGame.h"

using namespace std;

int main(int argc, char *argv[]){
    bool temRabo;
    if(argv[1]=="1") temRabo=true;
    else temRabo = false;

    SnakeGame game(temRabo, argv[2]);
    game.loop(); //bloqueia aqui e só saí quando o jogo termina
    

    return 0;
}