
#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <fstream>
#include <string>

class Time
{
public:
  Time() :
          _hours(-1),
          _minutes(-1)
      {}

    Time(const int hours, const int minutes) :
        _hours(hours),
        _minutes(minutes)
    {}

    Time(const Time &time) :
        _hours(time._hours),
        _minutes(time._minutes)
    {}

    Time & operator=(const Time &time)
    {
        if(this != &time)
        {
            this->_hours = time._hours;
            this->_minutes = time._minutes;
        }
        return *this;
    }

    std::string getTimeStr() const
    {
        return (std::to_string(this->_hours) +
                ':' +
                std::to_string(this->_minutes));
    }

    bool operator==(const Time &time) const
    {
        return ((this->_hours == time._hours) &&
                (this->_minutes == time._minutes));
    }

    bool operator<(const Time &time) const
    {
      return this->convertToMinutes() < time.convertToMinutes();
    }

    bool operator<=(const Time &time) const
    {
      return this->convertToMinutes() <= time.convertToMinutes();
    }

    Time operator-(const Time &time) const
    {
      int a = this->convertToMinutes();
      int b = time.convertToMinutes();

      int res = a - b;

      return Time((int)(res / 60), (res % 60));
    }

    int convertToMinutes() const
    {
        return this->_hours * 60 + this->_minutes;
    }

    friend std::istream & operator>>(std::istream &in, Time &time);
    friend std::ostream & operator<<(std::ostream &out, const Time &time);

    friend std::ifstream & operator>>(std::ifstream &in, Time &time);
    friend std::ofstream & operator<<(std::ofstream &out, const Time &time);

private:
    int _hours;
    int _minutes;

    void parseTimeStr(const std::string &timeStr)
    {
      if(timeStr.empty())
      {
        return;
      }

      std::string::size_type sz = 0;

      this->_hours = std::stoi(timeStr, &sz);

      ++sz;

      this->_minutes = std::stoi(timeStr.substr(sz));
    }
};

#endif
