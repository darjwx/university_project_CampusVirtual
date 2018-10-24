#ifndef _CampusVirtual_H_
#define _CampusVirtual_H_
class CampusVirtual {
private:
  char* listaAdmins;
  char*listaProfs;
  int* listaAlum;
public:
  CampusVirtual();
  CampusVirtual(char* listaAdmins, char* listaProfs,  int* listaAlum);
  void inicio();
  int login();
  void menuAlumno();
  void menuAdmin();
  void menuProfesor();
  void gestionarRecursos();
  void mostrarUsuarios();
  void mostrarRecursos();
  void calificar();
  void altaRecurso();
  void bajaRecurso();
};
#endif //_CampusVirtual_H_
