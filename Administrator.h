#ifndef _Administrator_H_
#define _Administrator_H_
#include <string>

using namespace std;

class Administrator {
private:
  char id;
  string name;
public:
  Administrator();
  Administrator(string name, char id);
  //Eliminar o subir contenido.
  void gestionarContenido();
  //modificar contenido
  void modificarContenido();
  //Crear, modificar y eliminar usuarios
  void gestionarUsuarios();
  void addUsuarios(int type);
  void removeUsuarios();
  void modificarDatos();
};
#endif //_Administrator_H_
