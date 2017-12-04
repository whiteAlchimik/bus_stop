
#include "timetable.h"

void TimeTable::sortByDepartureTime()
{
  if(this->_vectorServeces.empty())
  {
    return;
  }

  std::sort(this->_vectorServeces.begin(),
       this->_vectorServeces.end(),
       [](const Service &lhs, const Service &rhs) -> bool
       {
         return (lhs.getDepartureTime() < rhs.getDepartureTime());
       });
}

void TimeTable::removeLongService()
{
  if(this->_vectorServeces.empty())
  {
    return;
  }

  Time topLimit(1, 0);

  while(true)
  {
    auto it = std::find_if(this->_vectorServeces.begin(),
         this->_vectorServeces.end(),
         [&](const Service &item)
         {
           return !(item.getServiceTime() <= topLimit);
         });

    if(it == this->_vectorServeces.end())
    {
      break;
    }
    else
    {
      this->_vectorServeces.erase(it);
    }
  }
}

std::ofstream & operator<<(std::ofstream &out, const TimeTable &timeTable)
{
  for(auto i : timeTable._vectorServeces)
  {
      out << i << std::endl;
  }

  return out;
}
