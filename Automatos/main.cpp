#include <iostream>
#include <string.h>


using namespace std;

#include "funcaoPrograma.h"

int main()
{
    char **variaveis,estadoInicial[5],estadoFinal[20];
    int qntestados,qntestadosfinais,qntVariaveis;
    char buffer[100];

    cout<<"Insira a definicao do AFN \n";

    cout<<"Quantidade de Estados\n";
    cin>>qntestados;

    cout<<"\nQuantidade de  Simbolos de entrada \n";
    cin>>qntVariaveis;
    variaveis = new char*[qntVariaveis];

    cout<<"Preencha com os Simbolos de entrada\n";
    for(int i = 0; i < qntVariaveis; i++){
        variaveis[i] = new char[10];
        cin>>variaveis[i];
    }

    cout<<"\nEstado Inicial\n";
    cin>>estadoInicial;


    cout<<"Quantidade de estados Finais\n";
    cin>>qntestadosfinais;

    cout<<"Conjunto de Estados Finais\n";
    for(int i = 0; i < qntestadosfinais; i++){
        cin>>buffer;
        strcat(estadoFinal,buffer);
    }

    FuncaoPrograma Automato(variaveis,qntestados,qntVariaveis,estadoInicial,estadoFinal);

    Automato.PreencherCombinacoes();
    Automato.getMafn();
    Automato.VerificarUteis();
    Automato.getMafd();
    Automato.NewFuncaoPrograma();


}
