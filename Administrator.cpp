#include <iostream>
#include <string>
#include <fstream>

#include "Alumno.h"
#include "Administrator.h"

using namespace std;

Administrator::Administrator() {
  //TODO
}

void Administrator::gestionarContenido() {
  //TODO
}

void Administrator::modificarContenido() {
  //TODO
}

void Administrator::gestionarUsuarios() {
  int option = 0;

  cout<<"1. Añadir nuevos usuarios"<<endl
      <<"2. Modificar datos  de usuarios existentes"<<endl
      <<"3. Eliminar usuarios"<<endl;
  cin>>option;

  if(option == 1) {
    int a = 0;
    cout<<"1. Alumnos"<<endl
      <<"2. Profesores"<<endl
      <<"3. Administradores"<<endl;
    cin>>a;

      switch(a) {
        case 1:
          addUsuarios(a);
        break;
        case 2:
          addUsuarios(a);
        break;
        case 3:
          addUsuarios(a);
        break;
        default :
          cout<<"Opcion erronea"<<endl;
      }
  } else if(option == 2) {

  } else if(option == 3) {

  } else {
    cout<<"Opcion erronea"<<endl;
  }
}

void Administrator::addUsuarios(int type) {
  if (type == 1) {
    //Alumnos
    fstream fsalumnos("alumnos.dat", ios::out | ios::in /*ios::trunc*/ | ios::binary);
    char* nia = new char[9];
    string nombre;
    char more;
    do {
      fsalumnos.seekp(0,ios::end);

      cout<<"Introduce el nuevo alumno: "<<endl;
      cout<<"Nombre: ";
      cin>>nombre;
      cout<<endl<<"NIA: ";
      cin>>nia;

      string result = nombre + " " + nia;
      //fsalumnos.write(reinterpret_cast <char *>(&result), sizeof(result));
      fsalumnos << result << "\n" << flush;

      cout<<"¿Añadir mas alumnos? (y/n)"<<endl;
      cin>>more;
      delete[] nia;
    } while(more == 'y');
    //Sometimes I get munmap_chunk(): invalid pointer
    //after executing this line. Happens if nia's length is more than 9?
    fsalumnos.close();
  } else if(type == 2) {
    //Profesores
    fstream fsprofesores("profesores.dat", ios::out | ios::in | ios::binary);
    char* id = new char[7];
    string nombre;
    char more;
    do {
      fsprofesores.seekp(0,ios::end);

      cout<<"Introduce el nuevo profesor: "<<endl;
      cout<<"Nombre: ";
      cin>>nombre;
      cout<<endl<<"ID: ";
      cin>>id;

      string result = nombre + " " + id;
      fsprofesores << result << "\n" << flush;

      cout<<"¿Añadir mas profesores? (y/n)"<<endl;
      cin>>more;
      delete[] id;
    } while(more == 'y');
    //Sometimes I get munmap_chunk(): invalid pointer
    //after executing this line. Happens if id's length is more than 9?
    fsprofesores.close();
  } else if(type == 3) {
    //Administradores
    fstream fsadmins("admins.dat", ios::out | ios::in | ios::binary);
    char* id = new char[7];
    string nombre;
    char more;
    do {
      fsadmins.seekp(0,ios::end);

      cout<<"Introduce el nuevo administrador: "<<endl;
      cout<<"Nombre: ";
      cin>>nombre;
      cout<<endl<<"ID: ";
      cin>>id;

      string result = nombre + " " + id;
      fsadmins << result << "\n" << flush;

      cout<<"¿Añadir mas administradores? (y/n)"<<endl;
      cin>>more;
      delete[] id;
    } while(more == 'y');
    //Sometimes I get munmap_chunk(): invalid pointer
    //after executing this line. Happens if id's length is more than 9?
    fsadmins.close();
  } else {
    cout<<"Opcion erronea"<<endl;
  }

}
