#ifndef __TIME_H__
#define __TIME_H__
#include <stdint.h>

struct _time {
  uint32_t hour;
  uint32_t minute;
  uint32_t second;
  uint32_t day_of_week;
  uint32_t day_of_month;
  uint32_t day_of_year;
  uint32_t month;
  uint32_t year;
};

unsigned int mktime(unsigned int tm_sec,unsigned int tm_min, unsigned int tm_hour, unsigned int tm_yday, unsigned int tm_year);

uint16_t day_of_year(uint16_t day, uint16_t month, uint16_t year);

struct _time mkdate(uint32_t timestamp);

#endif
