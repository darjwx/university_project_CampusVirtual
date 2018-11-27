#ifndef _Administrator_H_
#define _Administrator_H_
#include <string>
#include "Usuario.h"

using namespace std;

class Administrator : public Usuario {
public:
  Administrator();
  Administrator(string, string);
  virtual void setName(string);
  virtual bool setId(string);
  virtual string getId();
  virtual string getName();

};
#endif //_Administrator_H_
