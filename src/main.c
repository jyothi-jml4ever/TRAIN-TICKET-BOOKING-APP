#include "../include/irctc.h"

int main()
{
    int choice;

    load_trains();

    while (1)
    {
        menu1();
        scanf("%d", &choice);

        if (choice == 1)
            signup();
        else if (choice == 2)
        {
            if (signin())
            {
                char opt;
                do {
                    display_trains();
                    menu2();
                    scanf(" %c", &opt);

                    switch (opt)
                    {
                        case 'R': case 'r': reserve_ticket(); break;
                        case 'C': case 'c': cancel_ticket(); break;
                        case 'B': case 'b': booking_details(); break;
                        case 'A': case 'a': add_train(); break;
                    }
                } while (opt != 'Q' && opt != 'q');
            }
        }
        else
            exit(0);
    }
}