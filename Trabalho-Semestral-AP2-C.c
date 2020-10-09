#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

///variaveis globais
#define TAMNOME 50
#define TAMSOBRENOME 50
#define TAMTURMA 100
#define DIAATUAL 12
#define MESATUAL 8
#define ANOATUAL 2020

///contador de alunos inseridos
int NumAlunosCadastrados = 0;
///variavel que define se foi ordenado a lista já.
int foi_ordenado = 0;

///Estrutura que armazena a data de nascimento, como dia, mes e o ano do aluno.
typedef struct data
{
    int dia, mes, ano;
}data;

///Estrutura que armazena o registro do aluno, seu nome e sobrenome, data de nascimento, prontuario e a sigla do curso.
typedef struct registro
{
    char nome[TAMNOME], sobrenome[TAMSOBRENOME];
    data datandenascimento;
    int prontuario; 
    char curso[4];
}aluno; 

///Vetor de alunos com o tamanho podendo ser mudado a qualquer momento alterando TAMTURMA. Vetor do tipo aluno, com o registro de cada um.
aluno alunos[TAMTURMA];

main()
{
    ///variavel utilizada para definir escolha do usuario.
    int escolha;
    ///menu de selecao, ele ficara em looping ate o usuario encerrar o programa.
    while (1) 
    {
        printf("1) Cadastro Aluno\n2) Ordenacao\n3) Buscar Aluno\n4) Remover Aluno\n5) Imprimir Lista de Alunos\n6) Salvar em Arquivo\n7) Ler Arquivo\n8) Encerrar Programa\nInsira sua escolha: ");
        scanf("%d", &escolha);
        switch(escolha) {
            case 1: cadastrar_aluno();
                    NumAlunosCadastrados++;
                    break;
            case 2: ordenar_alunos();
                    break;
            case 3: buscar_aluno();
                    break;
            case 4: deletar_aluno();
                    break;
            case 5: imprimir_lista();
                    break;
            case 6: salvar_arquivo();
                    break;
            case 7: ler_arquivo();
                    break;
            case 8: exit(0);
                    break;
            default: printf("Valor invalido\n");
        }
    }
}


///funcao de cadastro do aluno, recebe nome, sobrenome, prontuario, curso e data de nascimento. Caso haja o prontuario inserido, ele repete o pedido e altera foi_ordenado pra 0 sempre.
void cadastrar_aluno()
{
    foi_ordenado = 0;
    char Nome[TAMNOME], Sobrenome[TAMSOBRENOME];
    puts("Insira o nome: ");
    fflush(stdin);
    gets(Nome);
    capitalize(Nome);
    strcpy(alunos[NumAlunosCadastrados].nome, Nome);
    puts("Insira o sobrenome: ");
    fflush(stdin);
    gets(Sobrenome);
    capitalize(Sobrenome);
    strcpy(alunos[NumAlunosCadastrados].sobrenome, Sobrenome);
    while (1) {
        int Prontuario, i, existe = 0;
        printf("Insira o prontuario: ");
        scanf("%d",&Prontuario);
        for(i=0; i<NumAlunosCadastrados; i++) {
            if(Prontuario == alunos[i].prontuario) existe = 1; 
        }
        if(existe == 0) {
            alunos[NumAlunosCadastrados].prontuario = Prontuario;
            break;
        } else {
            printf("Esse prontuario ja se encontra na lista!\n");
        }
    }
    printf("Insira o curso: ");
    scanf("%s", alunos[NumAlunosCadastrados].curso);
    int i;
    for(i=0; i<strlen(alunos[NumAlunosCadastrados].curso); i++) {
        upperCurso(i);
    }
    printf("Dia de nascimento: ");
    scanf("%d", &alunos[NumAlunosCadastrados].datandenascimento.dia);
    printf("Mes de nascimento: ");
    scanf("%d", &alunos[NumAlunosCadastrados].datandenascimento.mes);
    printf("Ano de nascimento: ");
    scanf("%d", &alunos[NumAlunosCadastrados].datandenascimento.ano);
}

///funcao que imprime a lista de alunos.
void imprimir_lista()
{
    int i;
    for(i=0; i<NumAlunosCadastrados; i++) {
        printf("Nome: %s\n", alunos[i].nome);
        printf("Sobrenome: %s\n", alunos[i].sobrenome);
        printf("Data de Nascimento: %d/ %d/ %d\n", alunos[i].datandenascimento.dia, alunos[i].datandenascimento.mes, alunos[i].datandenascimento.ano);
        printf("Curso: %s\n", alunos[i].curso);
        printf("Prontuario: %d\n", alunos[i].prontuario);
    }
}

///menu que o usuario seleciona o tipo de ordenacao que deseja realizar.
void ordenar_alunos()
{
    int tipoOrd, tipo; 
    printf("1) Ordenar por nome e sobrenome\n2) Ordenar por sobrenome e nome\n3) Ordenar por prontuario\n4) Ordenar por curso\n5) Ordenar por idade\nInsira sua escolha: ");
    scanf("%d", &tipoOrd);
    switch(tipoOrd) {
        case 1: printf("1) Selection Sort\n2) Insertion Sort\n3) Merge Sort\n4) Quick Sort\nInsira sua Escolha: ");
                scanf("%d", &tipo);
                switch(tipo) {
                    case 1: ordenacao_nome();
                            break;
                    case 2: ordenacao_nome_insertion();
                            break;
                    case 3: ordenacao_nome_merge(0, NumAlunosCadastrados - 1);
                            break;
                    case 4: ordenacao_nome_quick(0, NumAlunosCadastrados - 1);
                            break;
                    default: printf("Valor Invalido!\n");
                }
                break;
        case 2: printf("1) Selection Sort\n2) Insertion Sort\n3) Merge Sort\n4) Quick Sort\nInsira sua Escolha: ");
                scanf("%d", &tipo);
                switch(tipo) {
                    case 1: ordenacao_sobrenome();
                            break;
                    case 2: ordenacao_sobrenome_insertion();
                            break;
                    case 3: ordenacao_sobrenome_merge(0, NumAlunosCadastrados - 1);
                            break;
                    case 4: ordenacao_sobrenome_quick(0, NumAlunosCadastrados - 1);
                            break;
                    default: printf("Valor Invalido!\n");
                }
                break;
        case 3: printf("1) Selection Sort\n2) Insertion Sort\n3) Merge Sort\n4) Quick Sort\nInsira sua Escolha: ");
                scanf("%d", &tipo);
                switch(tipo) {
                    case 1: ordenacao_prontuario();
                            break;
                    case 2: ordenacao_prontuario_insertion();
                            break;
                    case 3: ordenacao_prontuario_merge(0, NumAlunosCadastrados - 1);
                            break;
                    case 4: ordenacao_prontuario_quick(0, NumAlunosCadastrados - 1);
                            break;
                    default: printf("Valor Invalido!\n");
                }
                break;
        case 4: printf("1) Selection Sort\n2) Insertion Sort\n3) Merge Sort\n4) Quick Sort\nInsira sua Escolha: ");
                scanf("%d", &tipo);
                switch(tipo) {
                    case 1: ordenacao_curso();
                            break;
                    case 2: ordenacao_curso_insertion();
                            break;
                    case 3: ordenacao_curso_merge(0, NumAlunosCadastrados - 1);
                            break;
                    case 4: ordenacao_curso_quick(0, NumAlunosCadastrados - 1);
                            break;
                    default: printf("Valor Invalido!\n");
                }
                break;
        case 5: printf("1) Selection Sort\n2) Insertion Sort\n3) Merge Sort\n4) Quick Sort\nInsira sua Escolha: ");
                scanf("%d", &tipo);
                switch(tipo) {
                    case 1: ordenacao_idade();
                            break;
                    case 2: ordenacao_idade_insertion();
                            break;
                    case 3: ordenacao_idade_merge(0, NumAlunosCadastrados - 1);
                            break;
                    case 4: ordenacao_idade_quick(0, NumAlunosCadastrados - 1);
                            break;
                    default: printf("Valor Invalido!\n");
                }
                break;
        default: printf("Valor Invalido\n");
    }
}

///funcao que ordena por nome alfabeticamente, foi ordenado vai pra 1. 
void ordenacao_nome()
{
    foi_ordenado = 1;
    int i, posmenornome;
    for(i=0; i<NumAlunosCadastrados; i++) {
        posmenornome = menorNome(i);
        trocaPosicoes(i, posmenornome);
    }
}

///funcao que retorna a posicao do menor nome alfabeticamente
int menorNome(int posatual)
{
    int i, menor = posatual;
    for(i=posatual + 1; i<NumAlunosCadastrados; i++) {
        if ((strcmp(alunos[i].nome, alunos[menor].nome)) < 0) {
            menor = i;
        }
        if ((strcmp(alunos[i].nome, alunos[menor].nome)) == 0) {
            if((strcmp(alunos[i].sobrenome, alunos[menor].sobrenome)) < 0) {
                menor = i;
            }
        }
    }
    return menor;
}

///Ordenacao por inserção por nome
void ordenacao_nome_insertion() 
{
    foi_ordenado = 1;
    int i, j, aux, dia, mes, ano;
    char aux_nome[TAMNOME], aux_sobrenome[TAMSOBRENOME], aux_curso[4];
    for(i=1; i<NumAlunosCadastrados; i++) {
        aux = alunos[i].prontuario;
        strcpy(aux_nome, alunos[i].nome);
        strcpy(aux_sobrenome, alunos[i].sobrenome);
        strcpy(aux_curso, alunos[i].curso);
        dia = alunos[i].datandenascimento.dia;
        mes = alunos[i].datandenascimento.mes;
        ano = alunos[i].datandenascimento.ano;
        for(j=i; j>0 && strcmp(aux_nome, alunos[j-1].nome) < 0; j--) {
            strcpy(alunos[j].nome, alunos[j-1].nome);
            strcpy(alunos[j].sobrenome, alunos[j-1].sobrenome);
            strcpy(alunos[j].curso, alunos[j-1].curso);
            alunos[j].prontuario = alunos[j-1].prontuario;
            alunos[j].datandenascimento.dia = alunos[j-1].datandenascimento.dia;
            alunos[j].datandenascimento.mes = alunos[j-1].datandenascimento.mes;
            alunos[j].datandenascimento.ano = alunos[j-1].datandenascimento.ano;
        }
        strcpy(alunos[j].nome, aux_nome);
        strcpy(alunos[j].sobrenome, aux_sobrenome);
        strcpy(alunos[j].curso, aux_curso);
        alunos[j].prontuario = aux;
        alunos[j].datandenascimento.dia = dia;
        alunos[j].datandenascimento.mes = mes;
        alunos[j].datandenascimento.ano = ano;
    }
}


///função recursiva de ordenação merge por nome
void ordenacao_nome_merge(int ini, int fim)
{
    foi_ordenado = 1;
    int meio = 0;

    if(ini == fim) {
        return;
    }
    else {
        meio = (ini + fim) / 2;

        ordenacao_nome_merge(ini, meio);

        ordenacao_nome_merge(meio + 1, fim);

        merge_nome(ini, meio, fim);
    }
}

///função de ordenacação merge por nome
void merge_nome(int ini, int meio, int fim)
{
    int i;
    int esquerda = ini;
    int direita = meio + 1;
    int k = ini;
    aluno aux[TAMTURMA];
    while(esquerda <= meio && direita <= fim) {
        if(strcmp(alunos[esquerda].nome, alunos[direita].nome) <= 0) {
            int x1 = k;
            int x2 = k; 
            int x3 = k; 
            int x4 = k; 
            int x5 = k; 
            int x6 = k;
            int y1 = esquerda; 
            int y2 = esquerda; 
            int y3 = esquerda; 
            int y4 = esquerda; 
            int y5 = esquerda; 
            int y6 = esquerda; 
            aux[k++].prontuario = alunos[esquerda++].prontuario;
            strcpy(aux[x1++].nome, alunos[y1++].nome);
            strcpy(aux[x2++].sobrenome, alunos[y2++].sobrenome);
            strcpy(aux[x3++].curso, alunos[y3++].curso);
            aux[x4++].datandenascimento.dia = alunos[y4++].datandenascimento.dia;
            aux[x5++].datandenascimento.mes = alunos[y5++].datandenascimento.mes;
            aux[x6++].datandenascimento.ano = alunos[y6++].datandenascimento.ano;
        }
        else {
            int x1 = k;
            int x2 = k; 
            int x3 = k; 
            int x4 = k; 
            int x5 = k; 
            int x6 = k;
            int y1 = direita; 
            int y2 = direita; 
            int y3 = direita;
            int y4 = direita; 
            int y5 = direita; 
            int y6 = direita; 
            aux[k++].prontuario = alunos[direita++].prontuario;
            strcpy(aux[x1++].nome, alunos[y1++].nome);
            strcpy(aux[x2++].sobrenome, alunos[y2++].sobrenome);
            strcpy(aux[x3++].curso, alunos[y3++].curso);
            aux[x4++].datandenascimento.dia = alunos[y4++].datandenascimento.dia;
            aux[x5++].datandenascimento.mes = alunos[y5++].datandenascimento.mes;
            aux[x6++].datandenascimento.ano = alunos[y6++].datandenascimento.ano;
        }
    }

    if(esquerda == meio + 1) {
        while(direita <= fim) {
            int x1 = k;
            int x2 = k; 
            int x3 = k; 
            int x4 = k; 
            int x5 = k; 
            int x6 = k;
            int y1 = direita; 
            int y2 = direita; 
            int y3 = direita;
            int y4 = direita; 
            int y5 = direita; 
            int y6 = direita; 
            aux[k++].prontuario = alunos[direita++].prontuario;
            strcpy(aux[x1++].nome, alunos[y1++].nome);
            strcpy(aux[x2++].sobrenome, alunos[y2++].sobrenome);
            strcpy(aux[x3++].curso, alunos[y3++].curso);
            aux[x4++].datandenascimento.dia = alunos[y4++].datandenascimento.dia;
            aux[x5++].datandenascimento.mes = alunos[y5++].datandenascimento.mes;
            aux[x6++].datandenascimento.ano = alunos[y6++].datandenascimento.ano;
        }
    }
    else {
        while(esquerda <= fim) {
            int x1 = k;
            int x2 = k; 
            int x3 = k; 
            int x4 = k; 
            int x5 = k; 
            int x6 = k;
            int y1 = esquerda; 
            int y2 = esquerda; 
            int y3 = esquerda; 
            int y4 = esquerda; 
            int y5 = esquerda; 
            int y6 = esquerda; 
            aux[k++].prontuario = alunos[esquerda++].prontuario;
            strcpy(aux[x1++].nome, alunos[y1++].nome);
            strcpy(aux[x2++].sobrenome, alunos[y2++].sobrenome);
            strcpy(aux[x3++].curso, alunos[y3++].curso);
            aux[x4++].datandenascimento.dia = alunos[y4++].datandenascimento.dia;
            aux[x5++].datandenascimento.mes = alunos[y5++].datandenascimento.mes;
            aux[x6++].datandenascimento.ano = alunos[y6++].datandenascimento.ano;
        }
    }

    for(i = ini; i <= fim; i++) {
        alunos[i].prontuario = aux[i].prontuario;
        strcpy(alunos[i].nome, aux[i].nome);
        strcpy(alunos[i].sobrenome, aux[i].sobrenome);
        strcpy(alunos[i].curso, aux[i].curso);
        alunos[i].datandenascimento.dia = aux[i].datandenascimento.dia;
        alunos[i].datandenascimento.mes = aux[i].datandenascimento.mes;
        alunos[i].datandenascimento.ano = aux[i].datandenascimento.ano;
    }
}


///Função de Quick Sort por nome
void ordenacao_nome_quick(int ini, int fim) 
{
    foi_ordenado = 1;
    int pos;
    if (ini < fim) {
        pos = particionar_nome(ini, fim);
        ordenacao_nome_quick(ini, pos - 1);
        ordenacao_nome_quick(pos, fim);
    }
}

///função de particionamento do Quick Sort, por nome.
int particionar_nome(int ini, int fim) 
{
    char pivo[TAMNOME];
    strcpy(pivo, alunos[fim].nome);
    while (ini < fim) {
        while (ini < fim && (strcmp(alunos[ini].nome, pivo) <= 0))
            ini++;
        while (ini < fim && (strcmp(alunos[fim].nome, pivo) > 0))
            fim--;
        trocaPosicoes(ini, fim);
    }
    return ini;
}


///funcao de ordenacao por sobrenome, foi ordenado se torna 2. 
void ordenacao_sobrenome()
{
    foi_ordenado = 2; 
    int i, posmenorsobrenome;
    for(i=0; i<NumAlunosCadastrados; i++) {
        posmenorsobrenome = menorSobrenome(i);
        trocaPosicoes(i, posmenorsobrenome);
    }
}

///funcao que o menor sobrenome alfabeticamente
int menorSobrenome(int posatual)
{
    int i, menor = posatual;
    for(i=posatual + 1; i<NumAlunosCadastrados; i++) {
        if ((strcmp(alunos[i].sobrenome, alunos[menor].sobrenome)) < 0) {
            menor = i;
        }
        if ((strcmp(alunos[i].sobrenome, alunos[menor].sobrenome)) == 0) {
            if((strcmp(alunos[i].nome, alunos[menor].nome)) < 0) {
                menor = i;
            }
        }
    }
    return menor;
}


///função de ordenação de sobrenome por insertion
void ordenacao_sobrenome_insertion() 
{
    foi_ordenado = 2;
    int i, j, aux, dia, mes, ano;
    char aux_nome[TAMNOME], aux_sobrenome[TAMSOBRENOME], aux_curso[4];
    for(i=1; i<NumAlunosCadastrados; i++) {
        aux = alunos[i].prontuario;
        strcpy(aux_nome, alunos[i].nome);
        strcpy(aux_sobrenome, alunos[i].sobrenome);
        strcpy(aux_curso, alunos[i].curso);
        dia = alunos[i].datandenascimento.dia;
        mes = alunos[i].datandenascimento.mes;
        ano = alunos[i].datandenascimento.ano;
        for(j=i; j>0 && strcmp(aux_sobrenome, alunos[j-1].sobrenome) < 0; j--) {
            strcpy(alunos[j].nome, alunos[j-1].nome);
            strcpy(alunos[j].sobrenome, alunos[j-1].sobrenome);
            strcpy(alunos[j].curso, alunos[j-1].curso);
            alunos[j].prontuario = alunos[j-1].prontuario;
            alunos[j].datandenascimento.dia = alunos[j-1].datandenascimento.dia;
            alunos[j].datandenascimento.mes = alunos[j-1].datandenascimento.mes;
            alunos[j].datandenascimento.ano = alunos[j-1].datandenascimento.ano;
        }
        strcpy(alunos[j].nome, aux_nome);
        strcpy(alunos[j].sobrenome, aux_sobrenome);
        strcpy(alunos[j].curso, aux_curso);
        alunos[j].prontuario = aux;
        alunos[j].datandenascimento.dia = dia;
        alunos[j].datandenascimento.mes = mes;
        alunos[j].datandenascimento.ano = ano;
    }
}

///função recursiva de merge sort por sobrenome
void ordenacao_sobrenome_merge(int ini, int fim)
{
    foi_ordenado = 2;
    int meio = 0;

    if(ini == fim) {
        return;
    }
    else {
        meio = (ini + fim) / 2;

        ordenacao_sobrenome_merge(ini, meio);

        ordenacao_sobrenome_merge(meio + 1, fim);

        merge_sobrenome(ini, meio, fim);
    }
}

///função de merge sort por sobrenome
void merge_sobrenome(int ini, int meio, int fim)
{
    int i;
    int esquerda = ini;
    int direita = meio + 1;
    int k = ini;
    aluno aux[TAMTURMA];
    while(esquerda <= meio && direita <= fim) {
        if(strcmp(alunos[esquerda].sobrenome, alunos[direita].sobrenome) <= 0) {
            int x1 = k;
            int x2 = k; 
            int x3 = k; 
            int x4 = k; 
            int x5 = k; 
            int x6 = k;
            int y1 = esquerda; 
            int y2 = esquerda; 
            int y3 = esquerda; 
            int y4 = esquerda; 
            int y5 = esquerda; 
            int y6 = esquerda; 
            aux[k++].prontuario = alunos[esquerda++].prontuario;
            strcpy(aux[x1++].nome, alunos[y1++].nome);
            strcpy(aux[x2++].sobrenome, alunos[y2++].sobrenome);
            strcpy(aux[x3++].curso, alunos[y3++].curso);
            aux[x4++].datandenascimento.dia = alunos[y4++].datandenascimento.dia;
            aux[x5++].datandenascimento.mes = alunos[y5++].datandenascimento.mes;
            aux[x6++].datandenascimento.ano = alunos[y6++].datandenascimento.ano;
        }
        else {
            int x1 = k;
            int x2 = k; 
            int x3 = k; 
            int x4 = k; 
            int x5 = k; 
            int x6 = k;
            int y1 = direita; 
            int y2 = direita; 
            int y3 = direita;
            int y4 = direita; 
            int y5 = direita; 
            int y6 = direita; 
            aux[k++].prontuario = alunos[direita++].prontuario;
            strcpy(aux[x1++].nome, alunos[y1++].nome);
            strcpy(aux[x2++].sobrenome, alunos[y2++].sobrenome);
            strcpy(aux[x3++].curso, alunos[y3++].curso);
            aux[x4++].datandenascimento.dia = alunos[y4++].datandenascimento.dia;
            aux[x5++].datandenascimento.mes = alunos[y5++].datandenascimento.mes;
            aux[x6++].datandenascimento.ano = alunos[y6++].datandenascimento.ano;
        }
    }

    if(esquerda == meio + 1) {
        while(direita <= fim) {
            int x1 = k;
            int x2 = k; 
            int x3 = k; 
            int x4 = k; 
            int x5 = k; 
            int x6 = k;
            int y1 = direita; 
            int y2 = direita; 
            int y3 = direita;
            int y4 = direita; 
            int y5 = direita; 
            int y6 = direita; 
            aux[k++].prontuario = alunos[direita++].prontuario;
            strcpy(aux[x1++].nome, alunos[y1++].nome);
            strcpy(aux[x2++].sobrenome, alunos[y2++].sobrenome);
            strcpy(aux[x3++].curso, alunos[y3++].curso);
            aux[x4++].datandenascimento.dia = alunos[y4++].datandenascimento.dia;
            aux[x5++].datandenascimento.mes = alunos[y5++].datandenascimento.mes;
            aux[x6++].datandenascimento.ano = alunos[y6++].datandenascimento.ano;
        }
    }
    else {
        while(esquerda <= fim) {
            int x1 = k;
            int x2 = k; 
            int x3 = k; 
            int x4 = k; 
            int x5 = k; 
            int x6 = k;
            int y1 = esquerda; 
            int y2 = esquerda; 
            int y3 = esquerda; 
            int y4 = esquerda; 
            int y5 = esquerda; 
            int y6 = esquerda; 
            aux[k++].prontuario = alunos[esquerda++].prontuario;
            strcpy(aux[x1++].nome, alunos[y1++].nome);
            strcpy(aux[x2++].sobrenome, alunos[y2++].sobrenome);
            strcpy(aux[x3++].curso, alunos[y3++].curso);
            aux[x4++].datandenascimento.dia = alunos[y4++].datandenascimento.dia;
            aux[x5++].datandenascimento.mes = alunos[y5++].datandenascimento.mes;
            aux[x6++].datandenascimento.ano = alunos[y6++].datandenascimento.ano;
        }
    }

    for(i = ini; i <= fim; i++) {
        alunos[i].prontuario = aux[i].prontuario;
        strcpy(alunos[i].nome, aux[i].nome);
        strcpy(alunos[i].sobrenome, aux[i].sobrenome);
        strcpy(alunos[i].curso, aux[i].curso);
        alunos[i].datandenascimento.dia = aux[i].datandenascimento.dia;
        alunos[i].datandenascimento.mes = aux[i].datandenascimento.mes;
        alunos[i].datandenascimento.ano = aux[i].datandenascimento.ano;
    }
}

///Função de quick sort por sobrenome
void ordenacao_sobrenome_quick(int ini, int fim) 
{
    int pos;
    foi_ordenado = 2;
    if (ini < fim) {
        pos = particionar_sobrenome(ini, fim);
        ordenacao_sobrenome_quick(ini, pos - 1);
        ordenacao_sobrenome_quick(pos, fim);
    }
}

///Função de particionamento do quick sort por sobrenome
int particionar_sobrenome(int ini, int fim) 
{
    char pivo[TAMSOBRENOME];
    strcpy(pivo, alunos[fim].sobrenome);
    while (ini < fim) {
        while (ini < fim && (strcmp(alunos[ini].sobrenome, pivo) <= 0))
            ini++;
        while (ini < fim && (strcmp(alunos[fim].sobrenome, pivo) > 0))
            fim--;
        trocaPosicoes(ini, fim);
    }
    return ini;
}

///função de ordenaçao do prontuario, foi ordenado se torna 3.
void ordenacao_prontuario()
{
    int i, posMenorProntuario; 
    foi_ordenado = 3; 
    for(i=0; i<NumAlunosCadastrados; i++) {
        posMenorProntuario = menorProntuario(i);
        trocaPosicoes(i, posMenorProntuario);
    }
}

///funcao que define o menor prontuario
int menorProntuario(int posAtual)
{
    int i;
    int menor = posAtual;
    for (i= posAtual+1; i<NumAlunosCadastrados; i++) {
        if(alunos[i].prontuario < alunos[menor].prontuario) {
            menor = i;
        }
    }
    return menor;
}


///insertion sort de prontuario
void ordenacao_prontuario_insertion() 
{
    int i, j, aux, dia, mes, ano;
    foi_ordenado = 3;
    char aux_nome[TAMNOME], aux_sobrenome[TAMSOBRENOME], aux_curso[4];
    for(i=1; i<NumAlunosCadastrados; i++) {
        aux = alunos[i].prontuario;
        strcpy(aux_nome, alunos[i].nome);
        strcpy(aux_sobrenome, alunos[i].sobrenome);
        strcpy(aux_curso, alunos[i].curso);
        dia = alunos[i].datandenascimento.dia;
        mes = alunos[i].datandenascimento.mes;
        ano = alunos[i].datandenascimento.ano;
        for(j=i; j>0 && aux < alunos[j-1].prontuario; j--) {
            strcpy(alunos[j].nome, alunos[j-1].nome);
            strcpy(alunos[j].sobrenome, alunos[j-1].sobrenome);
            strcpy(alunos[j].curso, alunos[j-1].curso);
            alunos[j].prontuario = alunos[j-1].prontuario;
            alunos[j].datandenascimento.dia = alunos[j-1].datandenascimento.dia;
            alunos[j].datandenascimento.mes = alunos[j-1].datandenascimento.mes;
            alunos[j].datandenascimento.ano = alunos[j-1].datandenascimento.ano;
        }
        strcpy(alunos[j].nome, aux_nome);
        strcpy(alunos[j].sobrenome, aux_sobrenome);
        strcpy(alunos[j].curso, aux_curso);
        alunos[j].prontuario = aux;
        alunos[j].datandenascimento.dia = dia;
        alunos[j].datandenascimento.mes = mes;
        alunos[j].datandenascimento.ano = ano;
    }
}

///função recursiva de merge sort do prontuario
void ordenacao_prontuario_merge(int ini, int fim)
{
    int meio = 0;
    foi_ordenado = 3;
    if(ini == fim) {
        return;
    }
    else {
        meio = (ini + fim) / 2;

        ordenacao_prontuario_merge(ini, meio);

        ordenacao_prontuario_merge(meio + 1, fim);

        merge_prontuario(ini, meio, fim);
    }
}

///merge sort prontuario
void merge_prontuario(int ini, int meio, int fim)
{
    int i;
    int esquerda = ini;
    int direita = meio + 1;
    int k = ini;
    aluno aux[TAMTURMA];
    while(esquerda <= meio && direita <= fim) {
        if(alunos[esquerda].prontuario <= alunos[direita].prontuario) {
            int x1 = k;
            int x2 = k; 
            int x3 = k; 
            int x4 = k; 
            int x5 = k; 
            int x6 = k;
            int y1 = esquerda; 
            int y2 = esquerda; 
            int y3 = esquerda; 
            int y4 = esquerda; 
            int y5 = esquerda; 
            int y6 = esquerda; 
            aux[k++].prontuario = alunos[esquerda++].prontuario;
            strcpy(aux[x1++].nome, alunos[y1++].nome);
            strcpy(aux[x2++].sobrenome, alunos[y2++].sobrenome);
            strcpy(aux[x3++].curso, alunos[y3++].curso);
            aux[x4++].datandenascimento.dia = alunos[y4++].datandenascimento.dia;
            aux[x5++].datandenascimento.mes = alunos[y5++].datandenascimento.mes;
            aux[x6++].datandenascimento.ano = alunos[y6++].datandenascimento.ano;
        }
        else {
            int x1 = k;
            int x2 = k; 
            int x3 = k; 
            int x4 = k; 
            int x5 = k; 
            int x6 = k;
            int y1 = direita; 
            int y2 = direita; 
            int y3 = direita;
            int y4 = direita; 
            int y5 = direita; 
            int y6 = direita; 
            aux[k++].prontuario = alunos[direita++].prontuario;
            strcpy(aux[x1++].nome, alunos[y1++].nome);
            strcpy(aux[x2++].sobrenome, alunos[y2++].sobrenome);
            strcpy(aux[x3++].curso, alunos[y3++].curso);
            aux[x4++].datandenascimento.dia = alunos[y4++].datandenascimento.dia;
            aux[x5++].datandenascimento.mes = alunos[y5++].datandenascimento.mes;
            aux[x6++].datandenascimento.ano = alunos[y6++].datandenascimento.ano;
        }
    }

    if(esquerda == meio + 1) {
        while(direita <= fim) {
            int x1 = k;
            int x2 = k; 
            int x3 = k; 
            int x4 = k; 
            int x5 = k; 
            int x6 = k;
            int y1 = direita; 
            int y2 = direita; 
            int y3 = direita;
            int y4 = direita; 
            int y5 = direita; 
            int y6 = direita; 
            aux[k++].prontuario = alunos[direita++].prontuario;
            strcpy(aux[x1++].nome, alunos[y1++].nome);
            strcpy(aux[x2++].sobrenome, alunos[y2++].sobrenome);
            strcpy(aux[x3++].curso, alunos[y3++].curso);
            aux[x4++].datandenascimento.dia = alunos[y4++].datandenascimento.dia;
            aux[x5++].datandenascimento.mes = alunos[y5++].datandenascimento.mes;
            aux[x6++].datandenascimento.ano = alunos[y6++].datandenascimento.ano;
        }
    }
    else {
        while(esquerda <= fim) {
            int x1 = k;
            int x2 = k; 
            int x3 = k; 
            int x4 = k; 
            int x5 = k; 
            int x6 = k;
            int y1 = esquerda; 
            int y2 = esquerda; 
            int y3 = esquerda; 
            int y4 = esquerda; 
            int y5 = esquerda; 
            int y6 = esquerda; 
            aux[k++].prontuario = alunos[esquerda++].prontuario;
            strcpy(aux[x1++].nome, alunos[y1++].nome);
            strcpy(aux[x2++].sobrenome, alunos[y2++].sobrenome);
            strcpy(aux[x3++].curso, alunos[y3++].curso);
            aux[x4++].datandenascimento.dia = alunos[y4++].datandenascimento.dia;
            aux[x5++].datandenascimento.mes = alunos[y5++].datandenascimento.mes;
            aux[x6++].datandenascimento.ano = alunos[y6++].datandenascimento.ano;
        }
    }

    for(i = ini; i <= fim; i++) {
        alunos[i].prontuario = aux[i].prontuario;
        strcpy(alunos[i].nome, aux[i].nome);
        strcpy(alunos[i].sobrenome, aux[i].sobrenome);
        strcpy(alunos[i].curso, aux[i].curso);
        alunos[i].datandenascimento.dia = aux[i].datandenascimento.dia;
        alunos[i].datandenascimento.mes = aux[i].datandenascimento.mes;
        alunos[i].datandenascimento.ano = aux[i].datandenascimento.ano;
    }
}


///Função Quick Sort por prontuario
void ordenacao_prontuario_quick(int ini, int fim) 
{
    foi_ordenado = 3;
    int pos;
    if (ini < fim){
        pos = particionar_prontuario(ini, fim);
        ordenacao_prontuario_quick(ini, pos - 1);
        ordenacao_prontuario_quick(pos, fim);
    }
}

///Função de particionamento do quick sort por prontuario.
int particionar_prontuario(int ini, int fim) 
{
    int pivo;
    pivo = alunos[fim].prontuario;
    while (ini < fim) {
        while (ini < fim && alunos[ini].prontuario <= pivo)
            ini++;
        while (ini < fim && alunos[fim].prontuario > pivo)
            fim--;
        trocaPosicoes(ini, fim);
    }
    return ini;
}

///funcao para dividir os alunos por cursos, foi ordenado se torna 4.
void ordenacao_curso()
{
    foi_ordenado = 4; 
    int i, poscursos;
    for(i=0; i<NumAlunosCadastrados; i++) {
        poscursos = menorCurso(i);
        trocaPosicoes(i, poscursos);
    }
}

///funcao que define qual o menor curso alfabeticamente para dividir
int menorCurso(int posatual)
{
    int i, menor = posatual;
    for(i=posatual + 1; i<NumAlunosCadastrados; i++) {
        if ((strcmp(alunos[i].curso, alunos[menor].curso)) < 0) {
            menor = i;
        }
    }
    return menor;
}


///insertion sort dos cursos
void ordenacao_curso_insertion() 
{
    int i, j, aux, dia, mes, ano;
    foi_ordenado = 4;
    char aux_nome[TAMNOME], aux_sobrenome[TAMSOBRENOME], aux_curso[4];
    for(i=1; i<NumAlunosCadastrados; i++) {
        aux = alunos[i].prontuario;
        strcpy(aux_nome, alunos[i].nome);
        strcpy(aux_sobrenome, alunos[i].sobrenome);
        strcpy(aux_curso, alunos[i].curso);
        dia = alunos[i].datandenascimento.dia;
        mes = alunos[i].datandenascimento.mes;
        ano = alunos[i].datandenascimento.ano;
        for(j=i; j>0 && strcmp(aux_curso, alunos[j-1].curso) <= 0; j--) {
            strcpy(alunos[j].nome, alunos[j-1].nome);
            strcpy(alunos[j].sobrenome, alunos[j-1].sobrenome);
            strcpy(alunos[j].curso, alunos[j-1].curso);
            alunos[j].prontuario = alunos[j-1].prontuario;
            alunos[j].datandenascimento.dia = alunos[j-1].datandenascimento.dia;
            alunos[j].datandenascimento.mes = alunos[j-1].datandenascimento.mes;
            alunos[j].datandenascimento.ano = alunos[j-1].datandenascimento.ano;
        }
        strcpy(alunos[j].nome, aux_nome);
        strcpy(alunos[j].sobrenome, aux_sobrenome);
        strcpy(alunos[j].curso, aux_curso);
        alunos[j].prontuario = aux;
        alunos[j].datandenascimento.dia = dia;
        alunos[j].datandenascimento.mes = mes;
        alunos[j].datandenascimento.ano = ano;
    }
}


///funçao recursiva de merge sort pelo curso
void ordenacao_curso_merge(int ini, int fim)
{
    int meio = 0;
    foi_ordenado = 4;
    if(ini == fim) {
        return;
    }
    else {
        meio = (ini + fim) / 2;

        ordenacao_curso_merge(ini, meio);

        ordenacao_curso_merge(meio + 1, fim);

        merge_curso(ini, meio, fim);
    }
}

///merge sort do curso
void merge_curso(int ini, int meio, int fim)
{
    int i;
    int esquerda = ini;
    int direita = meio + 1;
    int k = ini;
    aluno aux[TAMTURMA];
    while(esquerda <= meio && direita <= fim) {
        if(strcmp(alunos[esquerda].curso, alunos[direita].curso) <= 0) {
            int x1 = k;
            int x2 = k; 
            int x3 = k; 
            int x4 = k; 
            int x5 = k; 
            int x6 = k;
            int y1 = esquerda; 
            int y2 = esquerda; 
            int y3 = esquerda; 
            int y4 = esquerda; 
            int y5 = esquerda; 
            int y6 = esquerda; 
            aux[k++].prontuario = alunos[esquerda++].prontuario;
            strcpy(aux[x1++].nome, alunos[y1++].nome);
            strcpy(aux[x2++].sobrenome, alunos[y2++].sobrenome);
            strcpy(aux[x3++].curso, alunos[y3++].curso);
            aux[x4++].datandenascimento.dia = alunos[y4++].datandenascimento.dia;
            aux[x5++].datandenascimento.mes = alunos[y5++].datandenascimento.mes;
            aux[x6++].datandenascimento.ano = alunos[y6++].datandenascimento.ano;
        }
        else {
            int x1 = k;
            int x2 = k; 
            int x3 = k; 
            int x4 = k; 
            int x5 = k; 
            int x6 = k;
            int y1 = direita; 
            int y2 = direita; 
            int y3 = direita;
            int y4 = direita; 
            int y5 = direita; 
            int y6 = direita; 
            aux[k++].prontuario = alunos[direita++].prontuario;
            strcpy(aux[x1++].nome, alunos[y1++].nome);
            strcpy(aux[x2++].sobrenome, alunos[y2++].sobrenome);
            strcpy(aux[x3++].curso, alunos[y3++].curso);
            aux[x4++].datandenascimento.dia = alunos[y4++].datandenascimento.dia;
            aux[x5++].datandenascimento.mes = alunos[y5++].datandenascimento.mes;
            aux[x6++].datandenascimento.ano = alunos[y6++].datandenascimento.ano;
        }
    }

    if(esquerda == meio + 1) {
        while(direita <= fim) {
            int x1 = k;
            int x2 = k; 
            int x3 = k; 
            int x4 = k; 
            int x5 = k; 
            int x6 = k;
            int y1 = direita; 
            int y2 = direita; 
            int y3 = direita;
            int y4 = direita; 
            int y5 = direita; 
            int y6 = direita; 
            aux[k++].prontuario = alunos[direita++].prontuario;
            strcpy(aux[x1++].nome, alunos[y1++].nome);
            strcpy(aux[x2++].sobrenome, alunos[y2++].sobrenome);
            strcpy(aux[x3++].curso, alunos[y3++].curso);
            aux[x4++].datandenascimento.dia = alunos[y4++].datandenascimento.dia;
            aux[x5++].datandenascimento.mes = alunos[y5++].datandenascimento.mes;
            aux[x6++].datandenascimento.ano = alunos[y6++].datandenascimento.ano;
        }
    }
    else {
        while(esquerda <= fim) {
            int x1 = k;
            int x2 = k; 
            int x3 = k; 
            int x4 = k; 
            int x5 = k; 
            int x6 = k;
            int y1 = esquerda; 
            int y2 = esquerda; 
            int y3 = esquerda; 
            int y4 = esquerda; 
            int y5 = esquerda; 
            int y6 = esquerda; 
            aux[k++].prontuario = alunos[esquerda++].prontuario;
            strcpy(aux[x1++].nome, alunos[y1++].nome);
            strcpy(aux[x2++].sobrenome, alunos[y2++].sobrenome);
            strcpy(aux[x3++].curso, alunos[y3++].curso);
            aux[x4++].datandenascimento.dia = alunos[y4++].datandenascimento.dia;
            aux[x5++].datandenascimento.mes = alunos[y5++].datandenascimento.mes;
            aux[x6++].datandenascimento.ano = alunos[y6++].datandenascimento.ano;
        }
    }

    for(i = ini; i <= fim; i++) {
        alunos[i].prontuario = aux[i].prontuario;
        strcpy(alunos[i].nome, aux[i].nome);
        strcpy(alunos[i].sobrenome, aux[i].sobrenome);
        strcpy(alunos[i].curso, aux[i].curso);
        alunos[i].datandenascimento.dia = aux[i].datandenascimento.dia;
        alunos[i].datandenascimento.mes = aux[i].datandenascimento.mes;
        alunos[i].datandenascimento.ano = aux[i].datandenascimento.ano;
    }
}


///Ordenação de curso por quick sort
void ordenacao_curso_quick(int ini, int fim) 
{
    int pos;
    foi_ordenado = 4;
    if (ini < fim) {
        pos = particionar_curso(ini, fim);
        ordenacao_curso_quick(ini, pos - 1);
        ordenacao_curso_quick(pos, fim);
    }
}

///particionamento do quick sort por curso
int particionar_curso(int ini, int fim) 
{
    char pivo[4];
    strcpy(pivo, alunos[fim].curso);
    while (ini < fim) {
        while (ini < fim && (strcmp(alunos[ini].curso, pivo) <= 0))
            ini++;
        while (ini < fim && (strcmp(alunos[fim].curso, pivo) > 0))
            fim--;
        trocaPosicoes(ini, fim);
    }
    return ini;
}

///funcao de ordenacao por idade, foi ordenado vai para 5
void ordenacao_idade()
{
    foi_ordenado = 5; 
    int i, maisNovo;
    for(i=0; i<NumAlunosCadastrados; i++) {
        maisNovo = mais_novo(i);
        trocaPosicoes(i, maisNovo);
    }
}


///funcao que define a posicao do mais novo
int mais_novo(int posAtual)
{
    int i;
    int menor = posAtual;
    int idade_menor = calculoIdade(menor);
    for (i= posAtual+1; i<NumAlunosCadastrados; i++) {
        int idade_atual = calculoIdade(i);
        if(idade_atual < idade_menor) {
            idade_menor = idade_atual;
            menor = i;
        }
    }
    return menor;
}


///insertion sort por idade
void ordenacao_idade_insertion() 
{
    int i, j, aux, dia, mes, ano;
    int aux_idade, idade;
    foi_ordenado = 5;
    char aux_nome[TAMNOME], aux_sobrenome[TAMSOBRENOME], aux_curso[4];
    for(i=1; i<NumAlunosCadastrados; i++) {
        aux = alunos[i].prontuario;
        strcpy(aux_nome, alunos[i].nome);
        strcpy(aux_sobrenome, alunos[i].sobrenome);
        strcpy(aux_curso, alunos[i].curso);
        dia = alunos[i].datandenascimento.dia;
        mes = alunos[i].datandenascimento.mes;
        ano = alunos[i].datandenascimento.ano;
        aux_idade = calculoIdade(i);
        for(j=i; j>0 && aux_idade < (idade = calculoIdade(j-1)); j--) {
            strcpy(alunos[j].nome, alunos[j-1].nome);
            strcpy(alunos[j].sobrenome, alunos[j-1].sobrenome);
            strcpy(alunos[j].curso, alunos[j-1].curso);
            alunos[j].prontuario = alunos[j-1].prontuario;
            alunos[j].datandenascimento.dia = alunos[j-1].datandenascimento.dia;
            alunos[j].datandenascimento.mes = alunos[j-1].datandenascimento.mes;
            alunos[j].datandenascimento.ano = alunos[j-1].datandenascimento.ano;
        }
        strcpy(alunos[j].nome, aux_nome);
        strcpy(alunos[j].sobrenome, aux_sobrenome);
        strcpy(alunos[j].curso, aux_curso);
        alunos[j].prontuario = aux;
        alunos[j].datandenascimento.dia = dia;
        alunos[j].datandenascimento.mes = mes;
        alunos[j].datandenascimento.ano = ano;
    }
}


///merge sort por idade 
void ordenacao_idade_merge(int ini, int fim)
{
    int meio = 0;
    foi_ordenado = 5;
    if(ini == fim) {
        return;
    }
    else {
        meio = (ini + fim) / 2;

        ordenacao_idade_merge(ini, meio);

        ordenacao_idade_merge(meio + 1, fim);

        merge_idade(ini, meio, fim);
    }
}

///função de merge sort para idade
void merge_idade(int ini, int meio, int fim)
{
    int i;
    int esquerda = ini;
    int direita = meio + 1;
    int k = ini;
    aluno aux[TAMTURMA];
    int idade1;
    int idade2; 
    while(esquerda <= meio && direita <= fim) {
        if((idade1 = calculoIdade(esquerda)) < (idade2 = calculoIdade(direita))) {
            int x1 = k;
            int x2 = k; 
            int x3 = k; 
            int x4 = k; 
            int x5 = k; 
            int x6 = k;
            int y1 = esquerda; 
            int y2 = esquerda; 
            int y3 = esquerda; 
            int y4 = esquerda; 
            int y5 = esquerda; 
            int y6 = esquerda; 
            aux[k++].prontuario = alunos[esquerda++].prontuario;
            strcpy(aux[x1++].nome, alunos[y1++].nome);
            strcpy(aux[x2++].sobrenome, alunos[y2++].sobrenome);
            strcpy(aux[x3++].curso, alunos[y3++].curso);
            aux[x4++].datandenascimento.dia = alunos[y4++].datandenascimento.dia;
            aux[x5++].datandenascimento.mes = alunos[y5++].datandenascimento.mes;
            aux[x6++].datandenascimento.ano = alunos[y6++].datandenascimento.ano;
        }
        else {
            int x1 = k;
            int x2 = k; 
            int x3 = k; 
            int x4 = k; 
            int x5 = k; 
            int x6 = k;
            int y1 = direita; 
            int y2 = direita; 
            int y3 = direita;
            int y4 = direita; 
            int y5 = direita; 
            int y6 = direita; 
            aux[k++].prontuario = alunos[direita++].prontuario;
            strcpy(aux[x1++].nome, alunos[y1++].nome);
            strcpy(aux[x2++].sobrenome, alunos[y2++].sobrenome);
            strcpy(aux[x3++].curso, alunos[y3++].curso);
            aux[x4++].datandenascimento.dia = alunos[y4++].datandenascimento.dia;
            aux[x5++].datandenascimento.mes = alunos[y5++].datandenascimento.mes;
            aux[x6++].datandenascimento.ano = alunos[y6++].datandenascimento.ano;
        }
    }

    if(esquerda == meio + 1) {
        while(direita <= fim) {
            int x1 = k;
            int x2 = k; 
            int x3 = k; 
            int x4 = k; 
            int x5 = k; 
            int x6 = k;
            int y1 = direita; 
            int y2 = direita; 
            int y3 = direita;
            int y4 = direita; 
            int y5 = direita; 
            int y6 = direita; 
            aux[k++].prontuario = alunos[direita++].prontuario;
            strcpy(aux[x1++].nome, alunos[y1++].nome);
            strcpy(aux[x2++].sobrenome, alunos[y2++].sobrenome);
            strcpy(aux[x3++].curso, alunos[y3++].curso);
            aux[x4++].datandenascimento.dia = alunos[y4++].datandenascimento.dia;
            aux[x5++].datandenascimento.mes = alunos[y5++].datandenascimento.mes;
            aux[x6++].datandenascimento.ano = alunos[y6++].datandenascimento.ano;
        }
    }
    else {
        while(esquerda <= fim) {
            int x1 = k;
            int x2 = k; 
            int x3 = k; 
            int x4 = k; 
            int x5 = k; 
            int x6 = k;
            int y1 = esquerda; 
            int y2 = esquerda; 
            int y3 = esquerda; 
            int y4 = esquerda; 
            int y5 = esquerda; 
            int y6 = esquerda; 
            aux[k++].prontuario = alunos[esquerda++].prontuario;
            strcpy(aux[x1++].nome, alunos[y1++].nome);
            strcpy(aux[x2++].sobrenome, alunos[y2++].sobrenome);
            strcpy(aux[x3++].curso, alunos[y3++].curso);
            aux[x4++].datandenascimento.dia = alunos[y4++].datandenascimento.dia;
            aux[x5++].datandenascimento.mes = alunos[y5++].datandenascimento.mes;
            aux[x6++].datandenascimento.ano = alunos[y6++].datandenascimento.ano;
        }
    }

    for(i = ini; i <= fim; i++) {
        alunos[i].prontuario = aux[i].prontuario;
        strcpy(alunos[i].nome, aux[i].nome);
        strcpy(alunos[i].sobrenome, aux[i].sobrenome);
        strcpy(alunos[i].curso, aux[i].curso);
        alunos[i].datandenascimento.dia = aux[i].datandenascimento.dia;
        alunos[i].datandenascimento.mes = aux[i].datandenascimento.mes;
        alunos[i].datandenascimento.ano = aux[i].datandenascimento.ano;
    }
}

///quick sort por idade
void ordenacao_idade_quick(int ini, int fim) 
{
    int pos;
    foi_ordenado = 5;
    if (ini < fim){
        pos = particionar_idade(ini, fim);
        ordenacao_idade_quick(ini, pos - 1);
        ordenacao_idade_quick(pos, fim);
    }
}

///particionamento do quick sort por idade 
int particionar_idade(int ini, int fim) 
{
    int pivo;
    pivo = calculoIdade(fim);
    int idade;
    while (ini < fim) {
        while (ini < fim && (idade = calculoIdade(ini)) <= pivo)
            ini++;
        while (ini < fim && (idade = calculoIdade(fim)) > pivo)
            fim--;
        trocaPosicoes(ini, fim);
    }
    return ini;
}

///funcao de calculo da idade das pessoas
int calculoIdade(int pessoa)
{
    int dia = alunos[pessoa].datandenascimento.dia;
    int mes = alunos[pessoa].datandenascimento.mes;
    int ano = (ANOATUAL - alunos[pessoa].datandenascimento.ano);
    int idade;
    if (dia > DIAATUAL) {
        dia = DIAATUAL - dia;
        if (mes < MESATUAL) {
            mes = (MESATUAL - mes - 1) * 30;
            ano = ano * 365;
            idade = dia + mes + ano;
            return idade;  
        } else {
            mes = (MESATUAL - 1) * 30;
            ano = (ano - 1) * 365;
            idade = dia + mes + ano;
            return idade;
        }
    } else {
        dia = DIAATUAL - dia;
        if (mes < MESATUAL) {
            mes = (MESATUAL - mes) * 30;
            ano = ano * 365;
            idade = dia + mes + ano;
            return idade;
        } else {
            mes = MESATUAL * 30;
            ano = (ano - 1) * 365;
            idade = dia + mes + ano;
            return idade;
        }
    }
}

///funcao que realiza a troca de "lugares" entre ini e fim.
void trocaPosicoes(int ini, int fim)
{
    char auxNome[TAMNOME], auxSobrenome[TAMSOBRENOME], auxCurso[4];
    int auxProntuario; 
    int auxdia, auxmes, auxano;
    strcpy(auxNome, alunos[ini].nome);
    strcpy(auxSobrenome, alunos[ini].sobrenome);
    strcpy(auxCurso, alunos[ini].curso);
    auxProntuario = alunos[ini].prontuario;
    auxdia = alunos[ini].datandenascimento.dia;
    auxmes = alunos[ini].datandenascimento.mes;
    auxano = alunos[ini].datandenascimento.ano;
    strcpy(alunos[ini].nome, alunos[fim].nome);
    strcpy(alunos[ini].sobrenome, alunos[fim].sobrenome);
    strcpy(alunos[ini].curso, alunos[fim].curso);
    alunos[ini].prontuario = alunos[fim].prontuario;
    alunos[ini].datandenascimento.dia = alunos[fim].datandenascimento.dia;
    alunos[ini].datandenascimento.mes = alunos[fim].datandenascimento.mes;
    alunos[ini].datandenascimento.ano = alunos[fim].datandenascimento.ano;
    strcpy(alunos[fim].nome, auxNome);
    strcpy(alunos[fim].sobrenome, auxSobrenome);
    strcpy(alunos[fim].curso, auxCurso);
    alunos[fim].prontuario = auxProntuario;
    alunos[fim].datandenascimento.dia = auxdia;
    alunos[fim].datandenascimento.mes = auxmes;
    alunos[fim].datandenascimento.ano = auxano;
}

///Menu de busca, com opcoes de busca por nome e sobrenome e por prontuario.
void buscar_aluno()
{
    int escolha_busca;
    printf("1) Buscar por nome e sobrenome:\n2) Buscar por Prontuario: \nInsira sua escolha: ");
    scanf("%d", &escolha_busca);
    switch (escolha_busca) {
        case 1: buscar_nome();
                break;
        case 2: buscar_prontuario();
                break;
        default: printf("Valor invalido");
    }
}

///Funcao que realiza a busca do usuario, pelo nome e sobrenome inseridos por ele.
void buscar_nome() 
{
    char Nome[TAMNOME];
    char Sobrenome[TAMSOBRENOME];
    printf("Insira o nome: ");
    scanf("%s", Nome);
    printf("Insira o sobrenome: ");
    scanf("%s", Sobrenome);
    capitalize(Nome);
    capitalize(Sobrenome);
    if (foi_ordenado != 2 && foi_ordenado != 1) {
        int posicao = posicao_nome_linear(Nome, Sobrenome);
        if (posicao >= 0) {
            printf("O aluno(a) se encontra na posicao: %d\n", posicao);
        } else {
            printf("O aluno nao foi encontrado na lista!\n");
        }
    } else {
        if (foi_ordenado == 1) {
            int posicao = posicao_nome_binario(Nome, Sobrenome);
            if (posicao >= 0) {
                printf("O aluno(a) se encontra na posicao: %d\n", posicao);
            } else {
                printf("O aluno nao foi encontrado na lista!\n");
            }
        } else {
            int posicao = posicao_nome_binario_sobrenome(Nome, Sobrenome);
            if (posicao >= 0) {
                printf("O aluno(a) se encontra na posicao: %d\n", posicao);
            } else {
                printf("O aluno nao foi encontrado na lista!\n");
            }
        }
    }
}

///Funcao que busca pelo nome linearmente, caso nao esteja ordenado.
int posicao_nome_linear(char Nome[], char Sobrenome[])
{
    int i; 
    for(i=0; i<NumAlunosCadastrados; i++) {
        if(strcmp(Nome, alunos[i].nome) == 0) {
            if(strcmp(Sobrenome, alunos[i].sobrenome) == 0) {
                return i;
            }
        }
    }
    return -1; 
}

///Função que realiza uma busca binaria na ordem Nome, Sobrenome, caso assim esteja ordenado.
int posicao_nome_binario(char Nome[], char Sobrenome[])
{
    int inicio = 0;
    int fim = NumAlunosCadastrados-1;
    int meio;
    while (inicio <= fim) {
        meio = (inicio + fim)/2;
        if (strcmp(Nome, alunos[meio].nome) == 0) {
            if (strcmp(Sobrenome, alunos[meio].sobrenome) == 0) {
                return meio;
            }
        }
        if (strcmp(alunos[meio].nome, Nome) > 0) fim = meio-1;
        if (strcmp(alunos[meio].nome, Nome) < 0) inicio = meio+1;
    }
    return -1; 
}

///Funcao que realiza uma busca binaria na ordem Sobrenome, Nome, caso esteja ordenado assim.
int posicao_nome_binario_sobrenome(char Nome[], char Sobrenome[])
{
    int inicio = 0;
    int fim = NumAlunosCadastrados-1;
    int meio;
    while (inicio <= fim) {
        meio = (inicio + fim)/2;
        if (strcmp(Sobrenome, alunos[meio].sobrenome) == 0) {
            if (strcmp(Nome, alunos[meio].nome) == 0) {
                return meio;
            }
        }
        if (strcmp(alunos[meio].sobrenome, Sobrenome) > 0) fim = meio-1;
        if (strcmp(alunos[meio].sobrenome, Sobrenome) < 0) inicio = meio+1;
    }
    return -1; 
}

///Função que recebe o numero de prontuario do usuario e busca pelo mesmo.
void buscar_prontuario()
{
    int escolha_pront; 
    printf("Insira o prontuario: ");
    scanf("%d", &escolha_pront);
    if (foi_ordenado == 3) {
        int posicao = busca_prontuario_binaria(escolha_pront);
        if (posicao >= 0) {
                printf("O aluno(a) se encontra na posicao: %d\n", posicao);
        } else {
            printf("O aluno nao foi encontrado na lista!\n");
        }
    } else {
        int posicao = busca_prontuario_linear(escolha_pront);
        if (posicao >= 0) {
                printf("O aluno(a) se encontra na posicao: %d\n", posicao);
        } else {
            printf("O aluno nao foi encontrado na lista!\n");
        }
    }
}

///Busca por prontuario linear, caso nao esteja ordenado.
int busca_prontuario_linear(int escolha)
{
    int i; 
    for(i=0; i<NumAlunosCadastrados; i++) {
        if(alunos[i].prontuario == escolha) {
                return i;
            }
        }
    return -1; 
}

///Função de busca binaria do prontuario, caso esteja ordenado.
int busca_prontuario_binaria(int escolha)
{
    int inicio = 0;
    int fim = NumAlunosCadastrados-1;
    int meio;
    while (inicio <= fim) {
        meio = (inicio + fim)/2;
        if (alunos[meio].prontuario == escolha) return meio;
        if (alunos[meio].prontuario > escolha) fim = meio-1;
        else inicio = meio+1;
    }
    return -1; 
}

///Menu que permite o usuario selecionar o que deseja deletar pelo método selecionado por ele.
void deletar_aluno()    
{
    int metodo_delete;
    printf("1) Nome e Sobrenome\n2) Nome\n3) Sobrenome\n4) Prontuario\n5) Data de Nascimento\n6) Curso\n");
    printf("Insira o metodo para que o aluno seja deletado: ");
    scanf("%d", &metodo_delete);
    switch(metodo_delete) {
        case 1: deletar_nome_sobrenome();
                break;
        case 2: deletar_nome();
                break;
        case 3: deletar_sobrenome();
                break;
        case 4: deletar_prontuario();
                break;
        case 5: deletar_idade();
                break;
        case 6: deletar_curso();
                break;
        default: printf("Valor Invalido!\n");
    }
}

///Função que deleta o usuario inserido, pelo nome e sobrenome, busca tanto linearmente quanto binario, dependendo da ordenacao.
void deletar_nome_sobrenome()
{
    char Nome[TAMNOME];
    char Sobrenome[TAMSOBRENOME];
    printf("Insira o nome: ");
    scanf("%s", Nome);
    printf("Insira o sobrenome: ");
    scanf("%s", Sobrenome);
    capitalize(Nome);
    capitalize(Sobrenome);
    if (foi_ordenado != 2 && foi_ordenado != 1) {
        int posicao = posicao_nome_linear(Nome, Sobrenome);
        if (posicao >= 0) {
            int i;
            if(NumAlunosCadastrados != posicao) {
                for(i=posicao; i<NumAlunosCadastrados; i++)  {
                    trocaPosicoes(i, i+1);
                }
                NumAlunosCadastrados -= 1;
            } else {
                NumAlunosCadastrados -= 1;
            }
        } else {
            printf("O aluno nao foi encontrado na lista!\n");
        }
    } else {
        if (foi_ordenado == 1) {
            int posicao = posicao_nome_binario(Nome, Sobrenome);
            if (posicao >= 0) {
                int i;
                if(NumAlunosCadastrados != posicao) {
                    for(i=posicao; i<NumAlunosCadastrados; i++)  {
                        trocaPosicoes(i, i+1);
                    }
                    NumAlunosCadastrados -= 1;
                } else {
                    NumAlunosCadastrados -= 1;
                }
            } else {
                printf("O aluno nao foi encontrado na lista!\n");
            }
        } else {
            int posicao = posicao_nome_binario_sobrenome(Nome, Sobrenome);
            if (posicao >= 0) {
                int i;
                if(NumAlunosCadastrados != posicao) {
                    for(i=posicao; i<NumAlunosCadastrados; i++)  {
                        trocaPosicoes(i, i+1);
                    }
                    NumAlunosCadastrados -= 1;
                } else {
                    NumAlunosCadastrados -= 1;
                }
            } else {
                printf("O aluno nao foi encontrado na lista!\n");
            }
        }
    }
}

///Função que deleta a pessoa pelo nome, podendo ser deletado mais de um, caso haja o mesmo nome.
void deletar_nome()
{
    char Nome[TAMNOME];
    int vetor_nomes[TAMTURMA];
    int n_iguais;
    int i;
    printf("Insira o nome: ");
    scanf("%s", Nome);
    capitalize(Nome);
    n_iguais = buscar_nome_repetidos(Nome, vetor_nomes);
    trocarPosicoesIguais(n_iguais, vetor_nomes);
}

///Função que busca pelo nome inserido pelo usuario, podendo ser encontrado mais de um do mesmo nome.
int buscar_nome_repetidos(char Nome[], int vetor_nomes[])
{   
    int i, n = 0;
    for(i=0; i<NumAlunosCadastrados;i++) {
        if (strcmp(alunos[i].nome, Nome) != 0) {
            vetor_nomes[n] = i;
            n++;
        }
    }
    return n;
}

///Função que deleta o sobrenome qual o usuario insere, podendo ser deletado mais de um. 
void deletar_sobrenome()
{
    char Sobrenome[TAMNOME];
    int vetor_sobrenomes[TAMTURMA];
    int n_iguais;
    int i;
    printf("Insira o sobrenome: ");
    scanf("%s", Sobrenome);
    capitalize(Sobrenome);
    n_iguais = buscar_sobrenome_repetidos(Sobrenome, vetor_sobrenomes);
    trocarPosicoesIguais(n_iguais, vetor_sobrenomes);
}

///Função que busca linearmente por sobrenomes que estejam repetidos, ou unicos. 
int buscar_sobrenome_repetidos(char Sobrenome[], int vetor_sobrenomes[])
{   
    int i, n = 0;
    for(i=0; i<NumAlunosCadastrados;i++) {
        if (strcmp(alunos[i].sobrenome, Sobrenome) != 0) {
            vetor_sobrenomes[n] = i;
            n++;
        }
    }
    return n;
}

///Função que deleta o usuario pelo prontuario, tanto por busca binaria, quanto por linear, dependendo da ordenacao.
void deletar_prontuario() 
{   
    int escolha_pront; 
    printf("Insira o prontuario: ");
    scanf("%d", &escolha_pront);
    if (foi_ordenado == 3) {
        int posicao = busca_prontuario_binaria(escolha_pront);
        if (posicao >= 0) {
            int i;
            if(NumAlunosCadastrados != posicao) {
                for(i=posicao; i<NumAlunosCadastrados; i++)  {
                    trocaPosicoes(i, i+1);
                }
                NumAlunosCadastrados -= 1;
            } else {
                NumAlunosCadastrados -= 1;
            }
        } else {
            printf("O aluno nao foi encontrado na lista!\n");
        }
    } else {
        int posicao = busca_prontuario_linear(escolha_pront);
        if (posicao >= 0) {
            int i;
            if(NumAlunosCadastrados != posicao) {
                for(i=posicao; i<NumAlunosCadastrados; i++)  {
                    trocaPosicoes(i, i+1);
                }
                NumAlunosCadastrados -= 1;
            } else {
                NumAlunosCadastrados -= 1;
            }
        } else {
            printf("O aluno nao foi encontrado na lista!\n");
        }
    }
}

///Funcao que deleta a pessoa pela idade, caso ela esteja no array.
void deletar_idade() 
{
    int dia, mes, ano;
    printf("Insira o dia de nascimento: ");
    scanf("%d", &dia);
    printf("Insira o mes de nascimento: ");
    scanf("%d", &mes);
    printf("Insira o ano de nascimento: ");
    scanf("%d", &ano);
    int idade = calcular_idade_inserida(dia, mes, ano);
    int i;
    int pos_pessoa = buscar_idade(idade);
    if (pos_pessoa >= 0) {
        for(i=pos_pessoa; i<NumAlunosCadastrados; i++) {
            trocaPosicoes(i, i+1);
        }
        NumAlunosCadastrados -= 1;
    } else {
        printf("O aluno nao foi encontrado!\n");
    }
}

///Calculo da idade inserida, sem utilizar o array de struct.
int calcular_idade_inserida(int dia, int mes, int ano)
{
    int idade;
    ano = (ANOATUAL - ano);
    if (dia > DIAATUAL) {
        dia = DIAATUAL - dia;
        if (mes < MESATUAL) {
            mes = (MESATUAL - mes - 1) * 30;
            ano = ano * 365;
            idade = dia + mes + ano;
            return idade;  
        } else {
            mes = (MESATUAL - 1) * 30;
            ano = (ano - 1) * 365;
            idade = dia + mes + ano;
            return idade;
        }
    } else {
        dia = DIAATUAL - dia;
        if (mes < MESATUAL) {
            mes = (MESATUAL - mes) * 30;
            ano = ano * 365;
            idade = dia + mes + ano;
            return idade;
        } else {
            mes = MESATUAL * 30;
            ano = (ano - 1) * 365;
            idade = dia + mes + ano;
            return idade;
        }
    }
}

///Função que realiza uma busca linear pelas idades, realizando um calculo para que sejam comparadas idade em dias.
int buscar_idade(int idade)
{
    int i, idade_cadaum; 
    for(i=0; i<NumAlunosCadastrados; i++) {
        idade_cadaum = calculoIdade(i);
        if(idade == idade_cadaum) {
            return i;
        }
    }
    return -1;
}

///Função que deleta o curso que foi selecionado, se o mesmo estiver presente, pode deletar mais de uma pessoa, caso haja mais de uma que realiza o curso.
void deletar_curso()
{
    char Curso[4];
    int vetor_curso[TAMTURMA];
    int n_iguais;
    int i;
    printf("Insira o curso: ");
    scanf("%s", Curso);
    for(i=0; i<strlen(Curso); i++) {
        upperCurso_b(i, Curso);
    }
    n_iguais = buscar_curso(Curso, vetor_curso);
    trocarPosicoesIguais(n_iguais, vetor_curso);
}

///Função que realiza uma busca linear pelos cursos.
int buscar_curso(char Curso[], int vetor_curso[])
{   
    int i, n = 0;
    for(i=0; i<NumAlunosCadastrados;i++) {
        if (strcmp(alunos[i].curso, Curso) != 0) {
            vetor_curso[n] = i;
            n++;
        }
    }
    return n;
}

///Função que troca a posiçao dos "itens" do vetor quando este possui mais de um para ser trocado, removido.
void trocarPosicoesIguais(int n_iguais, int vetor[])
{
    int i;
    int pos;
    for(i=0; i<n_iguais; i++) {
        pos = vetor[i];
        if(pos != i) trocaPosicoes(pos, i);
    }
    NumAlunosCadastrados = n_iguais;
}


///Função que realiza o Capitalize (1 Letra maiuscula, resto minuscula) quando chamada.
void capitalize(char *Nome)
{
    if (((int) Nome[0] >= 97 || (int) Nome[0] <= 122) && ((int) Nome[0] > 90 || (int) Nome[0] < 65)) {
        int carac = 65;
        int letra = ((int) Nome[0]) - 97;
        carac += letra;
        Nome[0] = (char) carac;
    }
    int i; 
    for(i=1; i<strlen(Nome); i++) {
        if (((int) Nome[i] < 97 || (int) Nome[i] > 122) && ((int) Nome[i] <= 90 || (int) Nome[i] >= 65)) {
            int carac = 97;
            int letra = ((int) Nome[i]) - 65;
            carac += letra;
            Nome[i] = (char) carac;
        }
    }
}

///função que realiza um "Caps Lock" de todas as letras de quando é declarado o curso no vetor de struct.
void upperCurso(int i) 
{
    if ((int) alunos[NumAlunosCadastrados].curso[i] >= 97 || (int) alunos[NumAlunosCadastrados].curso[i] <= 122 && (int) alunos[NumAlunosCadastrados].curso[i] > 90 || (int) alunos[NumAlunosCadastrados].curso[i] < 65) {
        int carac = 65;
        int letra = ((int) alunos[NumAlunosCadastrados].curso[i]) - 97;
        carac += letra;
        alunos[NumAlunosCadastrados].curso[i] = (char) carac;
    }
}

///Função que realiza o "Caps Lock" de todas as letras do curso declarado na remoção por curso.
void upperCurso_b(int i, char Curso[]) 
{
    if ((int) Curso[i] >= 97 || (int) Curso[i] <= 122 && (int) Curso[i] > 90 || (int) Curso[i] < 65) {
        int carac = 65;
        int letra = ((int) Curso[i]) - 97;
        carac += letra;
        Curso[i] = (char) carac;
    }
}


///função que insere a lista de alunos no arquivo alunos
void salvar_arquivo()
{
    FILE *arquivo;
    int i;
    arquivo = fopen ("alunos", "w");
    if ( arquivo == NULL )
    {
        printf ("O arquivo nao pode ser aberto. \n");
        return;
    }
    for (i = 0; i < NumAlunosCadastrados; i++ )
    {
        fprintf(arquivo, "%s %s %d %s %d %d %d\n", alunos[i].nome, alunos[i].sobrenome, alunos[i].prontuario, alunos[i].curso, alunos[i].datandenascimento.dia, alunos[i].datandenascimento.mes, alunos[i].datandenascimento.ano);
    }
    fclose (arquivo);
}

///função que lê o arquivo alunos e o adiciona na lista alunos
void ler_arquivo()
{
    FILE *arquivo;
    arquivo = fopen ( "alunos", "r" );
    if ( arquivo == NULL ) {
        printf ( "O arquivo nao pode ser aberto. \n" );
        return;
    }
    while(fscanf(arquivo, "%s %s %d %s %d %d %d", alunos[NumAlunosCadastrados].nome, alunos[NumAlunosCadastrados].sobrenome, &alunos[NumAlunosCadastrados].prontuario, alunos[NumAlunosCadastrados].curso, &alunos[NumAlunosCadastrados].datandenascimento.dia, &alunos[NumAlunosCadastrados].datandenascimento.mes, &alunos[NumAlunosCadastrados].datandenascimento.ano)!= EOF) {
        NumAlunosCadastrados++;
    }
    fclose (arquivo);
}
