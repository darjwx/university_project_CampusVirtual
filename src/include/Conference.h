#ifndef _Conference_H_
#define _Conference_H_
#include <string>
#include <fstream>
#include "Date.h"
#include "Alumno.h"
#include "Resources.h"
#include "Teacher.h"

using namespace std;

class Conference : public Resources{
private:
  Teacher* supervisor;
  string speaker;
  Date* date;
  int capacity;
  list<Alumno*> alumnoApuntados;
public:
  Conference();
  virtual void setStatus(char);
  virtual char getStatus();
  virtual void setId(string);
  virtual string getId();
  virtual void setName(string);
  virtual string getName();
  void setSupervisor(Teacher*);
  Teacher* getSupervisor();
  void setSpeaker(string);
  string getSpeaker();
  void setDate(Date*);
  Date* getDate();
  void setCapacity(int);
  int getCapacity();
  list<Alumno*>::iterator getItBegin();
  list<Alumno*>::iterator getItEnd();
  void setAlumnosApuntados(Alumno*);
  void eliminarAlumno(list<Alumno*>::iterator);
  void NullS();

};
#endif //_Conference_H_
