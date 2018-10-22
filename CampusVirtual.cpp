#include <iostream>
#include "CampusVirtual.h"

using namespace std;

CampusVirtual::CampusVirtual() {

}

void CampusVirtual::inicio() {
  int level = login();
  switch (level) {
    case 1:
      menuAlumno();
    break;
    case 2:
      menuProfesor();
    break;
    case 3:
      menuAdmin();
    break;
    default :
      cout<<"Error en la seleccion de usuario"<<endl;
  }
}

//1- alumno, 2-profesor, 3-admin
int CampusVirtual::login() {
  //TEMP
  /*string nombre;
  cout<<"Introduce tu nombre"<<endl;
  cin>>nombre;
  Detectar el tipo de usuario. Alumno o Profesor/Admin.
  Dividiendo el fichero de usuarios,
  o buscar el nombre en diferente ficheros
  Usar: bool alumnos.
  if(alumno) {
    Introduce tu nia. Ver si el nia esta en el fichero.
    si esta return 1
  } else {
    Introduce el id, ver si esta en el fichero
    si esta, return 2 o 3.
  }*/
  return 1;
}

void CampusVirtual::menuAlumno() {
  int opcion = 0;
  cout<<"1. Darse de alta en un recurso"<<endl
  <<"2. Darse de baja en un recurso"<<endl
  <<"3. Ver recursos que estan siendo cursados"<<endl;
  cin>>opcion;

  switch (opcion) {
    case 1:
      //altaRecurso();
    break;
    case 2:
      //bajaRecurso();
    break;
    case 3:
      //mostrarRecursos();
    break;
    default :
      cout<<"Opcion erronea"<<endl;
  }
}

void CampusVirtual::menuAdmin() {
  int option = 0;
  cout<<"1. Gestionar recursos"<<endl
  <<"2. Gestionar usuarios"<<endl;
  cin>>option;

  switch (option) {
    case 1:
      //gestionarRecursos();
    break;
    case 2:
      //gestionarUsuarios();
    break;
    default :
      cout<<"Opcion erronea"<<endl;
  }
}

void CampusVirtual::menuProfesor() {
  int option = 0;
  cout<<"1. Modificar recursos"<<endl
  <<"2. Calificar alumnos"<<endl;
  cin>>option;

  switch (option) {
    case 1:
      //gestionarRecursos();
    break;
    case 2:
      //calificar();
    break;
    default :
      cout<<"Opcion erronea"<<endl;
  }
}
