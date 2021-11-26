#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nome[50];
    int numero_usuario, numero_aleatorio, contador, valor;

    system("cls");

    printf("\n*******************************************\n");
    printf("*   Bem vindo/a ao jogo de adivinhacao!   *\n");
    printf("*******************************************\n");

    printf("\nInsira seu nome: ");
    gets(nome);

    //Confere à variável numero_aleatorio um valor qualquer entre 0 e 10.
    srand(time(NULL));
    numero_aleatorio = rand() % 11;

    printf("\nInsira um numero entre 0 e 10: ");
    scanf("%i", &numero_usuario);

    /*Loops aninhados para verificar se o valor inserido está no intervalo de [0,10]. 
    Caso contrário, o programa insistirá até que o usuário coloque um número válido.*/
    if (numero_usuario > 10 || numero_usuario < 0)
    {
        do
        {
            printf("\nNumero invalido!");
            printf("\nInsira um numero entre 0 e 10: ");
            scanf("%i", &numero_usuario);
        } while (numero_usuario > 10 || numero_usuario < 0);
    }

    printf("\nProcessando...\n");


    /*Loops aninhados para verificar se o valor inserido pelo usuário e o valor chutado pela máquina
    correspondem. Se sim, o loop será encerrado. Se não, será dada a opção de tentar novamente ao usuário.*/
    for (contador = 0; ; contador++)
    {
        if (numero_usuario == numero_aleatorio)
        {
            printf("\nParabens %s, voce acertou!\n", nome);
            break;
        }
        else
        {
            printf("\nVoce errou... Deseja tentar novamente?\nSim(1)             |            Nao(0)\n");
            scanf("%d", &valor);

            if (valor == 1)
            {
                printf("\nInsira um numero entre 0 e 10: ");
                scanf("%i", &numero_usuario);

                if (numero_usuario > 100 || numero_usuario < 0)
                {
                    do
                    {
                        printf("\nNumero invalido!");
                        printf("\nInsira um numero entre 0 e 10: ");
                        scanf("%i", &numero_usuario);
                        printf("\n");
                    } while (numero_usuario > 10 || numero_usuario < 0);
                }
            }
            else
            {
                printf("\nQue pena %s, o numero escolhido era %d.\n\n", nome, numero_aleatorio);
                break;
            }
        }
    }

    printf("\n");
    
    system("pause");
    return 0;
}
