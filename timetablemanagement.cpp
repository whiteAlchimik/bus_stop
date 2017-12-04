
#include "timetablemanagement.h"

void TimeTableManagement::load(const std::string &fileName)
{
  std::ifstream in(fileName);
  if(!in.is_open())
  {
    std::cout << "Error open file: " << fileName << std::endl;
    exit(1);
  }

  while(in)
  {
    Service service;
    in >> service;
    if(in.eof())
    {
      break;
    }
    int pos = this->getPositionByName(service.getNameCompany());
    if(pos < 0)
    {
      continue;
    }
    this->_vTimeTables[pos].insert(service);
  }

  in.close();
}

void TimeTableManagement::save(const std::string &fileName)
{
  std::ofstream out(fileName);
  if(!out.is_open())
  {
    std::cout << "Error open file: " << fileName << std::endl;
    exit(1);
  }

  for(auto i : this->_vTimeTables)
  {
    out << i << std::endl;
  }

  out.close();
}

void TimeTableManagement::sortByDepartureTime()
{
  for(auto &i : this->_vTimeTables)
  {
    i.sortByDepartureTime();
  }
}

void TimeTableManagement::removeLongService()
{
  for(auto &i : this->_vTimeTables)
  {
    i.removeLongService();
  }
}

int TimeTableManagement::getPositionByName(const std::string &nameCompany)
{
  if(nameCompany == "Posh")
  {
    return 0;
  }
  else if(nameCompany == "Grotty")
  {
    return 1;
  }
  else
  {
    return -1;
  }
}
