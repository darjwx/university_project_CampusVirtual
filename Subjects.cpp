#include <iostream>
#include "Subjects.h"

using namespace std;

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
