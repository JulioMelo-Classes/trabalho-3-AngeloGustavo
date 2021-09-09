#include "Player.h"
#include "Pos.h"

#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;

Player::Player(){
    //movimento=0;
}
Pos Player::setFrente(Pos _atual, int dir){
    switch(dir){
        case 0:
            _atual.linha--;
            break;
        case 1:
            _atual.coluna++;
            break;
        case 2:
            _atual.linha++;
            break;
        default:
            _atual.coluna--;
    }
    return _atual;
}
Pos Player::setEsquerda(Pos _atual, int dir){
    switch(dir){
        case 0:
            _atual.coluna--;
            break;
        case 1:
            _atual.linha--;
            break;
        case 2:
            _atual.coluna++;
            break;
        default:
            _atual.linha++;
    } 
    return _atual;
}
Pos Player::setDireita(Pos _atual, int dir){
    switch(dir){
        case 0:
            _atual.coluna++;
            break;
        case 1:
            _atual.linha++;
            break;
        case 2:
            _atual.coluna--;
            break;
        default:
            _atual.linha--;
    }  
    return _atual;
}
void Player::printSolucao(){
    cout<<"movimento "<<solucao.size()-movimento<<": "<<solucao[movimento-1]<<endl;
    for(int i=solucao.size()-1; i>=0; i--){
        if(i==movimento-1)
            cout<<"["<<solucao[i]<<"]";
        else
            cout<<solucao[i];
    }
    cout<<endl;
}
void Player::clearSolucao(){
    solucao.clear();
    visitado.clear();
}
bool Player::find_solution(Pos atual, int dir, vector<string> mapa){
    Pos frente, esquerda, direita;

    int diresq, dirdir;
    diresq = dir-1;
        if(diresq<0)
            diresq=3;
    dirdir = dir+1;
        if(dirdir>3)
            dirdir=0;

    frente = setFrente(atual, dir);
    esquerda = setEsquerda(atual, dir);
    direita = setDireita(atual, dir);
    
    if(mapa[atual.linha][atual.coluna]=='F')
        return true;
    else if(mapa[frente.linha][frente.coluna] != '#' && find_solution(frente, dir, mapa) && naoVisitado(frente, dir)){
        solucao.push_back(0);
        return true;
    }
    else if(mapa[esquerda.linha][esquerda.coluna] != '#' && find_solution(esquerda, diresq, mapa) && naoVisitado(esquerda, (dir-1)%4)){
        solucao.push_back(1);
        return true;
    }
    else if(mapa[direita.linha][direita.coluna] != '#' && find_solution(direita, dirdir, mapa) && naoVisitado(direita, (dir+1)%4)){
        solucao.push_back(2);
        return true;
    }
    return false;
}
int Player::next_move(){
    movimento--;
    return solucao[movimento];
}

int Player::getSolucaoTam(){
    return solucao.size();
}

bool Player::naoVisitado(Pos local, int dir){
    //for(auto i=visitado.begin(); i!=visitado.end(); i++)
        //if(i->first.linha == local.linha && i->first.coluna == local.coluna && i->second == dir)
            //return false;
    return true;
}


/*Pos frente, esquerda, direita;
Pos aux;
aux.linha = linha;
aux.coluna = coluna;

frente = setFrente(aux, direcao);
esquerda = setEsquerda(aux, direcao);
direita = setDireita(aux, direcao);

if(mapa[frente.linha][frente.coluna] == ' ')
    return 0;
else if(mapa[esquerda.linha][esquerda.coluna] == ' ')
    return 1;
else if(mapa[direita.linha][direita.coluna] == ' ')
    return 2;
else    
    return 0;
//Checkpoint 2


bool Player::find_solution(int l, int c, int dir, vector<string> mapa, int flinha, int fcoluna){    
    Pos frente, esquerda, direita;
    Pos atual;
    atual.linha=l;
    atual.coluna=c;
    bool aux;
    int diraux;

    movimento=0;
    solucao.clear();

    frente = setFrente(atual, dir);
    esquerda = setEsquerda(atual, dir);
    direita = setDireita(atual, dir);
    if(solucao.size()>0)
        cout<<solucao[solucao.size()-1];

    if(l==flinha && c==fcoluna)
        return true;
    else if(mapa[frente.linha][frente.coluna] != '#' && naoVisitado(frente)){
        visitado.push_back(frente);
        solucao.push_back(0);

        if(find_solution(frente.linha, frente.coluna, dir, mapa, flinha, fcoluna)){
            //solucao.push_back(0);
            return true;
        }
        solucao.pop_back();
        return false;
    }   
    else if(mapa[esquerda.linha][esquerda.coluna] != '#' && naoVisitado(esquerda)){
        visitado.push_back(esquerda);
        solucao.push_back(1);
        
        diraux = dir-1;
        if(diraux<0)
            diraux=3;

        if(find_solution(esquerda.linha, esquerda.coluna, diraux, mapa, flinha, fcoluna)){
            //solucao.push_back(1);
            return true;
        }
        solucao.pop_back();
        return false;
    }   
    else if(mapa[direita.linha][direita.coluna] != '#' && naoVisitado(direita)){
        visitado.push_back(direita);
        solucao.push_back(2);

        diraux = dir+1;
        if(diraux>3)
            diraux=0;

        if(find_solution(direita.linha, direita.coluna, diraux, mapa, flinha, fcoluna)){
            //solucao.push_back(2);
            return true;
        }
        solucao.pop_back();
        return false;
    }   
    return false;
}*/