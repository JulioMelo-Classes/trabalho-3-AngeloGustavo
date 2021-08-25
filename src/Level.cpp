#include "Level.h"

#include <stdio.h>
#include <stdlib.h>    
#include <time.h> 

using namespace std;

Level::Level(int lin, int col, int com, vector<string> map){
    linhas = lin;
    colunas = col;
    comidaRes = com;
    comidaTot = com;
    mapa = map;

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
}
int Level::getComidaTotal(){
    return comidaTot;
}
int Level::getJaComidas(){
    return comidaTot - comidaRes -1;
}
Pos Level::getPosComida(){
    return comida;
}
void Level::nextFood(){
    comidaRes--;
    comida.linha = posComidas[comidaRes].linha;
    comida.coluna = posComidas[comidaRes].coluna;
    if(comidaRes<0)
        comida.linha=-1;
}
Pos Level::getInicio(){
    return inicio;
}
vector<string> Level::getMapa(){
    return mapa;
}