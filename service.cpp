
#include "service.h"

std::ostream & operator<<(std::ostream & out, const Service &service)
{
  out << "Name company: " << service._nameCompany << ' ';
  out << "Departure time: " << service._departureTime << ' ';
  out << "Arrival time: " << service._arrivalTime;
  return out;
}

std::ifstream & operator>>(std::ifstream &in, Service &service)
{
    in >> service._nameCompany;
    in.ignore();
    in >> service._departureTime;
    in.ignore();
    in >> service._arrivalTime;
    in.ignore();
    return in;
}

std::ofstream & operator<<(std::ofstream &out, const Service &service)
{
    out << service._nameCompany << " ";
    out << service._departureTime.getTimeStr() << " ";
    out << service._arrivalTime.getTimeStr();

    return out;
}
