#ifndef PACIENTES_H_INCLUDED
#define PACIENTES_H_INCLUDED

typedef struct {

    char nombreApellido[30];
    int dniPaciente;
    int edad;
    int eliminado; // 0 alta /1 baja

} Paciente;

Paciente cargarPaciente();    // funcion para carga de paciente (de a uno) en estructura auxiliar y la devuelve

void cargarPacienteArchivo();     // carga el archivo paciente

void mostrarTodoPaciente();     // muestra todos los pacientes del archivo

void mostrarPaciente( Paciente paciente );     // muestra una estructura paciente

void bajaPaciente( int documento );     // da de baja un paciente buscado por dni

void modificarNombrePaciente( int documento );    // modifica nombre de paciente

int validarDocu ( int documento );    // valida que un documento se encuentre en el archivo de pacientes

void modificarEdadPaciente( int documento );   // modifica edad del paciente

void modificarPacienteEntero( int documento );   // modificar paciente entero

void mostrarPacienteDocu( int documento );     // muestra al paciente buscado por dni

void mostrarPacienteNombre();    // muestra al paciente buscado por nombre

Paciente buscarPacientePorDNI(int);

int atenderPaciente(char[], int);

void atenderPaciente2(char[], int);

#endif // PACIENTES_H_INCLUDED
