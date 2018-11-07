#include <iostream>
#include "include/Conference.h"

using namespace std;

Conference::Conference() {
  //DO NOTHING
}

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

Conference::~Conference() {

}

void Conference::showList() {
  int n = 0;
  string linea;
  fstream fs("seminarios.dat", ios::in | ios::binary);

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
    cin>>temp;
  //27 is ESC key in ASCII
  } while(temp != 27);
}
