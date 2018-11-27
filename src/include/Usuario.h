#ifndef _Usuario_H_
#define _Usuario_H_
#include <iostream>
#include <string>

using namespace std;

class Usuario {
protected:
  string id;
  string name;
public:
  virtual bool setId(string)=0;
  virtual void setName(string)=0;
  virtual string getId()=0;
  virtual string getName()=0;

};
#endif //_Usuario_H_
