#ifndef _TrabajoFinEstudios_H_
#define _TrabajoFinEstudios_H_
#include <string>

using namespace std;

class TrabajoFinEstudios {
private:
  string titulacion;
  string tutor;
  string coTutor;
  string alumno;
public:
  TrabajoFinEstudios();
  TrabajoFinEstudios(string titulacion,string tutor,string coTutor,
      string alumno);
  TrabajoFinEstudios(string titulacion,string tutor,string alumno);
  void setTitulacion(string titulacion);
  void setTutor(string tutor);
  void setCoTutor(string coTutor);
  void setAlumno(string alumno);
  string getTitulacion();
  string getTutor();
  string getCoTutor();
  string getAlumno();
};
#endif //_TrabajoFinEstudios_H_
