//TODO fix endless loops in menus when entering chars

#include <iostream>
#include <fstream>
#include <string.h>

#include "include/CampusVirtual.h"

using namespace std;

CampusVirtual::CampusVirtual() {

}

void CampusVirtual::inicio() {
  //CampusVirtual cv;
  cargarListas();
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
      list<Alumno*>::const_iterator it;
      it = listaAlumnos.begin();
      while(it != listaAlumnos.end()) {
        if(nombre == (*it)->getName()) {
          if(id == (*it)->getId()) {
            error = false;
          }
          ++it;
        }
      }

    } else if(user == 2) {
      list<Teacher*>::const_iterator it;
      it = listaProfesores.begin();
      while(it != listaProfesores.end()) {
        if(nombre == (*it)->getName()) {
          if(id == (*it)->getId()) {
            error = false;
          }
          ++it;
        }
      }

    } else if(user == 3) {
      list<Administrator*>::const_iterator it;
      it = listaAdmins.begin();
      while(it != listaAdmins.end()) {
        if(nombre == (*it)->getName()) {
          if(id == (*it)->getId()) {
            error = false;
          }
          ++it;
        }
      }
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
      gestionarRecursos();
    break;
    case '2':
      gestionarUsuarios();
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

char CampusVirtual::target(int n) {
  char opcion = ' ';
  if(n == 1) {
    //Usuarios
    cout<<"1. Alumnos"<<endl
      <<"2. Profesores"<<endl
      <<"3. Administradores"<<endl;
    cin>>opcion;
    return opcion;
  } else {
    //Recursos
    cout<<"1. Asignaturas"<<endl
      <<"2. Seminarios"<<endl
      <<"3. TFE"<<endl;
    cin>>opcion;
    return (3 + opcion);
  }

}

void CampusVirtual::gestionarUsuarios() {
  char option = '0';
  bool salir = false;

  do {
    /*ANSI escape codes:
    \033[2j clears the entire screen.
    \033[1;1H position the cursor at row 1, column 1.*/
    cout<<"\033[2J\033[1;1H";
    cout<<"1. Añadir nuevos usuarios"<<endl
        <<"2. Modificar datos  de usuarios existentes"<<endl
        <<"3. Eliminar usuarios"<<endl
        <<"4. Lista de usuarios registrados"<<endl
        <<"<. Salir";
    cin>>option;

    if(option == '1') {
      char t = target(1);
      string id;
      string nombre;
      char more;

      switch (t) {
        case '1':
          do {

            /*ANSI escape codes:
            \033[2j clears the entire screen.
            \033[1;1H position the cursor at row 1, column 1.*/
            cout<<"\033[2J\033[1;1H";
            cout<<"Introduce el nuevo alumno: "<<endl;
            cout<<"Nombre: ";
            cin>>nombre;
            cout<<endl<<"NIA: ";
            cin>>id;

            Alumno* a = new Alumno();
            a->setName(nombre);
            a->setId(id);

            listaAlumnos.push_back(a);
            numAlum = listaAlumnos.size();

            cout<<"¿Añadir mas alumnos? (y/n)"<<endl;
            cin>>more;
          } while(more == 'y');
        break;
        case '2':
          do {

            /*ANSI escape codes:
            \033[2j clears the entire screen.
            \033[1;1H position the cursor at row 1, column 1.*/
            cout<<"\033[2J\033[1;1H";
            cout<<"Introduce el nuevo profesor: "<<endl;
            cout<<"Nombre: ";
            cin>>nombre;
            cout<<endl<<"ID: ";
            cin>>id;

            Teacher* a = new Teacher();
            a->setName(nombre);
            a->setId(id);

            listaProfesores.push_back(a);
            numProf = listaProfesores.size();

            cout<<"¿Añadir mas alumnos? (y/n)"<<endl;
            cin>>more;
          } while(more == 'y');
        break;
        case '3':
          do {

            /*ANSI escape codes:
            \033[2j clears the entire screen.
            \033[1;1H position the cursor at row 1, column 1.*/
            cout<<"\033[2J\033[1;1H";
            cout<<"Introduce el nuevo administrador: "<<endl;
            cout<<"Nombre: ";
            cin>>nombre;
            cout<<endl<<"ID: ";
            cin>>id;

            Administrator* a = new Administrator();
            a->setName(nombre);
            a->setId(id);

            listaAdmins.push_back(a);
            numAdmin = listaAdmins.size();

            cout<<"¿Añadir mas administradores? (y/n)"<<endl;
            cin>>more;
          } while(more == 'y');
        break;
        default :
          ;
      }

    } else if(option == '2') {
      char t = target(1);

      string id;
      string nombre;
      int pos;
      char more;

      switch (t) {
        case '1':
          do {

            /*ANSI escape codes:
            \033[2j clears the entire screen.
            \033[1;1H position the cursor at row 1, column 1.*/
            cout<<"\033[2J\033[1;1H";
            mostrarListas(t);
            cout<<"Alumno a modificar: "<<endl;
            cin>>pos;

            cout<<"Introduce los nuevos datos: "<<endl;
            cout<<"Nombre: ";
            cin>>nombre;
            cout<<endl<<"NIA: ";
            cin>>id;

            list<Alumno*>::iterator it;
            it = listaAlumnos.begin();

            for(int i = 0; i <= pos; ++i) {
              ++it;
            }
            (*it)->setName(nombre);
            (*it)->setId(id);

            cout<<"¿Modificar mas alumnos? (y/n)"<<endl;
            cin>>more;
          } while(more == 'y');
        break;
        case '2':
          do {

            /*ANSI escape codes:
            \033[2j clears the entire screen.
            \033[1;1H position the cursor at row 1, column 1.*/
            cout<<"\033[2J\033[1;1H";
            cout<<"\033[2J\033[1;1H";
            mostrarListas(t);
            cout<<"Profesor a modificar: "<<endl;
            cin>>pos;

            cout<<"Introduce los nuevos datos: "<<endl;
            cout<<"Nombre: ";
            cin>>nombre;
            cout<<endl<<"ID: ";
            cin>>id;

            list<Teacher*>::iterator it;
            it = listaProfesores.begin();

            for(int i = 0; i <= pos; ++i) {
              ++it;
            }
            (*it)->setName(nombre);
            (*it)->setId(id);

            cout<<"¿Modificar mas profesores? (y/n)"<<endl;
            cin>>more;
          } while(more == 'y');
        break;
        case '3':
          do {

            /*ANSI escape codes:
            \033[2j clears the entire screen.
            \033[1;1H position the cursor at row 1, column 1.*/
            cout<<"\033[2J\033[1;1H";
            cout<<"\033[2J\033[1;1H";
            mostrarListas(t);
            cout<<"Administrador a modificar: "<<endl;
            cin>>pos;

            cout<<"Introduce los nuevos datos: "<<endl;
            cout<<"Nombre: ";
            cin>>nombre;
            cout<<endl<<"ID: ";
            cin>>id;

            list<Administrator*>::iterator it;
            it = listaAdmins.begin();

            for(int i = 0; i <= pos; ++i) {
              ++it;
            }
            (*it)->setName(nombre);
            (*it)->setId(id);

            cout<<"¿Modificar mas administradores? (y/n)"<<endl;
            cin>>more;
          } while(more == 'y');
        break;
        default :
          ;
      }

    } else if(option == '3') {
      int t = target(1);
      int pos;
      char more;

      switch (t) {
        case '1':
          do {

            /*ANSI escape codes:
            \033[2j clears the entire screen.
            \033[1;1H position the cursor at row 1, column 1.*/
            cout<<"\033[2J\033[1;1H";
            mostrarListas(t);
            cout<<"Alumno a eliminar: "<<endl;
            cin>>pos;

            list<Alumno*>::iterator it;
            it = listaAlumnos.begin();

            for(int i = 0; i < pos; ++i) {
              ++it;
            }
            it = listaAlumnos.erase(it);

            cout<<"¿Eliminar mas alumnos? (y/n)"<<endl;
            cin>>more;
          } while(more == 'y');
        break;
        case '2':
          do {

            /*ANSI escape codes:
            \033[2j clears the entire screen.
            \033[1;1H position the cursor at row 1, column 1.*/
            cout<<"\033[2J\033[1;1H";
            cout<<"\033[2J\033[1;1H";
            mostrarListas(t);
            cout<<"Profesor a eliminar: "<<endl;
            cin>>pos;

            list<Teacher*>::iterator it;
            it = listaProfesores.begin();

            for(int i = 0; i < pos; ++i) {
              ++it;
            }
            it = listaProfesores.erase(it);

            cout<<"¿Eliminar mas profesore? (y/n)"<<endl;
            cin>>more;
          } while(more == 'y');
        break;
        case '3':
          do {

            /*ANSI escape codes:
            \033[2j clears the entire screen.
            \033[1;1H position the cursor at row 1, column 1.*/
            cout<<"\033[2J\033[1;1H";
            cout<<"\033[2J\033[1;1H";
            mostrarListas(t);
            cout<<"Administrador a eliminar: "<<endl;
            cin>>pos;

            list<Administrator*>::iterator it;
            it = listaAdmins.begin();

            for(int i = 0; i < pos; ++i) {
              ++it;
            }
            it = listaAdmins.erase(it);

            cout<<"¿Eliminar mas administradores? (y/n)"<<endl;
            cin>>more;
          } while(more == 'y');
        break;
        default :
          ;
      }

    } else if(option == '4') {
      char t = target(1);
      mostrarListas(t);

    } else if(option == '<') {
      salir = true;

    } else {
      cout<<"Opcion erronea"<<endl;
    }
  } while (!salir);

  menuAdmin();
}

void CampusVirtual::gestionarRecursos() {
  char option = '0';
  bool salir = false;

  do {
    /*ANSI escape codes:
    \033[2j clears the entire screen.
    \033[1;1H position the cursor at row 1, column 1.*/
    cout<<"\033[2J\033[1;1H";
    cout<<"1. Añadir nuevos recursos"<<endl
        <<"2. Modificar datos  de recursos existentes"<<endl
        <<"3. Eliminar recursos"<<endl
        <<"4. Lista de recursos disponibles"<<endl
        <<"<. Salir";
    cin>>option;

    if(option == '1') {
      char t = target(2);
      string id;
      string nombre;
      string titulacion;
      string speaker;
      Teacher teacher1 = Teacher();
      Teacher teacher2 = Teacher();
      Teacher supervisor = Teacher();
      Teacher tutor = Teacher();
      Teacher coTutor = Teacher();
      Date* date;
      unsigned int credits;
      int capacity;
      //unsigned int grade;
      string auxN;
      string auxId;

      char more;

      switch (t) {
        case '4':
          do {

            /*ANSI escape codes:
            \033[2j clears the entire screen.
            \033[1;1H position the cursor at row 1, column 1.*/
            cout<<"\033[2J\033[1;1H";
            cout<<"Introduce la nueva asignatura: "<<endl;
            cout<<"Nombre: ";
            cin>>nombre;
            cout<<endl<<"ID: ";
            cin>>id;
            cout<<endl<<"Titulacion: ";
            cin>>titulacion;

            cout<<endl<<"Profesor 1: ";
            cout<<endl<<"Nombre: ";
            cin>>auxN;
            teacher1.setName(auxN);
            cout<<endl<<"ID: ";
            cin>>auxId;
            teacher1.setId(auxId);

            cout<<endl<<"Profesor 2: ";
            cout<<endl<<"Nombre: ";
            cin>>auxN;
            teacher2.setName(auxN);
            cout<<endl<<"ID: ";
            cin>>auxId;
            teacher2.setId(auxId);

            cout<<endl<<"Creditos: ";
            cin>>credits;

            Subjects* a = new Subjects();
            a->setName(nombre);
            a->setId(id);
            a->setTitulacion(titulacion);
            a->setTeacher(teacher1, teacher2);
            a->setCredits(credits);
            listaAsignaturas.push_back(a);
            numAsig = listaAsignaturas.size();

            cout<<"¿Añadir mas asignaturas? (y/n)"<<endl;
            cin>>more;
          } while(more == 'y');
        break;
        case '5':
          do {

            /*ANSI escape codes:
            \033[2j clears the entire screen.
            \033[1;1H position the cursor at row 1, column 1.*/
            cout<<"\033[2J\033[1;1H";
            cout<<"Introduce el nuevo seminario: "<<endl;
            cout<<"Nombre: ";
            cin>>nombre;
            cout<<endl<<"ID: ";
            cin>>id;
            cout<<endl<<"Ponente: ";
            cin>>speaker;

            cout<<endl<<"Supervisor: ";
            cout<<endl<<"Nombre: ";
            cin>>auxN;
            supervisor.setName(auxN);
            cout<<endl<<"ID: ";
            cin>>auxId;
            supervisor.setId(auxId);

            cout<<endl<<"Capacidad: ";
            cin>>capacity;

            int dia,mes,anio;
            cout<<endl<<"Fecha: ";
            cout<<"  Dia: ";
            cin>>dia;
            cout<<"  Mes: ";
            cin>>mes;
            cout<<"  Año: ";
            cin>>anio;
            date = new Date(dia,mes,anio);

            Conference* a = new Conference();
            a->setName(nombre);
            a->setId(id);
            a->setSpeaker(speaker);
            a->setSupervisor(supervisor);
            a->setCapacity(capacity);
            a->setDate(date);

            listaSeminarios.push_back(a);
            numSem = listaSeminarios.size();

            cout<<"¿Añadir mas seminarios? (y/n)"<<endl;
            cin>>more;
          } while(more == 'y');
        break;
        case '6':
          do {

            /*ANSI escape codes:
            \033[2j clears the entire screen.
            \033[1;1H position the cursor at row 1, column 1.*/
            cout<<"\033[2J\033[1;1H";
            cout<<"Introduce el nuevo TFE: "<<endl;
            cout<<"Nombre: ";
            cin>>nombre;
            cout<<endl<<"ID: ";
            cin>>id;
            cout<<endl<<"Titulacion: ";
            cin>>titulacion;

            cout<<endl<<"Tutor: ";
            cout<<endl<<"Nombre: ";
            cin>>auxN;
            teacher1.setName(auxN);
            cout<<endl<<"ID: ";
            cin>>auxId;
            tutor.setId(auxId);

            cout<<endl<<"coTutor: ";
            cout<<endl<<"Nombre: ";
            cin>>auxN;
            teacher2.setName(auxN);
            cout<<endl<<"ID: ";
            cin>>auxId;
            coTutor.setId(auxId);

            TrabajoFinEstudios* a = new TrabajoFinEstudios();
            a->setName(nombre);
            a->setId(id);
            a->setTitulacion(titulacion);
            a->setTutor(tutor);
            a->setCoTutor(coTutor);

            listaTFE.push_back(a);
            numTFE = listaTFE.size();

            cout<<"¿Añadir mas TFEs? (y/n)"<<endl;
            cin>>more;
          } while(more == 'y');
        break;
        default :
          ;
      }

    } else if(option == '2') {
      char t = target(2);

      string id;
      string nombre;
      string titulacion;
      string speaker;
      Teacher teacher1 = Teacher();
      Teacher teacher2 = Teacher();
      Teacher supervisor = Teacher();
      Teacher tutor = Teacher();
      Teacher coTutor = Teacher();
      unsigned int credits;
      int capacity;
      //unsigned int grade;
      string auxN;
      string auxId;
      int pos;
      char more;

      switch (t) {
        case '4':
          do {

            /*ANSI escape codes:
            \033[2j clears the entire screen.
            \033[1;1H position the cursor at row 1, column 1.*/
            cout<<"\033[2J\033[1;1H";
            mostrarListas(t);
            cout<<"Asignatura a modificar: "<<endl;
            cin>>pos;

            cout<<"Introduce los nuevos datos: "<<endl;
            cout<<"Nombre: ";
            cin>>nombre;
            cout<<endl<<"ID: ";
            cin>>id;
            cout<<endl<<"Titulacion: ";
            cin>>titulacion;

            cout<<endl<<"Profesor 1: ";
            cout<<endl<<"Nombre: ";
            cin>>auxN;
            teacher1.setName(auxN);
            cout<<endl<<"ID: ";
            cin>>auxId;
            teacher1.setId(auxId);

            cout<<endl<<"Profesor 2: ";
            cout<<endl<<"Nombre: ";
            cin>>auxN;
            teacher2.setName(auxN);
            cout<<endl<<"ID: ";
            cin>>auxId;
            teacher2.setId(auxId);

            cout<<endl<<"Creditos: ";
            cin>>credits;

            list<Subjects*>::iterator it;

            for(int i = 0; i <= pos; ++i) {
              ++it;
            }
            (*it)->setName(nombre);
            (*it)->setId(id);
            (*it)->setTitulacion(titulacion);
            (*it)->setTeacher(teacher1, teacher2);
            (*it)->setCredits(credits);

            cout<<"¿Modificar mas asignaturas? (y/n)"<<endl;
            cin>>more;
          } while(more == 'y');
        break;
        case '5':
          do {

            /*ANSI escape codes:
            \033[2j clears the entire screen.
            \033[1;1H position the cursor at row 1, column 1.*/
            cout<<"\033[2J\033[1;1H";
            mostrarListas(t);
            cout<<"Seminario a modificar: "<<endl;
            cin>>pos;

            cout<<"Introduce los nuevos datos: "<<endl;
            cout<<"Nombre: ";
            cin>>nombre;
            cout<<endl<<"ID: ";
            cin>>id;
            cout<<endl<<"Ponente: ";
            cin>>speaker;

            cout<<endl<<"Supervisor: ";
            cout<<endl<<"Nombre: ";
            cin>>auxN;
            supervisor.setName(auxN);
            cout<<endl<<"ID: ";
            cin>>auxId;
            supervisor.setId(auxId);

            cout<<endl<<"Capacidad: ";
            cin>>capacity;

            Date* date;
            int dia,mes,anio;
            cout<<endl<<"Fecha: ";
            cout<<"  Dia: ";
            cin>>dia;
            cout<<"  Mes: ";
            cin>>mes;
            cout<<"  Año: ";
            cin>>anio;
            date = new Date(dia,mes,anio);

            list<Conference*>::iterator it;

            for(int i = 0; i <= pos; ++i) {
              ++it;
            }
            (*it)->setName(nombre);
            (*it)->setId(id);
            (*it)->setSpeaker(speaker);
            (*it)->setSupervisor(supervisor);
            (*it)->setCapacity(capacity);
            (*it)->setDate(date);

            cout<<"¿Modificar mas seminarios? (y/n)"<<endl;
            cin>>more;
          } while(more == 'y');
        break;
        case '6':
          do {

            /*ANSI escape codes:
            \033[2j clears the entire screen.
            \033[1;1H position the cursor at row 1, column 1.*/
            cout<<"\033[2J\033[1;1H";
            cout<<"\033[2J\033[1;1H";
            mostrarListas(t);
            cout<<"TFE a modificar: "<<endl;
            cin>>pos;

            cout<<"Introduce los nuevos datos: "<<endl;
            cout<<"Nombre: ";
            cin>>nombre;
            cout<<endl<<"ID: ";
            cin>>id;
            cout<<endl<<"Titulacion: ";
            cin>>titulacion;

            cout<<endl<<"Tutor: ";
            cout<<endl<<"Nombre: ";
            cin>>auxN;
            teacher1.setName(auxN);
            cout<<endl<<"ID: ";
            cin>>auxId;
            tutor.setId(auxId);

            cout<<endl<<"coTutor: ";
            cout<<endl<<"Nombre: ";
            cin>>auxN;
            teacher2.setName(auxN);
            cout<<endl<<"ID: ";
            cin>>auxId;
            coTutor.setId(auxId);

            list<TrabajoFinEstudios*>::iterator it;

            for(int i = 0; i <= pos; ++i) {
              ++it;
            }
            (*it)->setName(nombre);
            (*it)->setId(id);
            (*it)->setTitulacion(titulacion);
            (*it)->setTutor(tutor);
            (*it)->setCoTutor(coTutor);

            cout<<"¿Modificar mas TFEs? (y/n)"<<endl;
            cin>>more;
          } while(more == 'y');
        break;
        default :
          ;
      }

    } else if(option == '3') {
      int t = target(2);
      int pos;
      char more;

      switch (t) {
        case '4':
          do {

            /*ANSI escape codes:
            \033[2j clears the entire screen.
            \033[1;1H position the cursor at row 1, column 1.*/
            cout<<"\033[2J\033[1;1H";
            mostrarListas(t);
            cout<<"Asignatura a eliminar: "<<endl;
            cin>>pos;

            list<Subjects*>::iterator it;
            it = listaAsignaturas.begin();

            for(int i = 0; i < pos; ++i) {
              ++it;
            }
            it = listaAsignaturas.erase(it);

            cout<<"¿Eliminar mas asignatura? (y/n)"<<endl;
            cin>>more;
          } while(more == 'y');
        break;
        case '5':
          do {

            /*ANSI escape codes:
            \033[2j clears the entire screen.
            \033[1;1H position the cursor at row 1, column 1.*/
            cout<<"\033[2J\033[1;1H";
            cout<<"\033[2J\033[1;1H";
            mostrarListas(t);
            cout<<"Seminario a eliminar: "<<endl;
            cin>>pos;

            list<Conference*>::iterator it;
            it = listaSeminarios.begin();

            for(int i = 0; i < pos; ++i) {
              ++it;
            }
            it = listaSeminarios.erase(it);

            cout<<"¿Eliminar mas seminarios (y/n)"<<endl;
            cin>>more;
          } while(more == 'y');
        break;
        case '6':
          do {

            /*ANSI escape codes:
            \033[2j clears the entire screen.
            \033[1;1H position the cursor at row 1, column 1.*/
            cout<<"\033[2J\033[1;1H";
            cout<<"\033[2J\033[1;1H";
            mostrarListas(t);
            cout<<"TFE a eliminar: "<<endl;
            cin>>pos;

            list<TrabajoFinEstudios*>::iterator it;
            it = listaTFE.begin();

            for(int i = 0; i < pos; ++i) {
              ++it;
            }
            it = listaTFE.erase(it);

            cout<<"¿Eliminar mas TFE? (y/n)"<<endl;
            cin>>more;
          } while(more == 'y');
        break;
        default :
          ;
      }

    } else if(option == '4') {
      char t = target(2);
      mostrarListas(t);

    } else if(option == '<') {
      salir = true;

    } else {
      cout<<"Opcion erronea"<<endl;
    }
  } while (!salir);

  menuAdmin();
}

void CampusVirtual::cargarListas() {
  fstream fs("alumnos.dat", ios::in | ios::binary);
  string l = " ";
  Alumno* a = new Alumno();

  fs.seekg(0);
  while(getline(fs,l)) {
    if(l == "Alumno") {
      getline(fs,l);
      //cout<<l<<endl;
      a->setName(l);
      getline(fs,l);
      //cout<<l<<endl;
      a->setId(l);

      listaAlumnos.push_back(a);
    }
  }
  numAlum = listaAlumnos.size();
  fs.close();

  fs.open("profesores.dat", ios::in | ios::binary);
  l = " ";
  Teacher* p = new Teacher();

  fs.seekg(0);
  while(getline(fs,l)) {
    if(l == "Profesor") {
      getline(fs,l);
      //cout<<l<<endl;
      p->setName(l);
      getline(fs,l);
      //cout<<l<<endl;
      p->setId(l);

      listaProfesores.push_back(p);
    }
  }
  numProf = listaProfesores.size();
  fs.close();

  fs.open("admins.dat", ios::in | ios::binary);
  l = " ";
  Administrator* ad = new Administrator();

  fs.seekg(0);
  while(getline(fs,l)) {
    if(l == "Admin") {
      getline(fs,l);
      //cout<<l<<endl;
      ad->setName(l);
      getline(fs,l);
      //cout<<l<<endl;
      ad->setId(l);

      listaAdmins.push_back(ad);
    }
  }
  numAdmin = listaAdmins.size();
  fs.close();

  fs.open("asignaturas.dat", ios::in | ios::binary);
  l = " ";
  Subjects* s = new Subjects();

  fs.seekg(0);
  while(getline(fs,l)) {
    if(l == "Asignatura") {
      getline(fs,l);
      //cout<<l<<endl;
      s->setName(l);
      getline(fs,l);
      //cout<<l<<endl;
      s->setId(l);
      getline(fs,l);
      s->setTitulacion(l);
      getline(fs,l);
      Teacher t1 = Teacher();
      Teacher t2 = Teacher();
      t1.setName(l);
      getline(fs,l);
      t1.setId(l);
      getline(fs,l);
      t2.setName(l);
      getline(fs,l);
      t2.setId(l);
      s->setTeacher(t1,t2);
      getline(fs,l);
      int cr = stoi(l,nullptr);
      s->setCredits(cr);

      listaAsignaturas.push_back(s);
    }
  }
  numAsig = listaAsignaturas.size();
  fs.close();

  fs.open("seminarios.dat", ios::in | ios::binary);
  l = " ";
  Conference* c = new Conference();

  fs.seekg(0);
  while(getline(fs,l)) {
    if(l == "Seminario") {
      getline(fs,l);
      //cout<<l<<endl;
      c->setName(l);
      getline(fs,l);
      //cout<<l<<endl;
      c->setId(l);
      Teacher supervisor = Teacher();
      getline(fs,l);
      supervisor.setName(l);
      getline(fs,l);
      supervisor.setId(l);
      c->setSupervisor(supervisor);
      getline(fs,l);
      c->setSpeaker(l);
      getline(fs,l);
      //String to int
      int ca = stoi(l,nullptr);
      c->setCapacity(ca);
      Date* date;
      getline(fs,l,' ');
      int dia = stoi(l,nullptr);
      getline(fs,l,' ');
      int mes = stoi(l,nullptr);
      getline(fs,l,' ');
      int anio = stoi(l,nullptr);
      date = new Date(dia,mes,anio);
      c->setDate(date);

      listaSeminarios.push_back(c);
    }
  }
  numSem = listaSeminarios.size();
  fs.close();

  fs.open("tfe.dat", ios::in | ios::binary);
  l = " ";
  TrabajoFinEstudios* tfe = new TrabajoFinEstudios();

  fs.seekg(0);
  while(getline(fs,l)) {
    if(l == "TFE") {
      getline(fs,l);
      //cout<<l<<endl;
      tfe->setName(l);
      getline(fs,l);
      //cout<<l<<endl;
      tfe->setId(l);
      getline(fs,l);
      tfe->setTitulacion(l);
      getline(fs,l);
      Teacher tutor = Teacher();
      Teacher coTutor = Teacher();
      tutor.setName(l);
      getline(fs,l);
      tutor.setId(l);
      getline(fs,l);
      coTutor.setName(l);
      getline(fs,l);
      coTutor.setId(l);
      tfe->setTutor(tutor);
      tfe->setCoTutor(coTutor);
      getline(fs,l);

      listaTFE.push_back(tfe);
    }
  }
  numTFE = listaTFE.size();
  fs.close();

}

void CampusVirtual::mostrarListas(char t) {

  if(t == '1') {
    list<Alumno*>::const_iterator it;
    it = listaAlumnos.begin();
    int i = 0;
    //Alumnos
    /*ANSI escape codes:
    \033[2j clears the entire screen.
    \033[1;1H position the cursor at row 1, column 1.*/
    cout<<"\033[2J\033[1;1H";

    while(it != listaAlumnos.end()) {
      cout<<i<<". "<<"Alumno: "<<(*it)->getName()
        <<" "<<"NIA: "<<(*it)->getId()<<endl;
        ++it;
        ++i;
    }

    char temp;
    do {
      cout<<"Presiona ESC para continuar";
      cin>>temp;
    //27 is ESC key in ASCII
    } while(temp != 27);
  } else if(t == '2') {
    list<Teacher*>::const_iterator it;
    it = listaProfesores.begin();
    int i = 0;
    //Profesores
    /*ANSI escape codes:
    \033[2j clears the entire screen.
    \033[1;1H position the cursor at row 1, column 1.*/
    cout<<"\033[2J\033[1;1H";
    while(it != listaProfesores.end()) {
      cout<<i<<". "<<"Profesor: "<<(*it)->getName()
        <<" "<<"ID: "<<(*it)->getId()<<endl;
        ++it;
        ++i;
    }

    char temp;
    do {
      cout<<"Presiona ESC para continuar";
      cin>>temp;
    //27 is ESC key in ASCII
    } while(temp != 27);
  } else if(t == '3') {
    list<Administrator*>::const_iterator it;
    it = listaAdmins.begin();
    int i = 0;
    //Administradores
    /*ANSI escape codes:
    \033[2j clears the entire screen.
    \033[1;1H position the cursor at row 1, column 1.*/
    cout<<"\033[2J\033[1;1H";
    while(it != listaAdmins.end()) {
      cout<<i<<". "<<"Administrador: "<<(*it)->getName()
        <<" "<<"ID: "<<(*it)->getId()<<endl;
        ++it;
        ++i;
    }

    char temp;
    do {
      cout<<"Presiona ESC para continuar";
      cin>>temp;
    //27 is ESC key in ASCII
    } while(temp != 27);
  } else if(t == '4') {
    //Asignaturas
    list<Subjects*>::const_iterator it;
    it = listaAsignaturas.begin();
    int i = 0;
    //Alumnos
    /*ANSI escape codes:
    \033[2j clears the entire screen.
    \033[1;1H position the cursor at row 1, column 1.*/
    cout<<"\033[2J\033[1;1H";

    while(it != listaAsignaturas.end()) {
      cout<<i<<". "<<"Asignatura: "<<(*it)->getName()
        <<" "<<"ID: "<<(*it)->getId()
        <<" "<<"Titulacion: "<<(*it)->getTitulacion()
        <<" "<<"Creditos: "<<(*it)->getCredits()
        <<" "<<"Profesor 1: "<<(*it)->getTeacher1().getName()
        <<" "<<"Profesor 1: "<<(*it)->getTeacher1().getId()
        <<" "<<"Profesor 2: "<<(*it)->getTeacher2().getName()
        <<" "<<"Profesor 2: "<<(*it)->getTeacher2().getId()<<endl;
        ++it;
        ++i;
    }

    char temp;
    do {
      cout<<"Presiona ESC para continuar";
      cin>>temp;
    //27 is ESC key in ASCII
    } while(temp != 27);
  } else if(t == '5') {
    //Seminarios
    list<Conference*>::const_iterator it;
    it = listaSeminarios.begin();
    int i = 0;
    //Alumnos
    /*ANSI escape codes:
    \033[2j clears the entire screen.
    \033[1;1H position the cursor at row 1, column 1.*/
    cout<<"\033[2J\033[1;1H";

    while(it != listaSeminarios.end()) {
      cout<<i<<". "<<"Seminario: "<<(*it)->getName()
        <<" "<<"ID: "<<(*it)->getId()
        <<" "<<"Supervisor: "<<(*it)->getSupervisor().getName()
        <<" "<<(*it)->getSupervisor().getId()
        <<" "<<"Ponente: "<<(*it)->getSpeaker()
        <<" "<<"Capacidad: "<<(*it)->getCapacity()
        <<" "<<"Fecha: "<<(*it)->getDate()->returnDay()
        <<"-"<<(*it)->getDate()->returnMonth()
        <<"-"<<(*it)->getDate()->returnYear()<<endl;
        ++it;
        ++i;
    }

    char temp;
    do {
      cout<<"Presiona ESC para continuar";
      cin>>temp;
    //27 is ESC key in ASCII
    } while(temp != 27);
  } else if(t == '6') {
    //TFE
    list<TrabajoFinEstudios*>::const_iterator it;
    it = listaTFE.begin();
    int i = 0;
    //Alumnos
    /*ANSI escape codes:
    \033[2j clears the entire screen.
    \033[1;1H position the cursor at row 1, column 1.*/
    cout<<"\033[2J\033[1;1H";

    while(it != listaTFE.end()) {
      cout<<1<<". "<<"TFE: "<<(*it)->getName()
        <<" "<<"ID: "<<(*it)->getId()
        <<" "<<"Titulacion: "<<(*it)->getTitulacion()
        <<" "<<"Tutor: "<<(*it)->getTutor().getName()
        <<" "<<"Tutor: "<<(*it)->getTutor().getId()
        <<" "<<"Co-Tutor: "<<(*it)->getCoTutor().getName()
        <<" "<<"Co-Tutor: "<<(*it)->getCoTutor().getId()<<endl;
        ++it;
        ++i;
    }

    char temp;
    do {
      cout<<"Presiona ESC para continuar";
      cin>>temp;
    //27 is ESC key in ASCII
    } while(temp != 27);
  } else {
    cout<<"Error"<<endl;
  }
}

void CampusVirtual::escribirLista() {
  fstream fs("admins.dat", ios::out | ios::in | ios::trunc | ios::binary);
  fs.seekp(0);
  list<Administrator*>::const_iterator it;
  it = listaAdmins.begin();
  while(it != listaAdmins.end()) {
    fs << "Admin" << "\n" << flush;
    fs << (*it)->getName() << "\n" <<flush;
    fs << (*it)->getId() << "\n" <<flush;
    ++it;
  }

  fs.close();

  fs.open("profesores.dat", ios::out | ios::trunc | ios::binary);
  fs.seekp(0);
  list<Teacher*>::const_iterator it2;
  it2 = listaProfesores.begin();
  while(it2 != listaProfesores.end()) {
    fs << "Profesor" << "\n" << flush;
    fs << (*it2)->getName() << "\n" <<flush;
    fs << (*it2)->getId() << "\n" <<flush;
    ++it2;
  }

  fs.close();

  fs.open("alumnos.dat", ios::out | ios::trunc | ios::binary);
  fs.seekp(0);
  list<Alumno*>::const_iterator it3;
  it3 = listaAlumnos.begin();
  while(it3 != listaAlumnos.end()) {
    fs << "Alumno" << "\n" << flush;
    fs << (*it3)->getName() << "\n" <<flush;
    fs << (*it3)->getId() << "\n" <<flush;
    ++it3;
  }

  fs.close();

  fs.open("asignaturas.dat", ios::out | ios::trunc | ios::binary);
  fs.seekp(0);
  list<Subjects*>::const_iterator it4;
  it4 = listaAsignaturas.begin();
  while(it4 != listaAsignaturas.end()) {
    fs<<"Asignatura"<<"\n"<<flush;
    fs<<(*it4)->getName()<<"\n"<<flush;
    fs<<(*it4)->getId()<<"\n"<<flush;
    fs<<(*it4)->getTitulacion()<<"\n"<<flush;
    fs<<(*it4)->getTeacher1().getName()<<"\n"<<flush;
    fs<<(*it4)->getTeacher1().getId()<<"\n"<<flush;
    fs<<(*it4)->getTeacher2().getName()<<"\n"<<flush;
    fs<<(*it4)->getTeacher2().getId()<<"\n"<<flush;
    fs<<(*it4)->getCredits()<<"\n"<<flush;
    ++it4;
  }

  fs.close();

  fs.open("seminarios.dat", ios::out | ios::trunc | ios::binary);
  fs.seekp(0);
  list<Conference*>::const_iterator it5;
  it5 = listaSeminarios.begin();
  while(it5 != listaSeminarios.end()) {
    fs<<"Seminario"<<"\n"<<flush;
    fs<<(*it5)->getName()<<"\n"<<flush;
    fs<<(*it5)->getId()<<"\n"<<flush;
    fs<<(*it5)->getSupervisor().getName()<<"\n"<<flush;
    fs<<(*it5)->getSupervisor().getId()<<"\n"<<flush;
    fs<<(*it5)->getSpeaker()<<"\n"<<flush;
    fs<<(*it5)->getCapacity()<<"\n"<<flush;
    fs<<(*it5)->getDate()->returnDay()<<" "<<flush;
    fs<<(*it5)->getDate()->returnMonth()<<" "<<flush;
    fs<<(*it5)->getDate()->returnYear()<<"\n"<<flush;
    ++it5;
  }

  fs.close();

  fs.open("tfe.dat", ios::out | ios::trunc | ios::binary);
  fs.seekp(0);
  list<TrabajoFinEstudios*>::const_iterator it6;
  it6 = listaTFE.begin();
  while(it6 != listaTFE.end()) {
    fs<<"TFE"<<"\n"<<flush;
    fs<<(*it6)->getName()<<"\n"<<flush;
    fs<<(*it6)->getId()<<"\n"<<flush;
    fs<<(*it6)->getTitulacion()<<"\n"<<flush;
    fs<<(*it6)->getTutor().getName()<<"\n"<<flush;
    fs<<(*it6)->getTutor().getId()<<"\n"<<flush;
    fs<<(*it6)->getCoTutor().getName()<<"\n"<<flush;
    fs<<(*it6)->getCoTutor().getId()<<"\n"<<flush;
    ++it6;
  }

  fs.close();
}

void CampusVirtual::cerrarSesion() {
  escribirLista();
  listaAlumnos.clear();
  listaProfesores.clear();
  listaAdmins.clear();
  listaAsignaturas.clear();
  listaSeminarios.clear();
  listaTFE.clear();
  inicio();
}
