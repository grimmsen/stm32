#include "time.h"

unsigned int mktime(unsigned int tm_sec,unsigned int tm_min, unsigned int tm_hour, unsigned int tm_yday, unsigned int tm_year) {
  uint32_t time;
  if(tm_year>=1972) {
    time = tm_sec + tm_min*60 + tm_hour*3600 + tm_yday*86400 + (tm_year-1970)*86400*365+((tm_year-1-1972)/4)*86400;
  } else { // silently ignore ancient times
    return 0;
  }
  return time;
}

uint16_t day_of_year(uint16_t day, uint16_t month, uint16_t year) {
  uint16_t doy=0;
  for(uint8_t c=1; c<month; c++) {
    switch(c) {
      case 1:
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
      case 12:
        doy+=31;
        break;
      case 4:
      case 6:
      case 9:
      case 11:
        doy+=30;
        break;
      case 2:
        if((year%4)==0) {
          doy+=29;
        } else {
          doy+=28;
        }
        break;
      default:
        break;
    }
  }
  return doy+day;
}

struct _time mkdate(uint32_t timestamp) {
  struct _time t_time;
  uint32_t doy=0;
  t_time.year = 1970+timestamp/31556926;
  t_time.day_of_year = (timestamp-((t_time.year-1970)*31536000+(t_time.year-1970)/4*86400))/86400;
  t_time.month=1;
  doy = t_time.day_of_year;
  while(doy>31) {
    switch(t_time.month) {
      case 1:
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
      case 12:
        if(doy>31) {
          t_time.month++;
          doy-=31;
        }
        break;
      case 4:
      case 6:
      case 9:
      case 11:
        if(doy>30) {
          t_time.month++;
          doy-=30;
        }
        break;
      case 2:
        if((t_time.year%4)==0) {
          if(doy>29) {
            t_time.month++;
            doy-=29;
          }
        } else {
          if(doy>28) {
            t_time.month++;
            doy-=28;
          }
        }
      default:
        break;
    }
  }
  t_time.day_of_month=doy+1;
  t_time.hour = (timestamp-mktime(0,0,0,t_time.day_of_year+1,t_time.year))/3600;
  t_time.minute = (timestamp-mktime(0,0,t_time.hour,t_time.day_of_year+1,t_time.year))/60;
  t_time.second = timestamp-mktime(0,t_time.minute,t_time.hour,t_time.day_of_year+1,t_time.year);
  return t_time;
}



