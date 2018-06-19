#include <iostream>
#include <string.h>
#include <math.h>
#include <iomanip>
using std::setw;
using namespace std;

#include "funcaoPrograma.h"


FuncaoPrograma :: FuncaoPrograma(char **variaveis,int qntestados,int qntVariaveis,char *inicial,char *fim)
    {
        chave = qntestados;
        this->variaveis = variaveis;
        qnt_transicoes = pow(2,chave) - 1;
        estadoI = inicial;
        estadoF = fim;
        qnt_variaveis = qntVariaveis;

        Uteis = new bool[qnt_transicoes];
        Uteis[0] = true;
        for(int i = 1; i < qnt_transicoes; i++) Uteis[i] = false;

}
FuncaoPrograma :: ~FuncaoPrograma()
{

    for(int i = 0; i < qnt_transicoes; i++)
        for(int j = 0; j < qnt_variaveis; j++) delete []transicoes[i][j];
    for(int i = 0; i < qnt_transicoes; i++) delete []transicoes[i];
    delete []transicoes;


}

void FuncaoPrograma ::  PreencherCombinacoes()
{
    combinacoes = new char*[qnt_transicoes];
    for(int i = 0; i < qnt_transicoes; i++) combinacoes[i] = new char[10];

    transicoes = new char**[qnt_transicoes];
    for(int i = 0; i < qnt_transicoes; i++) transicoes[i] = new char*[qnt_variaveis];
    for(int i = 0; i < qnt_transicoes; i++)
        for(int j = 0; j < qnt_variaveis; j++) transicoes[i][j] = new char[10];


    cout<<"\nPreencha com a funcao programa\n";
    if(chave > 0){
        strcpy(combinacoes[0],"q0");
        preencherTransicoes(combinacoes[0],0);
    }if(chave > 1){
        strcpy(combinacoes[1],"q1");
        preencherTransicoes(combinacoes[1],1);
        strcpy(combinacoes[2],"q0q1");
        preencherTransicoes(combinacoes[2],2);
    }if(chave > 2){
        strcpy(combinacoes[3],"q2");
        preencherTransicoes(combinacoes[3],3);
        strcpy(combinacoes[4],"q0q2");
        preencherTransicoes(combinacoes[4],4);
        strcpy(combinacoes[5],"q1q2");
        preencherTransicoes(combinacoes[5],5);
        strcpy(combinacoes[6],"q0q1q2");
        preencherTransicoes(combinacoes[6],6);
    }if(chave > 3){
        strcpy(combinacoes[7],"q3");
        preencherTransicoes(combinacoes[7],7);
        strcpy(combinacoes[8],"q0q3");
        preencherTransicoes(combinacoes[8],8);
        strcpy(combinacoes[9],"q1q3");
        preencherTransicoes(combinacoes[9],9);
        strcpy(combinacoes[10],"q2q3");
        preencherTransicoes(combinacoes[10],10);
        strcpy(combinacoes[11],"q0q1q3");
        preencherTransicoes(combinacoes[11],11);
        strcpy(combinacoes[12],"q0q2q3");
        preencherTransicoes(combinacoes[12],12);
        strcpy(combinacoes[13],"q1q2q3");
        preencherTransicoes(combinacoes[13],13);
        strcpy(combinacoes[14],"q0q1q2q3");
        preencherTransicoes(combinacoes[14],14);
    }
}
void FuncaoPrograma :: preencherTransicoes(char *combinacao,int i)
{
    for(int j = 0; j < qnt_variaveis; j++){
        cout<<"({"<<combinacao<<"},"<<variaveis[j]<<") = ";
        cin>>transicoes[i][j];
    }
}

void FuncaoPrograma :: VerificarUteis()
{
        int i,j,k;
        for(i = 0; i < qnt_transicoes;i++){
            for(j = 0; j < qnt_variaveis; j++){
                for(k = i; k < qnt_transicoes; k++){
                    if(strcmp(transicoes[i][j],combinacoes[k]) == 0 && !Uteis[k]){
                        Uteis[k] = true;
                        break;
                    }
                }
            }
            if(Uteis[i+1] == false && i < qnt_transicoes){
                while(!Uteis[i+1] && i < qnt_transicoes ) i++;
            }
        }
}

void FuncaoPrograma :: NewFuncaoPrograma()
{
        int i,j,k;
        cout<<"\nFuncao Programa (P)\nEstado      ";
        for(k = 0; k < qnt_variaveis; k++) cout<<variaveis[k]<<"           ";
        cout<<"\n\n";
        for(i = 0; i < qnt_transicoes; i++)
        {
            if(Uteis[i]){
                cout<<combinacoes[i];
                for(k = 0; k < 12 - strlen(combinacoes[i]);k++) cout<<" ";
                for(j = 0; j < qnt_variaveis; j++)
                {
                    cout<<transicoes[i][j];
                    for(k = 0; k < 12 - strlen(transicoes[i][j]); k++) cout<<" ";
                }
                cout<<endl;
            }
        }
    }

void FuncaoPrograma :: getMafn()
{

        int i,j,k;
        char *p;

        cout<<"\nDefinicao do AFN\n\n";
        cout<<"M = ({";
        if(chave > 0)cout<<"q0";
        if(chave > 1)cout<<",q1";
        if(chave > 2)cout<<",q2";
        if(chave > 3)cout<<",q3";
        cout<<"},{";
        for(i = 0; i < qnt_variaveis; i++){
            cout<<variaveis[i];
            if(i < qnt_variaveis - 1) cout<<",";
        }
        cout<<"},P,"<<estadoI<<",{";
        for(i = 0; (finalcpy[i] = estadoF[i]) != NULL; i++);
        p = strtok(finalcpy,"q");
        while(p != NULL){
            cout<<"q"<<p<<",";
            p = strtok(NULL,"q");
        }
        cout<<"})\n";
        cout<<"funcao Programa (P) :\n";
        cout<<"          ";
        for(i = 0; i < qnt_variaveis; i++) cout<<variaveis[i]<<"             ";
        cout<<endl;
        for(i = 0; i < qnt_transicoes; i++){
            cout<<combinacoes[i];
            for(k = 0; k < 10 - strlen(combinacoes[i]); k++) cout<<" ";
            for(j = 0; j < qnt_variaveis; j++){
                cout<<transicoes[i][j]<<"  ";
                for(k = 0; k < 12 - strlen(transicoes[i][j]); k++) cout<<" ";
            }
            cout<<endl;
        }
}
void FuncaoPrograma :: getMafd()
{

            int i,j,k;
            char *p;
            bool Uteiscpy[qnt_transicoes];

            cout<<"\nDefinicao do AFD :\n\n";
            cout<<"M = ({";
            for(i = 0; i < qnt_transicoes; i++){
                if(Uteis[i]){
                    cout<<combinacoes[i];
                    if(i < qnt_transicoes - 1) cout<<",";
                }
            }
            cout<<"},{";
            for(i = 0;i < qnt_variaveis; i++){
                cout<<variaveis[i];
                if(i < qnt_variaveis - 1) cout<<",";
            }
            cout<<"},P,"<<estadoI<<",{";

            for(i = 0; i < qnt_transicoes; i++) Uteiscpy[i] = Uteis[i];

            p = strtok(estadoF,"q");
            char copia[10], *q;
            while (p != NULL){
                for(i = 0; i < qnt_transicoes; i++){
                    if(Uteis[i]){
                        strcpy(copia,combinacoes[i]);
                        q = strtok(copia,"q");
                        while(q != NULL){
                            if(strcmp(q,p) == 0){
                                cout<<combinacoes[i]<<",";
                                Uteiscpy[i] = false;
                            }
                            q = strtok(NULL,"q");
                        }
                    }
                }
                p = strtok(NULL,"q");
            }
            cout<<"})";
}

