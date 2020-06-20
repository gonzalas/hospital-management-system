#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"
#include "turno.h"

#define archivoPacientes "paciente.bin"

Paciente cargarPaciente(){

    Paciente paciente;

    printf("\n\n Ingrese un nombre y apellido: ");
    fflush(stdin);
    gets(paciente.nombreApellido);

    printf("\n\n Ingrese DNI: ");
    fflush(stdin);
    scanf("%d", &paciente.dniPaciente);

    printf("\n\n Ingrese edad: ");
    fflush(stdin);
    scanf("%d", &paciente.edad);

    paciente.eliminado = 0;

    puts("\n\n");

    return paciente;
}

void cargarPacienteArchivo(){

    FILE *archi = fopen( archivoPacientes , "ab");

    Paciente aux;

    if ( archi != NULL ){

            aux = cargarPaciente();

            fwrite(&aux , sizeof(Paciente) , 1 , archi );

    }
    fclose(archi);
}

void mostrarTodoPaciente(){

    FILE *archi = fopen(archivoPacientes , "rb");

    Paciente aux;

    if ( archi != NULL ){

        printf("Listado de pacientes\n\n");

        while ( fread( &aux , sizeof(Paciente), 1 , archi) > 0){

            if ( aux.eliminado == 0){

                mostrarPaciente(aux);
            }
        }

    }

    fclose(archi);
}

void mostrarPaciente( Paciente paciente ){

    printf("\n\nPaciente\n\n Nombre y apellido: %s ", paciente.nombreApellido );

    printf("\n\n DNI: %d ", paciente.dniPaciente );

    printf("\n\n Edad: %d \n", paciente.edad );

}

void bajaPaciente( int documento ){

    FILE *archi = fopen(archivoPacientes, "r+b");

    Paciente aux;

    int flag = 0;

    if ( archi != NULL ){

        while (!flag && fread(&aux, sizeof(Paciente), 1 , archi ) > 0){

            if ( aux.dniPaciente == documento ){

                aux.eliminado = 1;

                fseek(archi , sizeof(Paciente)*(-1) , SEEK_CUR);

                fwrite(&aux, sizeof(Paciente), 1 , archi);

                flag = 1;

                fclose(archi);

            }
        }

    }



    if ( flag == 0 ){

        printf("\n\n No se encontr%c el documento. Intente otra vez.\n\n",162);

    } else if ( flag == 1 ){

        printf("\n\n El paciente se dio de baja con %cxito.\n\n",130);

    } else {

        printf("\n\n Hubo un error. Verifique el listado de pacientes para m%cs informaci%cn.\n\n",160,162);

    }

    fclose(archi);
}

void modificarNombrePaciente ( int documento ){

    FILE *archi = fopen(archivoPacientes, "r+b");

    Paciente aux;

    char nuevoNombreApellido[30];

    printf("\n\n Ingrese nuevo nombre: ");
    fflush(stdin);
    gets(nuevoNombreApellido);

    int flag = 0;

    if ( archi != NULL ){

        while ( fread(&aux , sizeof(aux), 1 , archi ) > 0 && !flag){

            if ( aux.dniPaciente == documento ){

                strcpy(aux.nombreApellido, nuevoNombreApellido);

                fseek(archi , sizeof(aux)*(-1), SEEK_CUR);

                fwrite(&aux, sizeof(aux), 1 , archi);

                flag++;

                fclose(archi);
            }

        }

    }


    if ( flag == 0 ){

        printf("\n\n No se pudo encontrar el documento buscado. Intente otra vez.\n");

    } else if ( flag == 1 ){

        printf("\n\n El nombre se cambi%c con %cxito. \n",162,130);

    } else {

        printf("\n\n Ocurri%c un error. Compruebe los listados.\n",162);

    }

}

void modificarEdadPaciente ( int documento ){

    FILE *archi = fopen(archivoPacientes, "r+b");

    Paciente aux;

    int flag = 0, nuevaEdad = 0;

    printf("\n\n Ingrese nueva edad: ");
    fflush(stdin);
    scanf("%d" , &nuevaEdad);

    if ( archi != NULL ){

        while (fread(&aux, sizeof(aux), 1 , archi ) > 0 && !flag ){

            if ( aux.dniPaciente == documento ){

                aux.edad = nuevaEdad;

                fseek(archi , sizeof(aux)*(-1) , SEEK_CUR);

                fwrite(&aux, sizeof(aux), 1 , archi);

                flag++;

                fclose(archi);

            }
        }

    }



    if ( flag == 0 ){

        printf("\n\n No se encontr%c el documento. Intente otra vez.\n",162);

    } else if ( flag == 1 ){

        printf("\n\n El paciente se modific%c con %cxito.\n",162,130);

    } else {

        printf("\n\n Hubo un error. Verifique el listado de pacientes para m%cs informaci%cn.\n",160,162);

    }

}

void modificarPacienteEntero ( int documento ){

    FILE *archi = fopen(archivoPacientes, "r+b");

    Paciente aux, aux2;

    int flag = 0;

    aux2 = cargarPaciente();

    aux2.dniPaciente = documento;

    if ( archi != NULL ){

        while ( fread( &aux , sizeof(aux), 1 , archi) > 0 && !flag ){

            if ( aux.dniPaciente == documento ){

                aux = aux2;

                fseek(archi , sizeof(Paciente)*(-1), SEEK_CUR);

                fwrite(&aux, sizeof(Paciente), 1, archi);

                flag++;

                fclose(archi);

            }

        }

    }

    if ( flag == 0 ){

        printf("\n\n No se encontr%c el documento. Intente otra vez.\n",162);

    } else if ( flag == 1 ){

        printf("\n\n El paciente se modific%c con %cxito.\n",162,130);

    } else {

        printf("\n\n Hubo un error. Verifique el listado de pacientes para m%cs informaci%cn.\n",160,162);

    }

}

int validarDocu( int documento ){

    FILE *archi = fopen(archivoPacientes , "rb");

    Paciente aux;

    int i = 0;

    if ( archi != NULL ){

        while ( fread( &aux , sizeof (aux), 1 , archi ) > 0 ){

            if ( aux.dniPaciente == documento ){

                i++;

            }
        }
    }

    fclose(archi);

    return i;
}

void mostrarPacienteDocu ( int documento ){

    FILE *archi = fopen( archivoPacientes , "rb");

    Paciente aux;

    int flag = 0;

    if ( archi != NULL ){

        while ( fread( &aux , sizeof(Paciente) , 1 , archi) > 0 && !flag ){

            if ( aux.dniPaciente == documento && aux.eliminado == 0){

                mostrarPaciente(aux);

                flag = 1;

                fclose(archi);
            }

        }

    }
    fclose(archi);

    if ( flag == 0 ){

        printf("\n\n No se encontr%c el documento. Intente otra vez.\n",162);

    }

}

void mostrarPacienteNombre(){

    char nombreBuscar[30];

    int flag = 0;

    Paciente aux;

    printf("\n\n Ingrese nombre a buscar: ");
    fflush(stdin);
    gets(nombreBuscar);

    FILE *archi = fopen(archivoPacientes , "rb");

    if (archi != NULL ){

        while ( fread( &aux , sizeof(Paciente), 1 , archi ) > 0 && !flag ){

            if ( strcmpi( aux.nombreApellido , nombreBuscar ) == 0 && aux.eliminado == 0){

                mostrarPaciente(aux);

                flag = 1;

                fclose(archi);
            }

        }

    }
    fclose(archi);

    if ( flag == 0 )

        printf("\n\n El nombre buscado no concuerda con ninguno del archivo.\n");

}


int comprobarPacientePorDNI()
{
    int flag = 0, dni = 0;

    printf("\nIngrese DNI para comprobar si el paciente est%c registrado: ",160);
    fflush(stdin);
    scanf("%i",&dni);

    FILE * archivo = fopen(archivoPacientes, "rb");

    if (archivo != NULL)
    {
        Paciente aux;

        while(!flag && fread(&aux, sizeof(Paciente), 1, archivo) > 0)
        {
            if (aux.dniPaciente == dni && aux.eliminado == 0)
            {
                dni = aux.dniPaciente;

                flag = 1;
            }
        }
    }
    fclose(archivo);

    if(flag == 0)

        dni = 0;

    return dni;
}



int atenderPaciente(char ArchivoTurno[], int dni)
{
    int i = 0, atendido = -1, flag = 0;

    FILE * archivo = fopen(ArchivoTurno,"r+b");

    if(archivo != NULL)
    {
        Turno aux;

        while(!flag && fread(&aux, sizeof(Turno), 1, archivo) > 0)
        {
            if(aux.dniPaciente == dni)
            {
                printf("\nEl paciente fue atendido.\n\n");

                aux.ocupado = 0;

                fseek(archivo, sizeof(Turno) * (-1), SEEK_CUR);

                fwrite(&aux, sizeof(Turno), 1, archivo);

                atendido = i;

                flag = 1;

            }

            i++;
        }
    }
    fclose(archivo);

    return atendido;
}


void atenderPaciente2(char ArchivoTurno[], int dni)
{
    int i = 0, flag = 0;

    FILE * archivo = fopen(ArchivoTurno,"r+b");

    if(archivo != NULL)
    {
        Turno aux;

        while(!flag && fread(&aux, sizeof(Turno), 1, archivo) > 0)
        {
            if(aux.dniPaciente == dni)
            {
                printf("\nEl paciente fue atendido.\n\n");

                aux.ocupado = 0;

                fseek(archivo, sizeof(Turno) * (-1), SEEK_CUR);

                fwrite(&aux, sizeof(Turno), 1, archivo);

                flag = 1;

                fclose(archivo);

            }

            i++;
        }
    }
    fclose(archivo);
}

int crearPaciente()
{
    int dni = 0;

    FILE * archivo = fopen(archivoPacientes,"ab");

    if (archivo != NULL)
    {
        Paciente aux;

        printf("\nConfirme el DNI del paciente: ");
        fflush(stdin);
        scanf("%i",&aux.dniPaciente);

        dni = aux.dniPaciente;

        printf("\n\nIngrese su nombre y apellido: ");
        fflush(stdin);
        gets(aux.nombreApellido);

        printf("\n\nIngrese la edad correspondiente: ");
        fflush(stdin);
        scanf("%i",&aux.edad);

        aux.eliminado = 0;

        fwrite(&aux, sizeof(Paciente), 1, archivo);
    }
    fclose(archivo);

    return dni;
}

Paciente buscarPacientePorDNI(int dni)
{
    int flag = 0;

    Paciente buscado;

    FILE * archivo = fopen(archivoPacientes, "rb");

    if (archivo != NULL)
    {
        Paciente aux;

        while(!flag && fread(&aux, sizeof(Paciente), 1, archivo) > 0)
        {
            if(aux.dniPaciente == dni)
            {
                flag = 1;

                buscado = aux;
            }
        }
    }
    fclose(archivo);

    return buscado;
}



