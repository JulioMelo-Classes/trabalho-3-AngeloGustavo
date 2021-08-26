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
