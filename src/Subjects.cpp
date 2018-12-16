#include <iostream>
#include "include/Subjects.h"

using namespace std;

Subjects::Subjects() {

}

void Subjects::setStatus(char status) {
  this->status = status;
}

char Subjects::getStatus() {
  return status;
}

void Subjects::setId(string id) {
  this->id = id;
}

string Subjects::getId() {
  return id;
}

void Subjects::setName(string name) {
  this->name = name;
}

string Subjects::getName() {
  return name;
}

void Subjects::setTitulacion(string titulacion) {
  this->titulacion = titulacion;
}

string Subjects::getTitulacion() {
  return titulacion;
}

void Subjects::setCredits(unsigned int credits) {
  this->credits = credits;
}

unsigned int Subjects::getCredits() {
  return credits;
}

void Subjects::setTeacher(Teacher* t1, Teacher* t2) {
  teacher1 = t1;
  teacher2 = t2;
}

void Subjects::setTeacher1(Teacher* t1) {
  teacher1 = t1;
}
void Subjects::setTeacher2(Teacher* t2) {
  teacher2 = t2;
}

Teacher* Subjects::getTeacher1() {
  return teacher1;
}

Teacher* Subjects::getTeacher2() {
  return teacher2;
}

void Subjects::setAlumnosApuntados(Alumno* a) {
  alumnoApuntados.push_back(a);
}


void Subjects::eliminarAlumno(list<Alumno*>::iterator it) {
  it = alumnoApuntados.erase(it);
}

list<Alumno*>::iterator Subjects::getItBegin() {
  list<Alumno*>::iterator it = alumnoApuntados.begin();
  return it;
}

list<Alumno*>::iterator Subjects::getItEnd() {
  list<Alumno*>::iterator it = alumnoApuntados.end();
  return it;
}

list<Alumno*>::iterator Subjects::getItPos(int n){
  list<Alumno*>::iterator it = alumnoApuntados.begin();
  for(int i=0;i<n;++i){
    ++it;
  }
  return(it);
}

string Subjects::getIdAlumno(list<Alumno*>::iterator it){
  return((*it)->getId());
}

int Subjects::getNumAl(){
  return(alumnoApuntados.size());
}

void Subjects::NullT1(){
  teacher1=NULL;
}
void Subjects::NullT2(){
  teacher2=NULL;
}
