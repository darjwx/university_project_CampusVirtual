#include <iostream>
#include "Date.h"

using namespace std;

Date::Date(int day, int month, int year) {
  this->day = day;
  this->month = month;
  this->year = year;
}

void Date::setDay(int day) {
  this->day = day;
}

void Date::setMonth(int month) {
  this->month = month;
}

void Date::setYear(int year) {
  this->year = year;
}

int Date::returnDay() {
  return day;
}

int Date::returnMonth() {
  return month;
}

int Date::returnYear() {
  return year;
}

Date& Date::operator=(const Date& date) {
  day = date.day;
  month = date.month;
  year = date.year;
  
  return *this;
}
