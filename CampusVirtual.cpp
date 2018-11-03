//TODO fix endless loops in menus when entering chars

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
  bool error = true;
  char* id = new char[9];

  do{
    /*ANSI escape codes:
    \033[2j clears the entire screen.
    \033[1;1H position the cursor at row 1, column 1.*/
    cout<<"\033[2J\033[1;1H";
    cout<<"LOGIN || UC3M Campus Virtual"<<endl;
    cout<<"Usuario: alumno(1),profesor(2) o admin(3) ";
    cin>>user;
  //Endless loop when you enter a float.
  } while (user > 3 || user < 1);

  do {
    /*ANSI escape codes:
    \033[2j clears the entire screen.
    \033[1;1H position the cursor at row 1, column 1.*/
    cout << "\033[2J\033[1;1H";
    cout<<endl<<"Nombre: ";
    cin>>nombre;
    cout<<endl<<"NIA/ID: ";
    cin>>id;
    string data = nombre + " " + id;

    if(user == 1) {
      string line;
      fstream fs("alumnos.dat", ios::in | ios::binary);
      fs.seekg(0,ios::beg);
      while(getline(fs,line)) {
        if(line.find(data, 0) != string::npos) {
          error = false;
        }
      }
      fs.close();

    } else if(user == 2) {
      string line;
      fstream fs("profesores.dat", ios::in | ios::binary);
      fs.seekg(0,ios::beg);
      while(getline(fs,line)) {
        if(line.find(data, 0) != string::npos) {
          error = false;
        }
      }
      fs.close();

    } else if(user == 3) {
      string line;
      fstream fs("admins.dat", ios::in | ios::binary);
      fs.seekg(0,ios::beg);
      while(getline(fs,line)) {
        if(line.find(data, 0) != string::npos) {
          error = false;
        }
      }
      fs.close();
    }
    if(error) {
      cout<<"Usuario no encontrado. Prueba otra vez"<<endl;
    }
  } while (error);

  delete[] id;
  return user;
}

void CampusVirtual::menuAlumno() {
  char option = '0';
  /*ANSI escape codes:
  \033[2j clears the entire screen.
  \033[1;1H position the cursor at row 1, column 1.*/
  cout<<"\033[2J\033[1;1H";
  cout<<endl<<"ALUMNOS"<<endl
    <<"1. Darse de alta en un recurso"<<endl
    <<"2. Darse de baja en un recurso"<<endl
    <<"3. Ver recursos que estan siendo cursados"<<endl
    <<"<. Cerrar sesion"<<endl;
  cin>>option;

  switch (option) {
    case '1':
      //altaRecurso();
    break;
    case '2':
      //bajaRecurso();
    break;
    case '3':
      //mostrarRecursos();
    break;
    case '<':
      cerrarSesion();
    break;
    default :
      cout<<"Opcion erronea"<<endl;
  }
}

void CampusVirtual::menuAdmin() {
  Administrator admin;
  char option = '0';
  /*ANSI escape codes:
  \033[2j clears the entire screen.
  \033[1;1H position the cursor at row 1, column 1.*/
  cout<<"\033[2J\033[1;1H";
  cout<<endl<<"ADMINISTRADORES"<<endl
    <<"1. Gestionar recursos"<<endl
    <<"2. Gestionar usuarios"<<endl
    <<"<. Cerrar sesion"<<endl;
  cin>>option;

  switch (option) {
    case '1':
      admin.gestionarContenido();
    break;
    case '2':
      admin.gestionarUsuarios();
    break;
    case '<':
      cerrarSesion();
    break;
    default :
      cout<<"Opcion erronea"<<endl;
  }
}

void CampusVirtual::menuProfesor() {
  char option = '0';
  /*ANSI escape codes:
  \033[2j clears the entire screen.
  \033[1;1H position the cursor at row 1, column 1.*/
  cout<<"\033[2J\033[1;1H";
  cout<<endl<<"PROFESORES"<<endl
    <<"1. Modificar recursos"<<endl
    <<"2. Calificar alumnos"<<endl
    <<"<. Cerrar sesion"<<endl;
  cin>>option;

  switch (option) {
    case '1':
      //gestionarRecursos();
    break;
    case '2':
      //calificar();
    break;
    case '<':
      cerrarSesion();
    break;
  default :
      cout<<"Opcion erronea"<<endl;
}
}

void CampusVirtual::cerrarSesion() {
  inicio();
}
