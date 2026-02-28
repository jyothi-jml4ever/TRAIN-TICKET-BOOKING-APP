#include "../include/irctc.h"

void reserve_ticket()
{
    int tno, seats;
    char date[15];

    train_t t;

    printf("Train No: ");
    scanf("%d", &tno);

    if (!train_exists(tno,&t)) {
        printf("Invalid Train Number!\n");
        return;
    }

    printf("Date (dd-mm-yyyy): ");
    scanf("%s", date);

    if (!valid_date(date))
    {
        printf("Booking allowed only for next 3 days\n");
        return;
    }

    printf("Seats Required: ");
    scanf("%d", &seats);

    FILE *fp = fopen("data/bookings.txt", "a");

    for (int i=1; i<=seats && i<=5; i++)
    {
        passenger_t p;
        int g;
        p.train_no = tno;
        strcpy(p.date, date);
        p.seat_no = i;

        printf("Passenger Name: ");
        scanf("%s", p.name);
        printf("Age: ");
        scanf("%d", &p.age);
        printf("Gender (0=Male,1=Female): ");
        scanf("%d",&g);
        p.gender = g;

        fprintf(fp, "%d %s %d %s %d %d\n",
            p.train_no, p.date,
            p.seat_no, p.name, p.age,p.gender);
    }

    update_seats(tno, seats);

    fclose(fp);

    if (seats > 5)
        printf("Only 5 seats booked\n");
}