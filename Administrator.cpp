//TODO
//Simplificar el codigo para no tener que estar preguntando
//Todo el rato sobre el tipo de usuario al que vas a hacer modificaciones

#include <iostream>
#include <string>
#include <fstream>

#include "Alumno.h"
#include "Administrator.h"
#include "Teacher.h"

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
      <<"3. Eliminar usuarios"<<endl
      <<"4. Lista de usuarios registrados"<<endl;
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
    modificarDatos();

  } else if(option == 3) {

  } else if(option == 4) {
    int a = 0;
    cout<<"1. Alumnos"<<endl
      <<"2. Profesores"<<endl
      <<"3. Administradores"<<endl;
    cin>>a;

      switch(a) {
        case 1:
          showLista(a);
        break;
        case 2:
          showLista(a);
        break;
        case 3:
          showLista(a);
        break;
        default :
          cout<<"Opcion erronea"<<endl;
      }
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

void Administrator::showLista(int user) {
  if(user == 1) {
    Alumno alumno;
    alumno.getLista();
  } else if(user == 2) {
    Teacher teacher;
    teacher.getLista();
  } else if(user == 3) {
    getLista();
  } else {
    cout<<"Tipo de usuario erroneo"<<endl;
  }
}

void Administrator::getLista() {
  int n = 0;
  string linea;
  fstream fsadmin("admins.dat", ios::in | ios::binary);
  while(getline(fsadmin,linea)) {
    cout<<n<<". "<<linea<<endl;
    ++n;
  }
}

void Administrator::modificarDatos() {
  int a = 0;
  int line = 0;
  cout<<"1. Alumnos"<<endl
    <<"2. Profesores"<<endl
    <<"3. Administradores"<<endl;
  cin>>a;

  if(a == 1) {
    string nombre;
    char* nia = new char[9];
    string l;
    int n = 0;
    fstream fsalum("alumnos.dat", ios::out | ios::in | ios::binary);
    fstream fstemp("temp.dat", ios::out | ios::in | ios::trunc | ios::binary);
    showLista(a);
    cout<<"Alumno a modificar(linea): "<<endl;
    cin>>line;

    cout<<"Nuevo nombre: "<<endl;
    cin>>nombre;
    cout<<"Nuevo NIA: "<<endl;
    cin>>nia;
    string result = nombre + " " + nia;

    //Copia fsalum en un archivo temporal con la llinea
    //seleccionada modoficada
    while(getline(fsalum,l)) {
      fsalum.seekp(fsalum.tellp());
      fstemp.seekp(fstemp.tellp());

      if(n == line) {
        fstemp << result<< "\n" << flush;
      } else {
        fstemp << l << "\n" << flush;
      }
      ++n;
    }
    fsalum.close();

    fstemp.seekp(0);
    //Elimina el contenido para poder sobreescribir
    fsalum.open("alumnos.dat", ios::out | ios::trunc | ios::binary);
    while(getline(fstemp,l)) {
      //cout<<l<<endl;
      fsalum.seekp(fsalum.tellp());
      fstemp.seekp(fstemp.tellp());
      fsalum << l << "\n" << flush;
    }

  } else if(a == 2) {
    string nombre;
    char* id = new char[9];
    string l;
    int n = 0;
    fstream fsprof("profesores.dat", ios::out | ios::in | ios::binary);
    fstream fstemp("temp.dat", ios::out | ios::in | ios::trunc | ios::binary);
    showLista(a);
    cout<<"Profesor a modificar(linea): "<<endl;
    cin>>line;

    cout<<"Nuevo profesor: "<<endl;
    cin>>nombre;
    cout<<"Nuevo ID: "<<endl;
    cin>>id;
    string result = nombre + " " + id;

    //Copia fsalum en un archivo temporal con la llinea
    //seleccionada modoficada
    while(getline(fsprof,l)) {
      fsprof.seekp(fsprof.tellp());
      fstemp.seekp(fstemp.tellp());

      if(n == line) {
        fstemp << result<< "\n" << flush;
      } else {
        fstemp << l << "\n" << flush;
      }
      ++n;
    }
    fsprof.close();

    fstemp.seekp(0);
    //Elimina el contenido para poder sobreescribir
    fsprof.open("profesores.dat", ios::out | ios::trunc | ios::binary);
    while(getline(fstemp,l)) {
      //cout<<l<<endl;
      fsprof.seekp(fsprof.tellp());
      fstemp.seekp(fstemp.tellp());
      fsprof << l << "\n" << flush;
    }

  } else if(a == 3) {
    string nombre;
    char* id = new char[9];
    string l;
    int n = 0;
    fstream fsadmin("admins.dat", ios::out | ios::in | ios::binary);
    fstream fstemp("temp.dat", ios::out | ios::in | ios::trunc | ios::binary);
    showLista(a);
    cout<<"Profesor a modificar(linea): "<<endl;
    cin>>line;

    cout<<"Nuevo profesor: "<<endl;
    cin>>nombre;
    cout<<"Nuevo ID: "<<endl;
    cin>>id;
    string result = nombre + " " + id;

    //Copia fsalum en un archivo temporal con la llinea
    //seleccionada modoficada
    while(getline(fsadmin,l)) {
      fsadmin.seekp(fsadmin.tellp());
      fstemp.seekp(fstemp.tellp());

      if(n == line) {
        fstemp << result<< "\n" << flush;
      } else {
        fstemp << l << "\n" << flush;
      }
      ++n;
    }
    fsadmin.close();

    fstemp.seekp(0);
    //Elimina el contenido para poder sobreescribir
    fsadmin.open("profesores.dat", ios::out | ios::trunc | ios::binary);
    while(getline(fstemp,l)) {
      //cout<<l<<endl;
      fsadmin.seekp(fsadmin.tellp());
      fstemp.seekp(fstemp.tellp());
      fsadmin << l << "\n" << flush;
    }

  } else {
    cout<<"Opcion erronea"<<endl;
  }
}
