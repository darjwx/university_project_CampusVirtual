#include <iostream>
#include <fstream>

#include "Administrator.h"
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
      cout<<"Usuario incorrecto"<<endl;
  }
}

//1- alumno, 2-profesor, 3-admin
int CampusVirtual::login() {
  string nombre;
  int user;
  char* id = new char[9];

  cout<<"LOGIN || UC3M Campus Virtual"<<endl;
  cout<<"Usuario: alumno(1),profesor(2) o admin(3) ";
  cin>>user;
  cout<<endl<<"Nombre: ";
  cin>>nombre;
  cout<<endl<<"NIA/ID: ";
  cin>>id;
  string data = nombre + " " + id;

  if(user == 1) {
    string line;
    fstream fsalum("alumnos.dat", ios::in | ios::binary);
    fsalum.seekg(0,ios::beg);
    while(getline(fsalum,line)) {
      if(line.find(data, 0) != string::npos) {
        delete[] id;
        return 1;
      }
    }

  } else if(user == 2) {
    string line;
    fstream fsprof("profesores.dat", ios::in | ios::binary);
    fsprof.seekg(0,ios::beg);
    while(getline(fsprof,line)) {
      if(line.find(data, 0) != string::npos) {
        delete[] id;
        return 2;
      }
    }

  } else if(user == 3) {
    string line;
    fstream fsadmin("admins.dat", ios::in | ios::binary);
    fsadmin.seekg(0,ios::beg);
    while(getline(fsadmin,line)) {
      if(line.find(data, 0) != string::npos) {
        delete[] id;
        return 3;
      }
    }

  } else {
    cout<<"Tipo de ususario incorrecto"<<endl;
  }
  delete[] id;
  return 0;
}

void CampusVirtual::menuAlumno() {
  int opcion = 0;
  cout<<endl<<"ALUMNOS"<<endl
    <<"1. Darse de alta en un recurso"<<endl
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
  Administrator admin;
  int option = 0;
  cout<<endl<<"ADMINISTRADORES"<<endl
    <<"1. Gestionar recursos"<<endl
    <<"2. Gestionar usuarios"<<endl;
  cin>>option;

  switch (option) {
    case 1:
      //gestionarRecursos();
    break;
    case 2:
      admin.gestionarUsuarios();
    break;
    default :
      cout<<"Opcion erronea"<<endl;
  }
}

void CampusVirtual::menuProfesor() {
  int option = 0;
  cout<<endl<<"PROFESORES"<<endl
    <<"1. Modificar recursos"<<endl
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
