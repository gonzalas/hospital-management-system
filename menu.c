#include "menu.h"
#include <stdio.h>
#include <stdlib.h>



void menuPrincipal()
{
    int opcion;

    do
    {
        printf("MEN%c PRINCIPAL\n\n",233);
        printf("Ingrese n%cmero de opci%cn:\n",163,162);
        printf("\n1. ABML.\n");
        printf("2. Turnos.\n");
        printf("3. Internaciones.\n\n");
        printf("0. Salir.\n\nOpci%cn: ",162);
        fflush(stdin);
        scanf("%i",&opcion);

        switch(opcion)
        {
            case 1: printf("\nHa elegido el sector ABML.\n\n");
                    system("pause");
                    system("cls");
                    abml();
                    system("cls");
                    break;

            case 2: printf("\nHa elegido el sector Turnos.\n\n");
                    system("pause");
                    system("cls");
                    turnos();
                    system("cls");
                    break;

            case 3: printf("\nHa elegido el sector Internaciones.\n\n");
                    system("pause");
                    system("cls");
                    internaciones();
                    system("cls");
                    break;

            case 0: system("cls");
                    printf("\n\t%c 2019, Lascar Gonzalo - Vera Nicol%cs, Trabajo Integrador UTN FRMDP.\n\n\n\n",184,160);
                    system("pause");
                    break;

            default: printf("\nLa opci%cn ingresada no es v%clida.\n\n",162,160);
                     system("pause");
                     system("cls");
        }

    } while(opcion != 0);
}

void subMenuAbml()
{
    printf("\nIngrese:\n\n");
    printf("1.Pacientes.\n");
    printf("2.M%cdicos.\n",130);
    printf("3.Habitaciones.\n");
    printf("0.Volver al men%c anterior.\n\nOpci%cn: ",163,162);
}

void abml()
{
    int opcion;

    do
    {
        subMenuAbml();

        fflush(stdin);
        scanf("%i",&opcion);

        switch(opcion)
        {
            case 1: printf("\nHa elegido Pacientes.\n\n");
                    system("pause");
                    system("cls");
                    pacientes();
                    break;

            case 2: printf("\nHa elegido M%cdicos.\n\n",130);
                    system("pause");
                    system("cls");
                    medicos();
                    break;

            case 3: printf("\nHa elegido Habitaciones.\n\n");
                    system("pause");
                    system("cls");
                    habitaciones();
                    break;

            case 0: ///salir del switch y volver al menú anterior.
                    system("cls");
                    break;

            default: printf("\nLa opci%cn ingresada no es v%clida.\n\n",162,160);
                     system("pause");
                     system("cls");
        }

    } while (opcion != 0);

}

void funcionesPacientes(){

    printf("\n\n 1.Cargar paciente. \n 2.Baja paciente. \n 3.Modificar paciente. \n 4.Mostrar listado. ");
    printf("\n 0.Volver a pantalla anterior.\n");

}

void pacientes()
{
    int opcion, dni;

    do
    {
        funcionesPacientes();   /// imprime las opciones de este menú

        printf("\n\n Elija una opci%cn: ",162);
        fflush(stdin);
        scanf("%i",&opcion);

        system("cls");

        switch(opcion)
        {
            case 1: printf("\nCargar paciente\n\n");
                    cargarPacienteArchivo();
                    system("pause");
                    system("cls");
                    break;

            case 2: printf("\nDar de baja a paciente\n");

                    printf("\n\n Ingrese DNI a buscar: ");
                    fflush(stdin);
                    scanf("%d" ,&dni);

                    bajaPaciente(dni);
                    system("pause");
                    system("cls");
                    break;

            case 3: printf("\nModificar informacion de paciente\n\n");
                    menuModificarPaciente();
                    system("pause");
                    system("cls");
                    break;

            case 4: printf("\nMostrar listado de pacientes\n\n");
                    menuListadoPacientes();
                    break;

            case 0: ///sale del switch y vuelve la pantalla anterior
                    system("cls");
                    break;

            default: printf("\nEl n%cmero ingresado no es v%clido.\n\n",163,160);
                     system("pause");
                     system("cls");
        }

    } while(opcion != 0);
}

void menuModificarPaciente(){

    int opcion = 0, documento = 0, validarPac = 0;

    printf("\n\n Ingrese documento del paciente: ");
    fflush(stdin);
    scanf("%d", &documento);

    validarPac = validarDocu ( documento );

    if ( validarPac == 0 ){

        do {

            printf("\n\n El documento ingresado no coincide. Intente otra vez");
            printf("\n\n Ingrese documento: ");
            fflush(stdin);
            scanf("%d" , documento );

            validarPac = validarDocu( documento );

        } while ( validarPac == 0);

    }

    do{
        printf("\n\n 1. Modificar nombre \n 2. Modificar edad \n 3. Modificar paciente entero \n 0. Salir ");

        printf("\n\n Elija una opci%cn:  ",162);
        fflush(stdin);
        scanf("%d" , &opcion );

        switch( opcion ){

            case 1: /// modificar nombre de paciente
                    modificarNombrePaciente(documento);
                    system("pause");
                    system("cls");
                    break;

            case 2: /// modificar edad de paciente
                    modificarEdadPaciente(documento);
                    puts("\n\n");
                    system("pause");
                    system("cls");
                    break;

            case 3: /// modificar paciente entero
                    modificarPacienteEntero(documento);
                    puts("\n\n");
                    system("pause");
                    system("cls");
                    break;

            case 0: /// Salir
                    system("cls");
                    break;

            default:
                    printf("\n\n Opci%cn inv%clida. Intente otra vez.\n\n",162,160);
                    system("pause");
                    system("cls");
                    break;

            }

    } while ( opcion != 0);

}

void menuListadoPacientes()
{
    int opcion = 0, documento = 0;

    do
    {
        printf("\n\n 1. Mostrar listado entero. \n 2. Consultar por dni. \n 3. Consultar por nombre. \n 0. Volver al men%c anterior. ",163);

        printf("\n\n Elija una opci%cn: ",162);
        fflush(stdin);
        scanf("%d",&opcion);

        system("cls");

        switch(opcion)
        {
            case 1: /// mostrar todo paciente
                    mostrarTodoPaciente();
                    puts("\n\n");
                    system("pause");
                    system("cls");
                    break;

            case 2: /// consultar paciente por dni
                    printf("\n\n Ingrese documento a buscar: ");
                    fflush(stdin);
                    scanf("%d", &documento);
                    mostrarPacienteDocu(documento);
                    puts("\n\n");
                    system("pause");
                    system("cls");
                    break;

            case 3: /// consultar paciente por nombre
                    mostrarPacienteNombre();
                    puts("\n\n");
                    system("pause");
                    system("cls");
                    break;

            case 0: /// vuelve a menu pacientes
                    system("cls");
                    break;

            default:
                    printf("\nEl n%cmero ingresado no es v%clido.\n\n",163,160);
                    system("pause");
                    system("cls");
        }

    } while(opcion != 0);
}


void subMenuMedicos()
{
    printf("M%cDICOS\n\n",144);
    printf("Ingrese n%cmero de opci%cn:\n",163,162);
    printf("\n1.Cargar m%cdico.\n",130);
    printf("2.Dar de baja m%cdico.\n",130);
    printf("3.Modificar informaci%cn de m%cdico.\n",162,130);
    printf("4.Mostrar listado de m%cdicos.\n",130);
    printf("\n0.Volver al men%c anterior.\n\nOpci%cn: ",163,162);
}

void medicos()
{
    int opcion, matricula, cantidad;
    char especialidad[30], nombre[50];

    do
    {
        subMenuMedicos();

        fflush(stdin);
        scanf("%i",&opcion);

        switch(opcion)
        {
            case 1: printf("\nCargar m%cdico\n\n",130);
                    cantidad = cantidadDeMedicos();
                    if (cantidad < 5)
                    {
                        guardarArchivoMedico();

                    } else if(cantidad >= 5)
                        {
                            printf("\nNo se puede seguir agregando m%cdicos. Ha llegado al tope de cinco profesionales.\n\n",130);
                        }
                    puts("\n\n");
                    system("pause");
                    system("cls");
                    break;

            case 2: printf("\nDar de baja a m%cdico\n\n",130);
                    printf("Ingrese la especialidad (sin tildes): ");
                    fflush(stdin);
                    gets(especialidad);
                    validarEspecialidad(especialidad);
                    puts("\n");
                    darDeBajaMedicoPorEspecialidad(especialidad);
                    printf("\nEl profesional de especialidad %s ha sido dado de baja del sistema.\n\n",especialidad);
                    printf("Deber%c dar de alta un m%cdico de la misma especialidad.\n\n",160,130);
                    darDeAltaMedicoMismaEspecialidad(especialidad);
                    puts("\n\n");
                    system("pause");
                    system("cls");
                    break;

            case 3: printf("\nModificar informaci%cn de m%cdico\n\n",162,130);
                    matricula = verificarMatricula();
                    if (matricula != 0)
                    {
                        pedirNuevoNombreMedico(nombre);
                        modificarNombreMedico(matricula,nombre);

                        printf("\nSe ha modificado el nombre del profesional de matr%ccula %i. Su nombre pas%c a ser: %s.\n\n",161,matricula,162,nombre);

                    } else

                        printf("\nNo se encontr%c la matr%cula introducida.\n\n",162,161);


                    system("pause");
                    system("cls");
                    break;

            case 4: printf("\nMostrar listado de m%cdicos\n\n",130);
                    system("pause");
                    system("cls");
                    menuListadoMedicos();
                    break;

            case 0: ///salir del switch y volver al menú anterior
                    system("cls");
                    break;

            default: printf("\nEl n%cmero ingresado no es v%clido.\n\n",163,160);
                     system("pause");
                     system("cls");
        }

    } while(opcion != 0);
}


void menuListadoMedicos()
{
    int opcion, matricula, validos;
    char especialidad[30];
    Medico listado[5];

    do
    {
        subMenuListadoMedicos();

        fflush(stdin);
        scanf("%i",&opcion);

        system("cls");

        switch(opcion)
        {
        case 1:
            printf("\nHa elegido mostrar listado de m%cdicos ordenado por matr%ccula.\n\n",130,161);
            validos = pasarArchivoMedicoAArreglo(listado,5);
            ordenarMedicoMatricula(listado,validos);
            mostrarListadoMedico(listado,validos);
            system("pause");
            system("cls");
            break;

        case 2:
            printf("\nHa elegido mostrar listado de m%cdicos ordenado por especialidad.\n\n",130);
            validos = pasarArchivoMedicoAArreglo(listado,5);
            ordenarMedicoEspecialidad(listado,validos);
            mostrarListadoMedico(listado,validos);
            system("pause");
            system("cls");
            break;

        case 3:
            printf("\nHa elegido buscar un m%cdico por matr%ccula.\n\n",130,161);
            matricula = pedirMatriculaMedicoParaBuscar();
            puts("\n\n");
            mostrarMedico(buscarMedicoMatricula(matricula));
            puts("\n\n");
            system("pause");
            system("cls");
            break;

        case 4:
            printf("\nHa elegido consultar un m%cdico por especialidad.\n\n",130);
            pedirEspecialidadMedicoParaBuscar(especialidad);
            puts("\n\n");
            mostrarMedico(buscarMedicoEspecialidad(especialidad));
            puts("\n\n");
            system("pause");
            system("cls");
            break;

        case 0:
            ///volver al menú anterior
            system("cls");
            break;

        default:
            printf("\nEl n%cmero ingresado no es v%clido.\n\n",163,162);
            system("pause");
            system("cls");
        }

    } while(opcion != 0);
}

void subMenuListadoMedicos()
{
    printf("\nMostrar listado de m%cdicos:\n\n",130);
    printf("Ingrese:\n\n");
    printf("1.Mostrar listado de m%cdicos ordenado por matr%ccula.\n\n",130,161);
    printf("2.Mostrar listado de m%cdicos ordenado por especialidad.\n\n",130);
    printf("3.Buscar y mostrar un m%cdico por matr%ccula.\n\n",130,161);
    printf("4.Buscar y mostrar un m%cdico por especialidad.\n\n",130);
    printf("0.Volver al men%c anterior.\n\nOpci%cn: ",163,162);
}

void habitaciones(){

    int opcion, piso = 0;

    char especialidad[30];

    do{
        printf("\n-Habitaciones-\n\nIngrese:\n\n 1.Muestra todas las habitaciones.\n 2.Habitaciones por piso.\n 3.Habitaciones libres por piso.\n 0.Volver atr%cs.",160);

        printf("\n\n Elija una opci%cn: ",162);
        fflush(stdin);
        scanf("%d", &opcion);

        comprobarNuevasHabitaciones();

        system("cls");

        switch(opcion)
        {
            case 1: /// Muestra todas las habitaciones
                    mostrarTodaHabit();
                    puts("\n\n");
                    system("pause");
                    system("cls");
                    break;

            case 2: /// Muestra habitaciones por piso
                    pedirEspecialidadAlUsuario(especialidad);
                    system("cls");
                    mostrarHabitPisos(especialidad);
                    break;

            case 3: /// Muestra habitaciones disponibles por piso
                    pedirEspecialidadAlUsuario(especialidad);
                    system("cls");
                    mostrarDispoPisos(especialidad);
                    puts("\n\n");
                    system("pause");
                    system("cls");
                    break;

            case 0: /// Vuelve al menu anterior
                    system("cls");
                    break;

            default:
                    printf("\nEl n%cmero ingresado no es v%clido.\n\n",163,160);
                    system("pause");
                    system("cls");
        }

    } while(opcion != 0);
}



void subMenuTurnos()
{
    printf("Turnos\n\n");
    printf("1.Dar turno.\n");
    printf("2.Atender paciente.\n");
    printf("3.Listado de turnos.\n\n");
    printf("0.Volver al men%c principal.\n\nOpci%cn: ",163,162);
}


void turnos()
{
    int opcion, dni, dia;
    char especialidad[30];

    do
    {
        subMenuTurnos();

        fflush(stdin);
        scanf("%i",&opcion);

        switch(opcion)
        {
            case 1: printf("\nHa elegido dar turno.\n\n");
                    system("pause");
                    system("cls");
                    dni = comprobarPacientePorDNI();
                    if(dni != 0)
                    {
                        printf("\nEl paciente se encuentra registrado.\n\n");

                        darTurno2(dni);

                    } else
                        {
                            printf("\nEl paciente ingresado no se encuentra registrado a%cn.\n\n",163);

                            dni = crearPaciente();

                            darTurno2(dni);
                        }
                    break;

            case 2: printf("\nHa elegido atender paciente.\n\n");
                    system("pause");
                    system("cls");
                    pedirEspecialidadAlUsuario(especialidad);
                    dia = pedirDiaParaAtender();
                    mostrarTurnosParaAtender(especialidad,dia);
                    subMenuParaAtender(especialidad);
                    system("pause");
                    system("cls");
                    break;

            case 3: printf("\nHa elegido mostrar listado de turnos por especialidad.\n\n");
                    pedirEspecialidadAlUsuario(especialidad);
                    system("pause");
                    system("cls");
                    menuListadoTurnos(especialidad);
                    break;

            case 0: //Volver atrás.
                    system("cls");
                    break;

            default: printf("\nLa opci%cn ingresada no es v%clida.\n\n",162,160);
                     system("pause");
                     system("cls");
        }

    } while (opcion != 0);

}

void subMenuParaAtender(char especialidad[])
{
    int cantidad = 0;

    int opcion = seleccionarTurnoPorEspecialidad(especialidad);

    int dni = pedirDniParaAtender();

    int validar = validarDocu(dni);

    if (validar == 0)
    {
        printf("\nEl DNI ingresado no tiene turnos para ser atendido.\n\n");

    } else
        {
        switch(opcion)
        {
        case 1:
            atenderPaciente2(TurnoGeriatria,dni);
            puts("\n\n");
            system("pause");
            puts("\n\n");
            internarPaciente(dni,especialidad,InternadosGeriatria);
            break;

        case 2:
            atenderPaciente2(TurnoClinica,dni);
            puts("\n\n");
            system("pause");
            puts("\n\n");
            internarPaciente(dni,especialidad,InternadosClinica);
            break;

        case 3:
            atenderPaciente2(TurnoPediatria,dni);
            puts("\n\n");
            system("pause");
            puts("\n\n");
            internarPaciente(dni,especialidad,InternadosPediatria);
            break;

        case 4:
            atenderPaciente2(TurnoTraumatologia,dni);
            puts("\n\n");
            system("pause");
            puts("\n\n");
            internarPaciente(dni,especialidad,InternadosTraumatologia);
            break;

        case 5:
            atenderPaciente2(TurnoToxicologia,dni);
            puts("\n\n");
            system("pause");
            puts("\n\n");
            internarPaciente(dni,especialidad,InternadosToxicologia);
            break;

        }
    }
}


void seleccionarArchivoPorEspecialidad(char especialidad[])
{
    int dni, posAtendido, opcion;
    Medico aux;

    opcion = seleccionarTurnoPorEspecialidad(especialidad);

    switch(opcion)
    {
        case 1: printf("\nTurnos del sector geriatr%ca\n\n",161);
                mostrarArchivoTurno(TurnoGeriatria);
                dni = pedirDniParaAtender();
                posAtendido = atenderPaciente(TurnoGeriatria,dni);
                aux = buscarMedicoEspecialidad(especialidad);
                modificarArregloTurno(aux.listTurnos,70,posAtendido);
                break;

        case 2: printf("\nTurnos del sector cl%cnica\n\n",161);
                mostrarArchivoTurno(TurnoClinica);
                dni = pedirDniParaAtender();
                posAtendido = atenderPaciente(TurnoClinica,dni);
                aux = buscarMedicoEspecialidad(especialidad);
                modificarArregloTurno(aux.listTurnos,70,posAtendido);
                break;

        case 3: printf("\nTurnos del sector pediatr%ca\n\n",161);
                mostrarArchivoTurno(TurnoPediatria);
                dni = pedirDniParaAtender();
                posAtendido = atenderPaciente(TurnoPediatria,dni);
                aux = buscarMedicoEspecialidad(especialidad);
                modificarArregloTurno(aux.listTurnos,70,posAtendido);
                break;

        case 4: printf("\nTurnos del sector traumatolog%ca\n\n",161);
                mostrarArchivoTurno(TurnoTraumatologia);
                dni = pedirDniParaAtender();
                posAtendido = atenderPaciente(TurnoTraumatologia,dni);
                aux = buscarMedicoEspecialidad(especialidad);
                modificarArregloTurno(aux.listTurnos,70,posAtendido);
                break;

        case 5: printf("\nTurnos del sector toxicolog%ca\n\n",161);
                mostrarArchivoTurno(TurnoToxicologia);
                dni = pedirDniParaAtender();
                posAtendido = atenderPaciente(TurnoToxicologia,dni);
                aux = buscarMedicoEspecialidad(especialidad);
                modificarArregloTurno(aux.listTurnos,70,posAtendido);
                break;

    }
    printf("\n\n");
    system("pause");
}

int pedirDniParaAtender()
{
    int dni;

    printf("\nIngrese el DNI del paciente que desea atender: ");
    fflush(stdin);
    scanf("%i",&dni);

    return dni;
}


void mostrarMenuEspecialidades()
{
    printf("\nElija especialidad:\n\n");
    printf("1.Planta Baja: Geriatr%ca.\n",161);
    printf("2.Primer Piso: Cl%cnica.\n",161);
    printf("3.Segundo Piso: Pediatr%ca.\n",161);
    printf("4.Tercer Piso: Traumatolog%ca.\n",161);
    printf("5.Cuarto Piso: Toxicolog%ca.\n\n",161);
    printf("0.Volver atr%cs.\n\n",160);
}

void darTurno2(int dni)
{
    int opcion;
    char especialidad[30], nombreMedico[30];
    Medico aux;

    Paciente paciente = buscarPacientePorDNI(dni);

    mostrarMenuEspecialidades();

    fflush(stdin);
    scanf("%i",&opcion);

    while(opcion < 0 || opcion > 5){

        printf("\nLa opci%cn ingresada no es v%clida. Vuelva a intentarlo: ",162,160);
        fflush(stdin);
        scanf("%i",&opcion);
    }

    system("cls");

    switch(opcion)
    {
    case 1:
        printf("\n- Turnos Geriatr%ca -\n\n",161);
        strcpy(especialidad,"geriatria");
        aux = buscarMedicoEspecialidad(especialidad);
        printf("\n\nEl profesional del %crea es el Dr. %s, Matr%ccula: %i.\n\n",160,aux.nombreApellido,161,aux.matricula);
        system("pause");
        system("cls");
        guardarTurnoArchivo2(TurnoGeriatria,dni);
        system("pause");
        system("cls");
        strcpy(nombreMedico,aux.nombreApellido);
        mostrarFichaDeTurno(TurnoGeriatria,dni,especialidad,nombreMedico,paciente);
        system("pause");
        system("cls");
        break;

    case 2:
        printf("\n- Turnos Cl%cnica - \n\n",161);
        strcpy(especialidad,"clinica");
        aux = buscarMedicoEspecialidad(especialidad);
        printf("\n\nEl profesional del %crea es el Dr. %s, Matr%ccula: %i.\n\n",160,aux.nombreApellido,161,aux.matricula);
        system("pause");
        system("cls");
        guardarTurnoArchivo2(TurnoClinica,dni);
        system("pause");
        system("cls");
        strcpy(nombreMedico,aux.nombreApellido);
        mostrarFichaDeTurno(TurnoClinica,dni,especialidad,nombreMedico,paciente);
        system("pause");
        system("cls");
        break;

    case 3:
        printf("\n- Turnos Pediatr%ca - \n\n",161);
        strcpy(especialidad,"pediatria");
        aux = buscarMedicoEspecialidad(especialidad);
        printf("\n\nEl profesional del %crea es el Dr. %s, Matr%ccula: %i.\n\n",160,aux.nombreApellido,161,aux.matricula);
        system("pause");
        system("cls");
        guardarTurnoArchivo2(TurnoPediatria,dni);
        system("pause");
        system("cls");
        strcpy(nombreMedico,aux.nombreApellido);
        mostrarFichaDeTurno(TurnoPediatria,dni,especialidad,nombreMedico,paciente);
        system("pause");
        system("cls");
        break;

    case 4:
        printf("\n- Turnos Traumatolog%ca - \n\n",161);
        strcpy(especialidad,"traumatologia");
        aux = buscarMedicoEspecialidad(especialidad);
        printf("\n\nEl profesional del %crea es el Dr. %s, Matr%ccula: %i.\n\n",160,aux.nombreApellido,161,aux.matricula);
        system("pause");
        system("cls");
        guardarTurnoArchivo2(TurnoTraumatologia,dni);
        system("pause");
        system("cls");
        strcpy(nombreMedico,aux.nombreApellido);
        mostrarFichaDeTurno(TurnoTraumatologia,dni,especialidad,nombreMedico,paciente);
        system("pause");
        system("cls");
        break;

    case 5:
        printf("\n- Turnos Toxicolog%ca - \n\n",161);
        strcpy(especialidad,"toxicologia");
        aux = buscarMedicoEspecialidad(especialidad);
        printf("\n\nEl profesional del %crea es el Dr. %s, Matr%ccula: %i.\n\n",160,aux.nombreApellido,161,aux.matricula);
        system("pause");
        system("cls");
        guardarTurnoArchivo2(TurnoToxicologia,dni);
        system("pause");
        system("cls");
        strcpy(nombreMedico,aux.nombreApellido);
        mostrarFichaDeTurno(TurnoToxicologia,dni,especialidad,nombreMedico,paciente);
        system("pause");
        system("cls");
        break;

    case 0:
        //volver menú atrás.
        system("cls");
        break;
    }


}



void darTurno(int dni)
{
    int opcion;
    char especialidad[30];
    Medico aux;

    mostrarMenuEspecialidades();

    fflush(stdin);
    scanf("%i",&opcion);

    while(opcion < 0 || opcion > 5){

        printf("\nLa opci%cn ingresada no es v%clida. Vuelva a intentarlo: ",162,160);
        fflush(stdin);
        scanf("%i",&opcion);
    }

    system("cls");

    switch(opcion)
    {
    case 1:
        printf("\n- Geriatr%ca - Turnos disponibles:\n\n",161);
        strcpy(especialidad,"geriatria");
        aux = buscarMedicoEspecialidad(especialidad);
        printf("\n\nEl profesional del %crea es el Dr. %s, Matr%ccula: %i.\n\n",160,aux.nombreApellido,161,aux.matricula);
        system("pause");
        system("cls");
        verTurnos(aux.listTurnos,0);
        guardarTurnoArchivo(aux.listTurnos,dni,TurnoGeriatria);
        puts("\n\n");
        system("pause");
        system("cls");
        break;

    case 2:
        printf("\n- Cl%cnica - Turnos disponibles:\n\n",161);
        strcpy(especialidad,"clinica");
        aux = buscarMedicoEspecialidad(especialidad);
        printf("\n\nEl profesional del %crea es el Dr. %s, Matr%ccula: %i.\n\n",160,aux.nombreApellido,161,aux.matricula);
        system("pause");
        system("cls");
        mostrarTurnosDisponible(TurnoClinica);
        //verTurnos(aux.listTurnos,0);
        guardarTurnoArchivo(aux.listTurnos,dni,TurnoClinica);
        puts("\n\n");
        system("pause");
        system("cls");
        break;

    case 3:
        printf("\n- Pediatr%ca - Turnos disponibles:\n\n",161);
        strcpy(especialidad,"pediatria");
        aux = buscarMedicoEspecialidad(especialidad);
        printf("\n\nEl profesional del %crea es el Dr. %s, Matr%ccula: %i.\n\n",160,aux.nombreApellido,161,aux.matricula);
        system("pause");
        system("cls");
        verTurnos(aux.listTurnos,0);
        guardarTurnoArchivo(aux.listTurnos,dni,TurnoPediatria);
        puts("\n\n");
        system("pause");
        system("cls");
        break;

    case 4:
        printf("\n- Traumatolog%ca - Turnos disponibles:\n\n",161);
        strcpy(especialidad,"traumatologia");
        aux = buscarMedicoEspecialidad(especialidad);
        printf("\n\nEl profesional del %crea es el Dr. %s, Matr%ccula: %i.\n\n",160,aux.nombreApellido,161,aux.matricula);
        system("pause");
        system("cls");
        verTurnos(aux.listTurnos,0);
        guardarTurnoArchivo(aux.listTurnos,dni,TurnoTraumatologia);
        puts("\n\n");
        system("pause");
        system("cls");
        break;

    case 5:
        printf("\n- Toxicolog%ca - Turnos disponibles:\n\n",161);
        strcpy(especialidad,"toxicologia");
        aux = buscarMedicoEspecialidad(especialidad);
        printf("\n\nEl profesional del %crea es el Dr. %s, Matr%ccula: %i.\n\n",160,aux.nombreApellido,161,aux.matricula);
        system("pause");
        system("cls");
        verTurnos(aux.listTurnos,0);
        guardarTurnoArchivo(aux.listTurnos,dni,TurnoToxicologia);
        puts("\n\n");
        system("pause");
        system("cls");
        break;

    case 0:
        //volver menú atrás.
        system("cls");
        break;
    }

}

void menuListadoTurnos(char especialidad[])
{
    int opcion;

    do
    {
        subMenuListadoTurnos(especialidad);

        fflush(stdin);
        scanf("%i",&opcion);

        system("cls");

        switch(opcion)
        {
            case 1: printf("\nVer listado de turnos de un d%ca concreto.\n\n",161);
                    int dia = pedirDiaParaVerTurnos();
                    verTurnosPorDia(dia);
                    puts("\n\n");
                    system("pause");
                    system("cls");
                    break;

            case 2: printf("\nVer listado de turnos ocupados de toda la semana.\n\n");
                    verTurnosPorEspecialidad(especialidad);
                    break;

            case 0: system("cls");
                    break;

            default: printf("\nLa opci%cn ingresada no es v%clida.\n\n",162,160);
                     system("pause");
                     system("cls");
        }

    } while (opcion != 0);

}

void subMenuListadoTurnos(char especialidad[])
{
    printf("Listado de turnos de la especialidad %s\n\n",especialidad);
    printf("1.Ver en un d%ca concreto.\n\n",161);
    printf("2.Ver turnos de toda la semana.\n\n");
    printf("0.Volver al men%c anterior.\n\nOpci%cn: ",163,162);
}


void internaciones()
{
    int opcion;
    char especialidad[30];

    do
    {
        subMenuInternaciones();

        fflush(stdin);
        scanf("%i",&opcion);

        system("cls");

        switch(opcion)
        {
            case 1: printf("\nHa elegido dar de alta a paciente.\n\n");
                    pedirEspecialidadAlUsuario(especialidad);
                    system("cls");
                    mostrarOcupadasPisos(especialidad);
                    menuAltaPaciente(especialidad);
                    break;

            case 2: printf("\nHa elegido ver pacientes internados.\n\n");
                    menuPacientesInternados();
                    break;

            case 0: ///salir del switch y volver atrás
                    system("cls");
                    break;

            default: printf("\nLa opci%cn ingresada no es v%clida.\n\n",162,160);
                     system("pause");
                     system("cls");
        }

    } while (opcion != 0);

}

void subMenuInternaciones()
{
    printf("INTERNACIONES\n\n");
    printf("Ingrese:\n\n");
    printf("1.Dar de alta paciente.\n");
    printf("2.Ver pacientes internados.\n");
    printf("0.Volver atr%cs.\n\nOpci%cn: ",160,162);
}

void menuAltaPaciente(char especialidad[])
{
    int opcion;

    do
    {
        subMenuDarAlta();

        fflush(stdin);
        scanf("%i",&opcion);

        system("cls");

        switch(opcion)
        {
            case 1: printf("\nDar de alta a paciente por DNI.\n\n");
                    darDeAltaPacientePorDNI(especialidad);
                    break;

            case 2: printf("\nDar de alta a paciente por n%cmero de habitaci%cn.\n\n",163,162);
                    darDeAltaPacientePorNumHabitacion(especialidad);
                    break;

            case 0: system("cls");
                    break;

            default: printf("\nLa opci%cn ingresada no es v%clida.\n\n",162,160);
                     system("pause");
                     system("cls");
        }

    } while (opcion != 0);

}

void subMenuDarAlta()
{
    printf("\nDar de alta a paciente:\n\n");
    printf("1.Por DNI.\n");
    printf("2.Por n%cmero de habitaci%cn.\n",163,162);
    printf("0.Volver atr%cs.\n\nOpci%cn: ",160,162);
}


void menuPacientesInternados()
{
    int opcion;

    do
    {
        subMenuPacientesInternados();

        fflush(stdin);
        scanf("%i",&opcion);

        system("cls");

        switch(opcion)
        {
            case 1: printf("\nMostrar listado de pacientes internados.\n\n");
                    mostrarListadoPacientesInternados();
                    break;

            case 2: printf("\nMostrar listado de pacientes en espera por especialidad.\n\n");
                    mostrarPacienteEnEspera();
                    break;

            case 0: system("cls");
                    break;

            default: printf("\nLa opci%cn ingresada no es v%clida.\n\n");
                     system("pause");
                     system("cls");
        }

    } while (opcion != 0);

}

void subMenuPacientesInternados()
{
    printf("\n- Listado de pacientes internados -\n\n");
    printf("Ingrese:\n\n");
    printf("1.Mostrar pacientes internados.\n");
    printf("2.Mostrar pacientes en espera.\n");
    printf("0.Volver atr%cs.\n\nOpci%cn: ",160,162);
}




