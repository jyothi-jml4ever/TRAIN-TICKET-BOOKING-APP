#include "../include/irctc.h"

void cancel_ticket()
{
    int tno, seat;
    char date[15];

    printf("Train No: ");
    scanf("%d", &tno);
    printf("Date: ");
    scanf("%s", date);
    printf("Seat No: ");
    scanf("%d", &seat);

    FILE *fp = fopen("data/bookings.txt", "r");
    FILE *tmp = fopen("data/tmp.txt", "w");

    passenger_t p;
    int found = 0;

    while (fscanf(fp, "%d %s %d %s %d",
        &p.train_no, p.date,
        &p.seat_no, p.name, &p.age) != EOF)
    {
        if (p.train_no==tno && p.seat_no==seat && !strcmp(p.date,date))
        {
            found = 1;
            continue;
        }
        fprintf(tmp, "%d %s %d %s %d\n",
            p.train_no, p.date, p.seat_no, p.name, p.age);
    }

    fclose(fp);
    fclose(tmp);

    remove("data/bookings.txt");
    rename("data/tmp.txt", "data/bookings.txt");

    if (found) 
    {
        printf("Ticket Cancelled\n");
        update_seats(tno, -1);
    }
    else printf("Booking not found\n");
}