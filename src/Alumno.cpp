#include <iostream>
#include <fstream>
#include <string>

#include "include/Alumno.h"

using namespace std;

Alumno::Alumno() {
}

void Alumno::setName(string name) {
  this->name = name;
}

bool Alumno::setId(string id) {
  if(id.length() > 7/*|| contiene letras*/) {
    return false;
  } else {
    this->id = id;
    return true;
  }
}

string Alumno::getName() {
  return name;
}

string Alumno::getId() {
  return id;
}

ostream& operator<<(ostream& os, Alumno* a) {
  os<<"Nombre: "<<a->getName()<<endl;
  os<<"NIA: "<<a->getId()<<endl;
  return os;
}
