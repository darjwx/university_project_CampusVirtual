#include <iostream>
#include "TrabajoFinEstudios.h"

using namespace std;

TrabajoFinEstudios::TrabajoFinEstudios(string titulacion,string tutor,string coTutor,
    string alumno) {
  this->titulacion = titulacion;
  this->tutor = tutor;
  this->coTutor = coTutor;
  this->alumno = alumno;
}
TrabajoFinEstudios::TrabajoFinEstudios(string titulacion,string tutor,string alumno) {
  this->titulacion = titulacion;
  this->tutor = tutor;
  this->coTutor = "";
  this->alumno = alumno;
}
void TrabajoFinEstudios::setTitulacion(string titulacion) {
  this->titulacion = titulacion;
}
void TrabajoFinEstudios::setTutor(string tutor) {
  this->tutor = tutor;
}
void TrabajoFinEstudios::setCoTutor(string coTutor) {
  this->coTutor = coTutor;
}
void TrabajoFinEstudios::setAlumno(string alumno) {
  this->alumno = alumno;
}
string TrabajoFinEstudios::getTitulacion() {
  return titulacion;
}
string TrabajoFinEstudios::getTutor() {
  return tutor;
}
string TrabajoFinEstudios::getCoTutor() {
  return coTutor;
}
string TrabajoFinEstudios::getAlumno() {
  return alumno;
}
