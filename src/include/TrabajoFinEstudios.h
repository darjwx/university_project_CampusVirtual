#ifndef _TrabajoFinEstudios_H_
#define _TrabajoFinEstudios_H_
#include <string>
#include <fstream>
#include "Resources.h"
#include "Teacher.h"
#include "Alumno.h"

using namespace std;

class TrabajoFinEstudios : public Resources {
private:
  Alumno* alumno;
  string titulacion;
  Teacher* tutor;
  Teacher* coTutor;
public:
  TrabajoFinEstudios();
  virtual void setStatus(char);
  virtual char getStatus();
  virtual void setId(string);
  virtual string getId();
  virtual void setName(string);
  virtual string getName();
  void setTitulacion(string);
  string getTitulacion();
  void setTutor(Teacher*);
  Teacher* getTutor();
  void setCoTutor(Teacher*);
  Teacher* getCoTutor();
  void setAlumnoApuntado(Alumno*);
  Alumno* getAlumno();
  void NullT();
  void NullCT();
  void NullAlumno();
};
#endif //_TrabajoFinEstudios_H_
