
#ifndef SERVICE_H
#define SERVICE_H

#include <iostream>
#include <fstream>
#include <string>

#include "time.h"


class Service
{
public:
  Service() :
  _nameCompany(""),
  _departureTime(),
  _arrivalTime()
  {}

  Service(const Service &service) :
  _nameCompany(service._nameCompany),
  _departureTime(service._departureTime),
  _arrivalTime(service._arrivalTime)
  {}

  Service & operator=(const Service &service)
  {
    if(this != &service)
    {
      this->_nameCompany = service._nameCompany;
      this->_departureTime = service._departureTime;
      this->_arrivalTime = service._arrivalTime;
    }
    return *this;
  }

  std::string getNameCompany() const
  {
    return this->_nameCompany;
  }

  Time getDepartureTime() const
  {
    return this->_departureTime;
  }

  Time getServiceTime() const
  {
    return this->_arrivalTime - this->_departureTime;
  }

  friend std::ostream & operator<<(std::ostream &out, const Service &service);

  friend std::ifstream & operator>>(std::ifstream &in, Service &service);
  friend std::ofstream & operator<<(std::ofstream &out, const Service &service);

private:
  std::string _nameCompany;
  Time _departureTime;
  Time _arrivalTime;
};

#endif
