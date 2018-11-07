#include <iostream>
#include <fstream>
#include <string>

#include "include/Alumno.h"

using namespace std;

Alumno::Alumno() {
  //DO NOTHING
}

void Alumno::getLista() {
  int n = 0;
  string linea;
  fstream fsalum("alumnos.dat", ios::in | ios::binary);

  /*ANSI escape codes:
  \033[2j clears the entire screen.
  \033[1;1H position the cursor at row 1, column 1.*/
  cout<<"\033[2J\033[1;1H";
  while(getline(fsalum,linea)) {
    cout<<n<<". "<<linea<<endl;
    ++n;
  }

  char temp;
  do {
    cout<<"Presiona ESC para continuar";
    cin.get(temp);
  //27 is ESC key in ASCII
  } while(temp != 27);
}
