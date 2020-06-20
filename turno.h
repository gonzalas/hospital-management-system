#ifndef TURNO_H_INCLUDED
#define TURNO_H_INCLUDED

#define TurnoGeriatria "turnoGeriatria.dat"
#define TurnoClinica "turnoClinica.dat"
#define TurnoPediatria "turnoPediatria.dat"
#define TurnoTraumatologia "turnoTraumatologia.dat"
#define TurnoToxicologia "turnoToxicologia.dat"

typedef struct
{
    int dniPaciente;
    int dia; //del 1 al 7
    float horario;
    int ocupado; //0 ó 1

} Turno;

#include "medico.h"
#include "paciente.h"

Turno cargarTurno(Turno[], int);

Turno cargarTurno2(int, char[]);

void guardarTurnoArchivo(Turno [], int, char []);

void guardarTurnoArchivo2(char [], int);

void mostrarTurno2(Turno);

void mostrarArchivoTurno(char []);

void verTurnos(Turno [], int);

void mostrarTurno(Turno, int);

void pedirEspecialidadAlUsuario(char []);

int seleccionarTurnoPorEspecialidad(char []);

void verTurnosPorEspecialidad(char []);

void pedirEspecialidadAlUsuario(char []);

void modificarArregloTurno(Turno [], int, int);

int horarioTurno(Turno);

void mostrarDia(Turno);

int validarDia(Turno);

int validarHorario(Turno[], Turno);

void mostrarTurnosDisponible(char []);

void mostrarTurnosOcupados(Turno[],int, int);

int pedirDiaParaVerTurnos();

void mostrarTextoSegunDia(int);

void mostrarTurnoArchivoPorDia(char [], int);

void verTurnosPorDia(int);

void mostrarFichaDeTurno(char[], int, char[], char[], Paciente);

void imprimirFicha(Turno, char[], char[], Paciente);

void verTurnosPorDiaYEspecialidad(char [], int);

void mostrarTurnosOcupados2(char []);

void mostrarTurnosParaAtender(char [], int);

int verificarHorarioTurno(Turno, char []);

int contarTurnos(char[]);

void mandarAImprimir();



#endif // TURNO_H_INCLUDED
