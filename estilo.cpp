#include <iostream>
#include <windows.h>
#include <conio.h>

#include "estilo.h"

using namespace std;

//\xDB

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
               corConsole(15,0); break;
               case 2:
               corConsole(15,1); break;
               case 3:
               corConsole(15,2); break;
               case 4:
               corConsole(15,3); break;
               case 5:
               corConsole(15,4); break;
               case 6:
               corConsole(15,5); break;
               case 7:
               corConsole(15,6); break;
               case 8:
               corConsole(15,14); break;
               case 9:
               corConsole(15,8); break;
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
               corLetra(15); break;
               case 2:
               corLetra(9); break;
               case 3:
               corLetra(10); break;
               case 4:
               corLetra(11); break;
               case 5:
               corLetra(12); break;
               case 6:
               corLetra(13); break;
               case 7:
               corLetra(6); break;
               case 8:
               corLetra(14); break;
               case 9:
               corLetra(7); break;
          }
     }  
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
    gotoxy(23, y);

}

