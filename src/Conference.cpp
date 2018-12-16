#include <iostream>
#include "include/Conference.h"

using namespace std;

Conference::Conference() {

}

void Conference::setStatus(char status) {
  this->status = status;
}

char Conference::getStatus() {
  return status;
}

void Conference::setId(string id) {
  this->id = id;
}

string Conference::getId() {
  return id;
}

void Conference::setName(string name) {
  this->name = name;
}

string Conference::getName() {
  return name;
}

void Conference::setSupervisor(Teacher* supervisor) {
  this->supervisor = supervisor;
}

Teacher* Conference::getSupervisor() {
  return supervisor;
}

void Conference::setSpeaker(string speaker) {
  this->speaker = speaker;
}

string Conference::getSpeaker() {
  return speaker;
}

void Conference::setDate(Date* date) {
  this->date = date;
}

Date* Conference::getDate() {
  return date;
}

void Conference::setCapacity(int capacity) {
  this->capacity = capacity;
}

int Conference::getCapacity() {
  return capacity;
}

list<Alumno*>::iterator Conference::getItBegin() {
  list<Alumno*>::iterator it = alumnoApuntados.begin();
  return it;
}

list<Alumno*>::iterator Conference::getItEnd() {
  list<Alumno*>::iterator it = alumnoApuntados.end();
  return it;
}

list<Alumno*>::iterator Conference::getItPos(int n){
  list<Alumno*>::iterator it = alumnoApuntados.begin();
  for(int i=0;i<n;++i){
    ++it;
  }
  return(it);
}

void Conference::setAlumnosApuntados(Alumno* a) {
  alumnoApuntados.push_back(a);
}

void Conference::eliminarAlumno(list<Alumno*>::iterator it) {
  it = alumnoApuntados.erase(it);
}

string Conference::getIdAlumno(list<Alumno*>::iterator it){
  return((*it)->getId());
}

int Conference::getNumAl(){
  return(alumnoApuntados.size());
}

void Conference::NullS(){
  supervisor=NULL;
}
