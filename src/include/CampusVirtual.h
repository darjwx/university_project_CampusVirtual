#ifndef _CampusVirtual_H_
#define _CampusVirtual_H_
#include <list>
#include "Administrator.h"
#include "Teacher.h"
#include "Alumno.h"
#include "Subjects.h"
#include "Conference.h"
#include "TrabajoFinEstudios.h"

class CampusVirtual {
private:
  list<Alumno*> listaAlumnos;
  list<Teacher*> listaProfesores;
  list<Administrator*> listaAdmins;
  list<Subjects*> listaAsignaturas;
  list<Conference*> listaSeminarios;
  list<TrabajoFinEstudios*> listaTFE;

  unsigned int numAdmin;
  unsigned int numProf;
  unsigned int numAlum;
  unsigned int numAsig;
  unsigned int numSem;
  unsigned int numTFE;

public:
  CampusVirtual();
  void inicio();
  int login();
  void menuAlumno();
  void menuAdmin();
  void menuProfesor();

  char target(int);
  void gestionarUsuarios();
  void gestionarRecursos();

  void cargarListas();
  void mostrarListas(char);
  void escribirLista();
  void cerrarSesion();
};
#endif //_CampusVirtual_H_
