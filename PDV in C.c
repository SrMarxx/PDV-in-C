#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int quant;
float valTotal, valCompra, valItem;

void compra() {

    valCompra = 0;
    char exit2 = 's';

    system("cls");
    while (exit2 == 's') {

        printf("\n\nInforme o valor do produto.: ");
        scanf("%f", &valItem);

        valCompra = valCompra + valItem;

        fflush(stdin);

        printf("\nValor total.: %.2f", valCompra);
        printf("\n\nDeseja acrescentar mais? (digite s ou n).: ");
        exit2 = getche();

        while (exit2 != 's' && exit2 != 'n' && exit2 != 'S' && exit2 != 'N') {

            printf("\n\nValor inválido, por favor digite novamente.: ");
            exit2 = getche();

        }

    }

}

void dinheiro(float valor) {

    char exit3;
    float valorT, valorP, taxa;
    quant++;

    taxa = 0.05;

    valorT = valor - valor*taxa;

    valorP = valorT / 2;

    printf("\n\nDesconto de %.2f\n", valor*taxa);
    printf("\nO valor total a pagar é.: %.2f", valorT);
    printf("\n\nDeseja parcelar?(digite s ou n).: ");
    exit3 = getche();

    while (exit3 != 's' && exit3 != 'n' && exit3 != 'S' && exit3 != 'N') {

        printf("\n\nValor inválido, por favor digite novamente.: ");
        exit3 = getche();

    }
    if (exit3 == 's' || exit3 == 'S') {

        printf("\n\nO valor da parcela a pagar é.: %.2f\n\n", valorP);
    }

    valTotal = valTotal + valorT;

    printf("\n");
    system("pause");
    system("cls");
    printf("\nObrigado e volte sempre!\n");

}

void cartao(float valor) {

    int nP;
    float valorT, valorP, taxa;
    char parcela;

    taxa = 0.05;
    quant++;

    valorT = valor + valor*taxa;

    printf("\nAcrescimo de %.2f no valor", valor*taxa);
    printf("\n\nO valor total a pagar é.: %.2f", valorT);

    printf("\n\nDeseja parcelar?(digite s ou n).: ");
    parcela = getche();

    while (parcela != 's' && parcela != 'S' && parcela != 'n' && parcela != 'N') {

        printf("\nOpção inválida, por favor digite novamente.: ");
        parcela = getche();
    }


    if (parcela == 's' || parcela == 'S') {

        printf("\nNúmero de parcelas (até 12 vezes).: ");
        scanf("%d", &nP);

        while (nP < 0 || nP > 12) {

            printf("\nOpção inválida, por favor digite novamente.: ");
            scanf("%d", &nP);
        }

        valorP = valor / nP;

        printf("\nValor das parelas.: %.2f", valorP);


    }

    valTotal = valTotal + valor;

    printf("\n\n");
    system("pause");
    system("cls");
    printf("\nObrigado e volte sempre!\n");

}

void consulta() {
    system ("cls");
    float ticket;

    ticket = valTotal/quant;

    printf("\nVendas hoje.: %d \nTotal arrecadado.: %.2f \nTicket médio.: %.2f\n\n", quant, valTotal, ticket);
    system("pause");
    system("cls");

}

int main() {

    setlocale(LC_ALL, "portuguese");

    int exit, exit1;
    char  menu, menu1;

    exit = 0;
    printf("Bem vindo ao programa de vendas!");

    while (exit == 0) {

        printf("\n\nSelecione uma opção: \n1. Compra. \n2. Consulta \n0. Sair. \nDigite.: ");
        menu = getche();

        while (menu != '0' && menu != '1' && menu != '2') {

            printf("\n\nValor inválido, por favor digite novamente.: ");
            menu = getche();
        }

        switch(menu) {

        case '1':
            exit1 = 0;
            while (exit1 == 0) {

                compra();

                printf("\n\nSelecione uma opção de pagamento: \n1. Dinheiro. \n2. Cartão. \n0. Cancelar. \nDigite.: ");
                menu1 = getche();

                while (menu1 != '0' && menu1 != '1' && menu1 != '2') {

                    printf("\n\nValor inválido, por favor digite novamente.: ");
                    menu1 = getche();
                }

                switch (menu1) {

                case '1':

                    dinheiro(valCompra);
                    exit1 = 1;

                    break;

                case '2':

                    cartao(valCompra);
                    exit1 = 1;

                    break;

                case '0':

                    exit1 = 1;

                    break;

                }
            }

            break;

        case '2':

            consulta();

            break;

        case '0':

            exit = 1;

            break;


        }
]
    system("pause");

}
