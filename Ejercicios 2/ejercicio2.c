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
    int A[TAM][TAM], B[TAM][TAM], C[TAM][TAM];
    for (int i = 0; i < TAM; ++i)
    {
        for (int j = 0; j < TAM; ++j)
        {
            A[i][j]=n[j];
            B[i][j]=n[j];
            C[i][j]=n[j];
        }
    }
    c1(n, TAM);
    c2(n, TAM);
    c3(A, B, C, TAM);
    c4(TAM);
    c5(n, n, TAM);
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
        }
        t++;//n-1
    }
    t++;

    printf("La variable temporal es: %d\n", t);
}

void c2(int A[], int n){
    //Falta declarar z, tomaremos z como un entero igual a 1
    int z = 1, t=0;

    //Inicio
    int polinomio = 0; t++;//polinomio = 0 se hace 1
    t++;// i = 0 se hace 1
    for (int i = 0; i <= n; ++i)
    {
        t++; //Se hacen (n+2) comprobaciones
        polinomio = polinomio*z + A[n-i]; t+=3; // Se hace 3(n+1)
        t++; // se hace n+1
    }
    t++; //Ultima comparación del i<=n 1
    
    printf("La variable temporal es: %d\n", t);

}

void c3(int A[TAM][TAM], int B[TAM][TAM], int C[TAM][TAM], int n){
    int t = 0;

    //Inicio
    t++; //lo hace 1 vez
    for (int i = 1; i < n; ++i)
    {
        t++; //Comparacion lo hace n
        t++; // j = 1 lo hace 1 (n-1)
        for (int j = 1; j < n; ++j){ //Todo por n-1
            t++; //Comparaciones lo hace n
            C[i][j] = 0; t++; // lo hace n-1
            t++; // lo hace una vez por n-1
            for (int k=1; k < n; ++k){ // Todo por n-1
                t++; //Comparaciones lo hace n
                C[i][j] = C[i][j] + A[i][k]*B[k][j]; t+=3; // lo hace 3 (n-1)
                t++; //el incremento lo hace n-1
            }
            t++; // comparaciones de k<n final (no contabilizar)
            t++; // lo hace n-1 incrementos de j++ 
        }
        t++; // comparaciones de j<n final (no contabilizar)
        t++; // i++ lo hace (n-1)
    }
    t++; // comparacion de i<n final (no contabilizar)

    printf("La variable temporal es: %d\n", t);
}

void c4(int n){
    int aux;
    int t = 0;
    //Inicio
    int anterior = 1; t++; // se hace 1
    int actual = 1; t++; // se hace 1
    while(n>2){ 
        t++; // se hace n-1 comprobaciones
        aux = anterior + actual; t+=2; // se hace 2(n-2)
        anterior = actual; t++; // se hace n-2
        actual = aux; t++; // se hace n-2
        n = n - 1; t++; // se hace n-2 decrementos
    }
    t++; // comparacion de n>2 final (no contabilizar)

    printf("La variable temporal es: %d\n", t);
}

void c5(int n1[], int n2[], int n){
    int *s = n1, *s2 = n2;
    int t = 0;

    //inicio
    t+=2; // se hace i=n-1 y j=0, se contabiliza con 2
    for (int i = n-1,j=0; i >= 0; i--, j++){ 
        t++; // se hace n+1 comprobaciones 
        s2[j] = s[i]; t++;// se hace n 
        t+=2; // se hace 2(n) incrementos o decrementos de i y j
    }
    t++; // comparacion de i>=0 final (no contabilizar)
    t++; // se hace 1
    for (int k=0; k<n; ++k){
        t++; // se hace n+1 comprobaciones
        //Aqui no esta declarada la "i" para esta instruccion s[i] = s2[i]; por lo que tomaremos a k como si fuera i
        s[k] = s2[k]; t++; // se hace n
        t++; // se hace n incrementos de k
    }
    t++; // comparacion de k<n final (no contabilizar)
    
    printf("La variable temporal es: %d\n", t);
}

void c6(int a, int b){
    int l,r, t = 0;

    //Inicio
    l=(a<b)?a:b; t+=2; // se hace una asignacion y una condicional se contabiliza con 2
    r=1; t++; // se hace 1
    t++; // se hace 1
    for (int i=2; i<=l; ++i){ // siempre se compara con el mas pequeño entre a y b, tomaremos n como ese valor
        t++; // se hace n comprobaciones
        t+=3;
        if(a%i==0 && b%i==0){ // se hace 3(n-1)
            r=i; t++; // se hace ->
            printf("La variable es %d , %d, %d\n", a, b, i);
        }
        t++; // se hace n-1 incrementos de i
    }
    t++; // comparacion de i<=l final (no contabilizar)

    printf("La variable temporal es: %d\n", t);
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

