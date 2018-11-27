#ifndef _Alumno_H_
#define _Alumno_H_
#include <string>
#include "Usuario.h"

using namespace std;

class Alumno : public Usuario {
public:
  Alumno();
  Alumno(string, string);
  virtual void setName(string);
  virtual bool setId(string);
  virtual string getId();
  virtual string getName();

};
#endif //_Alumno_H_
