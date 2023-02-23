#include <stdio.h>
#include <stdlib.h>
#include "lunarcalbase.h"


int main(int argc, char *argv[])
{
    int start, end;
    int solarOnly = 0;
    if (argc == 2) {
        start = atoi(argv[1]);
        end = start;
    } else if (argc > 2) {
        start = atoi(argv[1]);
        end = atoi(argv[2]);
        solarOnly = atoi(argv[3]);
    } else {
        printf("Usage: lunarcal startyear endyear solarOnly(1/0)\n");
        exit(2);
    }

    if (solarOnly == 1)
    {
       printf("BEGIN:VCALENDAR\n"
          "PRODID:-//Chen Wei//Chinese Lunar Calendar//EN\n"
          "VERSION:2.0\n"
          "CALSCALE:GREGORIAN\n"
          "METHOD:PUBLISH\n"
          "X-WR-CALNAME:节气\n"
          "X-WR-TIMEZONE:Asia/Shanghai\n"
          "X-WR-CALDESC:节气-%d-%d\n", start, end);
    }
    else
    {
      printf("BEGIN:VCALENDAR\n"
          "PRODID:-//Chen Wei//Chinese Lunar Calendar//EN\n"
          "VERSION:2.0\n"
          "CALSCALE:GREGORIAN\n"
          "METHOD:PUBLISH\n"
          "X-WR-CALNAME:农历\n"
          "X-WR-TIMEZONE:Asia/Shanghai\n"
          "X-WR-CALDESC:中国农历%d-%d, 包括节气.\n", start, end);
    }
    while (start <= end) {
        cn_lunarcal(start, solarOnly);
        start++;
    }
    printf("END:VCALENDAR\n");

    return 0;
}
