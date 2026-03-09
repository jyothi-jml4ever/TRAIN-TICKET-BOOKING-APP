#include "../include/irctc.h"

void load_trains()
{
    FILE *fp = fopen("data/trains_info.txt", "a+");
    fclose(fp);
}

int train_exists(int tno, train_t *out)
{
    FILE *fp = fopen("data/trains_info.txt", "r");
    if (!fp) return 0;

    train_t t;

    while (fscanf(fp,"%d %s %s %s %d %d\n",
            &t.train_no,
            t.train_name,
            t.source,
            t.destination,
            &t.total_seats,
            &t.available_seats) != EOF)
    {
        if (t.train_no == tno) {
            if (out) *out = t;
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

void display_trains()
{
    FILE *fp = fopen("data/trains_info.txt", "r");

    printf("\n------ Available Trains ------\n");
 
    if (!fp) {
        printf("No trains available.\n");
        return;
    }

    train_t t;
    int found=0;

    while (fscanf(fp, "%d %s %s %s %d %d",
        &t.train_no, t.train_name, t.source,
        t.destination, &t.total_seats, &t.available_seats) != EOF)
    {
        found=1;
        printf("%d %s %s -> %s Seats:%d\n",
            t.train_no, t.train_name,
            t.source, t.destination,
            t.available_seats);
    }
    fclose(fp);
}

void add_train()
{
    char user[MAX], pass[MAX];
    printf("Admin Username: ");
    scanf("%s", user);
    printf("Admin Password: ");
    scanf("%s", pass);

    if (strcmp(user, "admin") || strcmp(pass, "Admin@123"))
    {
        printf("Admin access denied\n");
        return;
    }

    train_t t;
    FILE *fp = fopen("data/trains_info.txt", "a+");

    printf("Train No: ");
    scanf("%d", &t.train_no);
    printf("Train Name: ");
    scanf("%s", t.train_name);
    printf("Source: ");
    scanf("%s", t.source);
    printf("Destination: ");
    scanf("%s", t.destination);
    printf("Total Seats: ");
    scanf("%d", &t.total_seats);

    t.available_seats = t.total_seats;

    fprintf(fp, "%d %s %s %s %d %d\n",
        t.train_no, t.train_name, t.source,
        t.destination, t.total_seats, t.available_seats);

    fclose(fp);
    printf("Train Added\n");

}
