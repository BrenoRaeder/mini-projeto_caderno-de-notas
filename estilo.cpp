#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <vector>

#include "estilo.h"
#include "notas.h"

using namespace std;

int letra, fundo; 

COORD xy = {0, 0};

void gotoxy (int x, int y)
{
    xy.X = x; 
    xy.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}

void corLetra(int ForgC)
{
     WORD wColor;
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}

void limpaCores()
{
    corLetra(15);
}

void corConsole(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     COORD coord = {0, 0};
     DWORD count;
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     SetConsoleTextAttribute(hStdOut, wColor);
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
          FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
          SetConsoleCursorPosition(hStdOut, coord);
     }
     return;
}

void imprimeMolduraNota(int y)
{
     gotoxy(0,y);
     for(int i=0;i<80;i++) cout << "\xdb";
     gotoxy(0,y+10);
     for(int i=0;i<80;i++) cout << "\xdb";
}

void imprimeMoldura(int y)
{
     system("cls");
     gotoxy(23,3);
     for(int i=0;i<34;i++) cout << "\xdb";
     gotoxy(23,y);
     for(int i=0;i<34;i++) cout << "\xdb";
     gotoxy(22,3);
     for(int i=0;i<y-2;i++)
     {
          gotoxy(22,3+i); cout << "\xdb";
          gotoxy(57,3+i); cout << "\xdb";
     }
}

void opcCor()
{    
     

     imprimeMoldura(9); //mandadno a altura da moldura
     gotoxy(24,5); cout << "1. Cor de fundo"; 
     gotoxy(24,7); cout << "2. Cor do texto";

     int opc;
     gotoxy(24,11);
     cout << "Entre com a sua opcao: ";
     cin >> opc;

     system("cls");

     if(opc==1)
     {
          imprimeMoldura(23);
          gotoxy(24,5); corLetra(15);
          cout << "1. Preto (padrao)";
          gotoxy(24,7); corLetra(9);
          cout << "2. Azul";
          gotoxy(24,9); corLetra(10);
          cout << "3. Verde";
          gotoxy(24,11); corLetra(11);
          cout << "4. Ciano";
          gotoxy(24,13); corLetra(12);
          cout << "5. Vermelho";
          gotoxy(24,15); corLetra(13);
          cout << "6. Magenta";
          gotoxy(24,17); corLetra(6);
          cout << "7. Marrom";
          gotoxy(24,19); corLetra(14);
          cout << "8. Amarelo (nao recomendado .-.)";
          gotoxy(24,21); corLetra(7);
          cout << "9. Cinza";

          gotoxy(24,24);limpaCores();
          cout << "Entre com a sua opcao: ";
          cin >> opc;

          switch(opc)
          {
               case 1:
               corConsole(15,0); 
               letra = 0; break;
               case 2:
               corConsole(15,1); 
               letra = 1; break;
               case 3:
               corConsole(15,2); 
               letra = 2; break;
               case 4:
               corConsole(15,3); 
               letra = 3; break;
               case 5:
               corConsole(15,4); 
               letra = 4; break;
               case 6:
               corConsole(15,5); 
               letra = 5; break;
               case 7:
               corConsole(15,6); 
               letra = 6; break;
               case 8:
               corConsole(15,14); 
               letra = 14; break;
               case 9:
               corConsole(15,8); 
               letra = 8; break;
          }
     }
     else 
     {
          imprimeMoldura(23);
          gotoxy(24,5); corLetra(15);
          cout << "1. Branco (padrao)";
          gotoxy(24,7); corLetra(9);
          cout << "2. Azul";
          gotoxy(24,9); corLetra(10);
          cout << "3. Verde";
          gotoxy(24,11); corLetra(11);
          cout << "4. Ciano";
          gotoxy(24,13); corLetra(12);
          cout << "5. Vermelho";
          gotoxy(24,15); corLetra(13);
          cout << "6. Magenta";
          gotoxy(24,17); corLetra(6);
          cout << "7. Marrom";
          gotoxy(24,19); corLetra(14);
          cout << "8. Amarelo (nao recomendado .-.)";
          gotoxy(24,21); corLetra(7);
          cout << "9. Cinza";

          gotoxy(24,24);limpaCores();
          cout << "Entre com a sua opcao: ";
          cin >> opc;

          switch(opc)
          {
               case 1:
               corLetra(15); 
               fundo = 15; break;
               case 2:
               corLetra(9); 
               fundo = 9; break;
               case 3:
               corLetra(10); 
               fundo = 10; break;
               case 4:
               corLetra(11); 
               fundo = 11; break;
               case 5:
               corLetra(12); 
               fundo = 12; break;
               case 6:
               corLetra(13); 
               fundo = 13; break;
               case 7:
               corLetra(6); 
               fundo = 6; break;
               case 8:
               corLetra(14); 
               fundo = 14; break;
               case 9:
               corLetra(7); 
               fundo = 7; break;
          }
     } 

     gravaCor(letra,fundo); 
}

vector<int> leCorArquivo()
{
     ifstream (arquivo);
     arquivo.open("cores.txt");

     if(arquivo.is_open())
     {
          vector<int> configuracao_cores;
          for(int i=0; i<2;i++)
          {
               int num;
               arquivo >> num;
               configuracao_cores.push_back(num);
          } 

          arquivo.close();
          return configuracao_cores;
     }
     else
     {
          cout << "Erro na leitura do arquivo." << endl;
          exit(0);
     }
}

void gravaCor(int letra, int fundo)
{
     ofstream arquivo;
     arquivo.open("cores.txt");

     if(arquivo.is_open())
     {
          arquivo << letra << endl;
          arquivo << fundo << endl;

          arquivo.close();
     }
     else
     {
          cout << "Erro na leitura do arquivo." << endl;
          exit(0);
     }
}

void configuracoesCores()
{
     vector<int> config = leCorArquivo();
     
     letra = config[1];
     fundo = config[0];
     corConsole(15,fundo);
     corLetra(letra);
}

void menu()
{
    system("cls");
    gotoxy(23,3);
    for(int i=0;i<14;i++) cout << "\xB2";
    cout << " Menu ";
    for(int i=0;i<14;i++) cout << "\xB2";
    cout << endl;

    int y = 5;

    gotoxy(23,y); y+=2;
    cout << "\xdb\xdb\xdb\xb2 1. Add nota" << endl;
    gotoxy(23,y); y+=2;
    cout << "\xdb\xdb\xdb\xb2 2. Deletar nota" << endl;
    gotoxy(23, y); y+=2;
    cout << "\xdb\xdb\xdb\xb2 3. Ler notas" << endl;
    gotoxy(23, y); y+=2;
    cout << "\xdb\xdb\xdb\xb2 4. Opcoes de cor" << endl;
    gotoxy(23, y); y+=2;
    cout << "\xdb\xdb\xdb\xb2 0. Sair" << endl;
    gotoxy(23, y); y+=2;
    for(int i=0;i<34;i++) cout << "\xB2";
    gotoxy(27,y); y+=2;
    cout << "Quantidade de nota(s): " << qtdNotas();
    gotoxy(27,y);
}

