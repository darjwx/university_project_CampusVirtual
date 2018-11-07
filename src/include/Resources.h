#ifndef _Resources_H_
#define _Resources_H_
class Resources {
private:
  //c: creado, i: iniciado, f:finalizado
  char status;
  //LLLNNNN: L, letra entre Aa y Zz. N, numero del 0 al 9
  char id;
public:
  Resources();
  Resources(char status, char id);
  ~Resources();
  void setStatus(char status);
  char getStatus();
  void setId(char id);
  char getId();
  void showList();
};
#endif //_Resources_H_
