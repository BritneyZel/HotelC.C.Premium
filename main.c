#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "Cadastro.h"
#include <locale.h>
#include <time.h>
/*
--Projeto Hotel Campina Confort Premium--
        Executar em tela cheia */
void inicializacao(){
    int i, j;
    for(i=0;i<3;i++){
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t******************************************************************************************************\n");
            printf("\t\t\t\t\t\t******************************************************************************************************\n");
            printf("\t\t\t\t\t\t====================================== HOTEL CAMPINA CONFORT PREMIUM =================================\n");
            printf("\t\t\t\t\t\t******************************************************************************************************\n");
            printf("\t\t\t\t\t\t******************************************************************************************************\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\tCARREGANDO");
            for(j=0;j<3;j++){
                Sleep(600);
                printf(".");
                Sleep(600);
            }
    }
}
void cabecalho(){
     system("cls");
     printf("\n\n\n\n\n\n\n\t\t*******************************************************************************************************************\n\n");
            printf("\t\t    HOTEL CAMPINA CONFORT PREMIUM                                                          ");
            Showdata();
            printf("\n\n\t\t*******************************************************************************************************************\n\n");
}
void menu(){
    cabecalho();
    printf("\n\n\t\t\t\t=============================================================================================\n");
    printf("\n\n\t\t\t\t\tEscolha uma das opções abaixo\n\n\t\t\t\t\t(1)-Criar reserva de hóspede\n\n\t\t\t\t\t(2)-Procurar reserva de hóspede\n\n\t\t\t\t\t(3)-Listar reservas de hóspede\n\n\t\t\t\t\t(4)-Editar reserva dos hóspedes\n\n\t\t\t\t\t(5)-CheckOuts\n\n\t\t\t\t\t(6)-Editar valores do hotel\n\n\t\t\t\t\t(7)-Checar disponibilidade do hotel\n\n\t\t\t\t\t(8)-Restaurante DelÍcias da Serra\n\n\t\t\t\t\t(9)-Sair do programa");
    printf("\n\n\t\t\t\t=============================================================================================\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tOpção: ");
}
void valoresiniciais(){
    VALOR ctt;
    FILE *valores;
    valores= fopen("valores.txt", "wb");
    ctt.qpresidencial=1200;
    ctt.qluxsim=520;
    ctt.qlixdupl=570;
    ctt.qluxtrpl=620;
    ctt.qexecsim=360;
    ctt.qexecdupl=385;
    ctt.qexectripl=440;
    ctt.bbshora=45;
    ctt.carrolux=100;
    ctt.carroexec=60;
    ctt.tanqcheio=300;
    ctt.carseguro=250;
    fwrite(&ctt, sizeof(VALOR),1,valores);
    fclose(valores);
}
void vervalores(){
    VALOR ctt;
    FILE *valores;
    valores= fopen("valores.txt", "r");
    fread(&ctt,sizeof(VALOR),1, valores);
        printf("\n\n\t\t\t\tQuarto presidencial= %.2f", ctt.qpresidencial);
        printf("\n\n\t\t\t\tQuarto de luxo simples= %.2f", ctt.qluxsim);
        printf("\n\n\t\t\t\tQuarto de luxo duplo= %.2f", ctt.qlixdupl);
        printf("\n\n\t\t\t\tQuarto de luxo triplo= %.2f", ctt.qluxtrpl);
        printf("\n\n\t\t\t\tQuarto executivo simples= %.2f", ctt.qexecsim);
        printf("\n\n\t\t\t\tQuarto executivo duplo= %.2f", ctt.qexecdupl);
        printf("\n\n\t\t\t\tQuarto executivo triplo= %.2f", ctt.qexectripl);
        printf("\n\n\t\t\t\tValor da babbysitter por hora= %.2f", ctt.bbshora);
        printf("\n\n\t\t\t\tAlugar carro de luxo= %.2f", ctt.carrolux);
        printf("\n\n\t\t\t\tAlugar carro executivo= %.2f", ctt.carroexec);
        printf("\n\n\t\t\t\tTanque cheio= %.2f", ctt.tanqcheio);
        printf("\n\n\t\t\t\tCarro assegurado= %.2f", ctt.carseguro);
    fclose(valores);
}
void quantidades(){
    TANTOs eae;
    FILE *quantia;
    quantia=fopen("quantidades.txt", "wb");
    eae.qpresidencial=5;
    eae.qluxsim=5;
    eae.qlixdupl=15;
    eae.qluxtrpl=20;
    eae.qexecsim=5;
    eae.qexecdupl=15;
    eae.qexectripl=20;
    fwrite(&eae, sizeof(TANTOs), 1, quantia);
    fclose(quantia);
}
int quantDias(int dia,int mes,int ano,int dia1,int mes1,int ano1){
    int diferenca;
        diferenca=(dia1-dia)+(mes1-mes)*30+(ano1-ano)*360;
        if(diferenca<0){
            diferenca=diferenca*-1;
    }
    return diferenca+1;
}
void inputHosp(){
        Hospcadastro cadast;
        FILE *cadasHospedes;
        FILE *valores;
        FILE *quantia;
        FILE *food;
        VALOR ctt;
        TANTOs opp;
        int op, dias, day1;
        valores=fopen("valores.txt", "rb");
        quantia= fopen("quantidades.txt", "r+");
        cadasHospedes= fopen("cadastroHospedes.txt", "ab");
        food= fopen("foodmenu.txt","rb");
        cabecalho();
        printf("\n\t\t\tCADASTRO DE HÓSPEDES");
        printf("\n\n\t\t\t\tDigite o nome do hóspede: ");
        fflush(stdin);
        gets(cadast.nome);
        strupr(cadast.nome);
        cadast.status=0;
        cadast.boletoCOMIDA=0;
        printf("\n\n\t\t\t\tDigite o cpf do hóspede: ");
        fflush(stdin);
        scanf("%d",&cadast.cpf);
        printf("\n\n\t\t\t\tDigite o telefone para contato do hóspede: ");
        fflush(stdin);
        scanf("%d",&cadast.telefone);
        printf("\n\n\t\t\t\tDigite a data de nacimento do hóspede(dia mes ano): ");
        fflush(stdin);
        scanf("%d %d %d",&cadast.nascimento.dia, &cadast.nascimento.mes, &cadast.nascimento.ano);
        printf("\n\n\t\t\t\tDigite a data do inicio da reserva do quarto(dia mes ano): ");
        fflush(stdin);
        scanf("%d %d %d",&cadast.inicio.dia, &cadast.inicio.mes, &cadast.inicio.ano);
        printf("\n\n\t\t\t\tDigite a data do fim da reserva do quarto(dia mes ano): ");
        fflush(stdin);
        scanf("%d %d %d",&cadast.fim.dia, &cadast.fim.mes, &cadast.fim.ano);
        dias=quantDias(cadast.inicio.dia, cadast.inicio.mes, cadast.inicio.ano, cadast.fim.dia, cadast.fim.mes, cadast.fim.ano);
         printf("\n\n\t\t\t\tDias totais de reserva: %d", dias);
        fread(&ctt,sizeof(VALOR),1, valores);
       do{
        printf("\n\n\t\t\t\tDigite o tipo de quarto do hóspede:\n\n\t\t\t(1)-Quarto Presidencial(Diária= %0.2f R$)\t\t(2)-Quarto de Luxo Simples(Diária= %.2f R$)\n\n\t\t\t(3)-Quarto de Luxo Duplo(Diária= %.2f R$)\t\t(4)-Quarto de Luxo Triplo(Diária= %.2f R$)\n\n\t\t\t(5)-Quarto Executivo Simples(Diária= %.2f R$)\t\t(6)-Quarto Executivo Duplo(Diária= %.2f R$)\n\n\t\t\t(7)-Quarto Executivo Triplo(Diária= %.2f R$)\n\n\t\t\t*Opção* ", ctt.qpresidencial, ctt.qluxsim, ctt.qlixdupl, ctt.qluxtrpl, ctt.qexecsim, ctt.qexecdupl, ctt.qexectripl);
        scanf("%d",&cadast.servicos.tipquart);
        cabecalho();
        printf("\n\t\t\tCADASTRO DE HÓSPEDES");
        fread(&opp,sizeof(TANTOs),1, quantia);
        if(cadast.servicos.tipquart==1){
            if(opp.qpresidencial>0){
                printf("\n\n\t\t\t\tQuarto Presidencial selecionado com sucesso\n\n\t\t\t\t(Capacidade: 4 Pessoas em dois quartos diferentes)\n");
                opp.qpresidencial=opp.qpresidencial-1;
                op=1;
                system("pause");
                break;
            }
            else{
                printf("\n\n\t\tQuarto não disponível\n\t\t");
                system("pause");
                op=0;
            }
        }
        else if(cadast.servicos.tipquart==2){
            if(opp.qluxsim>0){
                printf("\n\n\t\t\tQuarto de Luxo Simples selecionado com sucesso\n\n\t\t\t(Capacidade: 1 Pessoa)");
                opp.qluxsim=opp.qluxsim-1;
                printf("\n\n\n\t\t\t\tDeseja adicionar uma cama para criança?(Até nove anos) 1-Sim, 0-Não:  ");
                scanf("%d", &cadast.servicos.quartChild);
                if(cadast.servicos.quartChild==1){
                    printf("\n\n\t\t\tCama adicionada\n\t\t");
                    system("pause");
                }
                else{
                    printf("\n\n\t\t\tCama não adicionada\n\t\t");
                    system("pause");
                }
                op=1;
                break;
            }

            else{
                printf("\n\n\t\tQuarto não disponível\n\t\t");
                system("pause");
                op=0;
            }
        }
        else if(cadast.servicos.tipquart==3){
            if(opp.qlixdupl>0){
                printf("\n\n\t\t\tQuarto de Luxo Duplo selecionado com sucesso\n\n\t\t\t(Capacidade: 2 Pessoas)");
                opp.qlixdupl=opp.qlixdupl-1;
                printf("\n\n\t\t\t\tDeseja adicionar uma cama para criança?(Até nove anos) 1-Sim, 0-Não: ");
                scanf("%d", &cadast.servicos.quartChild);
                if(cadast.servicos.quartChild==1){
                    printf("\n\n\t\t\tCama adicionada\n\t\t");
                    system("pause");
                }
                else{
                    printf("\n\n\t\t\tCama não adicionada\n\t\t");
                    system("pause");
                }
                op=1;
                break;
            }
            else{
                printf("\n\n\t\tQuarto não disponível\n\t\t");
                system("pause");
                op=0;
            }
        }
        else if(cadast.servicos.tipquart==4){
            if(opp.qluxtrpl>0){
                printf("\n\n\t\t\tQuarto de Luxo Triplo selecionado com sucesso\n\n\t\t\t(Capacidade: 3 Pessoas)");
                opp.qluxtrpl=opp.qluxtrpl-1;
                printf("\n\n\t\t\tDeseja adicionar uma cama para criança?(Até nove anos) 1-Sim, 0-Não: ");
                scanf("%d", &cadast.servicos.quartChild);
                if(cadast.servicos.quartChild==1){
                    printf("\n\n\t\t\tCama adicionada\n\t\t");
                    system("pause");
                }
                else{
                    printf("\n\n\t\t\tCama não adicionada\n\t\t");
                    system("pause");
                }
                op=1;
                break;
            }
            else{
                printf("\n\n\t\tQuarto não disponível\n\t\t");
                system("pause");
                op=0;
            }
        }
        else if(cadast.servicos.tipquart==5){
            if(opp.qexecsim>0){
                printf("\n\n\t\t\tQuarto Executivo Simples selecionado com sucesso\n\n\t\t\t(Capacidade: 1 Pessoa)");
                opp.qexecsim=opp.qexecsim-1;
                printf("\n\n\t\t\tDeseja adicionar uma cama para criança?(Até nove anos) 1-Sim, 0-Não: ");
                scanf("%d", &cadast.servicos.quartChild);
                if(cadast.servicos.quartChild==1){
                    printf("\n\n\t\t\tCama adicionada\n\t\t");
                    system("pause");
                }
                else{
                    printf("\n\n\t\t\tCama não adicionada\n\t\t");
                    system("pause");
                }
                op=1;
                break;
            }
            else{
                printf("\n\n\t\tQuarto não disponível\n\t\t");
                system("pause");
                op=0;
            }
        }
        else if(cadast.servicos.tipquart==6){
            if(opp.qexecdupl>0){
                printf("\n\n\t\t\tQuarto Executivo Duplo selecionado com sucesso\n\n\t\t\t(Capacidade: 2 Pessoas)");
                opp.qexecdupl=opp.qexecdupl-1;
                printf("\n\n\t\t\tDeseja adicionar uma cama para criança?(Até nove anos) 1-Sim, 0-Não: ");
                scanf("%d", &cadast.servicos.quartChild);
                if(cadast.servicos.quartChild==1){
                    printf("\n\n\t\t\tCama adicionada\n\t\t");
                    system("pause");
                }
                else{
                    printf("\n\n\t\t\tCama não adicionada\n\t\t");
                    system("pause");
                }
                op=1;
                break;
            }
            else{
                printf("\n\n\t\tQuarto não disponível\n\t\t");
                system("pause");
                op=0;
            }
        }
        else if(cadast.servicos.tipquart==7){
            if(opp.qexectripl>0){
                printf("\n\n\t\t\tQuarto Executivo Triplo selecionado com sucesso\n\n\t\t\t(Capacidade: 3 Pessoas)");
                opp.qexectripl=opp.qexectripl-1;
                printf("\n\n\t\t\tDeseja adicionar uma cama para criança?(Até nove anos) 1-Sim, 0-Não: ");
                scanf("%d", &cadast.servicos.quartChild);
                if(cadast.servicos.quartChild==1){
                    printf("\n\n\t\t\tCama adicionada\n\t\t");
                    system("pause");
                }
                else{
                    printf("\n\n\t\t\tCama não adicionada\n\t\t");
                    system("pause");
                }
                op=1;
                break;
            }
            else{
                printf("\n\n\t\tQuarto não disponível\n\t\t");
                system("pause");
                op=0;
            }
        }
        else{
            printf("\n\nDigite uma opção válida\n\t\t");
            system("pause");
        }
        }while(op!=0);
        system("cls");
        op=0;
        cabecalho();
        printf("\n\n\t\t\tCADASTRO DE HÓSPEDES-Serviços adicionais");
        printf("\n\n\t\t\t\tDeseja adicionar horas de babysitter?(%.2f R$ por hora): (0-não, 1-sim): ", ctt.bbshora);
        scanf("%d", &op);
        if(op==1){
           printf("\n\n\t\t\t\tDeseja adicionar QUANTAS horas de babysitter?(00,00 = 00:00):");
           scanf("%f", &cadast.servicos.hourbaba);
        }
        else{
            cadast.servicos.hourbaba=0;
        }
        printf("\n\n\t\t\t\tDeseja alugar algum carro?(0-não, 1-sim): ");
        scanf("%d", &op);
        cabecalho();
            printf("\n\n\t\t\tCADASTRO DE HÓSPEDES-Serviços adicionais");
            switch (op){
                case 1 :
            printf("\n\n\t\t\t1-Automóvel de luxo(Diária: %.2f R$)\n\t\t\t2-Automóvel executivo(Diária: %.2f R$ )\n\t\t\t0-Nenhum carro\n\n\t\t\tOpção: ", ctt.carrolux, ctt.carroexec);
            scanf("%d", &cadast.servicos.carro);
            if(cadast.servicos.carro==1){
                printf("\n\n\t\t\t\tDigite a quantidade de dias que deseja alugar o carro de luxo: ");
                scanf("%d", &day1);
            while(day1>dias){
                printf("\n\n\t\t\t\tNúmero de dias de aluguel do carro não podem ser maior que o número de dias da reserva do hóspede\n\n\t\t\t");
                system("pause");
                cabecalho();
                printf("\n\n\t\t\tCADASTRO DE HÓSPEDES-Serviços adicionais");
                printf("\n\n\t\t\t\tDigite a quantidade de dias que deseja alugar o carro de luxo: ");
                scanf("%d", &day1);
            }
                cadast.servicos.diascarro=day1;
                op=0;
                printf("\n\n\t\t\t\tDeseja adicionar serviço tanque cheio ao carro?(%.2f R$)(0-não, 1-sim): ", ctt.tanqcheio);
                scanf("%d", &op);
                if(op==1){
                        cadast.servicos.tanqcheio=1;
                }
                op=0;
                printf("\n\n\t\t\t\tDeseja adicionar serviço de seguro ao carro?(%.2f R$)(0-não, 1-sim)", ctt.carseguro);
                scanf("%d", &op);
                if(op==1){
                    cadast.servicos.carseguro=1;
                }
            }
            else if(cadast.servicos.carro==2){
                printf("\n\n\t\t\t\tDigite a quantidade de dias que deseja alugar o carro de luxo: ");
                scanf("%d", &day1);
            while(day1>dias){
                printf("\n\n\t\t\t\tNúmero de dias de aluguel do carro não podem ser maior que o número de dias da reserva do hóspede\n\n\t\t\t");
                system("pause");
                cabecalho();
                printf("\n\n\t\t\tCADASTRO DE HÓSPEDES-Serviços adicionais");
                printf("\n\n\t\t\t\tDigite a quantidade de dias que deseja alugar o carro de luxo: ");
                scanf("%d", &day1);
            }
                cadast.servicos.diascarro=day1;
                op=0;
                printf("\n\n\t\t\t\tDeseja adicionar serviço tanque cheio ao carro?(%.2f R$)(0-não, 1-sim)", ctt.tanqcheio);
                scanf("%d", &op);
                if(op==1){
                        cadast.servicos.tanqcheio=1;
                }
                op=0;
                printf("\n\n\t\t\t\tDeseja adicionar serviço de seguro ao carro?(%.2f R$)(0-não, 1-sim)", ctt.carseguro);
                scanf("%d", &op);
                if(op==1){
                    cadast.servicos.carseguro=1;
                }

            }
            default :
                    break;
        }
                    printf("\n\n\n\t\t\t\tCADASTRO CONCLUIDO");
                    fseek(cadasHospedes, 0L,SEEK_END);
                    if(fwrite(&cadast, sizeof(Hospcadastro),1,cadasHospedes)!=1){
                        printf("\n\n\n\t\t\t\tFALHA AO CADASTRAR RESERVA");
                    }
                    fseek(quantia,-(long)sizeof(TANTOs),SEEK_CUR);
                    fwrite(&opp, sizeof(TANTOs),1, quantia);
                    fflush(quantia);
            fclose(quantia);
            fclose(valores);
            fclose(cadasHospedes);
            fclose(food);
}
void listar(){
    int num=1;
    Hospcadastro cadast;
    FILE *cadasHospedes;
    cadasHospedes=fopen("cadastroHospedes.txt", "rb");

    if(cadasHospedes==NULL){
        printf("\n\n\t\t\t\tPROBLEMA COM A ABERTURA DA LISTA\n\t\t\t\t");
        system("pause");
    }
    while(fread(&cadast, sizeof(Hospcadastro),1, cadasHospedes)==1){
    if(cadast.status!=1){
     printf("\n\n\t\t\t\t=============================================================================================\n");
    printf("\n\n\t\t\t\tNúmero de registro: %d", num);
    num=num+1;
    printf("\n\n\t\t\t\t\tNome do hóspede: %s\n\t\t\t\t\tCPF do hóspede: %d\n\t\t\t\t\tNúmero de telefone: %d\n\t\t\t\t\tData de Nascimento do hóspede: %d/%d/%d", cadast.nome, cadast.cpf, cadast.telefone, cadast.nascimento.dia, cadast.nascimento.mes, cadast.nascimento.ano);
    printf("\n\t\t\t\t\tInicio da reserva do hóspede:%d/%d/%d-----Fim da reserva: %d/%d/%d", cadast.inicio.dia, cadast.inicio.mes, cadast.inicio.ano, cadast.fim.dia, cadast.fim.mes, cadast.fim.ano);
    if(cadast.servicos.tipquart==1){
    printf("\n\t\t\t\t\tTipo de quarto:Presidencial");
    }
    else if(cadast.servicos.tipquart==2){
    printf("\n\t\t\t\t\tTipo de quarto:Luxo Simples");
    }
    else if(cadast.servicos.tipquart==3){
    printf("\n\t\t\t\t\tTipo de quarto:Luxo Duplo");
    }
    else if(cadast.servicos.tipquart==4){
    printf("\n\t\t\t\t\tTipo de quarto:Luxo Triplo");
    }
    else if(cadast.servicos.tipquart==5){
    printf("\n\t\t\t\t\tTipo de quarto:Executivo Simples");
    }
    else if(cadast.servicos.tipquart==6){
    printf("\n\t\t\t\t\tTipo de quarto:Executivo Duplo");
    }
    else if(cadast.servicos.tipquart==7){
    printf("\n\t\t\t\t\tTipo de quarto:Executivo Triplo");
    }
    printf("-----Possui cama de criança?:");
    if(cadast.servicos.quartChild==1){
        printf("Sim");
    }
    else{
        printf("Não");
    }
    printf("\n\t\t\t\t\tHóspede possui aluguel de carro?");
    if(cadast.servicos.carro==1){
        printf("Sim-----Tipo:Luxo");
        if(cadast.servicos.tanqcheio==1){
            printf("\n\t\t\t\t\tCarro com tanque cheio adquirido");
        }
       if(cadast.servicos.carseguro==1){
            printf("\n\t\t\t\t\tCarro com seguro adquirido");
        }
    }
    else if(cadast.servicos.carro==2){
        printf("Sim-----Tipo:Executivo");
        if(cadast.servicos.tanqcheio==1){
            printf("\n\t\t\t\t\tCarro com tanque cheio adquirido");
        }
       if(cadast.servicos.carseguro==1){
            printf("\n\t\t\t\t\tCarro com seguro adquirido");
        }
    }
    else{
        printf("Não");
    }
    printf("\n\t\t\t\t\tBabysitter: ");
    if(cadast.servicos.hourbaba==0){
        printf("0 horas");
    }
    else{
        printf("%.2f horas (00,00 = 00:00)", cadast.servicos.hourbaba);
    }
    printf("\n\n\t\t\t\t=============================================================================================\n");
    }
    }
    fclose(cadasHospedes);
    printf("\n\n\t\t\t\t");
    system("pause");
}
void boleto(Hospcadastro cadast){
    cabecalho();
    int i, diasreserva;
    FILE *valores;
    FILE *cadasHospedes;
    FILE *quantia;
    cadasHospedes=fopen("cadastroHospedes.txt", "r+");
    valores= fopen("valores.txt", "rb");
    quantia= fopen("quantidades.txt", "r+");
    VALOR ctt;
    TANTOs opp;
    Hospcadastro copia;
    float boleto=0;
    fread(&ctt,sizeof(VALOR),1, valores);
    fread(&cadast,sizeof(VALOR),1, valores);
    fread(&opp,sizeof(TANTOs),1, quantia);
    printf("\n\n\t\t\tBOLETO");
    printf("\n\n\t\t\t\t=============================================================================================\n");
    printf("\n\n\t\t\t\tHOTEL CAMPINA CONFORT PREMIUM\n");
    printf("\n\n\t\t\t\t\tNome do hóspede: %s\n\t\t\t\t\tCPF do hóspede: %d", cadast.nome, cadast.cpf);
    diasreserva=quantDias(cadast.inicio.dia, cadast.inicio.mes, cadast.inicio.ano, cadast.fim.dia, cadast.fim.mes, cadast.fim.ano);
    if(cadast.servicos.tipquart==1){
    printf("\n\n\t\t\t\t\tTipo de quarto:Presidencial.............%d X %.2f R$", diasreserva, ctt.qpresidencial);
    boleto=boleto+((float)diasreserva*ctt.qpresidencial);
    opp.qpresidencial=opp.qpresidencial+1;
    }
    else if(cadast.servicos.tipquart==2){
    printf("\n\n\t\t\t\t\tTipo de quarto:Luxo Simples.............%d X %.2f R$", diasreserva, ctt.qluxsim);
    boleto=boleto+((float)diasreserva*ctt.qluxsim);
    opp.qluxsim=opp.qluxsim+1;
    }
    else if(cadast.servicos.tipquart==3){
    printf("\n\n\t\t\t\t\tTipo de quarto:Luxo Duplo...............%d X %.2f R$", diasreserva,ctt.qlixdupl);
    boleto=boleto+((float)diasreserva*ctt.qlixdupl);
    opp.qlixdupl=opp.qlixdupl+1;
    }
    else if(cadast.servicos.tipquart==4){
    printf("\n\n\t\t\t\t\tTipo de quarto:Luxo Triplo..............%d X %.2f R$", diasreserva,ctt.qluxtrpl);
    boleto=boleto+((float)diasreserva*ctt.qluxtrpl);
    opp.qluxtrpl=opp.qluxtrpl+1;
    }
    else if(cadast.servicos.tipquart==5){
    printf("\n\n\t\t\t\t\tTipo de quarto:Executivo Simples........%d X %.2f R$",diasreserva,ctt.qexecsim);
    boleto=boleto+((float)diasreserva*ctt.qexecsim);
    opp.qexecsim=opp.qexecsim+1;
    }
    else if(cadast.servicos.tipquart==6){
    printf("\n\n\t\t\t\t\tTipo de quarto:Executivo Duplo..........%d X %.2f R$",diasreserva,ctt.qexecdupl);
    boleto=boleto+((float)diasreserva*ctt.qexecdupl);
    opp.qexecdupl=opp.qexecdupl+1;
    }
    else if(cadast.servicos.tipquart==7){
    printf("\n\n\t\t\t\t\tTipo de quarto:Executivo Triplo.........%d X %.2f R$",diasreserva, ctt.qexectripl);
    boleto=boleto+((float)diasreserva*ctt.qexectripl);
    opp.qexectripl=opp.qexectripl+1;
    }
     printf("\n\t\t\t\t\tCarro ");
    if(cadast.servicos.carro==1){
        printf("Sim-----Tipo:Luxo.................%d X %.2f R$)", cadast.servicos.diascarro, ctt.carrolux);
        boleto=boleto+((float)cadast.servicos.diascarro*ctt.carrolux);
        if(cadast.servicos.tanqcheio==1){
            printf("\n\n\t\t\t\t\tTanque cheio............................%.2f R$", ctt.tanqcheio);
            boleto=boleto+ctt.tanqcheio;
        }
       else if(cadast.servicos.carseguro==1){
            printf("\n\n\t\t\t\t\tCarro com seguro........................%.2f R$", ctt.carseguro);
            boleto=boleto+ctt.carseguro;
        }
    }
    else if(cadast.servicos.carro==2){
        printf("Sim-----Tipo:Executivo...........%d X %.2f R$",cadast.servicos.diascarro, ctt.carroexec);
        boleto=boleto+((float)cadast.servicos.diascarro*ctt.carroexec);
        if(cadast.servicos.tanqcheio==1){
            printf("\n\n\t\t\t\t\tTanque cheio............................%.2f R$", ctt.tanqcheio);
            boleto=boleto+ctt.tanqcheio;
        }
       else if(cadast.servicos.carseguro==1){
            printf("\n\n\t\t\t\t\tCarro com seguro........................%.2f R$", ctt.carseguro);
         boleto=boleto+ctt.carseguro;
        }
    }
    else{
        printf("Não");
    }
    printf("\n\n\t\t\t\t\tBabysitter: ");
    if(cadast.servicos.hourbaba==0){
        printf("0 horas....................0,00 R$");
    }
    else{
        printf("%.2f horas....................%.2f X %.2f R$", cadast.servicos.hourbaba,cadast.servicos.hourbaba, ctt.bbshora);
        boleto=boleto+(cadast.servicos.hourbaba*ctt.bbshora);
    }
    printf("\n\n\t\t\t\t\tGastos com alimentos no Restaurante Delícias da Serra:%.2f", cadast.boletoCOMIDA);
    boleto=boleto+cadast.boletoCOMIDA;
    printf("\n\n\t\t\t\t\tQuantidade de Dias de reserva: %d", quantDias(cadast.inicio.dia, cadast.inicio.mes, cadast.inicio.ano, cadast.fim.dia, cadast.fim.mes, cadast.fim.ano));
    printf("\n\n\t\t\t\t\tQuantidade de Dias de aluguel de carro: %d", cadast.servicos.diascarro);
    printf("\n\n\t\t\t\t\tVALOR FINAL: %.2f", boleto);
    printf("\n\n\n\t\t\t\t\t        ");
     for (i = 0; i < 43; i++){
    printf("%d", rand() % 9);
  }
    printf("\n\t\t\t\t\t");
     for (i = 0; i < 60; i++){
    printf("|");
  }
    printf("\n\n\n\n\t\t\t\t=============================================================================================\n");
   fseek(quantia,-(long)sizeof(TANTOs),SEEK_CUR);
   cadast.status=1;
    fwrite(&opp, sizeof(TANTOs),1, quantia);
    fseek(cadasHospedes,-(long)sizeof(Hospcadastro),SEEK_CUR);
    fwrite(&cadast, sizeof(Hospcadastro),1, cadasHospedes);
    fflush(quantia);
    fclose(quantia);
    fclose(valores);
    fclose(cadasHospedes);
    printf("\n\n\n\n\t\t\t\t");
    system("pause");
}
void pesquisacpf(int cpf){
    FILE *cadasHospedes;
    Hospcadastro cadast;
    cadasHospedes=fopen("cadastroHospedes.txt", "rb");
    while(fread(&cadast, sizeof(Hospcadastro),1, cadasHospedes)){
    if(cadast.status!=1 && cadast.cpf== cpf){
    printf("\n\n\t\t\t\t=============================================================================================\n");
    printf("\n\n\t\t\t\t\tNome do hóspede: %s\n\t\t\t\t\tCPF do hóspede: %d\n\t\t\t\t\tNúmero de telefone: %d\n\t\t\t\t\tData de Nascimento do hóspede: %d/%d/%d", cadast.nome, cadast.cpf, cadast.telefone, cadast.nascimento.dia, cadast.nascimento.mes, cadast.nascimento.ano);
    printf("\n\n\t\t\t\t\tInicio da reserva do hóspede:%d/%d/%d-----Fim da reserva: %d/%d/%d", cadast.inicio.dia, cadast.inicio.mes, cadast.inicio.ano, cadast.fim.dia, cadast.fim.mes, cadast.fim.ano);
    if(cadast.servicos.tipquart==1){
    printf("\n\n\t\t\t\t\tTipo de quarto:Presidencial");
    }
    else if(cadast.servicos.tipquart==2){
    printf("\n\n\t\t\t\t\tTipo de quarto:Luxo Simples");
    }
    else if(cadast.servicos.tipquart==3){
    printf("\n\n\t\t\t\t\tTipo de quarto:Luxo Duplo");
    }
    else if(cadast.servicos.tipquart==4){
    printf("\n\n\t\t\t\t\tTipo de quarto:Luxo Triplo");
    }
    else if(cadast.servicos.tipquart==5){
    printf("\n\n\t\t\t\t\tTipo de quarto:Executivo Simples");
    }
    else if(cadast.servicos.tipquart==6){
    printf("\n\n\t\t\t\t\tTipo de quarto:Executivo Duplo");
    }
    else if(cadast.servicos.tipquart==7){
    printf("\n\n\t\t\t\t\tTipo de quarto:Executivo Triplo");
    }
    printf("-----Possui cama de criança?:");
    if(cadast.servicos.quartChild==1){
        printf("Sim");
    }
    else{
        printf("Não");
    }
    printf("\n\n\t\t\t\t\tHóspede possui aluguel de carro?");
    if(cadast.servicos.carro==1){
        printf("Sim-----Tipo:Luxo");
        if(cadast.servicos.tanqcheio==1){
            printf("\n\n\t\t\t\t\tCarro com tanque cheio adquirido");
        }
       if(cadast.servicos.carseguro==1){
            printf("\n\n\t\t\t\t\tCarro com seguro adquirido");
        }
    }
    else if(cadast.servicos.carro==2){
        printf("Sim-----Tipo:Executivo");
        if(cadast.servicos.tanqcheio==1){
            printf("\n\n\t\t\t\t\tCarro com tanque cheio adquirido");
        }
       if(cadast.servicos.carseguro==1){
            printf("\n\n\t\t\t\t\tCarro com seguro adquirido");
        }
    }
    else{
        printf("Não");
    }
    printf("\n\n\t\t\t\t\tBabysitter: ");
    if(cadast.servicos.hourbaba==0){
        printf("0 horas");
    }
    else{
        printf("%.2f horas (00,00 = 00:00)", cadast.servicos.hourbaba);
    }
    printf("\n\n\t\t\t\t=============================================================================================\n");
        }
    }
    fclose(cadasHospedes);
}
void checarOutstoday(){
    int checar=0, op;
    FILE *cadasHospedes;
    Hospcadastro cadast;
    cadasHospedes=fopen("cadastroHospedes.txt", "r+");
    rewind(cadasHospedes);
     while(fread(&cadast, sizeof(Hospcadastro),1, cadasHospedes)){
            checar=checkfinalreserv(cadast.fim.dia, cadast.fim.mes, cadast.fim.ano);
            if(checar==1){
    printf("\n\n\t\t\t\t=============================================================================================\n");
    printf("\n\n\t\t\t\t\tNome do hóspede: %s\n\t\t\t\t\tCPF do hóspede: %d\n\t\t\t\t\tNúmero de telefone: %d\n\t\t\t\t\tData de Nascimento do hóspede: %d/%d/%d", cadast.nome, cadast.cpf, cadast.telefone, cadast.nascimento.dia, cadast.nascimento.mes, cadast.nascimento.ano);
    printf("\n\t\t\t\t\tInicio da reserva do hóspede:%d/%d/%d-----Fim da reserva: %d/%d/%d", cadast.inicio.dia, cadast.inicio.mes, cadast.inicio.ano, cadast.fim.dia, cadast.fim.mes, cadast.fim.ano);
    if(cadast.servicos.tipquart==1){
    printf("\n\t\t\t\t\tTipo de quarto:Presidencial");
    }
    else if(cadast.servicos.tipquart==2){
    printf("\n\t\t\t\t\tTipo de quarto:Luxo Simples");
    }
    else if(cadast.servicos.tipquart==3){
    printf("\n\t\t\t\t\tTipo de quarto:Luxo Duplo");
    }
    else if(cadast.servicos.tipquart==4){
    printf("\n\t\t\t\t\tTipo de quarto:Luxo Triplo");
    }
    else if(cadast.servicos.tipquart==5){
    printf("\n\t\t\t\t\tTipo de quarto:Executivo Simples");
    }
    else if(cadast.servicos.tipquart==6){
    printf("\n\t\t\t\t\tTipo de quarto:Executivo Duplo");
    }
    else if(cadast.servicos.tipquart==7){
    printf("\n\t\t\t\t\tTipo de quarto:Executivo Triplo");
    }
    printf("-----Possui cama de criança?:");
    if(cadast.servicos.quartChild==1){
        printf("Sim");
    }
    else{
        printf("Não");
    }
    printf("\n\t\t\t\t\tHóspede possui aluguel de carro?");
    if(cadast.servicos.carro==1){
        printf("Sim-----Tipo:Luxo");
        if(cadast.servicos.tanqcheio==1){
            printf("\n\t\t\t\t\tCarro com tanque cheio adquirido");
        }
       else if(cadast.servicos.carseguro==1){
            printf("\n\t\t\t\t\tCarro com seguro adquirido");
        }
    }
    else if(cadast.servicos.carro==2){
        printf("Sim-----Tipo:Executivo");
        if(cadast.servicos.tanqcheio==1){
            printf("\n\t\t\t\t\tCarro com tanque cheio adquirido");
        }
       else if(cadast.servicos.carseguro==1){
            printf("\n\t\t\t\t\tCarro com seguro adquirido");
        }
    }
    else{
        printf("Não");
    }
    printf("\n\t\t\t\t\tBabysitter: ");
    if(cadast.servicos.hourbaba==0){
        printf("0 horas");
    }
    else{
        printf("%.2f", cadast.servicos.hourbaba);
    }
    printf("\n\n\t\t\t\t=============================================================================================\n");
                printf("\n\n\t\t\t\t\tDeseja ver BOLETO desse hóspede?(1-Sim, 0-Ir para o próximo) ");
                scanf("%d", &op);
                if(op==1){
                    boleto(cadast);
                    op=0;
                }
            }
     }
     fclose(cadasHospedes);
}
void AlterarCadast(){
    FILE *cadasHospedes;
    FILE *quantia;
    FILE *valores;
    VALOR ctt;
    Hospcadastro cadast;
    Hospcadastro copia;
    TANTOs opp;
    quantia= fopen("quantidades.txt", "r+");
    cadasHospedes=fopen("cadastroHospedes.txt", "r+");
    valores=fopen("valores.txt","rb");
    fread(&opp, sizeof(TANTOs),1, quantia);
    fread(&ctt,sizeof(VALOR),1, valores);
    int op1, day1, dias, op;
    int registro;
    cabecalho();
    printf("\n\t\t\tALTERAR RESERVA DE HÓSPEDE");
    listar();
    printf("\n\n\t\t\t\tDigite o número do registro do hóspede: ");
    scanf("%1d", &registro);
    fflush(stdin);
    cabecalho();
    printf("\n\t\t\tALTERAR RESERVA DE HÓSPEDE");
    if(fseek(cadasHospedes,(registro-1)*sizeof(Hospcadastro),SEEK_SET)!=0){
        printf("\n\n\t\t\t\tProblemas com o posicionamento da reserva");
        return;
    }
    if(fread(&cadast,sizeof(Hospcadastro),1, cadasHospedes)!=1){
        printf("\n\n\t\t\t\tProblemas com a leitura da reserva");
        return;
    }
    printf("\n\n\t\t\t          DADOS ATUAIS: ");
    printf("\n\n\t\t\t\t=============================================================================================\n");
    printf("\n\n\t\t\t\t\tNome do hóspede: %s\n\t\t\t\t\tCPF do hóspede: %d\n\t\t\t\t\tNúmero de telefone: %d\n\t\t\t\t\tData de Nascimento do hóspede: %d/%d/%d", cadast.nome, cadast.cpf, cadast.telefone, cadast.nascimento.dia, cadast.nascimento.mes, cadast.nascimento.ano);
    printf("\n\n\t\t\t\t\tInicio da reserva do hóspede:%d/%d/%d-----Fim da reserva: %d/%d/%d", cadast.inicio.dia, cadast.inicio.mes, cadast.inicio.ano, cadast.fim.dia, cadast.fim.mes, cadast.fim.ano);
    if(cadast.servicos.tipquart==1){
    printf("\n\n\t\t\t\t\tTipo de quarto:Presidencial");
    }
    else if(cadast.servicos.tipquart==2){
    printf("\n\n\t\t\t\t\tTipo de quarto:Luxo Simples");
    }
    else if(cadast.servicos.tipquart==3){
    printf("\n\n\t\t\t\t\tTipo de quarto:Luxo Duplo");
    }
    else if(cadast.servicos.tipquart==4){
    printf("\n\n\t\t\t\t\tTipo de quarto:Luxo Triplo");
    }
    else if(cadast.servicos.tipquart==5){
    printf("\n\n\t\t\t\t\tTipo de quarto:Executivo Simples");
    }
    else if(cadast.servicos.tipquart==6){
    printf("\n\n\t\t\t\t\tTipo de quarto:Executivo Duplo");
    }
    else if(cadast.servicos.tipquart==7){
    printf("\n\n\t\t\t\t\tTipo de quarto:Executivo Triplo");
    }
    printf("-----Possui cama de criança?:");
    if(cadast.servicos.quartChild==1){
        printf("Sim");
    }
    else{
        printf("Não");
    }
    printf("\n\n\t\t\t\t\tHóspede possui aluguel de carro?");
    if(cadast.servicos.carro==1){
        printf("Sim-----Tipo:Luxo");
        if(cadast.servicos.tanqcheio==1){
            printf("\n\n\t\t\t\t\tCarro com tanque cheio adquirido");
        }
       if(cadast.servicos.carseguro==1){
            printf("\n\n\t\t\t\t\tCarro com seguro adquirido");
        }
    }
    else if(cadast.servicos.carro==2){
        printf("Sim-----Tipo:Executivo");
        if(cadast.servicos.tanqcheio==1){
            printf("\n\n\t\t\t\t\tCarro com tanque cheio adquirido");
        }
       if(cadast.servicos.carseguro==1){
            printf("\n\n\t\t\t\t\tCarro com seguro adquirido");
        }
    }
    else{
        printf("Não");
    }
    printf("\n\n\t\t\t\t\tBabysitter: ");
    if(cadast.servicos.hourbaba==0){
        printf("0 horas");
    }
    else{
        printf("%.2f horas (00,00 = 00:00)", cadast.servicos.hourbaba);
    }
    printf("\n\n\t\t\t\t=============================================================================================\n");
    printf("\n\n\t\t\t\t");
    system("pause");
    copia.cpf=cadast.cpf;
    copia.fim.dia= cadast.fim.dia;
    copia.fim.mes= cadast.fim.mes;
    copia.fim.ano= cadast.fim.ano;
    copia.inicio.ano= cadast.inicio.ano;
    copia.inicio.dia= cadast.inicio.dia;
    copia.inicio.mes= cadast.inicio.mes;
    copia.nascimento.dia=cadast.nascimento.dia;
    copia.nascimento.mes=cadast.nascimento.mes;
    copia.nascimento.ano=cadast.nascimento.ano;
    strcpy(copia.nome,cadast.nome);
    copia.servicos.carro=cadast.servicos.carro;
    copia.servicos.carseguro=cadast.servicos.carseguro;
    copia.servicos.diascarro=cadast.servicos.diascarro;
    copia.servicos.hourbaba=cadast.servicos.hourbaba;
    copia.servicos.quartChild=cadast.servicos.quartChild;
    copia.servicos.tanqcheio= cadast.servicos.tanqcheio;
    copia.servicos.tipquart=cadast.servicos.tipquart;
    copia.telefone=cadast.telefone;
    copia.boletoCOMIDA=cadast.boletoCOMIDA;
    do{
    cabecalho();
    printf("\n\t\t\tALTERAR RESERVA DE HÓSPEDE");
    printf("\n\n\t\t\t          DADOS NOVOS: ");
    printf("\n\n\t\t\t\t=============================================================================================\n");
    printf("\n\n\t\t\t\t\tO que deseja alterar?");
    printf("\n\n\t\t\t\t\t1-Nome do hóspede                      2-Data de nascimento do hóspede\n\n\t\t\t\t\t3-Data de inicio e fim da reserva      4- Tipo de quarto\n\n\t\t\t\t\t5-Serviços adicionais                  6-Fechar reserva\n\n\t\t\t\t\t7-Cpf do hóspede      8-sair");
    printf("\n\n\t\t\t\t=============================================================================================\n");
    printf("\n\n\t\t\t\tOpção: ");
    scanf("%d", &op1);
    switch(op1){
    case 1 :
    cabecalho();
    printf("\n\t\t\tALTERAR RESERVA DE HÓSPEDE-Nome do hóspede");
    printf("\n\n\t\t\t\t\tDigite o novo nome do hóspede: ");
    fflush(stdin);
    gets(copia.nome);
    strupr(copia.nome);
    printf("\n\n\t\t\t\t\t");
    system("pause");
        break;
    case 2:
    cabecalho();
    printf("\n\t\t\tALTERAR RESERVA DE HÓSPEDE-Data de nascimento do hóspede");
    printf("\n\n\t\t\t\t\tDigite a nova data de nascimento do hóspede: ");
    fflush(stdin);
    scanf("%d %d %d", &copia.nascimento.dia, &copia.nascimento.mes, &copia.nascimento.ano);
    printf("\n\n\t\t\t\t\t");
    system("pause");
        break;
    case 3:
    cabecalho();
    printf("\n\t\t\tALTERAR RESERVA DE HÓSPEDE-Datas de reserva do hóspede");
    printf("\n\n\t\t\t\t\tDigite a nova data inicial da reserva do hóspede: ");
    fflush(stdin);
    scanf("%d %d %d", &copia.inicio.dia, &copia.inicio.mes, &copia.inicio.ano);
    printf("\n\n\t\t\t\t\tDigite a nova data inicial da reserva do hóspede: ");
    fflush(stdin);
    scanf("%d %d %d", &copia.fim.dia, &copia.fim.mes, &copia.fim.ano);
    printf("\n\n\t\t\t\t\t");
    system("pause");
        break;
    case 4:
    cabecalho();
    printf("\n\t\t\tALTERAR RESERVA DE HÓSPEDE-Tipo de quarto do hóspede");
    do{
        if(cadast.servicos.tipquart==1){
            opp.qpresidencial=opp.qpresidencial+1;
        }
        else if(cadast.servicos.tipquart==2){
            opp.qluxsim=opp.qluxsim+1;
        }
        else if(cadast.servicos.tipquart==3){
            opp.qlixdupl=opp.qlixdupl+1;
        }
        else if(cadast.servicos.tipquart==4){
            opp.qluxtrpl=opp.qluxtrpl+1;
        }
        else if(cadast.servicos.tipquart==5){
            opp.qexecsim=opp.qexecsim+1;
        }
        else if(cadast.servicos.tipquart==6){
            opp.qexecdupl=opp.qexecdupl+1;
        }
        else if(cadast.servicos.tipquart==7){
            opp.qexectripl=opp.qexectripl+1;
        }
        printf("\n\n\t\t\t\tDigite o tipo de quarto do hóspede:\n\n\t\t\t(1)-Quarto Presidencial(Diária= %0.2f R$)\t\t(2)-Quarto de Luxo Simples(Diária= %.2f R$)\n\n\t\t\t(3)-Quarto de Luxo Duplo(Diária= %.2f R$)\t\t(4)-Quarto de Luxo Triplo(Diária= %.2f R$)\n\n\t\t\t(5)-Quarto Executivo Simples(Diária= %.2f R$)\t\t(6)-Quarto Executivo Duplo(Diária= %.2f R$)\n\n\t\t\t(7)-Quarto Executivo Triplo(Diária= %.2f R$)\n\n\t\t\t*Opção* ", ctt.qpresidencial, ctt.qluxsim, ctt.qlixdupl, ctt.qluxtrpl, ctt.qexecsim, ctt.qexecdupl, ctt.qexectripl);
        scanf("%d",&copia.servicos.tipquart);
        cabecalho();
        printf("\n\t\t\tALTERAR RESERVA DE HÓSPEDE-Tipo de quarto do hóspede");
        if(copia.servicos.tipquart==1){
            if(opp.qpresidencial>0){
                printf("\n\n\t\t\t\tQuarto Presidencial selecionado com sucesso\n\n\t\t\t\t(Capacidade: 4 Pessoas em dois quartos diferentes)\n");
                opp.qpresidencial=opp.qpresidencial-1;
                op=1;
                system("pause");
                break;
            }
            else{
                printf("\n\n\t\tQuarto não disponível\n\t\t");
                system("pause");
                op=0;
            }
        }
        else if(copia.servicos.tipquart==2){
            if(opp.qluxsim>0){
                printf("\n\n\t\t\tQuarto de Luxo Simples selecionado com sucesso\n\n\t\t\t(Capacidade: 1 Pessoa)");
                opp.qluxsim=opp.qluxsim-1;
                printf("\n\n\n\t\t\t\tDeseja adicionar uma cama para criança?(Até nove anos) 1-Sim, 0-Não:  ");
                scanf("%d", &copia.servicos.quartChild);
                if(copia.servicos.quartChild==1){
                    printf("\n\n\t\t\tCama adicionada\n\t\t");
                    system("pause");
                }
                else{
                    printf("\n\n\t\t\tCama não adicionada\n\t\t");
                    system("pause");
                }
                op=1;
                break;
            }

            else{
                printf("\n\n\t\tQuarto não disponível\n\t\t");
                system("pause");
                op=0;
            }
        }
        else if(copia.servicos.tipquart==3){
            if(opp.qlixdupl>0){
                printf("\n\n\t\t\tQuarto de Luxo Duplo selecionado com sucesso\n\n\t\t\t(Capacidade: 2 Pessoas)");
                opp.qlixdupl=opp.qlixdupl-1;
                printf("\n\n\t\t\t\tDeseja adicionar uma cama para criança?(Até nove anos) 1-Sim, 0-Não: ");
                scanf("%d", &copia.servicos.quartChild);
                if(copia.servicos.quartChild==1){
                    printf("\n\n\t\t\tCama adicionada\n\t\t");
                    system("pause");
                }
                else{
                    printf("\n\n\t\t\tCama não adicionada\n\t\t");
                    system("pause");
                }
                op=1;
                break;
            }
            else{
                printf("\n\n\t\tQuarto não disponível\n\t\t");
                system("pause");
                op=0;
            }
        }
        else if(copia.servicos.tipquart==4){
            if(opp.qluxtrpl>0){
                printf("\n\n\t\t\tQuarto de Luxo Triplo selecionado com sucesso\n\n\t\t\t(Capacidade: 3 Pessoas)");
                opp.qluxtrpl=opp.qluxtrpl-1;
                printf("\n\n\t\t\tDeseja adicionar uma cama para criança?(Até nove anos) 1-Sim, 0-Não: ");
                scanf("%d", &copia.servicos.quartChild);
                if(copia.servicos.quartChild==1){
                    printf("\n\n\t\t\tCama adicionada\n\t\t");
                    system("pause");
                }
                else{
                    printf("\n\n\t\t\tCama não adicionada\n\t\t");
                    system("pause");
                }
                op=1;
                break;
            }
            else{
                printf("\n\n\t\tQuarto não disponível\n\t\t");
                system("pause");
                op=0;
            }
        }
        else if(copia.servicos.tipquart==5){
            if(opp.qexecsim>0){
                printf("\n\n\t\t\tQuarto Executivo Simples selecionado com sucesso\n\n\t\t\t(Capacidade: 1 Pessoa)");
                opp.qexecsim=opp.qexecsim-1;
                printf("\n\n\t\t\tDeseja adicionar uma cama para criança?(Até nove anos) 1-Sim, 0-Não: ");
                scanf("%d", &copia.servicos.quartChild);
                if(copia.servicos.quartChild==1){
                    printf("\n\n\t\t\tCama adicionada\n\t\t");
                    system("pause");
                }
                else{
                    printf("\n\n\t\t\tCama não adicionada\n\t\t");
                    system("pause");
                }
                op=1;
                break;
            }
            else{
                printf("\n\n\t\tQuarto não disponível\n\t\t");
                system("pause");
                op=0;
            }
        }
        else if(copia.servicos.tipquart==6){
            if(opp.qexecdupl>0){
                printf("\n\n\t\t\tQuarto Executivo Duplo selecionado com sucesso\n\n\t\t\t(Capacidade: 2 Pessoas)");
                opp.qexecdupl=opp.qexecdupl-1;
                printf("\n\n\t\t\tDeseja adicionar uma cama para criança?(Até nove anos) 1-Sim, 0-Não: ");
                scanf("%d", &copia.servicos.quartChild);
                if(copia.servicos.quartChild==1){
                    printf("\n\n\t\t\tCama adicionada\n\t\t");
                    system("pause");
                }
                else{
                    printf("\n\n\t\t\tCama não adicionada\n\t\t");
                    system("pause");
                }
                op=1;
                break;
            }
            else{
                printf("\n\n\t\tQuarto não disponível\n\t\t");
                system("pause");
                op=0;
            }
        }
        else if(copia.servicos.tipquart==7){
            if(opp.qexectripl>0){
                printf("\n\n\t\t\tQuarto Executivo Triplo selecionado com sucesso\n\n\t\t\t(Capacidade: 3 Pessoas)");
                opp.qexectripl=opp.qexectripl-1;
                printf("\n\n\t\t\tDeseja adicionar uma cama para criança?(Até nove anos) 1-Sim, 0-Não: ");
                scanf("%d", &cadast.servicos.quartChild);
                if(copia.servicos.quartChild==1){
                    printf("\n\n\t\t\tCama adicionada\n\t\t");
                    system("pause");
                }
                else{
                    printf("\n\n\t\t\tCama não adicionada\n\t\t");
                    system("pause");
                }
                op=1;
                break;
            }
            else{
                printf("\n\n\t\tQuarto não disponível\n\t\t");
                system("pause");
                op=0;
            }
        }
        else{
            printf("\n\nDigite uma opção válida\n\t\t");
            system("pause");
        }
        }while(op!=0);
        break;
    case 5:
        cabecalho();
        printf("\n\t\t\tALTERAR RESERVA DE HÓSPEDE-Serviços adicionais");
        op=0;
        printf("\n\n\t\t\t\tDeseja adicionar horas de babysitter?(%.2f R$ por hora): (0-não, 1-sim): ", ctt.bbshora);
        scanf("%d", &op);
        if(op==1){
           printf("\n\n\t\t\t\tDeseja adicionar QUANTAS horas de babysitter?(00,00 = 00:00):");
           scanf("%f", &copia.servicos.hourbaba);
        }
        printf("\n\n\t\t\t\tDeseja alugar algum carro?(0-não, 1-sim): ");
        scanf("%d", &op);
        cabecalho();
            printf("\n\n\t\t\tALTERAR RESERVA DE HÓSPEDE-Serviços adicionais");
            switch (op){
                case 1 :
            printf("\n\n\t\t\t1-Automóvel de luxo(Diária: %.2f R$)\n\t\t\t2-Automóvel executivo(Diária: %.2f R$ )\n\t\t\t0-Nenhum carro\n\n\t\t\tOpção: ", ctt.carrolux, ctt.carroexec);
            scanf("%d", &copia.servicos.carro);
            if(copia.servicos.carro==1){
                printf("\n\n\t\t\t\tDigite a quantidade de dias que deseja alugar o carro de luxo: ");
                scanf("%d", &day1);
            dias=quantDias(copia.inicio.dia,copia.inicio.mes, copia.inicio.ano, copia.fim.dia,copia.fim.mes,copia.fim.ano);
            while(day1>dias){
                printf("\n\n\t\t\t\tNúmero de dias de aluguel do carro não podem ser maior que o número de dias da reserva do hóspede\n\n\t\t\t");
                system("pause");
                cabecalho();
                printf("\n\n\t\t\tCADASTRO DE HÓSPEDES-Serviços adicionais");
                printf("\n\n\t\t\t\tDigite a quantidade de dias que deseja alugar o carro de luxo: ");
                scanf("%d", &day1);
            }
                copia.servicos.diascarro=day1;
                op=0;
                printf("\n\n\t\t\t\tDeseja adicionar serviço tanque cheio ao carro?(%.2f R$)(0-não, 1-sim): ", ctt.tanqcheio);
                scanf("%d", &op);
                if(op==1){
                        copia.servicos.tanqcheio=1;
                }
                op=0;
                printf("\n\n\t\t\t\tDeseja adicionar serviço de seguro ao carro?(%.2f R$)(0-não, 1-sim)", ctt.carseguro);
                scanf("%d", &op);
                if(op==1){
                    copia.servicos.carseguro=1;
                }
            }
            else if(copia.servicos.carro==2){
                printf("\n\n\t\t\t\tDigite a quantidade de dias que deseja alugar o carro de luxo: ");
                scanf("%d", &day1);
            while(day1>dias){
                printf("\n\n\t\t\t\tNúmero de dias de aluguel do carro não podem ser maior que o número de dias da reserva do hóspede\n\n\t\t\t");
                system("pause");
                cabecalho();
                printf("\n\n\t\t\tALTERAR RESERVA DE HÓSPEDES-Serviços adicionais");
                printf("\n\n\t\t\t\tDigite a quantidade de dias que deseja alugar o carro de luxo: ");
                scanf("%d", &day1);
            }
                copia.servicos.diascarro=day1;
                op=0;
                printf("\n\n\t\t\t\tDeseja adicionar serviço tanque cheio ao carro?(%.2f R$)(0-não, 1-sim)", ctt.tanqcheio);
                scanf("%d", &op);
                if(op==1){
                        copia.servicos.tanqcheio=1;
                }
                op=0;
                printf("\n\n\t\t\t\tDeseja adicionar serviço de seguro ao carro?(%.2f R$)(0-não, 1-sim)", ctt.carseguro);
                scanf("%d", &op);
                if(op==1){
                    copia.servicos.carseguro=1;
                }

            }
            default :
                    break;
        }
    printf("\n\n\t\t\t\t\t");
    system("pause");
        break;
    case 6:
    cabecalho();
    printf("\n\t\t\tALTERAR RESERVA DE HÓSPEDE-Fechar reserva do hóspede");
    printf("\n\n\t\t\t\t\tRESERVA FECHADA\n\n\t\t\t\t\t");
        boleto(cadast);
    printf("\n\n\t\t\t\t\t");
    system("pause");
        break;
    case 7:
        cabecalho();
        printf("\n\t\t\tALTERAR RESERVA DE HÓSPEDE-Alterar cpf do hóspede");
        printf("\n\n\t\t\t\t\tDigite o novo número do cpf do hóspede: ");
        scanf("%d",&copia.cpf);
        break;
    case 8:
        fseek(quantia,-(long)sizeof(TANTOs),SEEK_CUR);
        fwrite(&opp, sizeof(TANTOs),1, quantia);
        fflush(quantia);
        fseek(cadasHospedes,-(long)sizeof(Hospcadastro),SEEK_CUR);
        fwrite(&copia, sizeof(Hospcadastro),1, cadasHospedes);
        fflush(cadasHospedes);
        break;
    }
    }while(op1!=8);
        printf("\n\n\t\t\t\t\t");
        system("pause");
        fclose(quantia);
        fclose(cadasHospedes);
        return;
}
void AlterarValores(){
    FILE *valores;
    VALOR ctt;
    valores= fopen("valores.txt", "r+");
    cabecalho();
    printf("\n\t\t\tEDITAR VALORES DO HOTEL");
    printf("\n\n\t\t\tVALORES INICIAIS:");
    printf("\n\n\t\t\t\t=============================================================================================\n");
    vervalores();
    printf("\n\n\t\t\t\t=============================================================================================\n");
    printf("\n\n\t\t\t\t");
    system("pause");
    cabecalho();
    printf("\n\t\t\tEDITAR VALORES DO HOTEL");
    printf("\n\n\t\t\t\tALTERAR VALORES:");
    fflush(stdin);
    printf("\n\n\t\t\t\tDigite o valor de quarto presidencial: ");
    scanf("%f", &ctt.qpresidencial);
    printf("\n\n\t\t\t\tDigite o valor de quarto luxo simples: ");
    fflush(stdin);
    scanf("%f", &ctt.qluxsim);
    printf("\n\n\t\t\t\tDigite o valor de quarto luxo duplo: ");
    fflush(stdin);
    scanf("%f", &ctt.qlixdupl);
    printf("\n\n\t\t\t\tDigite o valor de quarto luxo triplo: ");
    fflush(stdin);
    scanf("%f", &ctt.qluxtrpl);
    printf("\n\n\t\t\t\tDigite o valor de quarto executivo simples: ");
    fflush(stdin);
    scanf("%f", &ctt.qexecsim);
    printf("\n\n\t\t\t\tDigite o valor de quarto executivo duplo: ");
    fflush(stdin);
    scanf("%f", &ctt.qexecdupl);
    printf("\n\n\t\t\t\tDigite o valor de quarto executivo triplo: ");
    fflush(stdin);
    scanf("%f", &ctt.qexectripl);
    printf("\n\n\t\t\t\tDigite o valor da hora de babysitter: ");
    fflush(stdin);
    scanf("%f", &ctt.bbshora);
    printf("\n\n\t\t\t\tDigite o valor de carro de luxo: ");
    fflush(stdin);
    scanf("%f", &ctt.carrolux);
    printf("\n\n\t\t\t\tDigite o valor de carro executivo: ");
    fflush(stdin);
    scanf("%f", &ctt.carroexec);
    ctt.tanqcheio=300;
    ctt.carseguro=250;
    fseek(valores,-(long)sizeof(VALOR),SEEK_CUR);
    fwrite(&ctt, sizeof(VALOR),1, valores);
    fflush(valores);
    printf("\n\n\t\t\t\t");
    system("pause");
    cabecalho();
    printf("\n\t\t\tEDITAR VALORES DO HOTEL");
    printf("\n\n\t\t\t\tVALORES MODIFICADOS:\n");
    printf("\n\n\t\t\t\t=============================================================================================\n");
    vervalores();
    printf("\n\n\t\t\t\t=============================================================================================\n");
    printf("\n\n\t\t\t\t");
    system("pause");
    fclose(valores);
}
void checkouts(int op){
    FILE *cadasHospedes;
    int num=0;
    cadasHospedes=fopen("cadastroHospedes.txt", "r+");
    FILE *valores;
    valores=fopen("valores.txt","rb");
    FILE* quantia;
    quantia=("quantidades.txt","r+");
    TANTOs opp;
    Hospcadastro cadast;
    VALOR ctt;
    Hospcadastro copia;
    int check, cpf, registro;
if(op==3){
        cabecalho();
    printf("\n\t\t\tLISTA DE RESERVAS FECHADA");
while(fread(&cadast, sizeof(Hospcadastro),1, cadasHospedes)){
        if(checkreserv(cadast.fim.dia,cadast.fim.mes,cadast.fim.ano)==1){
    printf("\n\n\t\t\t\t=============================================================================================\n");
    printf("\n\n\t\t\t\tNúmero de registro: %d", num);
    num=num+1;
    printf("\n\n\t\t\t\t\tNome do hóspede: %s\n\t\t\t\t\tCPF do hóspede: %d\n\t\t\t\t\tNúmero de telefone: %d\n\t\t\t\t\tData de Nascimento do hóspede: %d/%d/%d", cadast.nome, cadast.cpf, cadast.telefone, cadast.nascimento.dia, cadast.nascimento.mes, cadast.nascimento.ano);
    printf("\n\t\t\t\t\tInicio da reserva do hóspede:%d/%d/%d-----Fim da reserva: %d/%d/%d", cadast.inicio.dia, cadast.inicio.mes, cadast.inicio.ano, cadast.fim.dia, cadast.fim.mes, cadast.fim.ano);
    if(cadast.servicos.tipquart==1){
    printf("\n\t\t\t\t\tTipo de quarto:Presidencial");

    }
    else if(cadast.servicos.tipquart==2){
    printf("\n\t\t\t\t\tTipo de quarto:Luxo Simples");
    }
    else if(cadast.servicos.tipquart==3){
    printf("\n\t\t\t\t\tTipo de quarto:Luxo Duplo");
    }
    else if(cadast.servicos.tipquart==4){
    printf("\n\t\t\t\t\tTipo de quarto:Luxo Triplo");
    }
    else if(cadast.servicos.tipquart==5){
    printf("\n\t\t\t\t\tTipo de quarto:Executivo Simples");
    }
    else if(cadast.servicos.tipquart==6){
    printf("\n\t\t\t\t\tTipo de quarto:Executivo Duplo");
    }
    else if(cadast.servicos.tipquart==7){
    printf("\n\t\t\t\t\tTipo de quarto:Executivo Triplo");
    }
    printf("-----Possui cama de criança?:");
    if(cadast.servicos.quartChild==1){
        printf("Sim");
    }
    else{
        printf("Não");
    }
    printf("\n\t\t\t\t\tHóspede possui aluguel de carro?");
    if(cadast.servicos.carro==1){
        printf("Sim-----Tipo:Luxo");
        if(cadast.servicos.tanqcheio==1){
            printf("\n\t\t\t\t\tCarro com tanque cheio adquirido");
        }
       if(cadast.servicos.carseguro==1){
            printf("\n\t\t\t\t\tCarro com seguro adquirido");
        }
    }
    else if(cadast.servicos.carro==2){
        printf("Sim-----Tipo:Executivo");
        if(cadast.servicos.tanqcheio==1){
            printf("\n\t\t\t\t\tCarro com tanque cheio adquirido");
        }
       if(cadast.servicos.carseguro==1){
            printf("\n\t\t\t\t\tCarro com seguro adquirido");
        }
    }
    else{
        printf("Não");
    }
    printf("\n\t\t\t\t\tBabysitter: ");
    if(cadast.servicos.hourbaba==0){
        printf("0 horas");
    }
    else{
        printf("%.2f horas (00,00 = 00:00)", cadast.servicos.hourbaba);
    }
    printf("\n\n\t\t\t\t=============================================================================================\n");
        }
}
printf("\n\n\t\t\t\t");
system("pause");
printf("\n\n\t\t\t\tDigite o número do registro do hóspede para ver o boleto: ");
    scanf("%1d", &registro);
    if(fseek(cadasHospedes,(registro-1)*sizeof(Hospcadastro),SEEK_SET)!=0){
        printf("\n\n\t\t\t\tProblemas com o posicionamento da reserva");
        return;
    }
    if(fread(&cadast,sizeof(Hospcadastro),1, cadasHospedes)!=1){
        printf("\n\n\t\t\t\tProblemas com a leitura da reserva");
        return;
    }
    boleto(cadast);
    system("pause");
}
rewind(cadasHospedes);
if(op==2){
    cabecalho();
    printf("\n\t\t\tPESQUISAR RESERVA FECHADA");
     printf("\n\n\t\t\t\t\tDigite o cpf do hóspede que deseja ver a reserva");
    scanf("%d", &cpf);
    while(fread(&cadast, sizeof(Hospcadastro),1, cadasHospedes)){
    if((checkreserv(cadast.fim.dia,cadast.fim.mes,cadast.fim.ano)==1) && (cadast.cpf== cpf)){
            boleto(cadast);
}
}
}
}
void foodInicial(){
    FILE *food;
    food=fopen("foodmenu.txt", "wb");
    struct Menucomida alimentus={"Tapioca com chocolate\0", "Goma de mandioca com recheio de chocolate\0", 4.20};
   fseek(food, 0L,SEEK_END);
   fwrite(&alimentus,sizeof(struct Menucomida),1,food);
   struct Menucomida alimentus1={"Arroz de Cuxá\0","Arroz com um molho feito com vinagreira, gengibre, camarão, pimenta de cheiro, gengibre e farinha\0", 22.50};
    fseek(food, 0L,SEEK_END);
   fwrite(&alimentus1,sizeof(struct Menucomida),1,food);
    struct Menucomida alimentus2={"Arroz Doce\0", "Arroz, leite, leite condensado e açúcar\0", 20.30};
    fseek(food, 0L,SEEK_END);
   fwrite(&alimentus2,sizeof(struct Menucomida),1,food);
    struct Menucomida alimentus3={"Acarajé\0", "Feita de massa de feijão-fradinho, cebola e sal, frita em azeite-de-dendê\0", 28.90};
    fseek(food, 0L,SEEK_END);
   fwrite(&alimentus3,sizeof(struct Menucomida),1,food);
    struct Menucomida alimentus4={"Baião de Dois\0", "Feito com leite de coco, arroz, feijão, carne de porco\0", 30};
    fseek(food, 0L,SEEK_END);
   fwrite(&alimentus4,sizeof(struct Menucomida),1,food);
    struct Menucomida alimentus5={"Canjica com leite condensado\0","Milho para canjica, leite, leite condensado, creme de leite, amendoim tostado sem pele e canela em pau\0", 12.48};
    fseek(food, 0L,SEEK_END);
   fwrite(&alimentus5,sizeof(struct Menucomida),1,food);
    struct Menucomida alimentus6={" Escondidinho de carne seca\0", "Purê feito com mandioca e o recheio de carne seca\0", 27.30};
   fseek(food, 0L,SEEK_END);
   fwrite(&alimentus6,sizeof(struct Menucomida),1,food);
    struct Menucomida alimentus7={"Bolo de rolo\0", "Manteiga, açúcar, ovos,farinha de trigo,goiabada, água e vinho\0", 17.30};
   fseek(food, 0L,SEEK_END);
   fwrite(&alimentus7,sizeof(struct Menucomida),1,food);
    fclose(food);
}
void EditarMenu(){
    cabecalho();
    printf("\n\t\t\tRESTAURANTRE DELÍCIAS DA SERRA-Pedido");
    cabecalho();
    int op=0, num=1;
    struct Menucomida alimentus;
    FILE *food;
    food=fopen("foodmenu.txt", "r+");
    printf("\n\t\t\tALTERAR MENU RESTAURANTE DELICÍAS DA SERRA");
   do{
    printf("\n\n\t\t\t\t\t1-Adicionar alimento ao menu\n\n\t\t\t\t\t2-Sair\n\n\t\t\t\t\tOpção:");
    scanf("%d",&op);
    switch(op){
    case 1:
        cabecalho();
        printf("\n\t\t\tALTERAR MENU RESTAURANTE DELICÍAS DA SERRA-Adicionar alimento");
        printf("\n\n\t\t\t\t\tDigite o nome do alimento: ");
        fflush(stdin);
        gets(alimentus.nomePrato);
        printf("\n\n\t\t\t\t\tDigite os ingredientes/descrição do alimento: ");
        fflush(stdin);
        gets(alimentus.ingredient);
        printf("\n\n\t\t\t\t\tDigite o preço do alimento: ");
        fflush(stdin);
        scanf("%f", &alimentus.preco);
        printf("\n\n\t\t\t\t");
        system("pause");
        fseek(food,0L,SEEK_END);
        fwrite(&alimentus, sizeof(struct Menucomida),1,food);
        break;
    case 2 :
        break;
    default:
        break;
    }
   }while(op!=2);
   fclose(food);
}

void comidaHosp(){
    int cpf, num=1;
    float precototal=0;
    char c;
    FILE *food;
        struct Menucomida alimentus;
    food=fopen("foodmenu.txt", "r+");
    FILE *cadasHospedes;
    Hospcadastro cadast;
    Hospcadastro copia;
    cadasHospedes=fopen("cadastroHospedes.txt", "r+");
    cabecalho();
    printf("\n\t\t\tRESTAURANTRE DELÍCIAS DA SERRA");
    printf("\n\n\t\t\t\t\tDigite o cpf do hóspede que deseja fazer um pedido");
    scanf("%d", &cpf);
     while(fread(&cadast, sizeof(Hospcadastro),1, cadasHospedes)){
    if(cadast.status!='*' && cadast.cpf== cpf){
    printf("\n\n\t\t\t\t=============================================================================================\n");
    printf("\n\n\t\t\t\t\tNome do hóspede: %s\n\t\t\t\t\tCPF do hóspede: %d\n\t\t\t\t\tNúmero de telefone: %d\n\t\t\t\t\tData de Nascimento do hóspede: %d/%d/%d", cadast.nome, cadast.cpf, cadast.telefone, cadast.nascimento.dia, cadast.nascimento.mes, cadast.nascimento.ano);
    printf("\n\n\t\t\t\t\tInicio da reserva do hóspede:%d/%d/%d-----Fim da reserva: %d/%d/%d", cadast.inicio.dia, cadast.inicio.mes, cadast.inicio.ano, cadast.fim.dia, cadast.fim.mes, cadast.fim.ano);
    if(cadast.servicos.tipquart==1){
    printf("\n\n\t\t\t\t\tTipo de quarto:Presidencial");
    }
    else if(cadast.servicos.tipquart==2){
    printf("\n\n\t\t\t\t\tTipo de quarto:Luxo Simples");
    }
    else if(cadast.servicos.tipquart==3){
    printf("\n\n\t\t\t\t\tTipo de quarto:Luxo Duplo");
    }
    else if(cadast.servicos.tipquart==4){
    printf("\n\n\t\t\t\t\tTipo de quarto:Luxo Triplo");
    }
    else if(cadast.servicos.tipquart==5){
    printf("\n\n\t\t\t\t\tTipo de quarto:Executivo Simples");
    }
    else if(cadast.servicos.tipquart==6){
    printf("\n\n\t\t\t\t\tTipo de quarto:Executivo Duplo");
    }
    else if(cadast.servicos.tipquart==7){
    printf("\n\n\t\t\t\t\tTipo de quarto:Executivo Triplo");
    }
    printf("-----Possui cama de criança?:");
    if(cadast.servicos.quartChild==1){
        printf("Sim");
    }
    else{
        printf("Não");
    }
    printf("\n\n\t\t\t\t\tHóspede possui aluguel de carro?");
    if(cadast.servicos.carro==1){
        printf("Sim-----Tipo:Luxo");
        if(cadast.servicos.tanqcheio==1){
            printf("\n\n\t\t\t\t\tCarro com tanque cheio adquirido");
        }
       if(cadast.servicos.carseguro==1){
            printf("\n\n\t\t\t\t\tCarro com seguro adquirido");
        }
    }
    else if(cadast.servicos.carro==2){
        printf("Sim-----Tipo:Executivo");
        if(cadast.servicos.tanqcheio==1){
            printf("\n\n\t\t\t\t\tCarro com tanque cheio adquirido");
        }
       if(cadast.servicos.carseguro==1){
            printf("\n\n\t\t\t\t\tCarro com seguro adquirido");
        }
    }
    else{
        printf("Não");
    }
    printf("\n\n\t\t\t\t\tBabysitter: ");
    if(cadast.servicos.hourbaba==0){
        printf("0 horas");
    }
    else{
        printf("%.2f horas (00,00 = 00:00)", cadast.servicos.hourbaba);
    }
    printf("\n\n\t\t\t\t=============================================================================================\n");
    }
     }
    printf("\n\n\t\t\t\t");
    system("pause");
    cabecalho();
    printf("\n\t\t\tRESTAURANTRE DELÍCIAS DA SERRA");
    printf("\n\n\t\t\t\tMENU DE PRATOS-selecione o número do alimento");
    while(fread(&alimentus, sizeof(struct Menucomida),1,food)==1){
        printf("\n\n\t\t\t\t=============================================================================================\n");
        printf("\n\n\t\t\t\tNúmero do alimento: %d", num);
        num=num+1;
        printf("\n\t\t\t\t\tNome do Prato: %s", alimentus.nomePrato);
        printf("\n\t\t\t\t\tIngredientes/descrição do Prato: %s", alimentus.ingredient);
        printf("\n\t\t\t\t\tValor do prato: %.2f", alimentus.preco);
        printf("\n\n\t\t\t\t=============================================================================================\n");
    }
        printf("\n\n\t\t\t\t");
        system("pause");
        printf("\n\t\t\t\t\tDigite o número do alimento do menu: ");
        scanf("%1d", &num);
        fflush(stdin);
        if(fseek(food,(num-1)*sizeof(struct Menucomida),SEEK_SET)!=0){
        printf("\n\n\t\t\t\tProblemas com o posicionamento dos pratos");
        return;
    }
    if(fread(&alimentus,sizeof(struct Menucomida),1, food)!=1){
        printf("\n\n\t\t\t\tProblemas com a leitura do menu");
        return;
    }
    copia.cpf=cadast.cpf;
    copia.fim.dia= cadast.fim.dia;
    copia.fim.mes= cadast.fim.mes;
    copia.fim.ano= cadast.fim.ano;
    copia.inicio.ano= cadast.inicio.ano;
    copia.inicio.dia= cadast.inicio.dia;
    copia.inicio.mes= cadast.inicio.mes;
    copia.nascimento.dia=cadast.nascimento.dia;
    copia.nascimento.mes=cadast.nascimento.mes;
    copia.nascimento.ano=cadast.nascimento.ano;
    strcpy(copia.nome,cadast.nome);
    copia.servicos.carro=cadast.servicos.carro;
    copia.servicos.carseguro=cadast.servicos.carseguro;
    copia.servicos.diascarro=cadast.servicos.diascarro;
    copia.servicos.hourbaba=cadast.servicos.hourbaba;
    copia.servicos.quartChild=cadast.servicos.quartChild;
    copia.servicos.tanqcheio= cadast.servicos.tanqcheio;
    copia.servicos.tipquart=cadast.servicos.tipquart;
    copia.telefone=cadast.telefone;
    cadast.boletoCOMIDA=cadast.boletoCOMIDA+alimentus.preco;
    copia.boletoCOMIDA=cadast.boletoCOMIDA;
    printf("%.2f",copia.boletoCOMIDA);
        cabecalho();
        printf("\n\t\t\tRESTAURANTRE DELÍCIAS DA SERRA");
        printf("\n\n\t\t\t\t=============================================================================================\n");
        printf("\n\t\t\t\t\tPrato %s com valor de %.2f foi adicionado com sucesso ao boleto de %s", alimentus.nomePrato, alimentus.preco, cadast.nome);
        printf("\n\n\t\t\t\t=============================================================================================\n");
         fseek(cadasHospedes,-(long)sizeof(Hospcadastro),SEEK_CUR);
         fwrite(&copia, sizeof(Hospcadastro),1, cadasHospedes);
         fflush(cadasHospedes);
         fclose(food);
}




int main(){
    setlocale(LC_ALL, "portuguese");
    int op, j, cpf,op1;
    FILE *valores;
    FILE *cadasHospedes;
    FILE *quantia;
    FILE *food;
    system("color B0");
    inicializacao();
    system("cls");
    valores=fopen("valores.txt", "rb");
    quantia= fopen("quantidades.txt", "rb");
    cadasHospedes= fopen("cadastroHospedes.txt", "rb");
    food=fopen("foodmenu.txt", "rb");
    if(valores==NULL || quantia==NULL|| cadasHospedes==NULL){
    valores=fopen("valores.txt", "wb");
    valoresiniciais();
    quantia= fopen("quantidades.txt", "wb");
    quantidades();
    cadasHospedes= fopen("cadastroHospedes.txt", "wb");
    food=fopen("foodmenu.txt", "wb");
    foodInicial();
    fclose(food);
    fclose(valores);
    fclose(quantia);
    fclose(cadasHospedes);
    }
    do{
        menu();
        scanf("%d", &op);
    switch(op){
    case 1:
        inputHosp();
        printf("\n\n");
        system("pause");
        break;
    case 2 :
        cabecalho();
        printf("\n\t\t\tPESQUISA DE HÓSPEDES");
        printf("\n\n\t\t\t\t=============================================================================================\n");
        printf("\n\n\t\t\t\t\tDigite o cpf do hóspede que deseja ver a reserva");
        scanf("%d", &cpf);
        pesquisacpf(cpf);
        printf("\n\n");
        system("pause");
        break;
    case 3 :
        cabecalho();
        printf("\n\t\t\tLISTA DE HÓSPEDES");
        listar();
        break;
    case 4 :
        AlterarCadast();
        system("pause");
        break;
    case 5 :
        cabecalho();
        printf("\n\n\t\t\t\t\t1-Ver CheckOuts de hoje\n\n\t\t\t\t\t2-Procurar CheckOut por cpf\n\n\t\t\t\t\t3-Listar ChekOuts\n\n\t\t\t\t\tOpção: ");
        scanf("%d", &op1);
        if(op1==1){
        cabecalho();
        printf("\n\t\t\tCHECKOUTS DE HOJE");
        checarOutstoday();
        }
        else{
            checkouts(op1);
        }
        system("pause");
        break;
    case 6:
        AlterarValores();
        break;
    case 7:
        cabecalho();
        printf("\n\t\t\tDISPONIBILIDADE DO HOTEL");
        TANTOs eae;
        FILE *quantia;
        quantia=fopen("quantidades.txt", "rb");
        fread(&eae,sizeof(TANTOs), 1, quantia);
        printf("\n\n\t\t\t\t=============================================================================================\n");
        if(eae.qpresidencial>5){
            eae.qpresidencial=5;
        }
        else if(eae.qluxsim>5){
            eae.qluxsim=5;
        }
        else if(eae.qlixdupl>15){
            eae.qlixdupl=15;
        }
        else if(eae.qluxtrpl>20){
            eae.qluxtrpl=20;
        }
        else if(eae.qexecsim>5){
            eae.qexecsim=5;
        }
        else if(eae.qexecdupl>15){
            eae.qexecdupl=15;
        }
        else if(eae.qexectripl>20){
            eae.qexectripl=20;
        }
        printf("\n\n\t\t\t\t\tQuantidade quarto presidencial:%d\n", eae.qpresidencial);
        printf("\n\n\t\t\t\t\tQuantidade quarto LUXO SIMPLES:%d\n", eae.qluxsim);
        printf("\n\n\t\t\t\t\tQuantidade quarto LUXO DUPLO:%d\n", eae.qlixdupl);
        printf("\n\n\t\t\t\t\tQuantidade quarto LUXO TRIPLO:%d\n", eae.qluxtrpl);
        printf("\n\n\t\t\t\t\tQuantidade quarto EXECUTIVO SIMPLES:%d\n", eae.qexecsim);
        printf("\n\n\t\t\t\t\tQuantidade quarto EXECUTIVO DUPLO:%d\n", eae.qexecdupl);
        printf("\n\n\t\t\t\t\tQuantidade quarto EXECUTIVO TRIPLO:%d\n", eae.qexectripl);
        printf("\n\n\t\t\t\t=============================================================================================\n");
        fclose(quantia);
        printf("\n\n\t\t\t\t");
        system("pause");
            break;
    case 8:
        cabecalho();
        printf("\n\t\t\tRESTAURANTRE DELÍCIAS DA SERRA");
        printf("\n\n\t\t\t\t=============================================================================================\n");
        printf("\n\n\t\t\t\t\t1-Editar o menu do restaurante");
        printf("\n\n\t\t\t\t\t2-Fazer um pedido para hóspede");
        printf("\n\n\t\t\t\t=============================================================================================\n");
        printf("\n\n\t\t\t\t\tOpção: ");
        scanf("%d",&op1);
        if(op1==1){
            EditarMenu();
        }
        else if(op1==2){
                comidaHosp();
        }
        printf("\n\n\t\t\t\t");
        system("pause");
        break;
    case 9 :
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tFINALIZANDO O PROGRAMA");
          for(j=0;j<3;j++){
                Sleep(600);
                printf(".");
                Sleep(600);
            }
            putchar('\n');
            break;
    default :
        cabecalho();
        printf("\n\n\n\n\t\t\t\t\tInsira uma opção válida.");
        break;
    }

    }while(op!=9);
}
