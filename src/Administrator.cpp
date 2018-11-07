#include <iostream>
#include <string>
#include <fstream>

#include "include/Alumno.h"
#include "include/Administrator.h"
#include "include/Teacher.h"
#include "include/Subjects.h"
#include "include/Conference.h"
#include "include/TrabajoFinEstudios.h"

using namespace std;

Administrator::Administrator() {
  //TODO
}

void Administrator::gestionarContenido() {
  //TODO use a dinamic array while the program is being used
  //and just use the files to save/get the info when
  //closing/opening the program
  char option = '0';
  bool salir = false;

  do {
    /*ANSI escape codes:
    \033[2j clears the entire screen.
    \033[1;1H position the cursor at row 1, column 1.*/
    cout<<"\033[2J\033[1;1H";
    cout<<"1. Añadir nuevo contenido"<<endl
        <<"2. Modificar recursos existentes"<<endl
        <<"3. Eliminar recursos"<<endl
        <<"4. Lista de recursos disponibles"<<endl
        <<"<. Salir";
    cin>>option;

    if(option == '1') {
      int type;
      string resource;
      getResource(&type,&resource);
      addRecurso(type,resource);

    } else if(option == '2') {
      int type;
      string resource;
      getResource(&type,&resource);
      modificarRecurso(type,resource);

    } else if(option == '3') {
      int type;
      string resource;
      getResource(&type,&resource);
      eliminarRecurso(type,resource);

    } else if(option == '4') {
      int type;
      string resource;
      getResource(&type,&resource);
      showRecurso(type);

    } else if(option == '<') {
      salir = true;

    } else {
      cout<<"Opcion erronea"<<endl;
    }
  } while (!salir);

  CampusVirtual cv;
  cv.menuAdmin();
}

void Administrator::addRecurso(int type, string recurso) {
  if (type == 1) {
    //Asignaturas
    fstream fs("asignaturas.dat", ios::out | ios::in /*ios::trunc*/ | ios::binary);
    string nombre;
    string profesor;
    string titulacion;
    char creds;
    char more;
    do {
      fs.seekp(0,ios::end);

      /*ANSI escape codes:
      \033[2j clears the entire screen.
      \033[1;1H position the cursor at row 1, column 1.*/
      cout<<"\033[2J\033[1;1H";
      cout<<"**"<<recurso<<"**"<<endl;
      cout<<"Introduce el nuevo recurso: "<<endl;
      cout<<"Nombre: ";
      cin>>nombre;
      cout<<endl<<"Titulacion: ";
      cin>>titulacion;
      cout<<endl<<"Profesor: ";
      cin>>profesor;
      cout<<endl<<"Creditos: ";
      cin>>creds;

      string result = nombre + " " + titulacion + " "
        + profesor + " " + creds;
      //fsalumnos.write(reinterpret_cast <char *>(&result), sizeof(result));
      fs << result << "\n" << flush;

      cout<<"¿Añadir mas asignaturas? (y/n)"<<endl;
      cin>>more;
    } while(more == 'y');
    //Sometimes I get munmap_chunk(): invalid pointer
    //after executing this line. Happens if nia's length is more than 9?
    fs.close();
  } else if(type == 2) {
    //Seminarios
    fstream fs("seminarios.dat", ios::out | ios::in /*ios::trunc*/ | ios::binary);
    string nombre;
    string ponente;
    string supervisor;
    char capacity;
    char more;
    do {
      fs.seekp(0,ios::end);

      /*ANSI escape codes:
      \033[2j clears the entire screen.
      \033[1;1H position the cursor at row 1, column 1.*/
      cout<<"\033[2J\033[1;1H";
      cout<<"**"<<recurso<<"**"<<endl;
      cout<<"Introduce el nuevo recurso: "<<endl;
      cout<<"Nombre: ";
      cin>>nombre;
      cout<<endl<<"Supervisor: ";
      cin>>supervisor;
      cout<<endl<<"Ponente: ";
      cin>>ponente;
      //I have to figure out how to handle dates first
      /*cout<<endl<<"Fecha: ";
      cout<<endl<<"Dia: ";
      cout<<endl<<"Mes: ";
      cout<<endl<<"Año: ";
      cout<<endl<<"Capacidad: ";*/
      cout<<"Capacidad: "<<endl;
      cin>>capacity;

      string result = nombre + " " + supervisor + " "
        + ponente + " " + capacity;
      //fsalumnos.write(reinterpret_cast <char *>(&result), sizeof(result));
      fs << result << "\n" << flush;

      cout<<"¿Añadir mas seminarios? (y/n)"<<endl;
      cin>>more;
    } while(more == 'y');
    //Sometimes I get munmap_chunk(): invalid pointer
    //after executing this line. Happens if nia's length is more than 9?
    fs.close();
  } else if(type == 3) {
    //TFE
    fstream fs("tfe.dat", ios::out | ios::in /*ios::trunc*/ | ios::binary);
    string nombre;
    string titulacion;
    string tutor;
    string coTutor;
    char more;
    do {
      fs.seekp(0,ios::end);

      /*ANSI escape codes:
      \033[2j clears the entire screen.
      \033[1;1H position the cursor at row 1, column 1.*/
      cout<<"\033[2J\033[1;1H";
      cout<<"**"<<recurso<<"**"<<endl;
      cout<<"Introduce el nuevo recurso: "<<endl;
      cout<<"Nombre: ";
      cin>>nombre;
      cout<<endl<<"Titulacion: ";
      cin>>titulacion;
      cout<<endl<<"Tutor: ";
      cin>>tutor;
      cout<<"Co-tutor: "<<endl;
      cin>>coTutor;

      string result = nombre + " " + titulacion + " "
        + tutor + " " + coTutor;
      //fsalumnos.write(reinterpret_cast <char *>(&result), sizeof(result));
      fs << result << "\n" << flush;

      cout<<"¿Añadir mas TFEs? (y/n)"<<endl;
      cin>>more;
    } while(more == 'y');
    //Sometimes I get munmap_chunk(): invalid pointer
    //after executing this line. Happens if nia's length is more than 9?
    fs.close();
  } else {
    cout<<"Opcion erronea"<<endl;
  }

}

void Administrator::modificarRecurso(int type, string recurso) {
  int line = 0;

  if(type == 1) {
    string nombre;
    string titulacion;
    string profesor;
    char creds;
    string l;
    int n = 0;
    fstream fs("asignaturas.dat", ios::out | ios::in | ios::binary);
    fstream fstemp("temp.dat", ios::out | ios::in | ios::trunc | ios::binary);
    showRecurso(type);

    /*ANSI escape codes:
    \033[2j clears the entire screen.
    \033[1;1H position the cursor at row 1, column 1.*/
    cout<<"\033[2J\033[1;1H";
    cout<<"**"<<recurso<<"**"<<endl;
    cout<<"Asignatura a modificar(linea): "<<endl;
    cin>>line;

    cout<<"Introduce el nuevo recurso: "<<endl;
    cout<<"Nombre: ";
    cin>>nombre;
    cout<<endl<<"Titulacion: ";
    cin>>titulacion;
    cout<<endl<<"Profesor: ";
    cin>>profesor;
    cout<<endl<<"Creditos: ";
    cin>>creds;
    string result = nombre + " " + titulacion + " "
      + profesor + " " + creds;

    //Copia fsalum en un archivo temporal con la linea
    //seleccionada modoficada
    while(getline(fs,l)) {
      fs.seekp(fs.tellp());
      fstemp.seekp(fstemp.tellp());

      if(n == line) {
        fstemp << result<< "\n" << flush;
      } else {
        fstemp << l << "\n" << flush;
      }
      ++n;
    }
    fs.close();

    fstemp.seekp(0);
    //Elimina el contenido para poder sobreescribir
    fs.open("asignaturas.dat", ios::out | ios::trunc | ios::binary);
    while(getline(fstemp,l)) {
      //cout<<l<<endl;
      fs.seekp(fs.tellp());
      fstemp.seekp(fstemp.tellp());
      fs << l << "\n" << flush;
    }
    fs.close();
    fstemp.close();
  } else if(type == 2) {
    string nombre;
    string ponente;
    string supervisor;
    char capacity;
    string l;
    int n = 0;
    fstream fs("seminarios.dat", ios::out | ios::in | ios::binary);
    fstream fstemp("temp.dat", ios::out | ios::in | ios::trunc | ios::binary);
    showRecurso(type);

    /*ANSI escape codes:
    \033[2j clears the entire screen.
    \033[1;1H position the cursor at row 1, column 1.*/
    cout<<"\033[2J\033[1;1H";
    cout<<"**"<<recurso<<"**"<<endl;
    cout<<"Seminario a modificar(linea): "<<endl;
    cin>>line;

    cout<<"Introduce el nuevo recurso: "<<endl;
    cout<<"Nombre: ";
    cin>>nombre;
    cout<<endl<<"Supervisor: ";
    cin>>supervisor;
    cout<<endl<<"Ponente: ";
    cin>>ponente;
    //I have to figure out how to handle dates first
    /*cout<<endl<<"Fecha: ";
    cout<<endl<<"Dia: ";
    cout<<endl<<"Mes: ";
    cout<<endl<<"Año: ";
    cout<<endl<<"Capacidad: ";*/
    cout<<"Capacidad: "<<endl;
    cin>>capacity;

    string result = nombre + " " + supervisor + " "
      + ponente + " " + capacity;
    //Copia fsalum en un archivo temporal con la linea
    //seleccionada modoficada
    while(getline(fs,l)) {
      fs.seekp(fs.tellp());
      fstemp.seekp(fstemp.tellp());

      if(n == line) {
        fstemp << result<< "\n" << flush;
      } else {
        fstemp << l << "\n" << flush;
      }
      ++n;
    }
    fs.close();

    fstemp.seekp(0);
    //Elimina el contenido para poder sobreescribir
    fs.open("seminarios.dat", ios::out | ios::trunc | ios::binary);
    while(getline(fstemp,l)) {
      //cout<<l<<endl;
      fs.seekp(fs.tellp());
      fstemp.seekp(fstemp.tellp());
      fs << l << "\n" << flush;
    }
    fs.close();
    fstemp.close();

  } else if(type == 3) {
    string nombre;
    string titulacion;
    string tutor;
    string coTutor;
    string l;
    int n = 0;
    fstream fs("tfe.dat", ios::out | ios::in | ios::binary);
    fstream fstemp("temp.dat", ios::out | ios::in | ios::trunc | ios::binary);
    showRecurso(type);

    /*ANSI escape codes:
    \033[2j clears the entire screen.
    \033[1;1H position the cursor at row 1, column 1.*/
    cout<<"\033[2J\033[1;1H";
    cout<<"TFE a modificar(linea): "<<endl;
    cin>>line;

    cout<<"**"<<recurso<<"**"<<endl;
    cout<<"Introduce el nuevo recurso: "<<endl;
    cout<<"Nombre: ";
    cin>>nombre;
    cout<<endl<<"Titulacion: ";
    cin>>titulacion;
    cout<<endl<<"Tutor: ";
    cin>>tutor;
    cout<<"Co-tutor: "<<endl;
    cin>>coTutor;

    string result = nombre + " " + titulacion + " "
      + tutor + " " + coTutor;

    //Copia fsalum en un archivo temporal con la linea
    //seleccionada modoficada
    while(getline(fs,l)) {
      fs.seekp(fs.tellp());
      fstemp.seekp(fstemp.tellp());

      if(n == line) {
        fstemp << result<< "\n" << flush;
      } else {
        fstemp << l << "\n" << flush;
      }
      ++n;
    }
    fs.close();

    fstemp.seekp(0);
    //Elimina el contenido para poder sobreescribir
    fs.open("tfe.dat", ios::out | ios::trunc | ios::binary);
    while(getline(fstemp,l)) {
      //cout<<l<<endl;
      fs.seekp(fs.tellp());
      fstemp.seekp(fstemp.tellp());
      fs << l << "\n" << flush;
    }
    fs.close();
    fstemp.close();

  }

}

void Administrator::eliminarRecurso(int type, string recurso) {
  int line = 0;

  if(type == 1) {
    string l;
    int n = 0;
    fstream fs("asignaturas.dat", ios::out | ios::in | ios::binary);
    fstream fstemp("temp.dat", ios::out | ios::in | ios::trunc | ios::binary);
    showRecurso(type);

    /*ANSI escape codes:
    \033[2j clears the entire screen.
    \033[1;1H position the cursor at row 1, column 1.*/
    cout<<"\033[2J\033[1;1H";
    cout<<"**"<<recurso<<"**"<<endl;
    cout<<"Asignatura a eliminar(linea): "<<endl;
    cin>>line;

    //Copia fsalum en un archivo temporal con la linea
    //seleccionada eliminada
    while(getline(fs,l)) {
      fs.seekp(fs.tellp());
      fstemp.seekp(fstemp.tellp());

      if(n != line) {
        fstemp << l << "\n" << flush;
      }
      ++n;
    }
    fs.close();

    fstemp.seekp(0);
    //Elimina el contenido para poder sobreescribir
    fs.open("asignaturas.dat", ios::out | ios::trunc | ios::binary);
    while(getline(fstemp,l)) {
      //cout<<l<<endl;
      fs.seekp(fs.tellp());
      fstemp.seekp(fstemp.tellp());
      fs << l << "\n" << flush;
    }
    fs.close();
    fstemp.close();
  } else if(type == 2) {
    string l;
    int n = 0;
    fstream fs("seminarios.dat", ios::out | ios::in | ios::binary);
    fstream fstemp("temp.dat", ios::out | ios::in | ios::trunc | ios::binary);
    showRecurso(type);

    /*ANSI escape codes:
    \033[2j clears the entire screen.
    \033[1;1H position the cursor at row 1, column 1.*/
    cout<<"\033[2J\033[1;1H";
    cout<<"**"<<recurso<<"**"<<endl;
    cout<<"Seminario a eliminar(linea): "<<endl;
    cin>>line;

    //Copia fsalum en un archivo temporal con la linea
    //seleccionada eliminada
    while(getline(fs,l)) {
      fs.seekp(fs.tellp());
      fstemp.seekp(fstemp.tellp());

      if(n != line) {
        fstemp << l << "\n" << flush;
      }
      ++n;
    }
    fs.close();

    fstemp.seekp(0);
    //Elimina el contenido para poder sobreescribir
    fs.open("seminarios.dat", ios::out | ios::trunc | ios::binary);
    while(getline(fstemp,l)) {
      //cout<<l<<endl;
      fs.seekp(fs.tellp());
      fstemp.seekp(fstemp.tellp());
      fs << l << "\n" << flush;
    }
    fs.close();
    fstemp.close();

  } else if(type == 3) {
    string l;
    int n = 0;
    fstream fs("tfe.dat", ios::out | ios::in | ios::binary);
    fstream fstemp("temp.dat", ios::out | ios::in | ios::trunc | ios::binary);
    showRecurso(type);

    /*ANSI escape codes:
    \033[2j clears the entire screen.
    \033[1;1H position the cursor at row 1, column 1.*/
    cout<<"\033[2J\033[1;1H";
    cout<<"**"<<recurso<<"**"<<endl;
    cout<<"TFE a modificar(linea): "<<endl;
    cin>>line;

    //Copia fsalum en un archivo temporal con la linea
    //seleccionada eliminada
    while(getline(fs,l)) {
      fs.seekp(fs.tellp());
      fstemp.seekp(fstemp.tellp());

      if(n != line) {
        fstemp << l << "\n" << flush;
      }
      ++n;
    }
    fs.close();

    fstemp.seekp(0);
    //Elimina el contenido para poder sobreescribir
    fs.open("tfe.dat", ios::out | ios::trunc | ios::binary);
    while(getline(fstemp,l)) {
      //cout<<l<<endl;
      fs.seekp(fs.tellp());
      fstemp.seekp(fstemp.tellp());
      fs << l << "\n" << flush;
    }
    fs.close();
    fstemp.close();

  }
}

void Administrator::gestionarUsuarios() {
  //TODO use a dinamic array while the program is being used
  //and just use the files to save/get the info when
  //closing/opening the program
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
      int type;
      string user;
      getType(&type,&user);
      addUsuarios(type,user);

    } else if(option == '2') {
      int type;
      string user;
      getType(&type,&user);
      modificarDatos(type,user);

    } else if(option == '3') {
      int type;
      string user;
      getType(&type,&user);
      removeUsuarios(type,user);

    } else if(option == '4') {
      int type;
      string user;
      getType(&type,&user);
      showLista(type);

    } else if(option == '<') {
      salir = true;

    } else {
      cout<<"Opcion erronea"<<endl;
    }
  } while (!salir);

  CampusVirtual cv;
  cv.menuAdmin();
}

void Administrator::addUsuarios(int type, string user) {
  if (type == 1) {
    //Alumnos
    fstream fsalumnos("alumnos.dat", ios::out | ios::in /*ios::trunc*/ | ios::binary);
    char* nia = new char[9];
    string nombre;
    char more;
    do {
      fsalumnos.seekp(0,ios::end);

      /*ANSI escape codes:
      \033[2j clears the entire screen.
      \033[1;1H position the cursor at row 1, column 1.*/
      cout<<"\033[2J\033[1;1H";
      cout<<"**"<<user<<"**"<<endl;
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

      /*ANSI escape codes:
      \033[2j clears the entire screen.
      \033[1;1H position the cursor at row 1, column 1.*/
      cout<<"\033[2J\033[1;1H";
      cout<<"**"<<user<<"**"<<endl;
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

      /*ANSI escape codes:
      \033[2j clears the entire screen.
      \033[1;1H position the cursor at row 1, column 1.*/
      cout<<"\033[2J\033[1;1H";
      cout<<"**"<<user<<"**"<<endl;
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

  /*ANSI escape codes:
  \033[2j clears the entire screen.
  \033[1;1H position the cursor at row 1, column 1.*/
  cout<<"\033[2J\033[1;1H";
  while(getline(fsadmin,linea)) {
    cout<<n<<". "<<linea<<endl;
    ++n;
  }

  char temp;
  do {
    cout<<"Presiona ESC para continuar";
    cin>>temp;
  //27 is ESC key in ASCII
  } while(temp != 27);
}

void Administrator::modificarDatos(int type,string user) {
  int line = 0;

  if(type == 1) {
    string nombre;
    char* nia = new char[9];
    string l;
    int n = 0;
    fstream fsalum("alumnos.dat", ios::out | ios::in | ios::binary);
    fstream fstemp("temp.dat", ios::out | ios::in | ios::trunc | ios::binary);
    showLista(type);

    /*ANSI escape codes:
    \033[2j clears the entire screen.
    \033[1;1H position the cursor at row 1, column 1.*/
    cout<<"\033[2J\033[1;1H";
    cout<<"**"<<user<<"**"<<endl;
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

  } else if(type == 2) {
    string nombre;
    char* id = new char[9];
    string l;
    int n = 0;
    fstream fsprof("profesores.dat", ios::out | ios::in | ios::binary);
    fstream fstemp("temp.dat", ios::out | ios::in | ios::trunc | ios::binary);

    /*ANSI escape codes:
    \033[2j clears the entire screen.
    \033[1;1H position the cursor at row 1, column 1.*/
    cout<<"\033[2J\033[1;1H";
    showLista(type);
    cout<<"Profesor a modificar(linea): "<<endl;
    cin>>line;

    cout<<"**"<<user<<"**"<<endl;
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

  } else if(type == 3) {
    string nombre;
    char* id = new char[9];
    string l;
    int n = 0;
    fstream fsadmin("admins.dat", ios::out | ios::in | ios::binary);
    fstream fstemp("temp.dat", ios::out | ios::in | ios::trunc | ios::binary);

    /*ANSI escape codes:
    \033[2j clears the entire screen.
    \033[1;1H position the cursor at row 1, column 1.*/
    cout<<"\033[2J\033[1;1H";
    showLista(type);
    cout<<"Profesor a modificar(linea): "<<endl;
    cin>>line;

    cout<<"**"<<user<<"**"<<endl;
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

void Administrator::removeUsuarios(int type, string user) {
  int line = 0;

  if(type == 1) {
    string l;
    int n = 0;
    fstream fs("alumnos.dat", ios::out | ios::in | ios::binary);
    fstream fstemp("temp.dat", ios::out | ios::in | ios::trunc | ios::binary);
    showLista(type);

    /*ANSI escape codes:
    \033[2j clears the entire screen.
    \033[1;1H position the cursor at row 1, column 1.*/
    cout<<"\033[2J\033[1;1H";
    cout<<"**"<<user<<"**"<<endl;
    cout<<"Alumno a eliminar(linea): "<<endl;
    cin>>line;

    //Copia fsalum en un archivo temporal con la linea
    //seleccionada eliminada
    while(getline(fs,l)) {
      fs.seekp(fs.tellp());
      fstemp.seekp(fstemp.tellp());

      if(n != line) {
        fstemp << l << "\n" << flush;
      }
      ++n;
    }
    fs.close();

    fstemp.seekp(0);
    //Elimina el contenido para poder sobreescribir
    fs.open("alumnos.dat", ios::out | ios::trunc | ios::binary);
    while(getline(fstemp,l)) {
      //cout<<l<<endl;
      fs.seekp(fs.tellp());
      fstemp.seekp(fstemp.tellp());
      fs << l << "\n" << flush;
    }
    fs.close();
    fstemp.close();
  } else if(type == 2) {
    string l;
    int n = 0;
    fstream fs("profesores.dat", ios::out | ios::in | ios::binary);
    fstream fstemp("temp.dat", ios::out | ios::in | ios::trunc | ios::binary);
    showLista(type);

    /*ANSI escape codes:
    \033[2j clears the entire screen.
    \033[1;1H position the cursor at row 1, column 1.*/
    cout<<"\033[2J\033[1;1H";
    cout<<"**"<<user<<"**"<<endl;
    cout<<"profesor a eliminar(linea): "<<endl;
    cin>>line;

    //Copia fsalum en un archivo temporal con la linea
    //seleccionada eliminada
    while(getline(fs,l)) {
      fs.seekp(fs.tellp());
      fstemp.seekp(fstemp.tellp());

      if(n != line) {
        fstemp << l << "\n" << flush;
      }
      ++n;
    }
    fs.close();

    fstemp.seekp(0);
    //Elimina el contenido para poder sobreescribir
    fs.open("profesor.dat", ios::out | ios::trunc | ios::binary);
    while(getline(fstemp,l)) {
      //cout<<l<<endl;
      fs.seekp(fs.tellp());
      fstemp.seekp(fstemp.tellp());
      fs << l << "\n" << flush;
    }
    fs.close();
    fstemp.close();

  } else if(type == 3) {
    string l;
    int n = 0;
    fstream fs("admins.dat", ios::out | ios::in | ios::binary);
    fstream fstemp("temp.dat", ios::out | ios::in | ios::trunc | ios::binary);
    showRecurso(type);

    /*ANSI escape codes:
    \033[2j clears the entire screen.
    \033[1;1H position the cursor at row 1, column 1.*/
    cout<<"\033[2J\033[1;1H";
    cout<<"**"<<user<<"**"<<endl;
    cout<<"Administrador a modificar(linea): "<<endl;
    cin>>line;

    //Copia fsalum en un archivo temporal con la linea
    //seleccionada eliminada
    while(getline(fs,l)) {
      fs.seekp(fs.tellp());
      fstemp.seekp(fstemp.tellp());

      if(n != line) {
        fstemp << l << "\n" << flush;
      }
      ++n;
    }
    fs.close();

    fstemp.seekp(0);
    //Elimina el contenido para poder sobreescribir
    fs.open("admins.dat", ios::out | ios::trunc | ios::binary);
    while(getline(fstemp,l)) {
      //cout<<l<<endl;
      fs.seekp(fs.tellp());
      fstemp.seekp(fstemp.tellp());
      fs << l << "\n" << flush;
    }
    fs.close();
    fstemp.close();

  }
}

//Maybe merge getType and getResource in a unique function?
void Administrator::getType(int* type, string* user) {
  int a = 0;

  /*ANSI escape codes:
  \033[2j clears the entire screen.
  \033[1;1H position the cursor at row 1, column 1.*/
  cout<<"\033[2J\033[1;1H";
  cout<<"1. Alumnos"<<endl
    <<"2. Profesores"<<endl
    <<"3. Administradores"<<endl;
  cin>>a;

  if(a == 1) {
    *user = "Gestionar alumnos";
  } else if(a == 2) {
    *user = "Gestionar profesores";
  } else {
    *user = "Gestionar administradores";
  }
  *type = a;
}

void Administrator::getResource(int* type, string* resource) {
  int a = 0;

  /*ANSI escape codes:
  \033[2j clears the entire screen.
  \033[1;1H position the cursor at row 1, column 1.*/
  cout<<"\033[2J\033[1;1H";
  cout<<"1. Asignaturas"<<endl
    <<"2. Seminarios"<<endl
    <<"3. TFE"<<endl;
  cin>>a;

  if(a == 1) {
    *resource = "Gestion asignaturas";
  } else if(a == 2) {
    *resource = "Gestionar seminarios";
  } else {
    *resource = "Gestionar RFE";
  }
  *type = a;
}

void Administrator::showRecurso(int type) {
  if(type == 1) {
    Subjects sub;
    sub.showList();
  } else if(type == 2) {
    Conference con;
    con.showList();
  } else if(type == 3) {
    TrabajoFinEstudios tfe;
    tfe.showList();
  } else {
    cout<<"Tipo de usuario erroneo"<<endl;
  }
}
