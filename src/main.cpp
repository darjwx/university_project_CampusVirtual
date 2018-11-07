#include <iostream>
//#include <fstream>
#include "include/main.h"
#include "include/CampusVirtual.h"

using namespace std;

int main() {
  //cargarArchivo();

  CampusVirtual cv;
  cv.inicio();

  return 0;
}

/*void cargarArchivo() {
  ifstream memoria("ajustes.txt");

  //Test
  char text[100];
  memoria.getline(text, 100);
  cout<<text<<endl;

}*/
