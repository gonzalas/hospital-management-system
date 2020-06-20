#ifndef HABITACIONES_H_INCLUDED
#define HABITACIONES_H_INCLUDED

#define archivoHabitaciones "habitaciones.bin"

#define InternadosGeriatria "internadosGeriatria.dat"
#define InternadosClinica "internadosClinica.dat"
#define InternadosPediatria "internadosPediatria.dat"
#define InternadosTraumatologia "internadosTraumatologia.dat"
#define InternadosToxicologia "internadosToxicologia.dat"

#define EnEsperaGeriatria "enEsperaGeriatria.dat"
#define EnEsperaClinica "enEsperaClinica.dat"
#define EnEsperaPediatria "enEsperaPediatria.dat"
#define EnEsperaTraumatologia "enEsperaTraumatologia.dat"
#define EnEsperaToxicologia "enEsperaToxicologia.dat"

typedef struct{

        int nroHabitacion;
        int ocupado; //0
        int dniPaciente;

}Habitacion;


void comprobarNuevasHabitaciones();

void cargarNuevasHabitaciones();

void mostrarTodaHabit();     /// Muestra un listado con todas las habitaciones

void mostrarHabitacion(Habitacion);       /// Muestra habitacion individual

void cargarArchivoHabitaciones();       /// Carga el archivo de habitaciones

void mostrarHabitPisos(char []);    /// Muestra habitaciones por pisos

void mostrarEspecialidad(Habitacion);

void internarPaciente(int, char[], char[]);

void darDeAltaPacientePorDNI(char []);

int pedirDniParaDarDeAlta();

int darDeAltaPorDni(char[], int);

void mostrarOcupadasPisos (char []);

void mostrarHabitacionesOcupadas (Habitacion);

void darDeAltaPacientePorNumHabitacion(char []);

int darDeAltaPorEspecialidad(char []);

void mostrarListadoPacientesInternados();

void mostrarPacienteInternado(Habitacion, char[]);

void mostrarPacientesInternados(char[], char[]);

void pasarPacienteAListaDeEsperaInternacion(int, char[]);

int contarHabitacionesInternacionOcupadas(char []);

void listaDeEspera(int, char []);

void mostrarPacienteEnEspera();

void mostrarPacientesListaDeEspera(char[], char[]);

void modificarArchivoHabitacionesAOcupado(char[], int, char[]);

void modificarArchivoHabitacionesADisponible(int);



#endif // HABITACIONES_H_INCLUDED
