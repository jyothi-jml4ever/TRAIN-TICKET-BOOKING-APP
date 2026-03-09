#include "../include/irctc.h"

/* Find last booked seat for given train and date */
int get_last_seat(int tno, char *date)
{
    FILE *fp = fopen("data/bookings.txt","r");
    if (!fp)
        return 0;

    passenger_t p;
    int g;
    int max_seat = 0;

    while (fscanf(fp,"%d %s %d %s %d %d",
        &p.train_no,
        p.date,
        &p.seat_no,
        p.name,
        &p.age,
        &g) != EOF)
    {
        if (p.train_no == tno && strcmp(p.date,date) == 0)
        {
            if (p.seat_no > max_seat)
                max_seat = p.seat_no;
        }
    }
    fclose(fp);
    return max_seat;
}

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

    /* prevent overbooking */
    if (seats > t.available_seats)
    {
        printf("Not enough seats available\n");
        return;
    }

    if (seats > 5)
    {
        printf("Maximum 5 seats allowed per booking\n");
        seats = 5;
    }

    FILE *fp = fopen("data/bookings.txt","a");

    if (!fp)
    {
        printf("Error opening bookings file\n");
        return;
    }

    /* get next seat number */
    int start_seat = get_last_seat(tno,date) + 1;
    
    //FILE *fp = fopen("data/bookings.txt", "a");

    for (int i=0; i<seats; i++)
    {
        passenger_t p;
        int g;
        p.train_no = tno;
        strcpy(p.date, date);
        //p.seat_no = i;
         p.seat_no = start_seat + i;

        printf("Name: ");
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
    
    fclose(fp);

    update_seats(tno, seats);
    
    //if (seats > 5)
       // printf("Only 5 seats booked\n");
     printf("\nBooking Successful!\n");
}
