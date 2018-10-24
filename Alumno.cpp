#include <iostream>
#include <fstream>
#include <string>

#include "Alumno.h"

using namespace std;

Alumno::Alumno() {
  //DO NOTHING
}

void Alumno::getLista() {
  string linea;
  fstream fsalum("alumnos.dat", ios::in | ios::binary);
  while(getline(fsalum,linea)) {
    cout<<linea<<endl;
  }
}
