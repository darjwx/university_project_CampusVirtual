#include <iostream>
#include <fstream>
#include <string>

#include "Teacher.h"

using namespace std;

Teacher::Teacher() {
  //DO NOTHING
}

void Teacher::getLista() {
  string linea;
  fstream fsprof("profesores.dat", ios::in | ios::binary);
  while(getline(fsprof,linea)) {
    cout<<linea<<endl;
  }
}
