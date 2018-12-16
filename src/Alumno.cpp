#include <iostream>
#include <fstream>
#include <string>

#include "include/Alumno.h"

using namespace std;

Alumno::Alumno() {
}

Alumno::Alumno(string name, string id) {
    this->name = name;
    this->id = id;
}

void Alumno::setName(string name) {
  this->name = name;
}

bool Alumno::setId(string id) {
  if(id.length() > 7/*|| contiene letras*/) {
    return false;
  } else {
    this->id = id;
    return true;
  }
}

string Alumno::getName() {
  return name;
}

string Alumno::getId() {
  return id;
}

ostream& operator<<(ostream& os, Alumno* a) {
  os<<"Nombre: "<<a->getName()<<endl;
  os<<"NIA: "<<a->getId()<<endl;
  return os;
}

list<Subjects*>::iterator Alumno::getItBegin() {
  list<Subjects*>::iterator it = asignaturas.begin();
  return it;
}

list<Subjects*>::iterator Alumno::getItEnd() {
  list<Subjects*>::iterator it = asignaturas.end();
  return it;
}

list<Conference*>::iterator Alumno::getItBeginConference() {
  list<Conference*>::iterator it = seminarios.begin();
  return it;
}
list<Conference*>::iterator Alumno::getItEndConference() {
  list<Conference*>::iterator it = seminarios.end();
  return it;
}
list<TrabajoFinEstudios*>::iterator Alumno::getItBeginTFE() {
  list<TrabajoFinEstudios*>::iterator it = tfe.begin();
  return it;
}
list<TrabajoFinEstudios*>::iterator Alumno::getItEndTFE() {
  list<TrabajoFinEstudios*>::iterator it = tfe.end();
  return it;
}

map<string,unsigned int>::iterator Alumno::getItBeginNotas() {
  map<string,unsigned int>::iterator it = notas.begin();

  return it;
}

map<string,unsigned int>::iterator Alumno::getItEndNotas() {
  map<string,unsigned int>::iterator it = notas.end();

  return it;
}

map<string,unsigned int>::iterator Alumno::findMapPosition(string key) {
  return notas.find(key);
}

void Alumno::setGrades(string id, unsigned int grade) {
  notas.insert(pair<string,unsigned int>(id,grade));
}

void Alumno::modifyGrades(string id, unsigned int grade) {
  notas[id] = grade;
}

void Alumno::setSubjects(Subjects* s) {
  asignaturas.push_back(s);
}

void Alumno::setConferences(Conference* c) {
  seminarios.push_back(c);
}
void Alumno::setTFE(TrabajoFinEstudios* t) {
  tfe.push_back(t);
}

void Alumno::removeSubjects(list<Subjects*>::iterator it) {
  asignaturas.erase(it);
}
void Alumno::removeConferences(list<Conference*>::iterator it) {
  seminarios.erase(it);
}
void Alumno::removeTFE(list<TrabajoFinEstudios*>::iterator it) {
  tfe.erase(it);
}
