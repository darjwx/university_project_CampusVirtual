#ifndef _Date_H_
#define _Date_H_
class Date {
private:
  int year;
  int month;
  int day;
public:
  Date(int day, int month, int year);
  void setDay(int day);
  void setMonth(int month);
  void setYear(int year);
  int returnDay();
  int returnMonth();
  int returnYear();
  Date& operator=(const Date& date);
};
#endif //_Date_H_
