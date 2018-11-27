#include <iostream>
#include <fstream>
#include <string>

#include "include/Administrator.h"

using namespace std;

Administrator::Administrator() {
}

Administrator::Administrator(string id, string name) {
  this->name = name;
  this->id = id;
}

void Administrator::setName(string name) {
  this->name = name;
}

bool Administrator::setId(string id) {
  if(id.length() > 7/*|| contiene letras*/) {
    return false;
  } else {
    this->id = id;
    return true;
  }
}

string Administrator::getName() {
  return name;
}

string Administrator::getId() {
  return id;
}

ostream& operator<<(ostream& os, Administrator* a) {
  os<<"Nombre: "<<a->getName()<<endl;
  os<<"NIA: "<<a->getId()<<endl;
  return os;
}
