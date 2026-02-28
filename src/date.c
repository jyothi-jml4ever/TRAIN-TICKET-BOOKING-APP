#include "../include/irctc.h"

int valid_date(char *d)
{
    struct tm jd = {0};
    time_t now = time(NULL);

    sscanf(d, "%d-%d-%d", &jd.tm_mday, &jd.tm_mon, &jd.tm_year);
    jd.tm_mon--;
    jd.tm_year -= 1900;

    time_t jt = mktime(&jd);
    double diff = difftime(jt, now)/(60*60*24);

    return (diff >= 0 && diff <= 3);
}