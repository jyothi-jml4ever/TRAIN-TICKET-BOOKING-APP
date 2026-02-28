#include "../include/irctc.h"

int signin()
{
    char user[MAX], pass[MAX];
    int tries = 3;

    while (tries--)
    {
        printf("Username: ");
        scanf("%s", user);
        printf("Password: ");
        scanf("%s", pass);

        if (check_user(user, pass))
        {
            printf("Login Successful\n");
            return 1;
        }
        printf("Invalid credentials\n");
    }
    printf("Max attempts reached. Wait 5 mins\n");
    sleep(300);
    return 0;
}