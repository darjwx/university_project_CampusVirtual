#ifndef _Subjects_H_
#define _Subjects_H_
#include <iostream>
#include <string>
#include <fstream>
#include "Resources.h"
#include "Teacher.h"

using namespace std;

class Subjects : public Resources {
private:
  string titulacion;
  Teacher teacher1;
  Teacher teacher2;
  unsigned int credits;
  //0-10
  unsigned int grade;
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
  void setGrade(unsigned int);
  unsigned int getGrade();
  void setTeacher(Teacher, Teacher);
  Teacher& getTeacher1();
  Teacher& getTeacher2();

};
#endif //_Subjects_H_
