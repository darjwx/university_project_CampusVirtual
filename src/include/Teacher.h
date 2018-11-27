#ifndef _Teacher_H_
#define _Teacher_H_
#include <string>
#include "Usuario.h"

using namespace std;

class Teacher : public Usuario {
public:
  Teacher();
  virtual void setName(string);
  virtual bool setId(string);
  virtual string getId();
  virtual string getName();
  Teacher& operator=(Teacher&);
};
#endif //_Teacher_H_
