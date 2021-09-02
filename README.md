# LP1 Projeto 3: Snaze

## O que é o Snaze
Uma simulação do jogo clássico Snake arcade video game, porém com a cobra presa em um labirinto.

## Organização
Os arquivos ```.cpp``` estão na pasta  **<em>src</em>**, os ```.h``` na pasta **<em>include</em>**, os scripts em **<em>data</em>** e, após criado, os arquivos de compilação em **<em>build</em>**.

## Como compilar o projeto
Na pasta do projeto realize os próximos comandos para compilar o programa com cmake.
```console
mkdir build
cd build
cmake ..
cmake --build .
```

## Como executar o projeto
Após o executavel ```./snaze``` o primeiro argumento deve ser o endereço de um arquivo de texto (```.txt```) com os dados de tamanho e comidas para cada nível e os seus mapas, e o segundo é o inteiro ```1``` (modo com rabo) ou ```0``` (modo sem rabo) que remetem aos modos do snaze.
```console
./snaze ../data/maze0.txt 1
```
## Autor

Angelo Gustavo Souza Marinho Morais de Sales -
[GitHub](https://github.com/AngeloGustavo)

## Contato

Angelo Gustavo Souza Marinho Morais de Sales -
*<angelo.sales.703@ufrn.edu.br>*

Link do projeto: [https://github.com/JulioMelo-Classes/trabalho-3-AngeloGustavo.git](https://github.com/JulioMelo-Classes/trabalho-3-AngeloGustavo.git)

## Avaliação CP1

### Snake/Pacman
O jogo deveria conter o modo snake/pacman. Em ambos os modos não é possível andar pra trás. No modo snake deve ser desenhado o corpo.

**Avaliação**

Ok

### Render.ui
O jogo deveria desenhar a UI corretamente, mostrando ao menos as vidas, o nível e o score.

**Avaliação**

Ok

### Render.mapa
O jogo deveria desenhar o mapa corretamente, com base no arquivo passado como argumento. Ok

**Avaliação**

Ok

### Render.snake
O jogo deveria desenhar a snake corretamente.

**Avaliação**
Ok

### Transição de mapas
O jogo deve ter transição de mapa uma vez que um mapa é terminado. Não implementado.

**Avaliação**

Não implementado.

### Logic.colisão e Logic.comida
O jogo deve se comportar corretamente quando ocorre uma colisão com comida e com paredes.

**Avaliação**

ok

### Interação com o usuário
O jogo deve perguntar ao usuário se quer continuar/reiniciar o nível/reiniciar o jogo a cada transição de mapa

**Avaliação**

Ok

### Classe Level ou similar
O software deve encapsular as funcionalidades do nível em uma classe.

**Avaliação**

Ok

### Classe Player ou similar
O software deve encapsular as decisões do jogo em uma classe.

**Avaliação**

Ok

### Classe Snake ou similar
O software deve encapsular as funcionalidades relacionadas à snake em uma classe. 

**Avaliação**

OK

## Comentários gerais CP1

- No cp 1 você deveria tomar uma decisão aleatória na classe palyer, como a gente conversou na entrevista a forma como vc fez causa a cobrinha a sempre tomar a mesma decisão. No seu caso era uma questão de colocar as possibilidades em um vetor e depois escolher uma delas aleatóriamente.
- A decisão de separar cobra e rabo não tem sentido em termos lógicos como conversei com você na entrevista. O melhor seria que a classe snake tivesse também o rabo. Inclusive muitos dos testes que você faz em snakegame poderiam ser colocados dentro da classe snake ou da classe mapa, dependendo de qual teste é realizado e de quem tem direito sobre os dados.
- O carregamento de mapas poderia ir para a classe level de alguma forma. Seria um bom ponto para um método estático!