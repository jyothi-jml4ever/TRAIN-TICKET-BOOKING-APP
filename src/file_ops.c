#include "../include/irctc.h"

int check_user(char *u, char *p)
{
    FILE *fp = fopen("data/usr_logins.txt", "r");
    char user[MAX], pass[MAX];

    while (fp && fscanf(fp, "%s %s", user, pass) != EOF)
    {
        if (!strcmp(user, u))
        {
            if (!p || !strcmp(pass, p))
            {
                fclose(fp);
                return 1;
            }
        }
    }
    if (fp) fclose(fp);
    return 0;
}

void save_user(char *u, char *p)
{
    FILE *fp = fopen("data/usr_logins.txt", "a");
    fprintf(fp, "%s %s\n", u, p);
    fclose(fp);
}

void update_seats(int tno, int booked)
{
    FILE *fp = fopen("data/trains_info.txt","r");
    FILE *tmp = fopen("data/temp.txt","w");

    train_t t;

    while (fscanf(fp,"%d %s %s %s %d %d\n",
            &t.train_no,
            t.train_name,
            t.source,
            t.destination,
            &t.total_seats,
            &t.available_seats) != EOF)
    {
        if (t.train_no == tno)
            t.available_seats -= booked;

        fprintf(tmp,"%d %s %s %s %d %d\n",
            t.train_no,t.train_name,t.source,
            t.destination,t.total_seats,t.available_seats);
    }

    fclose(fp);
    fclose(tmp);

    remove("data/trains_info.txt");
    rename("data/temp.txt","data/trains_info.txt");
}