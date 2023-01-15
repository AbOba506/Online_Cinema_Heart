#ifndef AUTHORIZATION_H_INCLUDED
#define AUTHORIZATION_H_INCLUDED

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

struct user {
  char name[20];
  char login[20];
  char password[20];
  char bankaccount[17];
  int fav_value;
  int isadmin;
};

int getch();
struct user signup();
struct user login();
struct user profile(struct user user);
char *cut(char str[], int num);
void edit(FILE *users, struct user user, struct user user_prev);
#endif
