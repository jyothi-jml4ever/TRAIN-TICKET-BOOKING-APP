#ifndef IRCTC_H
#define IRCTC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>

#define MAX 50

typedef enum { MALE, FEMALE } gender_t;

/* USER */
typedef struct user {
    char username[MAX];
    char password[MAX];
    struct user *next;
} user_t;

/* TRAIN */
typedef struct train {
    int train_no;
    char train_name[MAX];
    char source[MAX];
    char destination[MAX];
    int total_seats;
    int available_seats;
    struct train *next;
} train_t;

/* PASSENGER */
typedef struct passenger {
    int train_no;
    char date[15];
    int seat_no;
    char name[MAX];
    int age;
    gender_t gender;
    struct passenger *next;
} passenger_t;

/* MENUS */
void menu1();
void menu2();

/* AUTH */
void signup();
int signin();
int valid_password(char *);

/* TRAIN */
void load_trains();
void display_trains();
void add_train();
int train_exists(int, train_t *);

/* BOOKING */
void reserve_ticket();
void cancel_ticket();
void booking_details();
int get_last_seat(int, char *);

/* DATE */
int valid_date(char *);

/* FILE OPS */
int check_user(char *, char *);
void save_user(char *, char *);
void update_seats(int, int);

#endif
