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
    cout << "Digite o nome da materia que vc deseja adicionar: " << endl;
    cin >> nome_materia;
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
            cout << "Materia: " << lista_notas[i] << endl;
        }
        else
        {
            cout << "Nota: " << endl << lista_notas[i] << endl;
        }
    }

    system("pause");
}

