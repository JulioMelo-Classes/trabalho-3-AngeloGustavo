#ifndef Level_h
#define Level_h

#include <vector>
#include <string>
#include "Pos.h"

using namespace std;

class Level{
    public:
    
        /**
         * @brief Construtor de Level 
         * 
         * @param lin 
         * @param col 
         * @param com 
         * @param map 
         */
        Level(int lin, int col, int com, vector<string> *map);
    
        /**
         * @brief Retorna posição de inicio do nivel
         * 
         * @return Pos 
         */
        Pos getInicio();
    
        /**
         * @brief Gera posição para próxima comida
         * 
         * @param solucaoTam 
         */
        void nextFood(int solucaoTam);
    
        /**
         * @brief Retorna posição de comida
         * 
         * @return Pos 
         */
        Pos getPosComida();
    
        /**
         * @brief Retorna mapa do nivel
         * 
         * @return vector<string> 
         */
        vector<string> getMapa();
    
        /**
         * @brief Retorna total de comidas do nivel
         * 
         * @return int 
         */
        int getComidaTotal();
    
        /**
         * @brief Retorna comidas ja comidas do nivel
         * 
         * @return int 
         */
        int getJaComidas();
    
        /**
         * @brief Retorna vida restante do nivel
         * 
         * @return int 
         */
        int getVidaRes();
    
        /**
         * @brief Retorna pontuação
         * 
         * @return int 
         */
        int getScore();
    
        /**
         * @brief Reduz uma unidade de vidas do nivel
         * 
         */
        void perdeuLife();
    
        /**
         * @brief Resta atributos do nivel
         * 
         */
        void resetLevel();
    
        /**
         * @brief Retorna posição aleátoria elegivel para modo Random Start
         * 
         * @return Pos 
         */
        Pos espacoAleatorio();
    
    private:
        int linhas; //<! linhas do mapa do nivel
        int colunas; //<! colunas do mapa do nivel
        int comidaTot; //<! comidas totais
        int comidaRes; //<! comidas restantes
        int vidaTot; //<! vidas totais
        int vidaRes; //<! vidas restantes
        int score; //<! pontuação do jogo
        Pos inicio; //<! posição do inicio do nivel
        Pos comida; //<! posicão atual da comida
        vector<string> mapa; //<! mapa do nivel
        vector<Pos> espacos; //<! espacos em branco do nivel
        
};

#endif