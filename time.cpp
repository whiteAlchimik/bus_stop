
#include "time.h"

std::istream & operator>>(std::istream &in, Time &time)
{
  std::cout << "hh: ";
  in >> time._hours;
  std::cout << "mm: ";
  in >> time._minutes;
  return in;
}

std::ostream & operator<<(std::ostream &out, const Time &time)
{
  out << time.getTimeStr();
  return out;
}

std::ifstream & operator>>(std::ifstream &in, Time &time)
{
    std::string timeStr;
    in >> timeStr;

    time.parseTimeStr(timeStr);

    return in;
}

std::ofstream & operator<<(std::ofstream &out, const Time &time)
{
    out << time.getTimeStr();
    return out;
}
