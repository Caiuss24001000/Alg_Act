#include <stdio.h>
#include <stdlib.h>

//#include <math.h>
//#define LOG2 log2(x) = log10(x) / log10(2)

double log_2(int, double);
double p(double, int);

int main(){
    
    FILE *pf = fopen("./grafica.dat", "w+");
    if(pf == NULL)
        printf("Documento no encontrado\n");
    else
        printf("Documento encontrado\n");

    for (int i = 0; i < 500000; i+=100)
    {
        double a = 4*i+2+5*i*log_2(2,(double)i)+5*log_2(2,(double)i) ;
        fprintf(pf, "%d, %f \n", i, a);
        //printf("%d %f\n", i, a);
    }
    
    fclose(pf);
    return 0;
}

double log_2(int b,double n) {
    double val = 0;
    int i,accurate = 10,reps=0;
    while(n != 1 && accurate>=0) {
        for(i=0;n>=b;i++) n /= b;
            n = p(n,10);
            val = 10*(val+i);
            accurate--; reps++;
    }
    return (double)val/p(10,reps);
}

double p(double x,int i) {
    double r = 1.0;
    for(i;i>0;i--) r *= x;
    return r;
}

