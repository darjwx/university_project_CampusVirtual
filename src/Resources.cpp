#include <iostream>
#include "include/Resources.h"

using namespace std;

Resources::Resources() {
  //DO NOTHING
}

Resources::Resources(char status, char id) {
  this->status = status;
  this->id = id;
}

void Resources::setStatus(char status) {
  this->status = status;
}

char Resources::getStatus() {
  return status;
}

void Resources::setId(char id) {
  this->id = id;
}

char Resources::getId() {
  return id;
}

Resources::~Resources() {

}
