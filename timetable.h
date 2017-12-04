
#ifndef TIMETABLE_H
#define TIMETABLE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

#include "service.h"

class TimeTable
{
public:
  TimeTable()
  {}
    
  void insert(const Service &service)
  {
    this->_vectorServeces.push_back(service);
  }

  void clear()
  {
    this->_vectorServeces.clear();
  }

  void sortByDepartureTime();
  void removeLongService();

  friend std::ofstream & operator<<(std::ofstream &out, const TimeTable &timeTable);

private:
  std::vector<Service> _vectorServeces;
};

#endif
