
#include <iostream>

#include "timetablemanagement.h"

using namespace std;

int main()
{
  TimeTableManagement ttm;

  ttm.load("input");

  ttm.sortByDepartureTime();
  ttm.removeLongService();

  ttm.save("output");

  return 0;
}
