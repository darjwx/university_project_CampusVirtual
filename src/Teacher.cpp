#include <iostream>
#include <fstream>
#include <string>

#include "include/Teacher.h"

using namespace std;

Teacher::Teacher() {
  //DO NOTHING
}

void Teacher::setName(string name) {
  this->name = name;
}

bool Teacher::setId(string id) {
  if(id.length() > 7) {
    return false;
  } else {
    this->id = id;
    return true;
  }
}

string Teacher::getName() {
  return name;
}

string Teacher::getId() {
  return id;
}

Teacher& Teacher::operator=(Teacher& t) {
  name = t.name;
  id = t.id;

  return *this;
}

ostream& operator<<(ostream& os, Teacher& t) {
  os<<t.getName();
  os<<t.getId();

  return os;
}
