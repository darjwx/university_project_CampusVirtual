#include <iostream>
#include "Conference.h"

using namespace std;

Conference::Conference(string supervisor,string speaker,Date* date,int capacity,
    char* alumnos) {
  this->supervisor = supervisor;
  this->speaker = speaker;
  this->date = date;
  this->capacity = capacity;
  this->alumnos = alumnos;
}
void Conference::setSupervisor(string supervisor) {
  this->supervisor = supervisor;
}
void Conference::setSpeaker(string speaker) {
  this->speaker = speaker;
}
void Conference::setDate(Date* date) {
  this->date = date;
}
void Conference::setCapacity(int capacity) {
  this->capacity = capacity;
}
void Conference::setAlumnos(char* alumnos) {
  this->alumnos = alumnos;
}
string Conference::getSupervisor() {
  return supervisor;
}
string Conference::getSpeaker() {
  return speaker;
}
Date* Conference::getDate() {
  return date;
}
int Conference::getCapacity() {
  return capacity;
}
char* Conference::getAlumnos() {
  return alumnos;
}
