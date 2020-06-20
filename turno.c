#include <stdio.h>
#include "turno.h"
#include "medico.h"


Turno cargarTurno2(int dni, char ArchivoTurno[])
{
    Turno aux;

    int horario;

    aux.dniPaciente = dni;

    printf("\n\nSolicitud de turno para paciente de DNI: %i\n\n",aux.dniPaciente);

    printf("\n\nIngrese el n%cmero que corresponde al d%ca de la semana.\n",163,161);
    printf("(1- Lunes / 2- Martes / 3- Mi%crcoles / 4- Jueves / 5- Viernes / 6- S%cbado / 7-Domingo)",130,160);
    printf("\n\nOpci%cn: ",162);
    fflush(stdin);
    scanf("%i", &aux.dia);

    aux.dia = validarDia(aux);

    printf("\nIngrese el horario para el turno. ");
    printf("\n8.00 | 9.00 | 10.00 | 11.00 | 12.00 | 13.00 | 14.00 | 15.00 | 16.00 | 17.00 | 18.00\n\nHorario: ");
    fflush(stdin);
    scanf("%f", &aux.horario);

    do
    {
        horario = verificarHorarioTurno(aux,ArchivoTurno);

        if (horario == 1)
        {
            printf("\nEse horario ya est%c ocupado. Intente nuevamente: ",160);
        }

    } while(horario == 1);

    puts("\n\n");

    aux.ocupado = 1;

    return aux;
}

int verificarHorarioTurno(Turno aux, char ArchivoTurno[])
{
    int flag = 0;

    FILE * archivo = fopen(ArchivoTurno, "rb");

    if (archivo != NULL)
    {
        Turno verifica;

        while(!flag && fread(&verifica, sizeof(Turno), 1, archivo) > 0)
        {
            if(verifica.dia == aux.dia && verifica.horario == aux.horario && verifica.ocupado == 1)
            {
                flag = 1;
            }
        }
    }
    fclose(archivo);

    return flag;
}

void guardarTurnoArchivo2(char ArchivoTurno[], int dni)
{
    FILE * archivo = fopen(ArchivoTurno, "ab");

    if (archivo != NULL)
    {
        Turno aux = cargarTurno2(dni,ArchivoTurno);

        fwrite(&aux, sizeof(Turno), 1, archivo);
    }

    fclose(archivo);
}

Turno cargarTurno(Turno t[], int dni)
{
    Turno aux;

    aux.dniPaciente = dni;

    printf("\n\nSolicitud de turno para paciente de DNI: %i\n\n",aux.dniPaciente);

    printf("\n\nIngrese el n%cmero que corresponde al d%ca de la semana.\n",163,161);
    printf("(1- Lunes / 2- Martes / 3- Mi%crcoles / 4- Jueves / 5- Viernes / 6- S%cbado / 7-Domingo)",130,160);
    printf("\n\nOpci%cn: ",162);
    fflush(stdin);
    scanf("%i", &aux.dia);

    aux.dia = validarDia(aux);

    printf("\nIngrese el horario para el turno: ");
    fflush(stdin);
    scanf("%f", &aux.horario);

    aux.ocupado = validarHorario(t,aux);

    return aux;

}

int validarHorario(Turno t[], Turno aux)
{
    int ocupado = 0;

    int hora = horarioTurno(aux);

    int dia = (aux.dia - 1) * 10;

    if (t[dia + hora].ocupado == 0)
    {
        t[dia + hora] = aux;

        printf("\nEl horario ha sido guardado.\n\n");

        ocupado = 1;

    } else if (t[dia + hora].ocupado == 1)

        printf("\n\nEl horario elegido no est%c disponible.\n\n",160);

    return ocupado;
}


void mostrarTurnosDisponible(char ArchivoTurno[])
{
   FILE * archivo = fopen(ArchivoTurno,"rb");

   if(archivo != NULL)
   {
       Turno aux;

       while(fread(&aux, sizeof(Turno), 1, archivo) > 0)
       {
           if(aux.ocupado == 0)
           {
               mostrarTurno(aux,0);
           }
       }
   }
   fclose(archivo);
}

int validarDia(Turno t)
{
    int dia;

    while (t.dia < 1 || t.dia > 7)
    {
        printf("\n\nEl d%ca ingresado no es v%clido.\nIngrese nuevamente.\n\nOpci%cn: ",161,160,162);
        fflush(stdin);
        scanf("%i",&t.dia);
    }

    dia = t.dia;

    return dia;
}

void mostrarDia(Turno t)
{
    switch (t.dia)
    {
        case 1: printf("lunes");
                break;

        case 2: printf("martes");
                break;

        case 3: printf("mi%crcoles",130);
                break;

        case 4: printf("jueves");
                break;

        case 5: printf("viernes");
                break;

        case 6: printf("s%cbado",160);
                break;

        case 7: printf("domingo");
                break;
    }
}

void guardarTurnoArchivo(Turno t[], int dni, char ArchivoTurno[])
{
    FILE * archivo = fopen(ArchivoTurno, "ab");

    if (archivo != NULL)
    {
        Turno aux = cargarTurno(t,dni);

        fwrite(&aux, sizeof(Turno), 1, archivo);
    }

    fclose(archivo);

}


int horarioTurno(Turno aux)
{
    int hor;

    if (aux.horario == 10.00)
    {
        hor = 0;

    } else if (aux.horario == 10.30)
    {
        hor = 1;

    } else if (aux.horario == 11.00)
    {
        hor = 2;

    } else if (aux.horario == 11.30)
    {
        hor = 3;

    } else if (aux.horario == 12.00)
    {
        hor = 4;

    } else if (aux.horario == 12.30)
    {
        hor = 5;

    } else if (aux.horario == 13.00)
    {
        hor = 6;

    } else if (aux.horario == 13.30)
    {
        hor = 7;

    } else if (aux.horario == 14.00)
    {
        hor = 8;

    } else if (aux.horario == 14.30)
    {
        hor = 9;

    }

    return hor;
}

void mostrarTurno2(Turno t)
{
    printf("\n----------\nT U R N O\n----------\n");
    printf("\nPaciente DNI: %i\n",t.dniPaciente);
    printf("\n\nD%ca: ",161);
    mostrarDia(t);
    printf(" | Horario: %.2f\n\n",t.horario);
}

void mostrarArchivoTurno(char ArchivoTurno[])
{
    FILE * archivo = fopen(ArchivoTurno, "rb");

    if (archivo != NULL)
    {
        Turno aux;

        while (fread(&aux, sizeof(Turno), 1, archivo) > 0)
        {
            if (aux.ocupado == 1)
            {
                mostrarTurno2(aux);
            }
        }
    }

    fclose(archivo);
}



/**
 * muestra un turno pero sin el dia
 * Si la funcion se llama sola, valorX tiene que valer 0;
 */
void mostrarTurno(Turno aux, int valorX)
{
    printf("Hr.: %.2f", aux.horario);

    gotoxy(valorX, whereY()+1);

    if(aux.ocupado == 0)
    {
        printf("Disponible");

        gotoxy(valorX, whereY()+2);
    }
    else{

        printf("Ocupado");

        gotoxy(valorX, whereY()+1);

        printf("DNI: %d", aux.dniPaciente);

        gotoxy(valorX, whereY()+1);
    }

    printf("------------");
}



/**
 * Muestra todos los dias
 * estado puede venir con 0, 1 o 2
 *                      0 muestra solo los disponibles
 *                      1 muestra solo los ocupados
 *                      2 muestra todos los turnos
 */

void verTurnos(Turno a[], int estado)
{
    int valorX = 0;

    int valorY = whereY();

    for(int i = 0; i < 70; i++)
        {
        if((i+1)%10 == 1){///comienza un nuevo dia

            gotoxy(valorX, valorY = valorY + 1);

            printf("DIA: %d", a[i].dia);

            gotoxy(valorX, valorY + 2);

        }

        if(estado == 2 || a[i].ocupado == estado)
            {

            gotoxy(valorX, valorY + 1);

            mostrarTurno(a[i], valorX);

            valorX = whereX() + 2;

        }

        if((i+1)%10 == 0)
            {                       ///Llego al ultimo turno del dia

            valorX = 0;

            valorY = whereY() + 1;

            }
    }
}



void modificarArregloTurno(Turno t[], int validos, int atendido)
{
    Turno aux;

    int i = 0, j = validos - 1;

    while(i <= atendido)
    {
        aux = t[i];

        while(j >= 0)
        {
            t[j - 1] = t[j];

            j--;
        }

        t[validos - 1] = aux;

        i++;
    }
}

void pedirEspecialidadAlUsuario(char especialidad[])
{
    printf("\nIngrese la especialidad: ");
    fflush(stdin);
    gets(especialidad);

    validarEspecialidad(especialidad);

    puts("\n\n");
}

void verTurnosPorEspecialidad(char especialidad[])
{
    int opcion = seleccionarTurnoPorEspecialidad(especialidad);

    int cantidad = 0;

    switch(opcion)
    {
        case 1: mostrarArchivoTurno(TurnoGeriatria);
                cantidad = contarTurnos(TurnoGeriatria);
                if (cantidad == 0)
                {
                    printf("\nNo hay turnos registrados en la especialidad.\n\n");
                }
                puts("\n\n");
                system("pause");
                system("cls");
                break;

        case 2: mostrarArchivoTurno(TurnoClinica);
                cantidad = contarTurnos(TurnoClinica);
                if (cantidad == 0)
                {
                    printf("\nNo hay turnos registrados en la especialidad.\n\n");
                }
                puts("\n\n");
                system("pause");
                system("cls");
                break;

        case 3: mostrarArchivoTurno(TurnoPediatria);
                cantidad = contarTurnos(TurnoPediatria);
                if (cantidad == 0)
                {
                    printf("\nNo hay turnos registrados en la especialidad.\n\n");
                }
                puts("\n\n");
                system("pause");
                system("cls");
                break;

        case 4: mostrarArchivoTurno(TurnoTraumatologia);
                cantidad = contarTurnos(TurnoTraumatologia);
                if (cantidad == 0)
                {
                    printf("\nNo hay turnos registrados en la especialidad.\n\n");
                }
                puts("\n\n");
                system("pause");
                system("cls");
                break;

        case 5: mostrarArchivoTurno(TurnoToxicologia);
                cantidad = contarTurnos(TurnoToxicologia);
                if (cantidad == 0)
                {
                    printf("\nNo hay turnos registrados en la especialidad.\n\n");
                }
                puts("\n\n");
                system("pause");
                system("cls");
                break;
    }
}


int seleccionarTurnoPorEspecialidad(char especialidad[])
{
    int retorno = 0;

    if (strcmpi(especialidad,"geriatria") == 0)
    {
        retorno = 1;

    } else if (strcmpi(especialidad,"clinica") == 0)
        {
            retorno = 2;

        } else if (strcmpi(especialidad,"pediatria") == 0)
            {
                retorno = 3;

            } else if (strcmpi(especialidad,"traumatologia") == 0)
                {
                    retorno = 4;

                } else if (strcmpi(especialidad,"toxicologia") == 0)

                        retorno = 5;

    return retorno;
}

void mostrarTurnosOcupados(Turno lista[], int posInicial, int posFinal)
{
    int flag = 0;

    printf("\nListado de turnos ocupados para atender: \n\n");

    for(int i = posInicial; i < posFinal; i++)
    {
        if (lista[i].ocupado == 1)
        {
            printf("Hora: %.2f\n",lista[i].horario);
            printf("DNI paciente: %i\n",lista[i].dniPaciente);
            printf("--------------------\n\n");

            flag++;
        }
    }

    if(flag == 0)
        printf("\nNo hay turnos ocupados para este d%ca.\n\n",161);
}

void mostrarTurnosOcupados2(char ArchivoTurno[])
{
    FILE * archivo = fopen(ArchivoTurno,"rb");

    if(archivo != NULL)
    {
        Turno aux;

        while(fread(&aux, sizeof(Turno), 1, archivo) > 0)
        {
            if(aux.ocupado == 1)
            {
                mostrarTurno2(aux);
            }
        }
    }
    fclose(archivo);
}


int pedirDiaParaVerTurnos()
{
    int dia;

    printf("\nIngrese el d%ca para ver los turnos ocupados\n",161);
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

void mostrarTurnoArchivoPorDia(char ArchivoTurno[], int dia)
{
    FILE * archivo = fopen(ArchivoTurno,"rb");

    if (archivo != NULL)
    {
        Turno aux;

        while(fread(&aux, sizeof(Turno), 1, archivo) > 0)
        {
            if(aux.dia == dia && aux.ocupado == 1)
            {
                mostrarTurno2(aux);
            }
        }
    }
    fclose(archivo);
}

void verTurnosPorDia(int dia)
{
    int cantidad = 0;

    mostrarTextoSegunDia(dia);

    switch(dia)
    {
        case 1: mostrarTurnoArchivoPorDia(TurnoGeriatria,dia);
                cantidad = contarTurnos(TurnoGeriatria);

        case 2: mostrarTurnoArchivoPorDia(TurnoClinica,dia);
                cantidad += contarTurnos(TurnoClinica);

        case 3: mostrarTurnoArchivoPorDia(TurnoPediatria,dia);
                cantidad += contarTurnos(TurnoPediatria);

        case 4: mostrarTurnoArchivoPorDia(TurnoTraumatologia,dia);
                cantidad += contarTurnos(TurnoTraumatologia);

        case 5: mostrarTurnoArchivoPorDia(TurnoToxicologia,dia);
                cantidad += contarTurnos(TurnoToxicologia);
    }

    if(cantidad == 0)

        printf("\nNo hay ning%cn turno registrado.\n\n",163);
}

void mostrarTextoSegunDia(int dia)
{
    switch(dia)
    {
        case 1: printf("\nTurnos del lunes.\n\n");
                break;

        case 2: printf("\nTurnos del martes.\n\n");
                break;

        case 3: printf("\nTurnos del mi%crcoles.\n\n",130);
                break;

        case 4: printf("\nTurnos del jueves.\n\n");
                break;

        case 5: printf("\nTurnos del viernes.\n\n");
                break;

        case 6: printf("\nTurnos del s%cbado.\n\n",160);
                break;

        case 7: printf("\nTurnos del domingo.\n\n");
                break;
    }
}

void mostrarFichaDeTurno(char ArchivoTurno[], int dni, char especialidad[], char nombreMedico[], Paciente paciente)
{
    int flag = 0;

    FILE * archivo = fopen(ArchivoTurno,"rb");

    if (archivo != NULL)
    {
        Turno aux;

        while(!flag && fread(&aux, sizeof(Turno), 1, archivo) > 0)
        {
            if(aux.dniPaciente == dni)
            {
                flag = 1;

                imprimirFicha(aux,especialidad,nombreMedico,paciente);
            }
        }
    }
    fclose(archivo);
}

void imprimirFicha(Turno aux, char especialidad[], char nombreMedico[], Paciente paciente)
{
    printf("\n--------------------------------------\n");
    printf("*Ficha de turno*\n\n");
    printf("Paciente: %s\n",paciente.nombreApellido);
    printf("DNI: %i\n",aux.dniPaciente);
    printf("Turno en la especialidad: %s\n",especialidad);
    printf("D%ca: ",161);
    mostrarDia(aux);
    printf("\nHorario: %.2f\n",aux.horario);
    printf("Atiende el Dr.: %s\n",nombreMedico);
    printf("\n--------------------------------------\n\n");

    mandarAImprimir();
}


void mandarAImprimir()
{
    char opcion;

    printf("\n\n\n%cDesea imprimir la ficha? (s/n): ",168);
    fflush(stdin);
    scanf("%c",&opcion);

    if (opcion == 's')
    {
        printf("\n\n\tNo se ha detectado conecci%cn con impresora.\n\n\n\n\n\n",162);

    } else

        puts("\n\n\n\n\n\n");

}


/*void verTurnosPorDiaYEspecialidad(char especialidad[], int dia)
{
    Medico aux = buscarMedicoEspecialidad(especialidad);

    switch(dia)
    {
        case 1: verTurnosOcupadosPorDia(dia,aux);
                puts("\n\n");
                system("pause");
                system("cls");
                break;

        case 2: verTurnosOcupadosPorDia(dia,aux);
                puts("\n\n");
                system("pause");
                system("cls");
                break;

        case 3: verTurnosOcupadosPorDia(dia,aux);
                puts("\n\n");
                system("pause");
                system("cls");
                break;

        case 4: verTurnosOcupadosPorDia(dia,aux);
                puts("\n\n");
                system("pause");
                system("cls");
                break;

        case 5: verTurnosOcupadosPorDia(dia,aux);
                puts("\n\n");
                system("pause");
                system("cls");
                break;

        case 6: verTurnosOcupadosPorDia(dia,aux);
                puts("\n\n");
                system("pause");
                system("cls");
                break;

        case 7: verTurnosOcupadosPorDia(dia,aux);
                puts("\n\n");
                system("pause");
                system("cls");
                break;
    }
}*/

void mostrarTurnosParaAtender(char especialidad[], int dia)
{
    int opcion = seleccionarTurnoPorEspecialidad(especialidad);

    switch(opcion)
        {
        case 1:
            mostrarTurnosOcupados2(TurnoGeriatria);
            break;

        case 2:
            mostrarTurnosOcupados2(TurnoClinica);
            break;

        case 3:
            mostrarTurnosOcupados2(TurnoPediatria);
            break;

        case 4:
            mostrarTurnosOcupados2(TurnoTraumatologia);
            break;

        case 5:
            mostrarTurnosOcupados2(TurnoToxicologia);
            break;
        }
}


int contarTurnos(char ArchivoTurno[])
{
    int cantidad = 0;

    FILE * archivo = fopen(ArchivoTurno,"rb");

    if(archivo != NULL)
    {
        Turno aux;

        while(fread(&aux, sizeof(Turno), 1, archivo) > 0)

            if(aux.ocupado == 1)
            {
                fseek(archivo, 0, SEEK_END);

                cantidad += ftell(archivo) / sizeof(Turno);
            }
    }

    fclose(archivo);

    return cantidad;
}
