#ifndef _Subjects_H_
#define _Subjects_H_
#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "Resources.h"
#include "Teacher.h"
#include "Alumno.h"

using namespace std;

class Subjects : public Resources {
private:
  string titulacion;
  Teacher* teacher1;
  Teacher* teacher2;
  unsigned int credits;
  list<Alumno*> alumnoApuntados;

public:
  Subjects();
  virtual void setStatus(char);
  virtual char getStatus();
  virtual void setId(string);
  virtual string getId();
  virtual void setName(string);
  virtual string getName();
  void setTitulacion(string);
  string getTitulacion();
  void setCredits(unsigned int);
  unsigned int getCredits();
  void setTeacher(Teacher*, Teacher*);
  void setTeacher1(Teacher*);
  void setTeacher2(Teacher*);
  Teacher* getTeacher1();
  Teacher* getTeacher2();
  list<Alumno*>::iterator getItBegin();
  list<Alumno*>::iterator getItEnd();
  list<Alumno*>::iterator getItPos(int);
  void setAlumnosApuntados(Alumno*);
  void eliminarAlumno(list<Alumno*>::iterator);
  string getIdAlumno(list<Alumno*>::iterator);
  int getNumAl();
  void NullT1();
  void NullT2();

};
#endif //_Subjects_H_
