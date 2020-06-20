#include <stdio.h>
#include <string.h>

#include "medico.h"

Medico listado[5];

///especialidades: geriatría, clínica, pediatría, traumatología, toxicología

Medico cargarMedico()
{
    Medico aux;
    char especialidad[30];

    printf("--------------\nALTA DE M%cDICO\n--------------\n\n",144);

    printf("Ingrese nombre y apellido: ");
    fflush(stdin);
    gets(aux.nombreApellido);

    printf("\n\nIngrese matr%ccula: ",161);
    fflush(stdin);
    scanf("%i", &aux.matricula);

    printf("\n\nIngrese especialidad (sin tildes): ");
    fflush(stdin);
    gets(especialidad);

    validarEspecialidad(especialidad);

    strcpy(aux.especialidad,especialidad);

    aux.eliminado = 0;

    generadorTurnos(aux.listTurnos);

    return aux;
}

void validarEspecialidad(char especialidad[])
{
    char aux[30];

    while ((strcmpi(especialidad,"clinica") != 0) && (strcmpi(especialidad,"geriatria") != 0) && (strcmpi(especialidad,"pediatria") != 0) && (strcmpi(especialidad,"traumatologia") !=0) && (strcmpi(especialidad,"toxicologia") != 0))
    {
        printf("\n\nLa especialidad ingresada no es v%clida. Vuelva a intentarlo: ",160);
        fflush(stdin);
        gets(aux);

        strcpy(especialidad,aux);
    }
}


void generadorTurnos(Turno a[])
{
    int i = 0;

    for(int d = 0; d < 7; d++)
        {

        float inicioHorario = 10;

        for(i; i < 10 * (d+1); i++)
            {

            a[i].dniPaciente = 0;
            a[i].ocupado = 0;
            a[i].dia = (d+1);
            a[i].horario = inicioHorario;

            inicioHorario += 0.30;

            float result = inicioHorario - (int)inicioHorario;

            if(result >= 0.59)

                inicioHorario = (int)inicioHorario + 1;

            }
        }
}


void mostrarMedico(Medico m)
{
    printf("Nombre: %s\n", m.nombreApellido);

    printf("Matr%ccula: %i\n",161,m.matricula);

    printf("Especialidad: %s\n",m.especialidad);

    printf("\n-------------\n\n");
}


void guardarArchivoMedico()
{
    FILE * archivo = fopen(ArchivoMedico, "ab");

    if (archivo != NULL)
    {
        Medico aux = cargarMedico();

        fwrite(&aux, sizeof(Medico), 1, archivo);

    }

    fclose(archivo);
}


void mostrarArchivoMedico()
{
    FILE * archivo = fopen(ArchivoMedico, "rb");

    if (archivo != NULL)
    {
        Medico aux;

        printf("----------\nM%cDICO\n----------\n\n",144);

        while(fread(&aux, sizeof(Medico), 1, archivo) > 0)

            if (aux.eliminado == 0)

                mostrarMedico(aux);
    }

    fclose(archivo);
}

void darDeBajaMedicoPorEspecialidad(char especialidad[])
{
    int flag = 0;

    FILE * archivo = fopen(ArchivoMedico,"r+b");

    if (archivo != NULL)
    {
        Medico aux;

        while(fread(&aux, sizeof(Medico), 1, archivo) > 0 && !flag)
        {
            if (strcmpi(aux.especialidad,especialidad) == 0)
            {
                aux.eliminado = 1;

                fseek(archivo, sizeof(Medico) * (-1), SEEK_CUR);

                fwrite(&aux, sizeof(Medico), 1, archivo);

                flag = 1;
            }
        }
    }
    fclose(archivo);
}

Medico buscarMedicoEspecialidad(char especialidad [30])
{
    FILE * archivo = fopen(ArchivoMedico, "rb");

    int flag = 0;

    Medico buscado;

    if (archivo != NULL)
    {
        Medico aux;

        while (fread(&aux, sizeof(Medico), 1, archivo) > 0 && flag == 0)
        {
            if (strcmpi(especialidad,aux.especialidad) == 0 && aux.eliminado == 0)
            {
                buscado = aux;

                flag = 1;
            }

        }
    }
    fclose(archivo);

    if (flag == 0)
    {
        strcpy(buscado.nombreApellido,"NULL");
        strcpy(buscado.especialidad,"NULL");
        buscado.matricula = 0;

        printf("\nNo se encontr%c el profesional de especialidad %s.\n\n",162,especialidad);
    }

    return buscado;
}

void pedirEspecialidadMedicoParaBuscar(char especialidad[])
{
    printf("\nIngrese la especialidad del m%cdico que desea buscar (sin tildes): ",130);
    fflush(stdin);
    gets(especialidad);

    validarEspecialidad(especialidad);
}


Medico buscarMedicoMatricula(int matricula)
{
    FILE * archivo = fopen(ArchivoMedico, "rb");

    int flag = 0;

    Medico buscado;

    if (archivo != NULL)
    {
        Medico aux;

        while (fread(&aux, sizeof(Medico), 1, archivo) > 0 && !flag)
        {
            if (aux.matricula == matricula && aux.eliminado == 0)
            {
                buscado = aux;

                flag = 1;

            }

        }
    }
    fclose(archivo);

    if (flag == 0)
    {
        strcpy(buscado.nombreApellido,"NULL");
        strcpy(buscado.especialidad,"NULL");
        buscado.matricula = 0;

        printf("\nNo se encontr%c el profesional de matr%ccula %i.\n\n",162,161,matricula);
    }

    return buscado;
}

int pedirMatriculaMedicoParaBuscar()
{
    int matricula;

    printf("\nIngrese la matr%ccula del profesional que desea buscar: ",161);
    fflush(stdin);
    scanf("%i",&matricula);

    return matricula;
}

void pedirNuevoNombreMedico(char nombre[])
{
    printf("\nIngrese el nuevo nombre del profesional: ");
    fflush(stdin);
    gets(nombre);
}

int verificarMatricula()
{
    int matricula = 0, flag = 0;

    printf("\nIngrese la matr%ccula del profesional para modificarle el nombre en el archivo: ",161);
    fflush(stdin);
    scanf("%i",&matricula);

    FILE * archivo = fopen(ArchivoMedico,"rb");

    if (archivo != NULL)
    {
        Medico aux;

        while(!flag && fread(&aux, sizeof(Medico), 1, archivo) > 0)
        {
            if(aux.matricula == matricula)
            {
                flag = 1;
            }
        }
    }
    fclose(archivo);

    return matricula;
}


void modificarNombreMedico(int matricula, char nombre[])
{
    int flag = 0;

    FILE * archivo = fopen(ArchivoMedico, "r+b");

    if (archivo != NULL)
    {
        Medico aux;

        while (!flag && fread(&aux, sizeof(Medico), 1, archivo) > 0)
        {
            if (aux.matricula == matricula)
            {
                strcpy(aux.nombreApellido,nombre);

                fseek(archivo, sizeof(Medico) * (-1), SEEK_CUR);

                fwrite(&aux, sizeof(Medico), 1, archivo);

                flag = 1;

                fclose(archivo);
            }
        }
    }

    fclose(archivo);
}

int pasarArchivoMedicoAArreglo(Medico listado[], int dimension)
{
    int i = 0;

    FILE * archivo = fopen(ArchivoMedico,"rb");

    if (archivo != NULL)
    {
        Medico aux;

        while(fread(&aux, sizeof(Medico), 1, archivo) > 0 && i < dimension)
        {
            if (aux.eliminado == 0)
            {
                listado[i] = aux;

                i++;
            }
        }
    }
    fclose(archivo);

    return i;
}


void insertarMedicoMatricula(Medico listado[], Medico aux, int pos)
{
    int i = pos;

    while(i >= 0 && listado[i].matricula > aux.matricula)
    {
        listado[i + 1] = listado[i];

        i--;
    }

    listado[i + 1] = aux;
}

void ordenarMedicoMatricula(Medico listado[], int validos)
{
    int i = 0;

    while(i < validos - 1)
    {
        insertarMedicoMatricula(listado,listado[i+1],i);

        i++;
    }
}


void insertarMedicoEspecialidad(Medico listado[], Medico aux, int pos)
{
    int i = pos;

    while(i >= 0 && strcmpi(listado[i].especialidad,aux.especialidad) > 0)
    {
        listado[i + 1] = listado[i];

        i--;
    }

    listado[i + 1] = aux;
}

void ordenarMedicoEspecialidad(Medico listado[], int validos)
{
    int i = 0;

    while(i < validos - 1)
    {
        insertarMedicoEspecialidad(listado,listado[i+1],i);

        i++;
    }
}

void mostrarListadoMedico(Medico listado[], int validos)
{
    printf("\nListado de m%cdicos:\n\n",130);

    for (int i = 0; i < validos; i++)
    {
            mostrarMedico(listado[i]);
    }
}


void darDeAltaMedicoMismaEspecialidad(char especialidad[])
{
    FILE * archivo = fopen(ArchivoMedico,"ab");

    if (archivo != NULL)
    {
        Medico aux = registrarNuevoMedico(especialidad);

        fwrite(&aux, sizeof(Medico), 1, archivo);
    }
    fclose(archivo);
}

Medico registrarNuevoMedico(char especialidad[])
{
    Medico aux;

    strcpy(aux.especialidad,especialidad);

    aux.eliminado = 0;

    generadorTurnos(aux.listTurnos);

    printf("\nIngrese nombre del m%cdico: ",130);
    fflush(stdin);
    gets(aux.nombreApellido);

    printf("\n\nIngrese su matr%ccula: ",161);
    fflush(stdin);
    scanf("%i",&aux.matricula);

    return aux;
}


int pedirDiaParaAtender()
{
    int dia;

    printf("\nIngrese el d%ca para atender a los pacientes.\n",161);
    printf("(1- Lunes / 2- Martes / 3- Mi%crcoles / 4- Jueves / 5- Viernes / 6- S%cbado / 7-Domingo)",130,160);
    printf("\n\nOpci%cn: ",162);

    fflush(stdin);
    scanf("%i",&dia);

    while(dia < 1 && dia > 7)
    {
        printf("\nEl n%cmero ingresado no es v%clido. Vuelva a intentarlo: ",163,160);
        fflush(stdin);
        scanf("%i",&dia);
    }
    return dia;
}


int cantidadDeMedicos()
{
    int cantidad = 0;

    FILE * archivo = fopen(ArchivoMedico,"rb");

    if(archivo != NULL)
    {
        fseek(archivo,0,SEEK_END);

        cantidad = ftell(archivo) / sizeof(Medico);
    }
    fclose(archivo);

    return cantidad;
}
