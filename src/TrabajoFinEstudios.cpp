#include <iostream>
#include "include/TrabajoFinEstudios.h"

using namespace std;

TrabajoFinEstudios::TrabajoFinEstudios() {

}

void TrabajoFinEstudios::setStatus(char status) {
  this->status = status;
}

char TrabajoFinEstudios::getStatus() {
  return status;
}

void TrabajoFinEstudios::setId(string id) {
  this->id = id;
}

string TrabajoFinEstudios::getId() {
  return id;
}

void TrabajoFinEstudios::setName(string name) {
  this->name = name;
}

string TrabajoFinEstudios::getName() {
  return name;
}

void TrabajoFinEstudios::setTitulacion(string titulacion) {
  this->titulacion = titulacion;
}

string TrabajoFinEstudios::getTitulacion() {
  return titulacion;
}

void TrabajoFinEstudios::setTutor(Teacher tutor) {
  this->tutor = tutor;
}

Teacher& TrabajoFinEstudios::getTutor() {
  return tutor;
}

void TrabajoFinEstudios::setCoTutor(Teacher coTutor) {
  this->coTutor = coTutor;
}

Teacher& TrabajoFinEstudios::getCoTutor() {
  return coTutor;
}
