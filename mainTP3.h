#define file "FileTp3.bin"
#define filerecursivo "FileTp3recursivo.bin"
#define MAX_CHAR 10

int factorial(int n);
int potencia(int n, int exp);
int mostrarArregloRecursivo(char arreglo[], int validos);
void mostrarArreglo(int arreglo[], int validos, int i);
int verificarCapicua(int arreglo[], int validos1, int validos2);
int sumaArreglo(int arreglo[], int cero, int validos);
int menorElemento(int arreglo[], int validos, int menor);
void generarArchivo(int arreglo[], int validos);
int menorArchivoRecursivo(int registros, int menor);
int invertirArchivoRecurs(int registros);
void recorrerArchivo();
void recorrerArchivo2();
int registros();
int crearChar(char **palabra, int cero);
int mostrarArray(char *arr, int i);
int encontrarRecursivo(int arreglo[], int validos, int num);