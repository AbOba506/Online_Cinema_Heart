#ifndef PAGES_H_INCLUDED
#define PAGES_H_INCLUDED

#include <stdio.h>

int kolvo(int n);
int pageAuth();
int pageEnter(struct user user);
void pageSignup();
void pageLogin();
struct user pageProfile(struct user user);

#endif  
