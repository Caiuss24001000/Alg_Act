/*******    INSTRUCCIONES

DETERMIANR PARA LOS SIGUINETES CODIGOS LA FUNCION DE COMPLEJIDAD TEMPORAL Y ESPACIAL
EN TERMNOS DE N. CONSIDERAR LAS OPERACIONES DE ASIGNACIÓN, ARITMETICAS Y CONDICIONALES

DETERMINE PARA CADA CASO LA FUNCION COMPLEJIDAD TEMPORAL Y ESPACIAL (INDIQUE 
DETALLADAMENTE LA OBTENCION DEL MODELO)
CONTRASTE SUS FUNCIONES CON LA PRUEBA EMPIRICA (VERIFIQUE EL CONTEO CORRECTO DE LAS 
INSTRUCCIONES) PARA LOS 20 VALORES DE 
N={-1,0,1,2,3,5,15,20,100,409,500,593,1000,1471,1500,2801,3000,5000,10000,20000}

*Incluir portada con los datos del alumno, datos del trabajo y fotografía del alumno
*Incluir tabla comparativa de resultados teóricos vs empíricos
*Incluir la gráfica de cada modelo encontrado desde n=0 hasta n=500,000.
*Subir todo en un solo archivo de tipo documentos (Análisis, Comparativa y Códigos)
*Enmarcar los códigos en el documento y manejar formato de colores
*Recordar manejar encabezados y pies de página
*/

#include <stdio.h>

#define TAM 20

void c1(int [], int);
void c2(int [], int);
void c3(int [TAM][TAM], int [TAM][TAM], int [TAM][TAM], int);
void c4(int);
void c5(int [], int [], int);
void c6(int, int);
void c7(int [], int);

int main(){
    int n[]={-1,0,1,2,3,5,15,20,100,409,500,593,1000,1471,1500,2801,3000,5000,10000,20000};
    int ct, ce;
    
    c1(n,TAM);
    return 0;
}

void c1(int A[], int n){
    int temp, t=0;

    //Inicio
    t++;//Se hace una vez
    for (int i = 1; i < n; ++i){
        t++;//i < n se hace n
        t++;//j=n se hace n-1
        for (int j = n; j>1; j/=2){
            t++;//j>1   log2(n)+1
            temp = A[j]; t++; // (log2(n))
            A[j] = A[j+1]; t++; // (log2(n))
            A[j+1] = temp; t++; // (log2(n))
            t++; //j/2 log2(n)
            printf("Hola %d %d\n",j,j);
        }
        //printf("Hola %d\n", i);
        t++;//n-1
    }
    t++;
    printf("La variable temporal es: %d\n", t);
}

void c2(int A[], int n){
    //Falta declarar z, tomaremos z como un entero igual a 1
    int z = 1;

    //Inicio
    int polinomio = 0;
    for (int i = 0; i <= n; ++i)
    {
        polinomio = polinomio*z + A[n-i];
    }
}

void c3(int A[TAM][TAM], int B[TAM][TAM], int C[TAM][TAM], int n){
    

    //Inicio
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < n; ++j){
            C[i][j] = 0;
            for (int k=1; i < n; ++i){
                C[i][j] = C[i][j] + A[i][k]*B[k][j];
            }
        }
    }
}

void c4(int n){
    int aux;

    //Inicio
    int anterior = 1;
    int actual = 1;
    while(n>2){
        aux = anterior + actual;
        anterior = actual;
        actual = aux;

        n = n - 1;
    }
}

void c5(int s[], int s2[], int n){
    for (int i = n-1,j=0; i >= 0; i--, j++){
        s2[j] = s[i];
    }
    for (int k=0; k<n; ++k)
    {
        //Aqui no esta declarada la "i" para esta instruccion s[i] = s2[i]; por lo que tomaremos a k como si fuera i
        s[k] = s2[k]; 
    }
}

void c6(int a, int b){
    int l,r;

    //Inicio
    l=(a<b)?a:b;
    r=1;
    for (int i=2; i<=1; ++i)
    {
        if(a%i==0 && b%i==0)
            r=i;
    }
}

void c7(int lista[], int n){
    int temp;

    //Inicio
    for (int i =1; i < n; ++i)
    {
        for (int j= 0; j<n-1; ++i)
        {
            if(lista[j] > lista[j+1]){
                temp = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = temp;
            }
        }
    }
}

/*

for i = 0 to n do
        for j = 1 to n do
            C[i,j] = 0;
            for k=1 to n do
                C[i,j] = C[i,j] + A[i,k]*B[k,j];

void c3(int A[][], int B[][], int C[][], int n){

    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < n; ++j){
            C[i,j] = 0;
            for (int k=1; i < n; ++i){
                C[i][j] = C[i][j] + A[i][k]*B[k][j];
            }
        }
    }
}

*/