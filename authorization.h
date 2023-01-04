#ifndef AUTHORIZATION_H_INCLUDED
#define AUTHORIZATION_H_INCLUDED

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

int getch();
struct user signup(struct user user);
struct user login();

#endif 