#ifndef MEDICO_H_INCLUDED
#define MEDICO_H_INCLUDED

#include "turno.h"

#define ArchivoMedico "archivoMedico.dat"

typedef struct
{
    char nombreApellido[50];
    int matricula;
    char especialidad[30];
    Turno listTurnos[100];
    int eliminado;

} Medico;   //5 médicos, uno por cada especialidad


Medico cargarMedico();

void generadorTurnos(Turno[]);

Medico buscarMedicoEspecialidad(char []);

Medico buscarMedicoMatricula(int);

void darDeBajaMedicoPorEspecialidad(char []);

void guardarArchivoMedico();

void insertarMedicoEspecialidad(Medico [], Medico, int);

void insertarMedicoMatricula(Medico [], Medico, int);

void ordenarMedicoEspecialidad(Medico [], int);

void ordenarMedicoMatricula(Medico [], int);

void modificarNombreMedico(int, char []);

void mostrarArchivoMedico();

void mostrarListadoMedico(Medico [], int);

void mostrarMedico(Medico);

int pasarArchivoMedicoAArreglo(Medico [], int);

void pedirEspecialidadMedicoParaBuscar(char []);

int pedirMatriculaMedicoParaBuscar();

void pedirNuevoNombreMedico(char []);

void validarEspecialidad(char []);

int verificarMatricula();

void darDeAltaMedicoMismaEspecialidad(char []);

Medico registrarNuevoMedico(char []);

int pedirDiaParaAtender();

int cantidadDeMedicos();


#endif // MEDICO_H_INCLUDED
