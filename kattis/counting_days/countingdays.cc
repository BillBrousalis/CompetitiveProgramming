#include "countingdays.h"

int days = 1;
int last_hours = 0, last_minutes = 0;

void lookAtClock(int hours, int minutes)
{
  if (hours < last_hours || (hours == last_hours && minutes < last_minutes)) days++;
  last_hours = hours;
  last_minutes = minutes;
}

int getDay()
{
  return days;
}
