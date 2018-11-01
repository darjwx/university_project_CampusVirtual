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
  void addUsuarios(int type, string);
  void removeUsuarios();
  void modificarDatos(int,string);
  void showLista(int user);
  void getLista();
  void getType(int*,string*);
};
#endif //_Administrator_H_
