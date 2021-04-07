#include <iostream>
#include <vector>

#include "estilo.h"
#include "notas.h"

using namespace std;

int main()
{
    int opc = 1;
    bool sair = false;

    configuracoesCores();

    while(!sair)
    {
        menu();
        cout << "Entre com a sua opcao: ";
        cin >> opc;
        switch(opc)
        {
            case 1:
            addNotas(); break;
            
            case 2: 
            excluiNota(); break;
            
            case 3: 
            leNotas(); break;

            case 4:
            opcCor(); break;

            case 0: 
            sair=true;
        }
    }

    corConsole(15,0);
    
    return 0;
}