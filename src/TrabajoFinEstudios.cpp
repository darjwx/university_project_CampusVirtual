#include <iostream>
#include "include/TrabajoFinEstudios.h"

using namespace std;

TrabajoFinEstudios::TrabajoFinEstudios() {
  //DO NOTHING
}

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

TrabajoFinEstudios::~TrabajoFinEstudios() {

}

void TrabajoFinEstudios::showList() {
  int n = 0;
  string linea;
  fstream fs("tfe.dat", ios::in | ios::binary);

  /*ANSI escape codes:
  \033[2j clears the entire screen.
  \033[1;1H position the cursor at row 1, column 1.*/
  cout<<"\033[2J\033[1;1H";
  while(getline(fs,linea)) {
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
