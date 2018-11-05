#include <iostream>
#include "Subjects.h"

using namespace std;

Subjects::Subjects() {
  //DO NOTHING
}

Subjects::Subjects(string titulacion,char* teachers,unsigned int credits,
    char* alumnos) {
  this->titulacion = titulacion;
  this->teachers[0] = teachers[0];
  this->teachers[1] = teachers[1];
  this->credits = credits;
  this->alumnos = alumnos;

  }
void Subjects::setTeachers(char* teachers) {
  this->teachers[0] = teachers[0];
  this->teachers[1] = teachers[1];
}
void Subjects::setCredits(unsigned int credits) {
  this->credits = credits;
}
void Subjects::setAlumnos(char* alumnos) {
  this->alumnos = alumnos;
}
void Subjects::setGrade(unsigned int grade) {
  this->grade = grade;
}
char* Subjects::getTeachers() {
  return teachers;
}
unsigned int Subjects::getCredits() {
  return credits;
}
char* Subjects::getAlumnos() {
  return alumnos;
}
unsigned int Subjects::getGrade() {
  return grade;
}

Subjects::~Subjects() {
  
}

void Subjects::showList() {
  int n = 0;
  string linea;
  fstream fs("asignaturas.dat", ios::in | ios::binary);

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
