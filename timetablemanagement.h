
#ifndef TIMETABLEMANAGEMENT_H
#define TIMETABLEMANAGEMENT_H

#include <fstream>
#include <vector>
#include <string>

#include "timetable.h"

#define NUMBER_COMPANIES 2

class TimeTableManagement
{
public:
  TimeTableManagement() :
  _vTimeTables(NUMBER_COMPANIES)
  {}

  void load(const std::string &fileName);

  void save(const std::string &fileName);

  void sortByDepartureTime();

  void removeLongService();

private:
  std::vector<TimeTable> _vTimeTables;

  int getPositionByName(const std::string &nameCompany);
};

#endif
