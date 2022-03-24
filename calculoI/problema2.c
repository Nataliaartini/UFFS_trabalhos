#include <stdio.h>
#include <math.h>


double calculaDistanciaTotal(double distancia)
{
    double total;

    total = pow(pow(distancia,2)-200*distancia+11600,0.5) + distancia;

    return total;
}

double verificaMenorTempo(double distancia1, double distancia2, double x, double y)
{

    double tempo1, tempo2;

    tempo1 = (pow(pow(distancia1,2)-200*distancia1+11600,0.5))/x + distancia1/y;
    tempo2 = (pow(pow(distancia2,2)-200*distancia2+11600,0.5))/x + distancia2/y;

    if(tempo1<tempo2)
    {
        return distancia1;
    }
    else
    {
        return distancia2;
    }


}

double calculaPontosCriticos(double x, double y)
{

    double distancia1, distancia2, a,b,c, delta; 

    a = pow(y,2)-pow(x,2);
    b = -200*pow(y,2) + 200*pow(x,2);
    c = 10000*pow(y,2)-11600*pow(x,2);

    delta = b*b - 4*a*c;

    distancia1 = (-b + pow(delta, 0.5))/(2*a);
    distancia2 = (-b - pow(delta, 0.5))/(2*a);

    return verificaMenorTempo(distancia1,distancia2,x,y);

}


int main()
{

    double x,y, distancia, distanciaTotal;

    while(1)
    {

        printf("Digite a velocidade da barca (km/h):\n-->");
        scanf("%lf", &x);

        printf("Digite a velocidade dos carros (km/h):\n-->");
        scanf("%lf", &y);

        if(x>y)
        {
            printf("A velocidade dos carros deve ser maior do que a da barca! Tente novamente!\n\n");
            continue;
        }

        distancia = calculaPontosCriticos(x,y);
        distanciaTotal = calculaDistanciaTotal(distancia);

        printf("A distancia entre a estacao e a cidade e: %.2lf km\n", distancia);
        printf("A distancia total e: %.2lf km\n", distanciaTotal);

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