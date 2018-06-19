#ifndef FUNCAOPROGRAMA_H
#define FUNCAOPROGRAMA_H

class FuncaoPrograma
{
public:
    char **combinacoes;

    char ***transicoes; /// Sub de Combinações
    char **variaveis;
    char *estadoF,finalcpy[10];
    char *estadoI;
    bool *Uteis;
    char Estados[4][3] = {"q0","q1","q2","q3"};
    int chave,qnt_transicoes,qnt_variaveis;

    FuncaoPrograma(char **,int,int ,char *,char *);
    ~FuncaoPrograma();
    void PreencherCombinacoes();
    void preencherTransicoes(char *,int);
    void VerificarUteis();
    void NewFuncaoPrograma();
    void getMafn();
    void getMafd();
};
#endif // FUNCAOPROGRAMA_H
