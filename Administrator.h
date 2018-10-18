#ifndef _Administrator_H_
#define _Administrator_H_
class Administrator {
private:
  char id;
public:
  //Eliminar o subir contenido.
  void gestionarContenido();
  //modificar contenido
  void modificarContenido();
  //Crear, modificar y eliminar usuarios
  void gestionarUsuarios();
};
#endif //_Administrator_H_
