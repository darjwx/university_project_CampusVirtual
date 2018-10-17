#ifndef _Conference_H_
#define _Conference_H_
#include <string>
#include "Date.h"

using namespace std;

class Conference {
private:
  string supervisor;
  string speaker;
  Date* date;
  int capacity;
  //char* alumnos = new char[tam]
  char* alumnos;
public:
  Conference();
  Conference(string supervisor,string speaker,Date* date,int capacity,
      char* alumnos);
  ~Conference();
  void setSupervisor(string supervisor);
  void setSpeaker(string speaker);
  void setDate(Date* date);
  void setCapacity(int capacity);
  void setAlumnos(char* alumnos);
  string getSupervisor();
  string getSpeaker();
  Date* getDate();
  int getCapacity();
  char* getAlumnos();

};
#endif //_Conference_H_
