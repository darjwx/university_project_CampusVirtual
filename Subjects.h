#ifndef _Subjects_H_
#define _Subjects_H_
#include <iostream>
#include <string>
#include <fstream>
#include "Resources.h"

using namespace std;

class Subjects : public Resources {
private:
  string titulacion;
  //char teachers = new char[2];
  char* teachers;
  unsigned int credits;
  //char* alumnos = new char[tam];
  char* alumnos;
  //0-10
  unsigned int grade;
public:
  Subjects();
  Subjects(string titulacion,char* teachers,unsigned int credits,
    char* alumnos);
  ~Subjects();
  void setTeachers(char* teachers);
  void setCredits(unsigned int credits);
  void setAlumnos(char* alumnos);
  void setGrade(unsigned int grade);
  char* getTeachers();
  unsigned int getCredits();
  char* getAlumnos();
  unsigned int getGrade();
  void showList();
};
#endif //_Subjects_H_
