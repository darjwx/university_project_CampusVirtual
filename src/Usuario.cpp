#include <iostream>
#include "include/Usuario.h"

using namespace std;

string Usuario::getNombre() {
  return nombre;
}

void Usuario::setNombre(string nombre) {
  this->nombre = nombre;
}

string Usuario::getId() {
  return id;
}

void Usuario::setId(string id) {
  this->id = id;
}
