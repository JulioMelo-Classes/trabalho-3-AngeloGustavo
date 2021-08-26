#include "SnakeGame.h"
#include "Pos.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>

#include <chrono> //por causa do sleep
#include <thread> //por causa do sleep

using namespace std;

queue<Pos> rabo;

SnakeGame::SnakeGame(string arg1, bool arg2){
    arquivo = arg1;
    temRabo = arg2;
    cabecas = {'v','<','^','>'};
    vidas = {"","♥    ","♥♥   ","♥♥♥  ","♥♥♥♥ ", "♥♥♥♥♥"};
    lvl = 0;
    choice = "";
    frameCount = 0;
    initialize_game();
}

void SnakeGame::initialize_game(){
    //carrega o nivel ou os níveis
    ifstream levelFile(arquivo); 
    string line;
    stringstream ss;
    if(levelFile.is_open()){
        while(getline(levelFile, line)){ //pega cada linha do arquivo
            vector<string> mapaaux;
            int linhas, colunas, comidas;
            
            ss.clear();
            ss << line;
            ss >> linhas;
            ss >> colunas;
            ss >> comidas;
            
            for(int i=0; i<linhas; i++){
                getline(levelFile, line);
                mapaaux.push_back(line);
            }
            
            Level levelaux(linhas, colunas, comidas, mapaaux);
            niveis.push_back(levelaux);
        }
    }
    
    maze = niveis[lvl].getMapa();
    cobra.setPos(niveis[lvl].getInicio().linha, niveis[lvl].getInicio().coluna);
    maze[ (niveis[lvl].getPosComida()).linha ][ (niveis[lvl].getPosComida()).coluna ] = 'F';
    //Checkpoint 2
    //jogador.find_solution(cobra.getLinha(),cobra.getColuna(),cobra.getDirecao(),maze,comida.linha,comida.coluna);

    state = RUNNING;
}

void SnakeGame::process_actions(){
    //processa as entradas do jogador de acordo com o estado do jogo
    //nesse exemplo o jogo tem 3 estados, WAITING_USER, RUNNING e GAME_OVER.
    //no caso deste trabalho temos 2 tiPos de entrada, uma que vem da classe Player, como resultado do processamento da IA
    //outra vem do próprio usuário na forma de uma entrada do teclado.
    switch(state){
        case WAITING_USER: //o jogo bloqueia aqui esperando o usuário digitar a escolha dele
            cin>>std::ws>>choice;
            break;
        case RUNNING:
            movimento = jogador.next_move(cobra.getLinha(), cobra.getColuna(), cobra.getDirecao(), niveis[lvl].getMapa());
            break;
        default:
            //nada pra fazer aqui
            break;
    }
}
void SnakeGame::print_placar(){
    cout<<"------------------------------------------------------"<<endl;
    cout<<"Vidas: "<<vidas[niveis[lvl].getVidaRes()]<<" | Pontuação: "<<niveis[lvl].getScore()<<" | Maçãs comidas: "<<niveis[lvl].getJaComidas()<<" de "<<niveis[lvl].getComidaTotal()<<endl;
    cout<<"------------------------------------------------------"<<endl;
}
void SnakeGame::update(){
    //atualiza o estado do jogo de acordo com o resultado da chamada de "process_input"
    switch(state){
        case RUNNING:
            if(maze[cobra.getLinha()][cobra.getColuna()]=='F'){    
                maze[ (niveis[lvl].getPosComida()).linha ][ (niveis[lvl].getPosComida()).coluna ] = ' ';
                cobra.addTamanho();//Adiciona unidade a tamanho da cobra
                niveis[lvl].nextFood(jogador.getSolucaoTam());//Próxima comida e adição de pontos por sucesso
                if((niveis[lvl].getPosComida()).linha == -1){
                    state = WAITING_USER;
                    if(lvl > niveis.size()-2){
                        state = GAME_OVER;
                        overstates = WIN;
                    }
                }
                else
                    maze[ (niveis[lvl].getPosComida()).linha ][ (niveis[lvl].getPosComida()).coluna ] = 'F';
            }
            else if(maze[cobra.getLinha()][cobra.getColuna()]=='#' || maze[cobra.getLinha()][cobra.getColuna()]=='o'){ 
                if(niveis[lvl].getVidaRes() > 1 ){
                    //Reseta nivel
                    niveis[lvl].perdeuLife();
                    cobra.voltaInicio(niveis[lvl].getInicio());
                    maze = niveis[lvl].getMapa();
                    maze[ (niveis[lvl].getPosComida()).linha ][ (niveis[lvl].getPosComida()).coluna ] = 'F';
                    cobra.zeraTamanho();
                    while(!rabo.empty())
                        rabo.pop();                   
                }
                else{
                    state = GAME_OVER;
                    overstates = HIT;
                }
            }

            //Desenho do rabo (levar para Snake?) 
            if(temRabo == true){//Desenha unidade do corpo no local passado pela cabeça da cobra
                Pos aux;
                aux.linha=cobra.getLinha();
                aux.coluna=cobra.getColuna();
                rabo.push(aux);
                maze[cobra.getLinha()][cobra.getColuna()]='o';
            }
            if(rabo.size()>cobra.getTamanho()){//Apaga unidade da trás caso não tenha comido nesse frame
                maze[(rabo.front()).linha][(rabo.front()).coluna] = ' ';
                if(((rabo.front()).linha == (niveis[lvl].getPosComida().linha))&&
                   ((rabo.front()).coluna == (niveis[lvl].getPosComida().coluna)))
                   maze[ (niveis[lvl].getPosComida()).linha ][ (niveis[lvl].getPosComida()).coluna ] = 'F';//tirar espacos de rabo]]]]]]
                rabo.pop();
            }
            
            if(frameCount>0) 
                cobra.Move(movimento);
                //cobra.Move(jogador.next_move()); //Checkpoint 2
                

            break;
        case WAITING_USER: //se o jogo estava esperando pelo usuário então ele testa qual a escolha que foi feita
            if(choice == "n"){
                state = GAME_OVER;
                game_over();
            }
            else{    
                //começo do level
                maze.clear();
                cobra.zeraTamanho();
                while(!rabo.empty())
                    rabo.pop();
                lvl++;
                maze = niveis[lvl].getMapa();
                cobra.setPos(niveis[lvl].getInicio().linha, niveis[lvl].getInicio().coluna);
                //niveis[lvl].nextFood();
                maze[ (niveis[lvl].getPosComida()).linha ][ (niveis[lvl].getPosComida()).coluna ] = 'F';
                state = RUNNING;
            }
            break;
        default:
            //nada pra fazer aqui
            break;
    }
}

/**
 * @brief função auxiliar para fazer o programa esperar por alguns milisegundos
 * @param ms a quantidade de segundos que o programa deve esperar
 */
void wait(int ms){
    this_thread::sleep_for(chrono::milliseconds(ms));
}

/**
 * @brief função auxiliar para limpar o terminal
 */
void clearScreen(){
//some C++ voodoo here ;D
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

void SnakeGame::render(){
    clearScreen();
    switch(overstates){
        case WIN:
            cout<<"Você passou de todas as fases. Parabéns!!"<<endl;
            break;
        case HIT:
            cout<<"Parece que sua cobra bateu a cabeça! :°"<<endl;
            break;
    }
    switch(state){
        case RUNNING:
            print_placar();
            //desenha todas as linhas do labirinto
            for(int i=0; i<maze.size(); i++){
                for(int j=0; j<maze[i].size(); j++){
                    if(i==cobra.getLinha() and j==cobra.getColuna()) cout<<cabecas[cobra.getDirecao()];
                    else if(maze[i][j]=='F')
                        cout<<"●";
                    else cout<<maze[i][j];
                }
                cout<<endl;
            }
            break;
        case WAITING_USER:
            cout<<"Você quer continuar com o jogo? (s/n)"<<endl;
            break;
        case GAME_OVER:
            cout<<"O jogo terminou!"<<endl;
            break;
    }
    frameCount++;
}

void SnakeGame::game_over(){
}

void SnakeGame::loop(){
    while(state != GAME_OVER){
        process_actions();
        update();
        render();
        wait(50);// espera 1 segundo entre cada frame
    }
}
