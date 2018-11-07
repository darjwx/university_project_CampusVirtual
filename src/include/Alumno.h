#ifndef _Alumno_H_
#define _Alumno_H_
class Alumno {
private:
  int nia;
  char nombre;
public:
  Alumno();
  Alumno(int nia, char nombre);
  void setNombre(char nombre);
  void setNia(int nia);
  int getNia();
  char getNombre();
  void getLista();

};
#endif //_Alumno_H_
