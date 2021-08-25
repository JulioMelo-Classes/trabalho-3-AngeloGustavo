#include "Level.h"

#include <stdio.h>
#include <stdlib.h>    
#include <time.h> 

using namespace std;

Level::Level(int lin, int col, int com, vector<string> map){
    linhas = lin;
    colunas = col;
    comidaTot = comidaRes = com;
    mapa = map;
    score = 0;
    vidaRes = vidaTot = 5;

    for(int i=0; i<mapa.size(); i++)
        for(int j=0; j<mapa[i].size(); j++){
            if(mapa[i][j] == '*'){
                mapa[i][j] = ' ';
                inicio.linha = i;
                inicio.coluna = j;
            }
            else if(mapa[i][j]==' '){
                Pos aux;
                aux.linha=i;
                aux.coluna=j;
                espacos.push_back(aux);
            }
        }
    
    srand (time(NULL));
    for(int i=0; i<comidaRes; i++){
       posComidas.push_back( espacos[rand() % espacos.size() + 1] );
    }
    comida.linha = posComidas[comidaRes-1].linha;
    comida.coluna = posComidas[comidaRes-1].coluna;
}
int Level::getComidaTotal(){
    return comidaTot;
}
int Level::getJaComidas(){
    return comidaTot - comidaRes;
}
Pos Level::getPosComida(){
    return comida;
}
int Level::getVidaTot(){
    return vidaTot;
}
int Level::getVidaRes(){
    return vidaRes;
}
int Level::getScore(){
    return score;
}
Pos Level::getInicio(){
    return inicio;
}
void Level::perdeuLife(){
    vidaRes--;
    score = 0;
    comidaRes = comidaTot;
    posComidas.clear();
    srand (time(NULL));
    for(int i=0; i<comidaTot; i++){
       posComidas.push_back( espacos[rand() % espacos.size() + 1] );
    }
    comida.linha = posComidas[comidaRes-1].linha;
    comida.coluna = posComidas[comidaRes-1].coluna;
}
void Level::nextFood(){
    comidaRes--;
    comida.linha = posComidas[comidaRes-1].linha;
    comida.coluna = posComidas[comidaRes-1].coluna;
    if(comidaRes<1)
        comida.linha=-1;
}
vector<string> Level::getMapa(){
    return mapa;
}