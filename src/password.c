#include "../include/irctc.h"

int valid_password(char *p)
{
    int u=0,l=0,d=0,s=0;

    if (strlen(p) < 8) return 0;

    for (int i=0; p[i]; i++)
    {
        if (isupper(p[i])) u=1;
        else if (islower(p[i])) l=1;
        else if (isdigit(p[i])) d=1;
        else s=1;
    }
    return u && l && d && s;
}