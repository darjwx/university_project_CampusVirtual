#ifndef _Alumno_H_
#define _Alumno_H_
#include <string>
#include <list>
#include "Usuario.h"
class Subjects;
class Conference;
class TrabajoFinEstudios;

using namespace std;

class Alumno : public Usuario {
private:
  list<Subjects*> asignaturas;
  list<Conference*> seminarios;
  list<TrabajoFinEstudios*> tfe;
public:
  Alumno();
  Alumno(string, string);
  virtual void setName(string);
  virtual bool setId(string);
  virtual string getId();
  virtual string getName();
  list<Subjects*>::iterator getItBegin();
  list<Subjects*>::iterator getItEnd();
  list<Conference*>::iterator getItBeginConference();
  list<Conference*>::iterator getItEndConference();
  list<TrabajoFinEstudios*>::iterator getItBeginTFE();
  list<TrabajoFinEstudios*>::iterator getItEndTFE();
  void setSubjects(Subjects*);
  void setConferences(Conference*);
  void setTFE(TrabajoFinEstudios*);

};
#endif //_Alumno_H_
