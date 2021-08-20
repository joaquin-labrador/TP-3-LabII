#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "mainTP3.h"

int main()
{
    //1
    int l = factorial(5);
    printf("\tFactorial de 5|%d|\n");
    //2
    int resultado = 0;
    resultado = potencia(7, 7);
    printf("\t%d\n", resultado);
   //Crear archivo
    int *arreglo = (int *)calloc(6, sizeof(int));
    arreglo[0] = 8;
    arreglo[1] = -12;
    arreglo[2] = 3;
    arreglo[3] = 3;
    arreglo[4] = 32;
    arreglo[5] = -6;
    size_t validos = _msize(arreglo) / sizeof(int) - 1;
    //_msize() devuelve el tamaño del bloque de memoria asignado por Malloc/Calloc/realloc
    //3
    mostrarArregloRecursivo(arreglo, validos - 1);
    printf("\n");
    //4
    int i=0;
    mostrarArreglo(arreglo,validos,i);
    printf("\n");
    //5
    int capicua = verificarCapicua(arreglo, validos, validos);
    printf("%d\n \n",validos);
    printf("El arreglo %s es capicua.", (capicua) ? "si" : "no ");
    printf("\n");
    //7
    int suma = sumaArreglo(arreglo, 0, validos);
    printf("\t La suma del arreglo es %d\n", suma);
     printf("\n");
    //8
    generarArchivo(arreglo, validos);
    int menor = menorArchivoRecursivo(0, 0);
    printf("El menor numero del arreglo es:\t %d", menor);
    printf("\n");
    //9
    i = registros();
    recorrerArchivo();
    printf("\n");
    invertirArchivoRecurs(i-1);
    printf("\n");
    recorrerArchivo2();
    printf("\n");
    //11
    char *arr = (char *)calloc(1, sizeof(char));
    char **pArr = &arr; //Necesitas el espacio de memoria del arrelgo para modificar con el REALLOC
    crearChar(pArr, 0);
    size_t size = _msize(arr) / sizeof(char) - 1;
    mostrarArray(arr, size);
    //12
    int num = -12;
    int verificacion = encontrarRecursivo(arreglo, validos, num);
    //printf("%d %s esta en el arreglo.", num, (verificacion) ? "si" : "no ");
    if(verificacion == 0)
    {
        printf("\n%d si esta en el arreglo.\n",num);
    }
    else{
        printf("\nNo ta\n");
    }

    return 0;
}

//1

int factorial(int n)
{
    if (n == 0) //Condicion de corte
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1); //Queda en stand by si entra un 2   [ (2 * factorial(1)) * (1*factorial(0)) ]
    }
}
//2
int potencia(int n, int exp)
{
    if (exp == 0) //Condicion de corte
    {
        return 1;
    }
    else
    {
        printf("\t|%d |\tpor\t |%d|\n", n, n);
        printf("\n");

        return n * potencia(n, exp - 1);
    }
}
//3
int mostrarArregloRecursivo(char arreglo[], int validos)
{
    if (validos == -1) //Condicion de corte
    {
        return 0;
    }
    else
    {
        printf("\t|%d|", arreglo[validos]);
        printf("\t%d", validos);
        return mostrarArregloRecursivo(arreglo, validos - 1); //Queda en stand by ejcutandose la funcion hasta que se rompe el if y duevelve los printf primero el ultimo validos
            //ya que quedo en standy por ende se ma a mostrar la celda 0 (el valido 0) en este caso 3
    }
}
//4
void mostrarArreglo(int arreglo[], int validos, int i)
{
    if (i == validos - 1) //Resto uno pq la primera celda es la cero
    {
        printf("|%d|", arreglo[i]);
    }
    else
    {
        printf("|%d|", arreglo[i]);
        mostrarArreglo(arreglo, validos, i + 1); //Recursividad muy parecidad a la anterior pero la diferrencia
        //es que en esta en la condicion de corte se aumenta invocando una variable extra que la iniciaremos en 0
        //esta recorre el arreglo de 0-->5 y la anterior de 5-->0
        //Por eso el printf es antes de invocar la funcion
    }
}
//5
int verificarCapicua(int arreglo[], int validos1, int validos2)
{
    if (validos1 == 0) //La condicion de corte es con los "validos1" debemos decrementar la misma
    {
        return 1;
    }
    else
    {
        if (arreglo[validos2 - validos1] == arreglo[validos1]) //Comparacion para verificar si es capicua
        //  (arreglo[6-6]==arreglo[6])
        {

            return (arreglo, validos2, validos1 - 1); //Disminuyo "validos1" para acercarnos a la condicion de corte y ademas para en la proxima comparar arr[6-5] == arr[5]
        }
        {
            return 0;
        }
    }
}
//6
int sumaArreglo(int arreglo[], int cero, int validos)
{
    int suma = 0;
    if (cero == validos) //Cuando Cero aumente hasta validos retorno la ultima poscion para sumar :D
    {

        return arreglo[cero]; //aca seria igual poner arreglo[validos] pq son iguales
    }
    else
    {
        suma = arreglo[cero] + sumaArreglo(arreglo, cero + 1, validos); //Entra como cero pero debemos amuentar para acercarnos la condicion de corte
        //y para avanzar en el arreglo (no seria mas cero XD)
    }
    return suma;
}
//7
int menorElemento(int arreglo[], int validos, int menor)
{
    //traigo un entero de parametro para tener un registro de comparaciones
    if (validos == -1) //Condicion de corte decremento los validos
    {
        return menor; //Retorno el menor
    }
    else
    {
        if (arreglo[validos] < menor) //Comparacion si el menor es mayor que otro es una falacia hay que cambiar
        {
            menor = arreglo[validos]; //Asigno nuevo valor para pasar uno nuevo en la recursividad
        }
        return menorElemento(arreglo, validos - 1, menor); //traigo devuelta el menor :D DECREMENTAR VALIDOS!!!
                                                           //Fuera del if ya que aunque no sea mayor se debe cumplir la recursividad :D
    }
}
//8
void generarArchivo(int arreglo[], int validos)
{
    FILE *buffer = fopen(file, "wb");
    if (buffer != NULL)
    {
        for (int i = 0; i < validos; i++)
        {
            fwrite(&arreglo[i], sizeof(int), 1, buffer);
        }
        fclose(buffer);
    }
}
int menorArchivoRecursivo(int registros, int menor) //  (0,0)
{
    if (registros == -1)
    {
        return menor;
    }
    else
    {
        int aux;                                          //Genero un variable auxiliar para leer un archivo
        FILE *buffer = fopen(file, "rb");                 //Abro el archivo
        fseek(buffer, sizeof(int) * registros, SEEK_SET); //Cuando se iteraciona movemos el curso al elemto que queremos comparar
        fread(&aux, sizeof(int), 1, buffer);
        if (registros == 0) //si el registro es cero menor no tiene ningun valor asiganado
        {
            menor = aux; //Le asigo en valor del primer elemento que leeo del archivo
        }
        else
        {
            if (aux < menor) //comparacion
            {
                menor = aux;
            }
        }
        if (feof(buffer)) //Si llego al final del archivo
        {
            registros = -2; //para que? para cuando realice la iteriacion retorne menos -1 cuando termine de leer
            // el archivo y generar la condicion de corte y asi retonar el menor
        }
        fclose(buffer);
        return menorArchivoRecursivo(registros + 1, menor); //para comparar todos los registros del archivooo
    }
}
//9
int invertirArchivoRecurs(int registros)
{
    FILE *buff = fopen(file, "rb");
    FILE *archi = fopen(filerecursivo, "ab");
    int aux;
    if (buff != NULL && archi != NULL)
    {

        if (registros == -1)
        {
            fclose(buff);
            fclose(archi);
            return 0;
        }
        else
        {
            fseek(buff, sizeof(int) * registros, SEEK_SET);
            fread(&aux, sizeof(int), 1, buff);
            fwrite(&aux, sizeof(int), 1, archi);
            fclose(buff);
            fclose(archi);
            return invertirArchivoRecurs(registros - 1);
        }
    }
}
void recorrerArchivo()
{
    FILE *buffer = fopen(file, "rb");
    int aux;
    if (buffer != NULL)
    {
        while (fread(&aux, sizeof(int), 1, buffer) > 0)
        {
            printf("\t%d", aux);
        }
        fclose(buffer);
    }
}
void recorrerArchivo2()
{
    FILE *buffer = fopen(filerecursivo, "rb");
    int aux;
    if (buffer != NULL)
    {
        while (fread(&aux, sizeof(int), 1, buffer) > 0)
        {
            printf("\t%d", aux);
        }
        fclose(buffer);
    }
}
int registros()
{
    FILE *buffer = fopen(file, "rb");
    int registros;
    if (buffer != NULL)
    {
        fseek(buffer, 0, SEEK_END);
        registros = ftell(buffer) / sizeof(int);
        fclose(buffer);
    }
    return registros;
}
//11
int mostrarArray(char *arr, int i)
{
    if (i == -1)
    {
        return 0;
    }
    else
    {
        printf("%c", arr[i]);
        return mostrarArray(arr, i - 1);
    }
}
int crearChar(char **palabra, int cero) //(string && 0 )
{
    char input; //Creo variable a cargar
    fflush(stdin);
    scanf("%c", &input);
    if (input == '*') //Condicion de corte dada por el usuario
    {
        return 0;
    }
    else
    {
        *palabra = (char *)realloc(*palabra, sizeof(char) * (cero + 1)); //Reasigo mas espacio de memoria al arreglo ya que puso un
        //caracter != "*"
        *(*palabra + cero) = input;          //Cargo el arreglo
        return crearChar(palabra, cero + 1); //Recursividad se va a cortar cuando ingrese un "*", por ende tengo que
        //aumentar ser para asigar mayor espacion es el REALLOC
    }
}
//12
int encontrarRecursivo(int arreglo[], int validos, int num)
{
    if (validos == -1)
    {
        return 1;
    }
    else
    {
        if (arreglo[validos] != num)
        {
            return 0;
        }
        return encontrarRecursivo(arreglo, validos - 1, num);
    }
}
