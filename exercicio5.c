#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{

//VARIAVEIS
    //quantidade de funcionarios
    int qtd_funcionarios, qtd_f, qtd_m;

    //informações dos funcionarios
    int prontuario, qtd_pecas;
    char sexo;
    float salario;

    //informações da empresa
    int qtd_pecas_f, qtd_pecas_m, qtd_pecas_total, seu_prontuario;
    float maior_salario, salario_total, media_f, media_m;

    //controle
    float salario_minimo = 1412.00;
    int i;
    int valido;

    salario_total = 0;
    qtd_pecas_total = 0;
    qtd_f = 0;
    qtd_m = 0;
    qtd_pecas_f = 0;
    qtd_pecas_m = 0;

    printf("Quantidade de Funcionarios: ");
    scanf("%d", &qtd_funcionarios);
    printf("--------------------------------\n\n");

    for (i = 1; i <= qtd_funcionarios; i++)
    {
        salario = 0;
        qtd_pecas = 0;

        //definindo valores
        printf("Funcionario - %d\n\n",i);

        printf("Prontuario: ");
        scanf("%d", &prontuario);
        fflush(stdin);

        printf("Sexo (F/M): ");
        scanf(" %c", &sexo);
        //um espaço branco antes do %c é a mesma coisa que o fflush
        sexo = toupper(sexo);

        //no C while é bugado && é || e vice versa
        while(sexo != 'M' && sexo != 'F')
        {
            printf("Insira F ou M\n");
            printf("Sexo: ");
            scanf(" %c", &sexo);
            fflush(stdin);
        }
        sexo = toupper(sexo);

        printf("Quantidade de pecas produzidas: ");
        scanf("%d", &qtd_pecas);
        fflush(stdin);

    //OPERAÇÕES

        //salario
        if(qtd_pecas <= 30)
        {
            salario = salario_minimo;
        }
        else if (qtd_pecas <= 35)
        {
            salario = salario_minimo+(salario_minimo*(0.03*(qtd_pecas-30)));
        }
        else
        {
            salario = salario_minimo+(salario_minimo*(0.05*(qtd_pecas-30)));
        }

        //maior salario
        if(salario > maior_salario)
        {
            maior_salario = salario;
            seu_prontuario = prontuario;
        }

        //o total da folha de pagamento da fabrica
        salario_total += salario;

        //peças produzidas
        //total
        qtd_pecas_total += qtd_pecas;

        //por homem/mulheres
        if(sexo == 'F')
        {
            qtd_f++;
            qtd_pecas_f += qtd_pecas;
        }
        else if (sexo == 'M')
        {
            qtd_m++;
            qtd_pecas_m += qtd_pecas;
        }

    //EXIBIR
        printf("\n--------------------------------\n");
        printf("Prontuario: %d\n", prontuario);
        printf("Salario: R$%.2f\n", salario);
        printf("--------------------------------\n\n");

    }

    system("pause");
    system("cls");

    printf("---------- RELATÓRIO ----------\n\n");
    printf("Folha de pagamento da empresa: R$%.2f\n", salario_total);
    printf("Quantidade de peças produzidas: %d\n", qtd_pecas_total);

    if(qtd_f != 0)
    {
        media_f = (qtd_pecas_f/qtd_f);
        printf("\nProducao media dos mulheres: %.2f\n",media_f);
    }

    if(qtd_m != 0)
    {
        media_m = (qtd_pecas_m/qtd_m);
        printf("Producao media dos homens: %.2f\n",media_m);
    }

    printf("\nMaior salario: R$%.2f\n",maior_salario);
    printf("Seu prontuario: %d\n", seu_prontuario);

    return 0;
}
