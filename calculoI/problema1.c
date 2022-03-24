#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846

double encontraCusto(double r, double h, double x, double y) 
{
    double valorBase, valorLateral;

    valorBase = x*((2*M_PI*pow(r,2))/10000);
    valorLateral = y*((2*M_PI*r*h)/10000);

    return valorBase + valorLateral;

}

double encontraArea(double r, double h)
{
    double area;

    area = 2*M_PI*pow(r,2) + 2*M_PI*r*h;

    return area;
}

double encontraAltura(double r, double v)
{
    double altura;

    altura = v/(M_PI*pow(r,2));

    return altura;
}

double verificaPontoMinino(double raio, double x, double y, double v)
{
    double resultado;

    resultado = x*4*M_PI + (4*y*v)/pow(raio, 3);

    return resultado;

}

double calculaPontosCriticos(double x, double y, double v)
{

    double raio, valor, resultado;

    raio = pow((y*v)/(2*x*M_PI), 0.33333333333333);

    resultado = verificaPontoMinino(raio,x,y,v);

    if(resultado>0)
    {
        return raio;
    }
    else
    {
        printf("A funcao nao possui ponto minimo\n");
        return 0;
    }

}


int main()
{

    double x,y,v, raio, altura, areaTotal, custoTotal;

    while(1)
    {
        printf("Digite o valor do volume desejado(cm3):\n-->");
        scanf("%lf", &v);

        printf("Digite o preco do material da base:\n-->R$");
        scanf("%lf", &x);

        printf("Digite o preco do material da lateral:\n-->R$");
        scanf("%lf", &y);

        raio = calculaPontosCriticos(x,y,v);

        if (raio != 0)
        {
            altura = encontraAltura(raio, v);
            areaTotal = encontraArea(raio, altura);
            custoTotal = encontraCusto(raio, altura, x, y);

            printf("\nValor do raio que minimiza o preco de fabricacao: %.2lf cm3\n", raio);
            printf("Valor da altura: %.2lf cm\n", altura);
            printf("Valor da area total: %.2lf cm2\n", areaTotal);
            printf("Valor do custo total: R$ %.2lf\n", custoTotal);

        }

        int opc;

        printf("\nSe deseja calcular mais uma vez digite 1, para sair digite um numero qualquer.\n-->");
        scanf("%d", &opc);
        printf("\n");

        if(opc!= 1)
        {
            break;
        }
       
    }

    

}