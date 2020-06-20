#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "turno.h"
#include "paciente.h"
#include "medico.h"
#include "habitaciones.h"


void menuPrincipal();

void habitaciones();

void abml();

void subMenuAbml();

void darTurno(int);

void subMenuTurnos();

void funcionesPacientes();

void internaciones();

void medicos();

void subMenuMedicos();

void menuAltaPaciente();

void menuListadoTurnos(char []);

void subMenuListadoTurnos(char especialidad[]);

void menuListadoMedicos();

void menuListadoPacientes();

void menuModificarPaciente();

void menuPacientesInternados();

void mostrarMenuEspecialidades();

void pacientes();

int pedirDniParaAtender();

void seleccionarArchivoPorEspecialidad(char []);

void subMenuListadoMedicos();

void turnos();

void subMenuParaAtender(char[]);

void subMenuInternaciones();

void subMenuDarAlta();

void subMenuPacientesInternados();

#endif // MENU_H_INCLUDED
