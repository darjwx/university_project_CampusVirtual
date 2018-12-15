//TODO fix endless loops in menus when entering chars
//TODO poner a null la posicion de los alumno eliminados.
//No imprimir ese alumno si esta a null.
//Eliminar las posiciones con null al finalizar en la lista de alumnos principal
//y en la lista de alumnos de las asginaturas.

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
            currentUserId = id;
            currentUserName = nombre;
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
            currentUserId = id;
            currentUserName = nombre;
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
            currentUserId = id;
            currentUserName = nombre;
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
      altaRecurso();
    break;
    case '2':
      //bajaRecurso();
    break;
    case '3':
      mostrarRecursosAlta();
    break;
    case '<':
      cerrarSesion();
    break;
    default :
      cout<<"Opcion erronea"<<endl;
  }
}

void CampusVirtual::menuAdmin() {
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
            mostrarListas(t);
            cout<<"Profesor a eliminar: "<<endl;
            cin>>pos;

            list<Teacher*>::iterator it;
            it = listaProfesores.begin();

            for(int i = 0; i < pos; ++i) {
              ++it;
            }

            list<Subjects*>::iterator it_as;
            list<Conference*>::iterator it_sem;
            list<TrabajoFinEstudios*>::iterator it_tfe;
            it_as = listaAsignaturas.begin();
            it_sem = listaSeminarios.begin();
            it_tfe = listaTFE.begin();
            for(unsigned int i=0;i<numAsig;i++){
              if((*it_as)->getTeacher1() != NULL) {
                if((*it_as)->getTeacher1()->getId()==(*it)->getId()){
                  (*it_as)->NullT1();
                }
              }
              if((*it_as)->getTeacher2() != NULL) {
                if((*it_as)->getTeacher2()->getId()==(*it)->getId()){
                  (*it_as)->NullT2();
                }
              }
              ++it_as;
            }
            for(unsigned int i=0;i<numSem;i++){
              if((*it_sem)->getSupervisor() != NULL) {
                if((*it_sem)->getSupervisor()->getId()==(*it)->getId()){
                  (*it_sem)->NullS();
                }
              }
              ++it_sem;
            }
            for(unsigned int i=0;i<numTFE;i++){
              if((*it_tfe)->getTutor() != NULL) {
                if((*it_tfe)->getTutor()->getId()==(*it)->getId()){
                  (*it_tfe)->NullT();
                }
              }
              if((*it_tfe)->getCoTutor() != NULL) {
                if((*it_tfe)->getCoTutor()->getId()==(*it)->getId()){
                  (*it_tfe)->NullCT();
                }
              }
              ++it_tfe;
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
      Date* date;
      unsigned int credits;
      int capacity;
      //unsigned int grade;
      string auxId;

      char more;

      switch (t) {
        case '4':
          do {
            list<Teacher*>::const_iterator it_pr;
            Teacher* teacher1 = new Teacher();
            Teacher* teacher2 = new Teacher();

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

            it_pr = listaProfesores.begin();
            bool exit = false;
            cout<<endl<<"Profesor 1: ";
            cout<<endl<<"ID: ";
            cin>>auxId;

            while(it_pr != listaProfesores.end()) {
             if(auxId == (*it_pr)->getId()) {
               teacher1 = (*it_pr);
               exit = true;
             }
             //Evita que se incremente si se ha encontrado los datos en la lista
             if(!exit) {
               ++it_pr;
             } else {
               it_pr = listaProfesores.end();
             }
            }
            if(!exit) {
              cout<<"El profesor no esta dado de alta"<<endl
                <<"Profesor no asignado"<<endl;
              teacher1 = NULL;
            }

            it_pr = listaProfesores.begin();
            exit = false;
            cout<<endl<<"Profesor 2: ";
            cout<<endl<<"ID: ";
            cin>>auxId;
            while(it_pr != listaProfesores.end()) {
             if(auxId == (*it_pr)->getId()) {
               teacher2 = (*it_pr);
               exit = true;
             }
             //Evita que se incremente si se ha encontrado los datos en la lista
             if(!exit) {
               ++it_pr;
             } else {
               it_pr = listaProfesores.end();
             }
            }
            if(!exit) {
              cout<<"El profesor no esta dado de alta"<<endl
                <<"Profesor no asignado"<<endl;
              teacher2 = NULL;
            }

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

            list<Teacher*>::const_iterator it_pr;
            Teacher* supervisor = new Teacher();
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

            it_pr = listaProfesores.begin();
            bool exit = false;
            cout<<endl<<"Supervisor: ";
            cout<<endl<<"ID: ";
            cin>>auxId;
            while(it_pr != listaProfesores.end()) {
             if(auxId == (*it_pr)->getId()) {
               supervisor = (*it_pr);
               exit = true;
             }
             //Evita que se incremente si se ha encontrado los datos en la lista
             if(!exit) {
               ++it_pr;
             } else {
               it_pr = listaProfesores.end();
             }
            }
            if(!exit) {
              cout<<"El profesor no esta dado de alta"<<endl
                <<"Supervisor no asignado"<<endl;
              supervisor = NULL;
            }

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

            list<Teacher*>::const_iterator it_pr;
            Teacher* tutor = new Teacher();
            Teacher* coTutor = new Teacher();
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

            it_pr = listaProfesores.begin();
            bool exit = false;
            cout<<endl<<"Tutor: ";
            cout<<endl<<"ID: ";
            cin>>auxId;
            while(it_pr != listaProfesores.end()) {
             if(auxId == (*it_pr)->getId()) {
               tutor = (*it_pr);
               exit = true;
             }
             //Evita que se incremente si se ha encontrado los datos en la lista
             if(!exit) {
               ++it_pr;
             } else {
               it_pr = listaProfesores.end();
             }
            }
            if(!exit) {
              cout<<"El profesor no esta dado de alta"<<endl
                <<"Tutor no asignado"<<endl;
              tutor = NULL;
            }

            it_pr = listaProfesores.begin();
            exit = false;
            cout<<endl<<"coTutor: ";
            cout<<endl<<"ID: ";
            cin>>auxId;
            while(it_pr != listaProfesores.end()) {
             if(auxId == (*it_pr)->getId()) {
               coTutor = (*it_pr);
               exit = true;
             }
             //Evita que se incremente si se ha encontrado los datos en la lista
             if(!exit) {
               ++it_pr;
             } else {
               it_pr = listaProfesores.end();
             }
            }
            if(!exit) {
              cout<<"El profesor no esta dado de alta"<<endl
                <<"CoTutor no asignado"<<endl;
              coTutor = NULL;
            }

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
            Teacher* teacher1 = new Teacher();
            Teacher* teacher2 = new Teacher();

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
            teacher1->setName(auxN);
            cout<<endl<<"ID: ";
            cin>>auxId;
            teacher1->setId(auxId);

            cout<<endl<<"Profesor 2: ";
            cout<<endl<<"Nombre: ";
            cin>>auxN;
            teacher2->setName(auxN);
            cout<<endl<<"ID: ";
            cin>>auxId;
            teacher2->setId(auxId);

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
            Teacher* supervisor = new Teacher();

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
            supervisor->setName(auxN);
            cout<<endl<<"ID: ";
            cin>>auxId;
            supervisor->setId(auxId);

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
            Teacher* tutor = new Teacher();
            Teacher* coTutor = new Teacher();

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
            tutor->setName(auxN);
            cout<<endl<<"ID: ";
            cin>>auxId;
            tutor->setId(auxId);

            cout<<endl<<"coTutor: ";
            cout<<endl<<"Nombre: ";
            cin>>auxN;
            coTutor->setName(auxN);
            cout<<endl<<"ID: ";
            cin>>auxId;
            coTutor->setId(auxId);

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

void CampusVirtual::altaRecurso() {
  char salir;
  do {
    char t = target(2);
    list<Alumno*>::const_iterator ita;
    list<Subjects*>::iterator it;
    list<Conference*>::iterator it2;
    list<TrabajoFinEstudios*>::iterator it3;
    int opcion = 0;
    bool exit = false;

    switch(t) {
      case '4':
        mostrarListas('4');
        cout<<"¿En que asignatura quieres darte de alta?"<<endl;
        cin>>opcion;

        it = listaAsignaturas.begin();
        ita = listaAlumnos.begin();

        for(int i = 0; i < opcion; ++i) {
          ++it;
        }
         while(!exit) {
          if(currentUserName == (*ita)->getName()) {
            if(currentUserId == (*ita)->getId()) {
              exit = true;
            }
          }
          //Evita que se incremente si se ha encontrado los datos en la lista
          if(!exit) {
            ++ita;
          }
        }
        (*it)->setAlumnosApuntados((*ita));
        (*ita)->setSubjects(*it);

      break;
      case '5':
        mostrarListas('5');
        cout<<"¿En que seminario quieres darte de alta?"<<endl;
        cin>>opcion;

        it2 = listaSeminarios.begin();
        ita = listaAlumnos.begin();

        for(int i = 0; i < opcion; ++i) {
          ++it2;
        }
        while(!exit) {
         if(currentUserName == (*ita)->getName()) {
           if(currentUserId == (*ita)->getId()) {
             exit = true;
           }
         }
         //Evita que se incremente si se ha encontrado los datos en la lista
         if(!exit) {
           ++ita;
         }
       }
        (*it2)->setAlumnosApuntados((*ita));
        (*ita)->setConferences(*it2);
      break;
      case '6':
        mostrarListas('6');
        cout<<"¿En que tfe quieres darte de alta?"<<endl;
        cin>>opcion;

        it3 = listaTFE.begin();
        ita = listaAlumnos.begin();

        for(int i = 0; i < opcion; ++i) {
          ++it3;
        }
        while(!exit) {
         if(currentUserName == (*ita)->getName()) {
           if(currentUserId == (*ita)->getId()) {
             exit = true;
           }
         }
         //Evita que se incremente si se ha encontrado los datos en la lista
         if(!exit) {
           ++ita;
         }
       }
        (*it3)->setAlumnoApuntado((*ita));
        (*ita)->setTFE(*it3);
      break;
      default:
        ;
    }
    cout<<"¿Darse de alta en mas recursos?(s/n)"<<endl;
    cin>>salir;
  } while(salir == 's');
  menuAlumno();
}

void CampusVirtual::bajaRecurso() {

}

void CampusVirtual::mostrarRecursosAlta() {
  list<Alumno*>::iterator ita = listaAlumnos.begin();
  list<Subjects*>::iterator asignaturas;
  list<Conference*>::iterator seminarios;
  list<TrabajoFinEstudios*>::iterator tfe;
  bool exit = false;
  int i = 0;

  while(!exit) {
   if(currentUserName == (*ita)->getName()) {
     if(currentUserId == (*ita)->getId()) {
       exit = true;
     }
   }
   //Evita que se incremente si se ha encontrado los datos en la lista
   if(!exit) {
     ++ita;
   }
 }

   /*ANSI escape codes:
   \033[2j clears the entire screen.
   \033[1;1H position the cursor at row 1, column 1.*/
   cout<<"\033[2J\033[1;1H";

   asignaturas = (*ita)->getItBegin();
   cout<<"ASIGNATURAS: "<<endl;
   while(asignaturas != (*ita)->getItEnd()) {
     cout<<i<<". "<<"Asignatura: "<<(*asignaturas)->getName()
       <<" "<<"ID: "<<(*asignaturas)->getId()
       <<" "<<"Titulacion: "<<(*asignaturas)->getTitulacion()
       <<" "<<"Creditos: "<<(*asignaturas)->getCredits()
       <<" "<<"Profesor 1: "<<(*asignaturas)->getTeacher1()->getName()
       <<" "<<"Profesor 1: "<<(*asignaturas)->getTeacher1()->getId()
       <<" "<<"Profesor 2: "<<(*asignaturas)->getTeacher2()->getName()
       <<" "<<"Profesor 2: "<<(*asignaturas)->getTeacher2()->getId()<<endl;
       ++asignaturas;
       ++i;
   }

   seminarios = (*ita)->getItBeginConference();
   cout<<"SEMINARIOS: "<<endl;
   while(seminarios != (*ita)->getItEndConference()) {
     cout<<i<<". "<<"Seminario: "<<(*seminarios)->getName()
       <<" "<<"ID: "<<(*seminarios)->getId()
       <<" "<<"Supervisor: "<<(*seminarios)->getSupervisor()->getName()
       <<" "<<(*seminarios)->getSupervisor()->getId()
       <<" "<<"Ponente: "<<(*seminarios)->getSpeaker()
       <<" "<<"Capacidad: "<<(*seminarios)->getCapacity()
       <<" "<<"Fecha: "<<(*seminarios)->getDate()->returnDay()
       <<"/"<<(*seminarios)->getDate()->returnMonth()
       <<"/"<<(*seminarios)->getDate()->returnYear()<<endl;
       ++seminarios;
       ++i;
   }

   tfe = (*ita)->getItBeginTFE();
   cout<<"TRABAJOS FIN ESTUDIOS: "<<endl;
   while(tfe != (*ita)->getItEndTFE()) {
     cout<<i<<". "<<"TFE: "<<(*tfe)->getName()
       <<" "<<"ID: "<<(*tfe)->getId()
       <<" "<<"Titulacion: "<<(*tfe)->getTitulacion()
       <<" "<<"Tutor: "<<(*tfe)->getTutor()->getName()
       <<" "<<"Tutor: "<<(*tfe)->getTutor()->getId()
       <<" "<<"Co-Tutor: "<<(*tfe)->getCoTutor()->getName()
       <<" "<<"Co-Tutor: "<<(*tfe)->getCoTutor()->getId()<<endl;
       ++tfe;
       ++i;
   }

   char temp;
   do {
     cout<<"Presiona ESC para continuar";
     cin>>temp;
   //27 is ESC key in ASCII
   } while(temp != 27);
   menuAlumno();

}

void CampusVirtual::cargarListas() {
  fstream fs("alumnos.dat", ios::in | ios::binary);
  string l = " ";
  list <Teacher*>::iterator it_pr;

  fs.seekg(0);
  while(getline(fs,l)) {
    Alumno* a = new Alumno();
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

  fs.seekg(0);
  while(getline(fs,l)) {
    Teacher* p = new Teacher();
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

  fs.seekg(0);
  while(getline(fs,l)) {
    Administrator* ad = new Administrator();
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

  fs.seekg(0);
  while(getline(fs,l)) {
    Subjects* s = new Subjects();
    if(l == "Asignatura") {
      getline(fs,l);
      s->setName(l);
      getline(fs,l);
      s->setId(l);
      getline(fs,l);
      s->setTitulacion(l);
      getline(fs,l);
      if(l=="NULL"){
        s->NullT1();
      }
      else{
        it_pr=listaProfesores.begin();
        for(unsigned int i=0;i<numProf;i++){
          if((*it_pr)->getId()==l){
            s->setTeacher1(*it_pr);
            i=numProf;
          }
          it_pr++;
        }
      }
      getline(fs,l);
      if(l=="NULL"){
        s->NullT2();
      }
      else{
        it_pr=listaProfesores.begin();
        for(unsigned int i=0;i<numProf;i++){
          if((*it_pr)->getId()==l){
            s->setTeacher2(*it_pr);
            i=numProf;
          }
        }
      }
      getline(fs,l);
      int cr = stoi(l,nullptr);
      s->setCredits(cr);

      getline(fs,l);
      string name;
      string id;
      if (l == "Lista") {
        getline(fs,l);
        name = l;
        getline(fs,l);
        id = l;
        Alumno* a = new Alumno(name,id);
        s->setAlumnosApuntados(a);

        bool exit = false;
        list<Alumno*>::iterator aux = listaAlumnos.begin();
        while(aux != listaAlumnos.end()) {
         if(name == (*aux)->getName()) {
           if(id == (*aux)->getId()) {
             (*aux)->setSubjects(s);
             exit = true;
           }
         }
         //Evita que se incremente si se ha encontrado los datos en la lista
         if(!exit) {
           ++aux;
         }
       }
      }

      listaAsignaturas.push_back(s);
    }
  }
  numAsig = listaAsignaturas.size();
  fs.close();

  fs.open("seminarios.dat", ios::in | ios::binary);
  l = " ";

  fs.seekg(0);
  while(getline(fs,l)) {
    Conference* c = new Conference();
    if(l == "Seminario") {
      getline(fs,l);
      c->setName(l);
      getline(fs,l);
      c->setId(l);
      getline(fs,l);
      if(l=="NULL"){
        c->NullS();
      }
      else{
        it_pr=listaProfesores.begin();
        for(unsigned int i=0;i<numProf;i++){
          if((*it_pr)->getId()==l){
            c->setSupervisor(*it_pr);
            i=numProf;
          }
          it_pr++;
        }
      }
      getline(fs,l);
      c->setSpeaker(l);
      getline(fs,l);
      //String to int
      int ca = stoi(l,nullptr);
      c->setCapacity(ca);
      Date* date;
      getline(fs,l,'/');
      int dia = stoi(l,nullptr);
      getline(fs,l,'/');
      int mes = stoi(l,nullptr);
      getline(fs,l);
      int anio = stoi(l,nullptr);
      date = new Date(dia,mes,anio);
      c->setDate(date);

      getline(fs,l);
      string name;
      string id;
      if (l == "Lista") {
        getline(fs,l);
        name = l;
        getline(fs,l);
        id = l;
        Alumno* a = new Alumno(name,id);
        c->setAlumnosApuntados(a);

        bool exit = false;
        list<Alumno*>::iterator aux = listaAlumnos.begin();
        while(!exit) {
         if(name == (*aux)->getName()) {
           if(id == (*aux)->getId()) {
             (*aux)->setConferences(c);
             exit = true;
           }
         }
         //Evita que se incremente si se ha encontrado los datos en la lista
         if(!exit) {
           ++aux;
         }
       }

      }

      listaSeminarios.push_back(c);
    }
  }
  numSem = listaSeminarios.size();
  fs.close();

  fs.open("tfe.dat", ios::in | ios::binary);
  l = " ";

  fs.seekg(0);
  while(getline(fs,l)) {
    TrabajoFinEstudios* tfe = new TrabajoFinEstudios();
    if(l == "TFE") {
      getline(fs,l);
      tfe->setName(l);
      getline(fs,l);
      tfe->setId(l);
      getline(fs,l);
      tfe->setTitulacion(l);
      getline(fs,l);
      if(l=="NULL"){
        tfe->NullT();
      }
      else{
        it_pr=listaProfesores.begin();
        for(unsigned int i=0;i<numProf;i++){
          if((*it_pr)->getId()==l){
            tfe->setTutor(*it_pr);
            i=numProf;
          }
          it_pr++;
        }
      }
      getline(fs,l);
      if(l=="NULL"){
        tfe->NullCT();
      }
      else{
        it_pr=listaProfesores.begin();
        for(unsigned int i=0;i<numProf;i++){
          if((*it_pr)->getId()==l){
            tfe->setCoTutor(*it_pr);
            i=numProf;
          }
          it_pr++;
        }
      }

      getline(fs,l);
      string name;
      string id;
      if (l == "Lista") {
        getline(fs,l);
        name = l;
        getline(fs,l);
        id = l;
        Alumno* a = new Alumno(name,id);
        tfe->setAlumnoApuntado(a);

        bool exit = false;
        list<Alumno*>::iterator aux = listaAlumnos.begin();
        while(!exit) {
         if(name == (*aux)->getName()) {
           if(id== (*aux)->getId()) {
             (*aux)->setTFE(tfe);
             exit = true;
           }
         }
         //Evita que se incremente si se ha encontrado los datos en la lista
         if(!exit) {
           ++aux;
         }
       }

      }

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
        <<" "<<"Creditos: "<<(*it)->getCredits()<<endl;
        if((*it)->getTeacher1() == NULL) {
          cout<<" "<<"Profesor 1: "<<"Sin asignar"
            <<" "<<"Profesor 1: "<<"Sin asignar"<<endl;
        } else {
          cout<<" "<<"Profesor 1: "<<(*it)->getTeacher1()->getName()
            <<" "<<"Profesor 1: "<<(*it)->getTeacher1()->getId()<<endl;
        }
        if((*it)->getTeacher2() == NULL) {
          cout<<" "<<"Profesor 2: "<<"Sin asignar"
            <<" "<<"Profesor 2: "<<"Sin asignar"<<endl;

        } else {
          cout<<" "<<"Profesor 2: "<<(*it)->getTeacher2()->getName()
            <<" "<<"Profesor 2: "<<(*it)->getTeacher2()->getId()<<endl;
        }
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
        <<" "<<"ID: "<<(*it)->getId()<<endl;
        if((*it)->getSupervisor() == NULL) {
          cout<<" "<<"Supervisor: "<<"Sin asignar"
            <<" "<<"Supervisor: "<<"Sin asignar"<<endl;
        } else {
          cout<<" "<<"Supervisor: "<<(*it)->getSupervisor()->getName()
            <<" "<<"Supervisor: "<<(*it)->getSupervisor()->getId()<<endl;
        }
        cout<<" "<<"Ponente: "<<(*it)->getSpeaker()
          <<" "<<"Capacidad: "<<(*it)->getCapacity()
          <<" "<<"Fecha: "<<(*it)->getDate()->returnDay()
          <<"/"<<(*it)->getDate()->returnMonth()
          <<"/"<<(*it)->getDate()->returnYear()<<endl;
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
      cout<<i<<". "<<"TFE: "<<(*it)->getName()
        <<" "<<"ID: "<<(*it)->getId()
        <<" "<<"Titulacion: "<<(*it)->getTitulacion()<<endl;
        if((*it)->getTutor() == NULL) {
          cout<<" "<<"Tutor: "<<"Sin asignar"
            <<" "<<"Tutor: "<<"Sin asignar"<<endl;
        } else {
          cout<<" "<<"Tutor: "<<(*it)->getTutor()->getName()
            <<" "<<"Tutor: "<<(*it)->getTutor()->getId()<<endl;
        }
        if((*it)->getCoTutor() == NULL) {
          cout<<" "<<"CoTutor: "<<"Sin asignar"
            <<" "<<"CoTutor: "<<"Sin asignar"<<endl;

        } else {
          cout<<" "<<"CoTutor: "<<(*it)->getCoTutor()->getName()
            <<" "<<"CoTutor: "<<(*it)->getCoTutor()->getId()<<endl;
        }
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
  fstream fs("admins.dat", ios::out | ios::trunc | ios::binary);
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
  list<Alumno*>::const_iterator itAlumnos;
  it4 = listaAsignaturas.begin();
  while(it4 != listaAsignaturas.end()) {
    fs<<"Asignatura"<<"\n"<<flush;
    fs<<(*it4)->getName()<<"\n"<<flush;
    fs<<(*it4)->getId()<<"\n"<<flush;
    fs<<(*it4)->getTitulacion()<<"\n"<<flush;
    if((*it4)->getTeacher1()==NULL){
      fs << "NULL" <<"\n"<<flush;
    }
    else{
      fs << (*it4)->getTeacher1()->getId() << "\n" <<flush;
    }
    if((*it4)->getTeacher2()==NULL){
      fs << "NULL" <<"\n"<<flush;
    }
    else{
      fs << (*it4)->getTeacher2()->getId() << "\n" <<flush;
    }
    fs<<(*it4)->getCredits()<<"\n"<<flush;

    itAlumnos = (*it4)->getItBegin();
    for(; itAlumnos != (*it4)->getItEnd(); ++itAlumnos) {
      fs<<"Lista"<<"\n"<<flush;
      fs<<(*itAlumnos)->getName()<<"\n"<<flush;
      fs<<(*itAlumnos)->getId()<<"\n"<<flush;
    }
    fs<<"END"<<"\n"<<flush;
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

    if((*it5)->getSupervisor()==NULL){
      fs << "NULL" <<"\n"<<flush;
    }
    else{
      fs << (*it5)->getSupervisor()->getId() << "\n" <<flush;
    }
    fs<<(*it5)->getSpeaker()<<"\n"<<flush;
    fs<<(*it5)->getCapacity()<<"\n"<<flush;
    fs<<(*it5)->getDate()->returnDay()<<'/'<<flush;
    fs<<(*it5)->getDate()->returnMonth()<<'/'<<flush;
    fs<<(*it5)->getDate()->returnYear()<<"\n"<<flush;

    itAlumnos = (*it5)->getItBegin();
    for(; itAlumnos != (*it5)->getItEnd(); ++itAlumnos) {
      fs<<"Lista"<<"\n"<<flush;
      fs<<(*itAlumnos)->getName()<<"\n"<<flush;
      fs<<(*itAlumnos)->getId()<<"\n"<<flush;
    }
    fs<<"END"<<"\n"<<flush;
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

    if((*it6)->getTutor()==NULL){
      fs << "NULL" <<"\n"<<flush;
    }
    else{
      fs << (*it6)->getTutor()->getId() << "\n" <<flush;
    }
    if((*it6)->getCoTutor()==NULL){
      fs << "NULL" <<"\n"<<flush;
    }
    else{
      fs << (*it6)->getCoTutor()->getId() << "\n" <<flush;
    }

    if((*it6)->getAlumno()==NULL){
      fs << "NULL" <<"\n"<<flush;
    }
    else{
      fs << (*it6)->getAlumno()->getId() << "\n" << flush;
    }
    fs<<"END"<<"\n"<<flush;
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
