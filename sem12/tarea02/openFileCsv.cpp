/**
 * nomPrograma: openFileExcel-v1.cpp
 * descripcion: Abre un archivo de texto separados por comas (CSV),
 *              lo copia a vector de registros y lo muestra en pantalla.
 *
 * TAREAS:
 * 1. Analice, compile y ejecute luego analice los resultados.
 * 2. Comentado en forma breve y adecuada (ver abajo).
 * 3. Ensenanzas rescatadas al final del archivo.
 * 4. mostrarVectorRegistros modificado para mostrar por paginas
 *    y permitir salir cuando el usuario lo desee.
 *
 * autor: GASA  (completado y corregido)
 * fecha: 23032020 / 2024
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Constantes de tamanio maximo */
#define  MAXLINEA    255   /* longitud maxima de una linea del CSV       */
#define  MAXCAMPO    41    /* longitud maxima de un campo (nombre, etc.) */
#define  MAXVECTOR   20    /* capacidad maxima del vector de alumnos     */
#define  PAGSIZE     5     /* registros por pagina en la visualizacion   */

using namespace std;

/* Tipos alias para mayor legibilidad */
typedef char   str20[MAXCAMPO];   /* cadena para campos de texto  */
typedef char   strLin[MAXLINEA];  /* cadena para una linea entera */

struct CodIndex {
   int  icod;     // codigo del alumno (clave del indice)
   long dirlog;   // direccion logica en el archivo .dat
};

/* Estructura que representa un alumno */
struct ALUMNO {
    int   icod;   /* codigo numerico del alumno  */
    str20 snom;   /* nombre del alumno           */
    float fnota;  /* nota/calificacion obtenida  */
};

/* ---- Prototipos ---- */
void crearVector(ALUMNO x[], int *dx);
void adicionaDatoVector(ALUMNO x[], int *dx, ALUMNO dato);
void mostrarVectorRegistros(ALUMNO x[], int dx);
void recuperar(FILE *fx, ALUMNO x[], int *dx);

void adicionarDatoFile(ALUMNO ax);
void mostrarFileAlu();

void adicionarDatoFileIndex(ALUMNO x[], int dx);
void mostrarFileIndex();

void encabezado1();
void encabezado2();
void raya1();
void raya2();

/* ================================================================
   MAIN
   ================================================================ */
int main()
{
    int   nalu;
    ALUMNO a, alu[MAXVECTOR];
    FILE  *fa;

    /* Abre el archivo CSV en modo texto lectura */
    fa = fopen("pruebaCsv.csv", "rt");
    if (fa == NULL) {
        cout << "No se pudo abrir el Archivo de Entrada.\n";
        system("pause");
        return 1;   /* termina con error si no existe el archivo */
    } else {
        cout << "El archivo se abrio correctamente.\n";
    }

    /* Inicializa el vector (dx = -1 indica vacio) */
    crearVector(alu, &nalu);

    /* Muestra el vector vacio antes de cargar datos */
    mostrarVectorRegistros(alu, nalu);

    /* Lee el CSV y llena el vector */
    recuperar(fa, alu, &nalu);

    /* Muestra el vector ya cargado, con paginacion */
    mostrarVectorRegistros(alu, nalu);

    adicionarDatoFileIndex(alu, nalu);   // necesita el vector
    mostrarFileIndex();

    fclose(fa);

    printf("\n");
    system("pause");
    return 0;
}

/* ================================================================
   recuperar: lee linea a linea el CSV, tokeniza por ';'
              y agrega cada registro al vector.
   ================================================================ */
void recuperar(FILE *fa, ALUMNO x[], int *dx)
{
    ALUMNO  a;
    char   *token;
    strLin  linea;

    fgets(linea, MAXLINEA, fa);          /* lee primera linea      */
    while (!feof(fa)) {
        /* Separa el codigo (primer campo) */
        token   = strtok(linea, ";");
        a.icod  = atoi(token);

        /* Separa el nombre (segundo campo) */
        token   = strtok(NULL, ";");
        strcpy(a.snom, token);

        /* Separa la nota (tercer campo) */
        token   = strtok(NULL, ";");
        a.fnota = atof(token);

        adicionaDatoVector(x, dx, a);    /* agrega al vector       */
        fgets(linea, MAXLINEA, fa);      /* avanza a la siguiente  */
    }
}

/* ================================================================
   crearVector: inicializa el vector como vacio (dx = -1).
   ================================================================ */
void crearVector(ALUMNO x[], int *dx)
{
    *dx = -1;
}

/* ================================================================
   adicionaDatoVector: inserta un ALUMNO al final del vector.
   Primer elemento usa posicion 0; los siguientes se van apilando.
   ================================================================ */
void adicionaDatoVector(ALUMNO x[], int *dx, ALUMNO dato)
{
    int n;
    if (*dx < 0) {
        /* Vector estaba vacio: primer elemento en posicion 0 */
        x[0] = dato;
        *dx  = 1;
    } else {
        n = *dx + 1;                 /* nueva cantidad        */
        if (n < MAXVECTOR) {
            x[*dx] = dato;           /* guarda en ultima pos  */
            *dx    = n;
        } else {
            printf("Vector lleno...!\n");
        }
    }
}

/* ================================================================
   adicionarDatoFile: escribe un registro ALUMNO en archivo binario.
   CORRECCION: fwrite necesita puntero; se pasa &ax en lugar de ax.
   ================================================================ */
void adicionarDatoFile(ALUMNO ax)
{
    FILE *f;
    f = fopen("alumno.dat", "a+");
    if (f == NULL) {
        printf("No se pudo abrir el archivo para escritura.\n");
        return;                       /* evita continuar con f=NULL */
    }
    fwrite(&ax, sizeof(ALUMNO), 1, f);  /* <-- &ax corrige el bug   */
    fclose(f);
}

/* ================================================================
   mostrarVectorRegistros: muestra el vector por paginas de PAGSIZE
   registros.  Tras cada pagina pregunta al usuario si continua.
   Tarea 4: solucion para archivos de 300 000 lineas.
   ================================================================ */
void mostrarVectorRegistros(ALUMNO x[], int dx)
{
    int  i;
    char resp;

    if (dx <= 0) {
        printf("Vector vaciooo...!\n");
        return;
    }

    system("cls");
    encabezado1();
    encabezado2();

    for (i = 0; i < dx; i++) {
        /* Imprime la fila del alumno actual */
        printf("%3d%5d\t%-15s%10.1f\n",
               i + 1, x[i].icod, x[i].snom, x[i].fnota);

        /* Al completar una pagina (o llegar al ultimo registro)
           ofrece continuar o salir                              */
        if ((i + 1) % PAGSIZE == 0 && (i + 1) < dx) {
            raya1();
            printf("Pagina %d de %d  --  [ENTER] continuar  /  [s] salir: ",
                   (i + 1) / PAGSIZE,
                   (dx - 1) / PAGSIZE + 1);
            resp = getchar();
            if (resp == 's' || resp == 'S') {
                printf("Saliendo de la visualizacion...\n");
                break;               /* el usuario elige salir        */
            }
            /* Limpia pantalla y repite encabezado en cada pagina nueva */
            system("cls");
            encabezado1();
            encabezado2();
        }
    }
    raya1();
}

/* ================================================================
   mostrarFileAlu: lee y muestra todos los registros del archivo
                  binario alumno.dat.
   ================================================================ */
void mostrarFileAlu()
{
    int    i = 0;
    ALUMNO a;
    FILE  *f;

    f = fopen("alumno.dat", "rb");   /* binario: rb en lugar de "rt" */
    if (f == NULL) {
        cout << "No se pudo abrir el Archivo de Entrada.\n";
        return;
    } else {
        cout << "El archivo se abrio correctamente.\n";
    }

    fread(&a, sizeof(a), 1, f);
    while (!feof(f)) {
        cout << i + 1 << "\t" << a.icod << "\t"
             << a.snom << "\t" << a.fnota << endl;
        fread(&a, sizeof(a), 1, f);
        i++;
    }
    fclose(f);
}

void adicionarDatoFileIndex(ALUMNO x[], int dx)
{
    CodIndex ci;
    FILE *f = fopen("aluindex.dat", "wb");
    if (f == NULL) { printf("Error al abrir aluindex.dat\n"); return; }

    for (int i = 0; i < dx; i++) {
        ci.icod   = x[i].icod;
        ci.dirlog = i;           // posicion logica en el arreglo/archivo
        fwrite(&ci, sizeof(CodIndex), 1, f);
    }
    fclose(f);
}

void mostrarFileIndex()
{
    int    i = 1;
    CodIndex ci;
    FILE  *f;

    f = fopen("aluindex.dat", "r");   /* binario: rb en lugar de "rt" */
    if (f == NULL) {
        cout << "No se pudo abrir el Archivo de Entrada.\n";
        return;
    } else {
        cout << "El archivo se abrio correctamente.\n";
    }

    fread(&ci, sizeof(ci), 1, f);
    while (!feof(f)) {
        cout << i + 1 << "\t" << ci.icod <<"\t"<< ci.dirlog << endl;
        fread(&ci, sizeof(ci), 1, f);
        i++;
    }
    fclose(f);
}



/* ================================================================
   Funciones de presentacion en pantalla
   ================================================================ */
void encabezado1()
{
    printf("\t%-25s\n", "RELACION DE ALUMNOS");
    printf("\t%-25s\n", "Ordenado por codigo");
}

void encabezado2()
{
    raya2();
    printf("%4s %-7s %-15s %15s\n", "No", "CODIGO", "NOMBRE", "CALIFICACION");
    raya1();
}

void raya1()
{
    int  ancho = 45;
    char r10[] = "-----------------------------------------------------------";
    printf("%.*s\n", ancho, r10);
}

void raya2()
{
    int  ancho = 45;
    char r20[] = "===========================================================";
    printf("%.*s\n", ancho, r20);
}
