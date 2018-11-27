#ifndef _Resources_H_
#define _Resources_H_
#include <string>

using namespace std;

class Resources {
protected:
  //c: creado, i: iniciado, f:finalizado
  char status;
  //LLLNNNN: L, letra entre Aa y Zz. N, numero del 0 al 9
  string id;
  string name;
public:
  virtual void setStatus(char) = 0;
  virtual char getStatus() = 0;
  virtual void setId(string) = 0;
  virtual string getId() = 0;
  virtual void setName(string) = 0;
  virtual string getName() = 0;
};
#endif //_Resources_H_
