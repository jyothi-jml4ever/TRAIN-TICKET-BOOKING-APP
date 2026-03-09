#include "../include/irctc.h"

void booking_details()
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
    passenger_t p;
    int found=0;
    int g;

    while (fscanf(fp, "%d %s %d %s %d %d",
        &p.train_no, p.date,
        &p.seat_no, p.name, &p.age, &g) != EOF)
    {
        if (p.train_no==tno && p.seat_no==seat && !strcmp(p.date,date))
        {
            printf("\n---------Booking_Details-----------\n");
            printf("Seat:%d\n",p.seat_no);
            printf("Name:%s\n",p.name);
            printf("Age:%d\n",p.age);
            printf("Gender: %s\n", g==MALE?"Male":"Female");
            printf("-----------------------------------\n");

        }
    }
    if(found);
    else printf("Booking details not found\n");
    fclose(fp);

}
