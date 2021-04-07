#include <iostream>
#include <vector>
#include <fstream>

#include "notas.h"
#include "estilo.h"

using namespace std;

void gravaNotas(vector<string> lista_notas)
{
    ofstream arquivo;
    arquivo.open("notas.txt");

    if(arquivo.is_open())
    {   
        arquivo << lista_notas.size() << endl;
        for(string nota : lista_notas)
        {
            arquivo << nota << endl;
        }

        arquivo.close();
    }
    else 
    {
        cout << "Erro ao abrir arquivo de texto" << endl;
        exit(0);
    }
}

void addNotas()
{
    system("cls");

    string nome_materia;
    string nota;
    imprimeMoldura(8);
    gotoxy(24,5); 
    cout << "\xb2 Digite o nome da materia que";
    gotoxy(24,6);
    cout << "voce deseja adicionar: ";
    cin >> nome_materia;
    system("cls");
    imprimeMolduraNota(3);
    gotoxy(0,4);
    cout << "Digite a nota: " << endl;
    cin.ignore();
    getline(cin,nota);

    vector<string> lista_notas = leArquivo();
    lista_notas.push_back(nome_materia);
    lista_notas.push_back(nota);

    gravaNotas(lista_notas);
}

vector<string> leArquivo()
{
    ifstream arquivo;
    arquivo.open("notas.txt");

    if(arquivo.is_open())
    {
        int qtd_notas;
        vector<string> lista_notas;
        arquivo >> qtd_notas;

        for(int i=0;i<qtd_notas;i++)
        {
            string nota_lida;

            if(i%2==0)
            {
                arquivo >> nota_lida;
                lista_notas.push_back(nota_lida);
            }
            else 
            {
                arquivo.ignore(); //importanteee
                getline(arquivo,nota_lida);
                lista_notas.push_back(nota_lida);
            }
        }
        arquivo.close();
        return lista_notas;
    }
    else 
    {
        cout << "Erro ao abrir arquivo de texto" << endl;
        exit(0);
    }
}


void leNotas()
{
    system("cls");

    vector<string> lista_notas = leArquivo();

    for(int i=0; i<lista_notas.size(); i++)
    {
        if(i%2==0)
        {
            system("cls");
            gotoxy(0,3);
            for(int i=0;i<80;i++) cout << "\xdb";
            gotoxy(0,4);
            cout << "Materia: " << lista_notas[i];
            gotoxy(73,4);
            cout << "num: " << i;
        }
        else
        {   
            imprimeMolduraNota(5);
            gotoxy(0,7);
            cout << lista_notas[i];
            char resposta;
            gotoxy(24,18);
            cout << "Deseja continuar? [s/n]";
            cin >> resposta;
            if(resposta=='n') break;
        }
    }
}

void excluiNota()
{
    imprimeMoldura(8);
    
    int num_nota;

    gotoxy(24,5);
    cout << "\xb2 Entre com o numero da nota"; 
    gotoxy(24,6);
    cout << "que deseja apagar: ";
    cin >> num_nota;

    vector<string> lista_notas = leArquivo();
    lista_notas.erase(lista_notas.begin()+num_nota);
    lista_notas.erase(lista_notas.begin()+num_nota);
    gravaNotas(lista_notas);
}

int qtdNotas()
{
    vector<string> lista_notas = leArquivo();
    return lista_notas.size()/2;
}
