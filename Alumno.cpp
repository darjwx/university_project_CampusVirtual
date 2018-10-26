#include <iostream>
#include <fstream>
#include <string>

#include "Alumno.h"

using namespace std;

Alumno::Alumno() {
  //DO NOTHING
}

void Alumno::getLista() {
  int n = 0;
  string linea;
  fstream fsalum("alumnos.dat", ios::in | ios::binary);
  while(getline(fsalum,linea)) {
    cout<<n<<". "<<linea<<endl;
    ++n;
  }
}
