#include "habitaciones.h"
#include "paciente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "medico.h"
#include "turno.h"

#define pisos 5
#define habitaciones 10


void comprobarNuevasHabitaciones()
{
    FILE * archi = fopen(archivoHabitaciones, "rb");

    if(archi == NULL)
    {
        fclose(archi);

        cargarNuevasHabitaciones();
    }

    fclose(archi);
}

void cargarNuevasHabitaciones(){

    FILE *archi = fopen(archivoHabitaciones , "wb");

    Habitacion matriz [5][10];

    if ( archi != NULL ){

        for (int i = 0; i < pisos; i++){

                for (int j = 0; j < habitaciones; j++){

                    int num = j+1;

                    matriz[i][j].nroHabitacion = num;

                    matriz[i][j].ocupado = 0;

                    matriz[i][j].dniPaciente = 0;

                    fwrite(&matriz, sizeof(Habitacion), 1, archi);
                }
            }
    }

    fclose(archi);

}

void mostrarHabitacion(Habitacion h){

    printf("\n\n Habitacion: %d ", h.nroHabitacion);

    if ( h.ocupado == 1 ){

        printf("\n\n DNI paciente: %d ", h.dniPaciente);

    }
}

void internarPaciente(int dni, char especialidad[], char ArchivoInternados[])
{
    char opcion;
    int num;

    int cantidad = contarHabitacionesInternacionOcupadas(ArchivoInternados);

    printf("\n%cDesea internar al paciente? (s/n): ",168);
    fflush(stdin);
    scanf("%c",&opcion);

    system("cls");

    if (cantidad < 10 && opcion == 's')
    {

        mostrarDispoPisos(especialidad);

        printf("\n\nIngrese el n%cmero de habitaci%cn donde ser%c internado: ",163,162,160);
        fflush(stdin);
        scanf("%i",&num);

        puts("\n\n");

        FILE * archivo = fopen(ArchivoInternados,"ab");

        if(archivo != NULL)
        {
            Habitacion aux;

            aux.dniPaciente = dni;

            aux.ocupado = 1;

            aux.nroHabitacion = num;

            fwrite(&aux, sizeof(Habitacion), 1, archivo);
        }

        fclose(archivo);

        modificarArchivoHabitacionesAOcupado(ArchivoInternados,dni,especialidad);

    } else

        if (opcion == 's' && cantidad >= 10)
        {
            printf("\nNo hay habitaciones disponibles. Todas est%cn llenas.\n\n",160);
            printf("El paciente ser%c puesto en una lista de espera.\n\n",160);

            listaDeEspera(dni,especialidad);
        }
}

void listaDeEspera(int dni, char especialidad[])
{
    int opcion = seleccionarTurnoPorEspecialidad(especialidad);

    switch(opcion)
    {
    case 1:
        pasarPacienteAListaDeEsperaInternacion(dni,EnEsperaGeriatria);
        break;

    case 2:
        pasarPacienteAListaDeEsperaInternacion(dni,EnEsperaClinica);
        break;

    case 3:
        pasarPacienteAListaDeEsperaInternacion(dni,EnEsperaPediatria);
        break;

    case 4:
        pasarPacienteAListaDeEsperaInternacion(dni,EnEsperaTraumatologia);
        break;

    case 5:
        pasarPacienteAListaDeEsperaInternacion(dni,EnEsperaToxicologia);
        break;

    }
}

void mostrarTodaHabit (){

    FILE *archi = fopen(archivoHabitaciones, "rb");

    Habitacion aux;

    int i = 0;

    if ( archi != NULL ){

        while ( fread( &aux, sizeof(aux), 1 , archi) > 0 ){

            especialidades( i );

            //printf("\n\n Habitacion: %d", i+1);

            mostrarHabitacion(aux);

            i++;
        }

    } else {

        printf("\n\n No se pudo abrir el archivo. ");

    }

    fclose(archi);
}

void especialidades(int i){

    if ( i == 0 )

                printf("\n\n----------------------------\n\n\n Primer piso: Geriatria. ");

    if ( i == 10 )

                printf("\n\n----------------------------\n\n\n Segundo piso: Clinica. ");

    if ( i == 20 )

                printf("\n\n----------------------------\n\n\n Tercer piso: Pediatria. ");

    if ( i == 30 )

                printf("\n\n----------------------------\n\n\n Cuarto piso: Traumatologia. ");

    if ( i == 40 )

                printf("\n\n----------------------------\n\n\n Quinto piso: Toxicologia. ");
}

void mostrarHabitPisos (char especialidad[]){

    FILE *archi = fopen(archivoHabitaciones, "rb");

    Habitacion aux;

    int i = 0, opcion = 0;

    opcion = seleccionarTurnoPorEspecialidad(especialidad);

    if ( archi != NULL ){

        switch (opcion){

            case 1: /// primer piso
                    printf("\n\n Mostrando Geriatr%ca:\n\n",161);
                    fseek(archi,0,SEEK_SET);
                    while (fread(&aux, sizeof(Habitacion), 1 , archi) > 0 && i < 10){
                        mostrarEspecialidad(aux);
                        i++;
                    }
                    puts("\n\n");
                    system("pause");
                    system("cls");
                    break;

            case 2: /// segundo piso
                    printf("\n\n Mostrando Cl%cnica:\n\n",161);
                    fseek(archi,0,SEEK_SET);
                    while ( fread(&aux, sizeof(Habitacion), 1 , archi) > 0 && i < 20){
                        if ( i >= 10 ){
                            mostrarEspecialidad(aux);
                            i++;
                        } else {
                            i++;
                        }
                    }
                    puts("\n\n");
                    system("pause");
                    system("cls");
                    break;

            case 3: /// tercer piso
                    printf("\n\n Mostrando Pediatr%ca:\n\n",161);
                    fseek(archi,0,SEEK_SET);
                    while ( fread(&aux, sizeof(Habitacion), 1, archi) > 0 && i < 30){
                        if ( i >= 20 ){
                            mostrarEspecialidad(aux);
                            i++;
                        } else {
                            i++;
                        }
                    }
                    puts("\n\n");
                    system("pause");
                    system("cls");
                    break;

            case 4: /// cuarto piso
                    printf("\n\n Mostrando Traumatolog%ca:\n\n",161);
                    fseek(archi,0,SEEK_SET);
                    while ( fread(&aux, sizeof(Habitacion), 1 , archi) > 0 && i < 40){
                        if ( i >= 30 ){
                            mostrarEspecialidad(aux);
                            i++;
                        } else {
                            i++;
                        }
                    }
                    puts("\n\n");
                    system("pause");
                    system("cls");
                    break;

            case 5: /// quinto piso
                    printf("\n\n Mostrando Toxicolog%ca:\n\n",161);
                    fseek(archi,0,SEEK_SET);
                    while ( fread(&aux, sizeof(Habitacion), 1, archi) > 0 && i <50){
                        if ( i >= 40 ){
                            mostrarEspecialidad(aux);
                            i++;
                        } else {
                            i++;
                        }
                    }
                    puts("\n\n");
                    system("pause");
                    system("cls");
                    break;
            }

    } else {

        printf("\n\n No se pudo abrir el archivo. ");

    }

    fclose(archi);
}



void mostrarEspecialidad(Habitacion aux){

    printf("\n\n Habitacion: %d" , aux.nroHabitacion);

}


void mostrarDispoPisos ( char especialidad[]){

    FILE *archi = fopen(archivoHabitaciones, "rb");

    Habitacion aux;

    int i = 0, opcion = 0;

    opcion = seleccionarTurnoPorEspecialidad(especialidad);

    if ( archi != NULL ){

            printf("\n- HABITACIONES DISPONIBLES -");

        switch (opcion){

            case 1: /// primer piso
                    printf("\n\n Mostrando Geriatria");
                    fseek(archi,0,SEEK_SET);
                    while (fread(&aux, sizeof(aux), 1 , archi) > 0 && i < 10){
                        mostrarHabitacionesDispo(aux);
                        i++;
                    }
                    break;

            case 2: /// segundo piso
                    printf("\n\n Mostrando Clinica");
                    fseek(archi,0,SEEK_SET);
                    while ( fread(&aux, sizeof(aux), 1 , archi) > 0 && i < 20){
                        if ( i >= 10 ){
                            mostrarHabitacionesDispo(aux);
                            i++;
                        } else {
                            i++;
                        }
                    }
                    break;

            case 3: /// tercer piso
                    printf("\n\n Mostrando Pediatria");
                    fseek(archi,0,SEEK_SET);
                    while ( fread(&aux, sizeof(aux), 1, archi) > 0 && i < 30){
                        if ( i >= 20 ){
                            mostrarHabitacionesDispo(aux);
                            i++;
                        } else {
                            i++;
                        }
                    }
                    break;

            case 4: /// cuarto piso
                    printf("\n\n Mostrando Traumatologia");
                    fseek(archi,0,SEEK_SET);
                    while ( fread(&aux, sizeof(aux), 1 , archi) > 0 && i < 40){
                        if ( i >= 30){
                            mostrarHabitacionesDispo(aux);
                            i++;
                        } else {
                            i++;
                        }
                    }
                    break;

            case 5: /// quinto piso
                    printf("\n\n Mostrando Toxicologia");
                    fseek(archi,0,SEEK_SET);
                    while ( fread(&aux, sizeof(aux), 1, archi) > 0 && i <50){
                        if ( i >= 40 ){
                            mostrarHabitacionesDispo(aux);
                            i++;
                        } else {
                            i++;
                        }
                    }
                    break;
            }

    } else {

        printf("\n\n No se pudo abrir el archivo. ");

    }

    fclose(archi);
}

void mostrarHabitacionesDispo ( Habitacion aux ){

    if ( aux.ocupado == 0 ){

        printf("\n\n Habitaci%cn: %d ", 162, aux.nroHabitacion);

    }

}

void darDeAltaPacientePorNumHabitacion(char especialidad[])
{
    int exito;

    int opcion = seleccionarTurnoPorEspecialidad(especialidad);

    mostrarOcupadasPisos(especialidad);

    switch(opcion)
    {
    case 1:
        exito = darDeAltaPorEspecialidad(InternadosGeriatria);

        if(exito == 1)
        {
            printf("\nEl paciente ha sido dado de alta exitosamente.\n\n");

        } else

            printf("\nNo se encontr%c n%cmero de habitaci%cn.\n\n",162,163,162);

        puts("\n\n");
        system("pause");
        system("cls");
        break;

    case 2:
        exito = darDeAltaPorEspecialidad(InternadosClinica);

        if(exito == 1)
        {
            printf("\nEl paciente ha sido dado de alta exitosamente.\n\n");

        } else

            printf("\nNo se encontr%c n%cmero de habitaci%cn.\n\n",162,163,162);

        puts("\n\n");
        system("pause");
        system("cls");
        break;

    case 3:
        exito = darDeAltaPorEspecialidad(InternadosPediatria);

        if(exito == 1)
        {
            printf("\nEl paciente ha sido dado de alta exitosamente.\n\n");

        } else

            printf("\nNo se encontr%c n%cmero de habitaci%cn.\n\n",162,163,162);

        puts("\n\n");
        system("pause");
        system("cls");
        break;

    case 4:
        exito = darDeAltaPorEspecialidad(InternadosTraumatologia);

        if(exito == 1)
        {
            printf("\nEl paciente ha sido dado de alta exitosamente.\n\n");

        } else

            printf("\nNo se encontr%c n%cmero de habitaci%cn.\n\n",162,163,162);

        puts("\n\n");
        system("pause");
        system("cls");
        break;

    case 5:
        exito = darDeAltaPorEspecialidad(InternadosToxicologia);

        if(exito == 1)
        {
            printf("\nEl paciente ha sido dado de alta exitosamente.\n\n");

        } else

            printf("\nNo se encontr%c n%cmero de habitaci%cn.\n\n",162,163,162);

        puts("\n\n");
        system("pause");
        system("cls");
        break;

    }

}

int darDeAltaPorEspecialidad(char ArchivoInternado[])
{
    int flag = 0, num;

    printf("\nIngrese el n%cmero de habitaci%cn para dar de alta al paciente: ",163,162);
    fflush(stdin);
    scanf("%i",&num);

    FILE * archivo = fopen(ArchivoInternado,"r+b");

    if(archivo != NULL)
    {
        Habitacion aux;

        while(!flag && fread(&aux, sizeof(Habitacion), 1, archivo) > 0)
        {
            if(aux.nroHabitacion == num && aux.ocupado == 1)
            {
                flag = 1;

                aux.ocupado = 0;

                fseek(archivo, sizeof(Habitacion) * (-1), SEEK_CUR);

                fwrite(&aux, sizeof(Habitacion), 1, archivo);

                fclose(archivo);
            }
        }
    }

    fclose(archivo);

    return flag;
}

void darDeAltaPacientePorDNI(char especialidad[])
{
    int exito;

    int dni = pedirDniParaDarDeAlta();

    int opcion = seleccionarTurnoPorEspecialidad(especialidad);

    switch(opcion)
    {
    case 1:
        exito = darDeAltaPorDni(InternadosGeriatria,dni);

        if(exito == 1)
        {
            printf("\nEl paciente ha sido dado de alta exitosamente.\n\n");

        } else

            printf("\nNo se encontr%c paciente internado.\n\n",162);

        modificarArchivoHabitacionesADisponible(dni);

        puts("\n\n");
        system("pause");
        system("cls");
        break;

    case 2:
        exito = darDeAltaPorDni(InternadosClinica,dni);

        if(exito == 1)
        {
            printf("\nEl paciente ha sido dado de alta exitosamente.\n\n");

        } else

            printf("\nNo se encontr%c paciente internado.\n\n",162);

        modificarArchivoHabitacionesADisponible(dni);

        puts("\n\n");
        system("pause");
        system("cls");
        break;

    case 3:
        exito = darDeAltaPorDni(InternadosPediatria,dni);

        if(exito == 1)
        {
            printf("\nEl paciente ha sido dado de alta exitosamente.\n\n");

        } else

            printf("\nNo se encontr%c paciente internado.\n\n",162);

        modificarArchivoHabitacionesADisponible(dni);

        puts("\n\n");
        system("pause");
        system("cls");
        break;

    case 4:
        exito = darDeAltaPorDni(InternadosTraumatologia,dni);

        if(exito == 1)
        {
            printf("\nEl paciente ha sido dado de alta exitosamente.\n\n");

        } else

            printf("\nNo se encontr%c paciente internado.\n\n",162);

        modificarArchivoHabitacionesADisponible(dni);

        puts("\n\n");
        system("pause");
        system("cls");
        break;

    case 5:
        exito = darDeAltaPorDni(InternadosToxicologia,dni);

        if(exito == 1)
        {
            printf("\nEl paciente ha sido dado de alta exitosamente.\n\n");

        } else

            printf("\nNo se encontr%c paciente internado.\n\n",162);

        modificarArchivoHabitacionesADisponible(dni);

        puts("\n\n");
        system("pause");
        system("cls");
        break;

    }
}


int pedirDniParaDarDeAlta()
{
    int dni;

    printf("\nIngrese el DNI del paciente que desea dar de alta: ");
    fflush(stdin);
    scanf("%i",&dni);

    return dni;
}

int darDeAltaPorDni(char ArchivoInternado[], int dni)
{
    int flag = 0;

    FILE * archivo = fopen(ArchivoInternado,"r+b");

    if(archivo != NULL)
    {
        Habitacion aux;

        while(!flag && fread(&aux, sizeof(Habitacion), 1, archivo) > 0)
        {
            if(aux.dniPaciente == dni)
            {
                aux.ocupado = 0;

                flag = 1;

                fseek(archivo, sizeof(Habitacion) * (-1), SEEK_CUR);

                fwrite(&aux, sizeof(Habitacion), 1, archivo);
            }
        }
    }

    fclose(archivo);

    return flag;
}


void mostrarHabitacionesOcupadas(Habitacion aux)
{

    if ( aux.ocupado == 1 ){

        printf("\n\n Habitaci%cn: %d ", 162, aux.nroHabitacion);

        printf("\n\n DNI Paciente: %d ", aux.dniPaciente);

        printf("\n-----------------------------\n");

    }
}

void mostrarOcupadasPisos(char especialidad[])
{

    FILE *archi = fopen(archivoHabitaciones, "rb");

    Habitacion aux;

    int i = 0;

    int opcion = seleccionarTurnoPorEspecialidad(especialidad);

    int moverse = (opcion - 1) * 10;

    if ( archi != NULL ){

        printf("\n- HABITACIONES OCUPADAS -");

        switch (opcion){

            case 1: /// primer piso
                    printf("\n\n Mostrando Geriatr%ca:\n\n",161);
                    fseek(archi, sizeof(Habitacion) * moverse, SEEK_SET);
                    while (fread(&aux, sizeof(aux), 1 , archi) > 0 && i < 10){
                        mostrarHabitacionesOcupadas(aux);
                        i++;
                    }
                    puts("\n\n");
                    system("pause");
                    system("cls");
                    break;

            case 2: /// segundo piso
                    printf("\n\n Mostrando Cl%cnica:\n\n",161);
                    fseek(archi, sizeof(Habitacion) * moverse, SEEK_SET);
                    while ( fread(&aux, sizeof(aux), 1 , archi) > 0 && i < 10){
                            mostrarHabitacionesOcupadas(aux);
                            i++;
                    }
                    puts("\n\n");
                    system("pause");
                    system("cls");
                    break;

            case 3: /// tercer piso
                    printf("\n\n Mostrando Pediatr%ca:\n\n",161);
                    fseek(archi, sizeof(Habitacion) * moverse, SEEK_SET);
                    while ( fread(&aux, sizeof(aux), 1, archi) > 0 && i < 10){
                            mostrarHabitacionesOcupadas(aux);
                            i++;
                    }
                    puts("\n\n");
                    system("pause");
                    system("cls");
                    break;

            case 4: /// cuarto piso
                    printf("\n\n Mostrando Traumatolog%ca:\n\n",161);
                    fseek(archi, sizeof(Habitacion) * moverse, SEEK_SET);
                    while ( fread(&aux, sizeof(aux), 1 , archi) > 0 && i < 10){
                            mostrarHabitacionesOcupadas(aux);
                            i++;
                    }
                    puts("\n\n");
                    system("pause");
                    system("cls");
                    break;

            case 5: /// quinto piso
                    printf("\n\n Mostrando Toxicolog%ca:\n\n",161);
                    fseek(archi, sizeof(Habitacion) * moverse, SEEK_SET);
                    while ( fread(&aux, sizeof(aux), 1, archi) > 0 && i < 10){
                            mostrarHabitacionesOcupadas(aux);
                            i++;
                    }
                    puts("\n\n");
                    system("pause");
                    system("cls");
                    break;
            }

    } else {

        printf("\n\n No se pudo abrir el archivo. ");

    }

    fclose(archi);
}


void mostrarPacientesInternados(char ArchivoInternados[], char especialidad[])
{
    FILE * archivo = fopen(ArchivoInternados,"rb");

    if(archivo != NULL)
    {
        Habitacion aux;

        while(fread(&aux, sizeof(Habitacion), 1, archivo) > 0)
        {
            if(aux.ocupado == 1)
            {
                mostrarPacienteInternado(aux,especialidad);
            }
        }
    }

    fclose(archivo);
}

void mostrarPacienteInternado(Habitacion aux, char especialidad[])
{
    Paciente paciente = buscarPacientePorDNI(aux.dniPaciente);

    printf("\n------------------\nPaciente internado\n------------------\n\n");
    printf("Nombre: %s\n",paciente.nombreApellido);
    printf("Edad: %i\n",paciente.edad);
    printf("Habitaci%cn: %i\n",162,aux.nroHabitacion);
    printf("Especialidad: %s\n\n",especialidad);
}

void mostrarListadoPacientesInternados()
{
    char especialidad[30];

    pedirEspecialidadAlUsuario(especialidad);

    system("cls");

    int opcion = seleccionarTurnoPorEspecialidad(especialidad);

    switch(opcion)
    {
    case 1:
        printf("\n- Internados en Geriatr%ca -\n\n",161);
        mostrarPacientesInternados(InternadosGeriatria,especialidad);
        puts("\n\n");
        system("pause");
        system("cls");
        break;

    case 2:
        printf("\n- Internados en Cl%cnica -\n\n",161);
        mostrarPacientesInternados(InternadosClinica,especialidad);
        puts("\n\n");
        system("pause");
        system("cls");
        break;

    case 3:
        printf("\n- Internados en Pediatr%ca -\n\n",161);
        mostrarPacientesInternados(InternadosPediatria,especialidad);
        puts("\n\n");
        system("pause");
        system("cls");
        break;

    case 4:
        printf("\n- Internados en Traumatolog%ca -\n\n",161);
        mostrarPacientesInternados(InternadosTraumatologia,especialidad);
        puts("\n\n");
        system("pause");
        system("cls");
        break;

    case 5:
        printf("\n- Internados en Toxicolog%ca -\n\n",161);
        mostrarPacientesInternados(InternadosToxicologia,especialidad);
        puts("\n\n");
        system("pause");
        system("cls");
        break;

    }
}


void pasarPacienteAListaDeEsperaInternacion(int dni, char EnEsperaInternacion[])
{
    FILE * archivo = fopen(EnEsperaInternacion,"ab");

    if(archivo != NULL)
    {
        Habitacion aux;

        aux.dniPaciente = dni;

        aux.nroHabitacion = 0;

        aux.ocupado = 0;

        fwrite(&aux, sizeof(Habitacion), 1, archivo);
    }

    fclose(archivo);
}

int contarHabitacionesInternacionOcupadas(char ArchivoInternados[])
{
    int cantidad = 0;

    FILE * archivo = fopen(ArchivoInternados,"rb");

    if(archivo != NULL)
    {
        Habitacion aux;

        while(fread(&aux, sizeof(Habitacion), 1, archivo) > 0)
        {
            if(aux.ocupado == 1)
            {
                fseek(archivo, 0, SEEK_END);

                cantidad += ftell(archivo) / sizeof(Habitacion);
            }
        }
    }

    fclose(archivo);

    return cantidad;
}


void mostrarPacientesListaDeEspera(char EnEspera[], char especialidad[])
{
    FILE * archivo = fopen(EnEspera,"rb");

    if(archivo != NULL)
    {
        Habitacion aux;

        printf("\nPacientes en lista de espera de la especialidad %s\n\n",especialidad);

        while(fread(&aux, sizeof(Habitacion), 1, archivo) > 0)
        {
            if(aux.ocupado == 1)
            {
                mostrarPacienteInternado(aux,especialidad);
            }
        }
    }

    fclose(archivo);
}

void mostrarPacienteEnEspera()
{
    char especialidad[30];

    pedirEspecialidadAlUsuario(especialidad);

    int opcion = seleccionarTurnoPorEspecialidad(especialidad);

    switch(opcion)
    {
    case 1:
        mostrarPacientesListaDeEspera(EnEsperaGeriatria,especialidad);
        puts("\n\n");
        system("pause");
        system("cls");
        break;

    case 2:
        mostrarPacientesListaDeEspera(EnEsperaGeriatria,especialidad);
        puts("\n\n");
        system("pause");
        system("cls");
        break;

    case 3:
        mostrarPacientesListaDeEspera(EnEsperaGeriatria,especialidad);
        puts("\n\n");
        system("pause");
        system("cls");
        break;

    case 4:
        mostrarPacientesListaDeEspera(EnEsperaGeriatria,especialidad);
        puts("\n\n");
        system("pause");
        system("cls");
        break;

    case 5:
        mostrarPacientesListaDeEspera(EnEsperaGeriatria,especialidad);
        puts("\n\n");
        system("pause");
        system("cls");
        break;

    }
}

void modificarArchivoHabitacionesAOcupado(char ArchivoInternados[], int dni, char especialidad[])
{
    int numHabitacion, flag = 0;

    int opcion = seleccionarTurnoPorEspecialidad(especialidad);

    int moverse = (opcion - 1) * 10;

    FILE * archivo = fopen(ArchivoInternados,"rb");

    if(archivo != NULL)
    {
        Habitacion aux;

        while(!flag && fread(&aux, sizeof(Habitacion), 1, archivo) > 0)
        {
            if(aux.dniPaciente == dni && aux.ocupado == 1)
            {
                numHabitacion = aux.nroHabitacion;

                flag = 1;
            }
        }
    }

    fclose(archivo);

    flag = 0;

    FILE * archi = fopen(archivoHabitaciones,"r+b");

    if(archi != NULL)
    {
        Habitacion aux;

        fseek(archi, sizeof(Habitacion) * moverse, SEEK_SET);

        while(!flag && fread(&aux, sizeof(Habitacion), 1, archi) > 0)
        {
            if(aux.nroHabitacion == numHabitacion)
            {
                aux.ocupado = 1;

                aux.dniPaciente = dni;

                fseek(archi, sizeof(Habitacion) * (-1), SEEK_CUR);

                fwrite(&aux, sizeof(Habitacion), 1, archi);

                flag = 1;

                fclose(archi);
            }
        }
    }

    fclose(archi);
}


void modificarArchivoHabitacionesADisponible(int dni)
{
    int flag = 0;

    FILE * archivo = fopen(archivoHabitaciones,"r+b");

    if(archivo != NULL)
    {
        Habitacion aux;

        while(!flag && fread(&aux, sizeof(Habitacion), 1, archivo) > 0)
        {
            if(aux.dniPaciente == dni && aux.ocupado == 1)
            {
                flag = 1;

                aux.ocupado = 0;

                fseek(archivo, sizeof(Habitacion) * (-1), SEEK_CUR);

                fwrite(&aux, sizeof(Habitacion), 1, archivo);

                fclose(archivo);
            }
        }
    }

    fclose(archivo);
}
