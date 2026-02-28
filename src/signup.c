#include "../include/irctc.h"

void signup()
{
    char user[MAX], pass[MAX];
    int tries = 0;

    printf("Enter Username: ");
    scanf("%s", user);

    if (check_user(user, NULL))
    {
        printf("Username already exists\n");
        return;
    }

    while (tries < 5)
    {
        printf("Enter Password: ");
        scanf("%s", pass);

        if (valid_password(pass))
        {
            save_user(user, pass);
            printf("Signup Successful\n");
            return;
        }
        printf("Invalid password format\n");
        tries++;
    }
    printf("TIME OUT. Signup again\n");
}