#ifndef Player_h
#define Player_h

#include <vector>
#include <string>
#include <map>
#include "Pos.h"

using namespace std;

class Player{
    public:
        /**
         * @brief Gera vetor de solução
         * 
         * @param atual 
         * @param mapa 
         * @return true 
         * @return false 
         */
        bool find_solution(Pos atual, vector<string> mapa);

        /**
         * @brief Retorna próximo movimento a ser executado
         * 
         * @return int 
         */
        int next_move();

        /**
         * @brief Retorna tamanho da solução
         * 
         * @return int 
         */
        int getSolucaoTam();

        /**
         * @brief Limpa vetor de solução
         * 
         */
        void clearSolucao();

        /**
         * @brief Seta primeiro movimento da solução
         * 
         */
        void setMovimento();

    private:
        /**
         * @brief Seta bloco da frente dependendo da direção
         * 
         * @param atual 
         * @return Pos 
         */
        Pos setFrente(Pos atual);

        /**
         * @brief Seta bloco da esquerda dependendo da direção
         * 
         * @param atual 
         * @return Pos 
         */
        Pos setEsquerda(Pos atual);

        /**
         * @brief Seta bloco da direita dependendo da direção
         * 
         * @param atual 
         * @return Pos 
         */
        Pos setDireita(Pos atual);

        /**
         * @brief Retorna se bloco (e direção) ja foi visitado
         * 
         * @param local 
         * @return true 
         * @return false 
         */
        bool naoVisitado(Pos local);
    
    private:
        int movimento; //<! posicação no vetor do movimento atual
        vector<int> solucao; //<! vetor de inteiros de solução
        vector<Pos> visitado; //<! vetor de posição de blocos visitados
};

#endif