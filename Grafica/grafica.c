#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAM_MAX 500000

double log_2(int, double);      //Logaritmo de una base dada
double p(double, int);          //Potencia
double fc1(int);
double fc2(int);
double fc3(int);
double fc4(int);
double fc5(int);

int main(){
    
    FILE *pf = fopen("./grafica.dat", "w+");
    if(pf == NULL)
        printf("Documento no encontrado\n");
    else
        printf("Documento encontrado\n");

    for (int i = 0; i <= TAM_MAX; i+=500)
    {
        double a = fc5(i);
        fprintf(pf, "%d, %f \n", i, a);
        //printf("%d %f\n", i, a);
    }

    /*
    int n[20];
    for (int i = 0; i < 20; ++i)
    {
        n[i]=i*1.7;
    }
    
    for (int i = 0; i < 20; ++i)
    {
        int a = (n[i]*10)%(i+1);
        printf("n: %d modulo i: %d es: %d\n", n[i]*10, i+1, a);
    }
    */
    
    fclose(pf);
    return 0;
}

double fc5(int n){
    return 7*n+5;
}

double fc4(int n){
    return 6*n-7;
}

double fc3(int n){
    return 5*p(n, 3) - 10*p(n,2) + 9*n - 2;
}

double fc2(int i){
    return 5*i+8;
}

double fc1(int i){
    return 4*i+2+5*i*log_2(2,(double)i)+5*log_2(2,(double)i);
}

//Funcion para hacer logaritmo de un numero(n) en una base(b) dada
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

//Funcion para elevar a un exponenete entero dado, retorna el resultado
double p(double numero,int exponente) {
    double r = 1.0;
    for(exponente;exponente>0;exponente--) 
        r *= numero;
    return r;
}

