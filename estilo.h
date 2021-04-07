#ifndef ESTILO_H
#define ESTILO_H

#include <vector>



/*class estilo
{
    public: 
        void teste();
};*/

void imprimeMolduraNota(int y);
void imprimeMoldura(int y);
void opcCor();
void menu();
void gotoxy (int x, int y);
void corLetra(int ForgC);
void limpaCores();
void corConsole(int ForgC, int BackC);
void gravaCor(int letra, int fundo);
std::vector<int> leCorArquivo();
void configuracoesCores();

#endif