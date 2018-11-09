#ifndef _Usuario_H_
#define _Usuario_H_
#include <string>

using namespace std;

class Usuario {
protected:
  string nombre;
  string id;
public:
  string getNombre();
  void setNombre(string);
  string getId();
  void setId(string);
};
#endif //_Usuario_H_
