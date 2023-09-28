#include "time.h"

unsigned int mktime(unsigned int tm_sec,unsigned int tm_min, unsigned int tm_hour, unsigned int tm_yday, unsigned int tm_year) {
  return tm_sec + tm_min*60 + tm_hour*3600 + tm_yday*86400 +
    (tm_year-70)*31536000 + ((tm_year-69)/4)*86400 -
    ((tm_year-1)/100)*86400 + ((tm_year+299)/400)*86400;
}
