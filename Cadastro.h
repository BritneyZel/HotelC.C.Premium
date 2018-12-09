#include <stdio.h>
#include <time.h>

typedef struct{
    int tipquart;
    int carro;
    int diascarro;
    int tanqcheio; //if 1, entao tem
    int carseguro; //if 1, entao tem
    float hourbaba;
    int quartChild; //if 1, entao tem uma caminha no quarto
}Servadd;


struct Menucomida{
    char nomePrato[40];
    char ingredient[80];
    float preco;
};


typedef struct{
    float qpresidencial;
    float qluxsim;
    float qlixdupl;
    float qluxtrpl;
    float qexecsim;
    float qexecdupl;
    float qexectripl;
    float bbshora;
    float carrolux;
    float carroexec;
    float tanqcheio;
    float carseguro;
}VALOR;

typedef struct{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct{
    int qpresidencial;
    int qluxsim;
    int qlixdupl;
    int qluxtrpl;
    int qexecsim;
    int qexecdupl;
    int qexectripl;
}TANTOs;

typedef struct{
    Data inicio;
    Data fim;
    Data nascimento;
    Servadd servicos;
    float boletoCOMIDA;
    int cpf;
    int telefone;
    char nome[50];
    int status;
}Hospcadastro;

void Showdata(){
    int diaatual, mesatual, anoatual;
    struct tm *local;
    time_t temp;
    temp= time(NULL);
    local= localtime(&temp);
    diaatual= local -> tm_mday;
    mesatual= local -> tm_mon+1;
    anoatual= local -> tm_year+1900;
    printf("%d/%d/%d", diaatual, mesatual, anoatual);
}

int checkfinalreserv(int dia, int mes, int ano){
     int diaatual, mesatual, anoatual;
    struct tm *local;
    time_t temp;
    temp= time(NULL);
    local= localtime(&temp);
    diaatual= local -> tm_mday;
    mesatual= local -> tm_mon+1;
    anoatual= local -> tm_year+1900;
    if(dia==diaatual&&mes==mesatual&&ano==anoatual){
        return 1; //reserva fechada;
    }
    else{
        return 0;//reserba anerta;
    }
}
int checkreserv(int dia, int mes, int ano){
     int diaatual, mesatual, anoatual;
    struct tm *local;
    time_t temp;
    temp= time(NULL);
    local= localtime(&temp);
    diaatual= local -> tm_mday;
    mesatual= local -> tm_mon+1;
    anoatual= local -> tm_year+1900;
    if((dia==diaatual||dia<diaatual)&&(mes==mesatual||mes<mesatual)&&(ano==anoatual||ano<anoatual)){
        return 1; //reserva fechada;
    }
    else{
        return 0;//reserba anerta;
    }
}

