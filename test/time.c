#include <stdio.h>
#include <stdint.h>

struct _time {
  uint32_t hour;
  uint32_t minute;
  uint32_t second;
  uint32_t day_of_year;
  uint32_t day_of_month;
  uint32_t month;
  uint32_t year;
};

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


struct dcf77_time {
  uint8_t hour;
  uint8_t minute;
  uint8_t seconds;
  uint8_t day_of_month;
  uint8_t day_of_week;
  uint8_t month;
  uint8_t year;
};

void main() {
  uint32_t _bit32_58= 0xFC8E0494;  
  struct dcf77_time x;
  x.day_of_month = (uint8_t)((_bit32_58&0x000000f0)>>4)+(((_bit32_58&0x00000300)>>8)*10); // X
  x.day_of_week = (uint8_t)((_bit32_58&0x00001c00)>>10);
  x.month = (uint8_t)((_bit32_58&0x0001e000)>>13)+(((_bit32_58&0x00020000)>>17)*10);
  x.year = (uint8_t)((_bit32_58&0x003c0000)>>18)+(((_bit32_58&0x03c00000)>>22)*10); // X
  printf("%u %u %u %u\n",x.day_of_month,x.day_of_week,x.month,x.year);
  printf("%u\n\r",day_of_year(10,10,23));
  printf("unix time: %u\n\r",mktime(0,0,0,day_of_year(20,3,2000),2000));
  struct _time test = mkdate(1696944498);
  printf("year: %u.%u.%u, dayofyear %u %u:%u:%u\r\n",test.day_of_month,test.month,test.year,test.day_of_year,test.hour,test.minute,test.second);
}
