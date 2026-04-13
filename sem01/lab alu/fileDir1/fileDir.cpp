/*
 * nomPrograma:
 * descripcion:
 *
 *
 * autor:
 * fecha:
 * version 1.
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define MAX 4
#define STR15 15

struct ALUMNO {
    int codAlu;
    char nombre[STR15];
    int prac[MAX];
    char valido; // S: valido, N: no valido
    long nreg;
};

void menu();
void leerAlumno(ALUMNO *reg);
void escribirAlumno(ALUMNO *reg);
void mostrarAlumnos(long n, ALUMNO *reg);
void listar(long n, ALUMNO *reg);
long leerDirLogica(long nr);
void eliminacionFisica(FILE **fa);

int main()
{

   menu();

   system("pause");
   return(0);
}

// Muestra un menú con las opciones disponibles y captura una opción del usuario
void menu()
{
    int opc;
    long nr=0;
    ALUMNO reg;
    FILE *fa;
    long numero;
    fa = fopen("alumnos.dat", "r+b"); // Este modo permite leer y escribir
    if(!fa){
        fa = fopen("alumnos.dat", "w+b"); // si el ficherono existe, lo crea
    }

    do {
        system("cls");
        printf("\n\t\tMENU PRINCIPAL\n\n");
        printf("\t0. SALIR\n");
        printf("\t1. Adicionar alumnos\n");
        printf("\t2. Escribir alumno\n");
        printf("\t3. Eliminar alumno\n");
        printf("\t4. Mostrar alumnos\n");
        printf("\t5. Eliminar alumnos marcados\n\n");
        printf("\tDigite su opcion ---> ");
        scanf("%d", &opc);
        switch(opc) {
            case 0:
                printf("El programa a terminadooo...\n");
                exit(0);
            case 1: // Añadir ALUMNO
                fread(&reg, sizeof(ALUMNO), 1, fa);
                nr=reg.nreg;
                if(nr<0){
                    reg.nreg=-1;
                    nr=reg.nreg;
                }
                leerAlumno(&reg);
                nr=nr+1;
                reg.nreg=nr;
                fseek(fa, 0, SEEK_END); //Se posiciona al final de file
                fwrite(&reg, sizeof(ALUMNO), 1, fa);
                break;
            case 2: // Escribir alumno
                system("cls");
                printf("Direccion logica --->\n");
                fread(&reg, sizeof(ALUMNO), 1, fa);
                nr=reg.nreg;
                numero = leerDirLogica(nr);
                fseek(fa, numero*sizeof(ALUMNO),
                SEEK_SET);
                escribirAlumno(&reg);
                system("PAUSE");
                break;
            case 3: // Eliminar ALUMNO
                system("cls");
                printf("Eliminar ALUMNO: ");
                fread(&reg, sizeof(ALUMNO), 1, fa);
                nr=reg.nreg;
                numero = leerDirLogica(nr);
                fseek(fa, numero*sizeof(ALUMNO),
                SEEK_SET);
                reg.valido = 'n';
                fseek(fa, numero*sizeof(ALUMNO),
                SEEK_SET);
                fwrite(&reg, sizeof(ALUMNO), 1, fa);
                break;
            case 4: // Mostrar todo
                rewind(fa);
                numero = 0;
                system("cls");
                printf("ALUMNOS\n");
                while(fread(&reg, sizeof(ALUMNO), 1,fa)){
                    mostrarAlumnos(numero++, &reg);
                }
                system("PAUSE");
                break;
            case 5: // Eliminar marcados
                eliminacionFisica(&fa);
                break;
        }

    } while(opc != 0);
    fclose(fa);
}
// Permite que el usuario introduzca un ALUMNO por pantalla
void leerAlumno(ALUMNO *ra)
{
    int cod,i,pra;
    char nom[STR15];
    system("cls");
    printf("Leer ALUMNO\n\n");
    ra->valido = 's';
    printf("Codigo: ");
    scanf("%d", &ra->codAlu);
    printf("Nombre: ");
    scanf("%s", &ra->nombre);
    printf("Practicas:\n");
    for(i = 0; i < MAX; i++) {
        printf("p[%d]: ", i);
        scanf("%d",&pra);
        ra->prac[i] = pra;
    }
}
// Muestra un ALUMNO en pantalla, si no está marcado como borrado
void escribirAlumno(ALUMNO *ra)
{
    int i;
    //system("cls");
    if(ra->valido == 'S' || ra->valido == 's') {
        printf("%6d %-15s %-3c",ra->codAlu,ra->nombre,ra->valido);
        for(i = 0; i < MAX; i++){
            printf("%4d", ra->prac[i]);
        }
        printf("\n");
    }
    else{
        printf("Registro no valiudo...\n");
    }
    //system("PAUSE");
}

// Muestra un ALUMNO por pantalla en forma de listado,
// si no está marcado como borrado
void mostrarAlumnos(long n, ALUMNO *ra)
{
    int i;
    if(ra->valido == 'S' || ra->valido == 's'){
        printf("[%6d]",n);
        escribirAlumno(&*ra);
    }
    /*
    if(ra->valido == 'S' || ra->valido == 's') {
        printf("[%6ld] %6d %-15s %-3c",n,ra->codAlu,ra->nombre,ra->valido);
        for(i = 0; i < MAX; i++){
            printf("%4d", ra->prac[i]);
        }
        printf("\n\n");
    }
    */

}
// Lee un número suministrado por el usuario
long leerDirLogica(long nr)
{
    long  dl=-1;
    scanf("%ld", &dl);
    if(dl>=0 && dl<=nr){
        printf("%d: Direccion logica VALIDA...\n", dl);
        return dl;
    }
    else{
        printf("%d: Direccion logica NO EXISTE...\n", dl);
        return dl;
    }
}
long leerDirLogica()
{
    long  dl;
    scanf("%ld", &dl);
    do{
        printf("Ingrese un numero positivo...");
        scanf("%ld", &dl);
    }while(dl<0);
    return dl;
}
// Elimina los ALUMNOs marcados como borrados
void eliminacionFisica(FILE **fa)
{
    FILE *ftemp;
    struct ALUMNO reg;
    ftemp = fopen("alumnos.tmp", "wb");
    rewind(*fa);
    while(fread(&reg, sizeof(ALUMNO), 1, *fa)){
        if(reg.valido == 'S'){
            fwrite(&reg, sizeof(ALUMNO), 1, ftemp);
        }
    }
    fclose(ftemp);
    fclose(*fa);
    remove("alumnos.bak");
    rename("alumnos.dat", "alumnos.bak");
    rename("alumnos.tmp", "alumnos.dat");
    *fa = fopen("alumnos.dat", "r+b");
}


