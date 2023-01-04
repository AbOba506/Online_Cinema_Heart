#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

int getch() {
  int ch;
  struct termios oldt, newt;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  return ch;
}
struct user {
  char name[20];
  char login[20];
  char password[20];
  char bankaccount[17];
  int fav_value;
  int isadmin;
};

//регистрация нового аккаунта
struct user signup(struct user user) {
  FILE *users;
  char string_tmp[20];
  char str[20];
  char rule1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char rule2[] = "abcdefghijklmnopqrstuvwxyz";
  char rule3[] = "0123456789";
  int checker = 0;
  int i = 0;
  strcpy(user.login, "unknown");
  strcpy(user.name, "unknown");
  strcpy(user.password, "unknown");
  strcpy(user.bankaccount, "0000 0000 0000 0000");
  user.isadmin = 0;

  printf("Придумайте никнейм : ");
  scanf("%s", user.name);

  printf("Придумайте логин: ");
  scanf("%s", string_tmp);

  //проверка логина на длину
  while (6 > strlen(string_tmp)) {
    printf(
        "Пожалуйста, введите логин не короче 6 и не длиннее 20 символов. \n");
    scanf("%s", string_tmp);
  }

  //проверка логина на занятость
  while (checker != 1) {
    checker = 0;
    i = 1;
    users = fopen("users.txt", "r");
    while (feof(users) == 0) {
      fscanf(users, "%s", &str);
      if (i % 6 == 1 && strcmp(str, string_tmp) == 0) {
        printf("Логин занят. Введите другой. \n");
        checker = 2;
      }
      i++;
    }
    fclose(users);
    if (checker == 2) {
      scanf("%s", &string_tmp);
    } else
      checker = 1;
  }
  strcpy(user.login, string_tmp);

  printf("Придумайте надежный пароль: ");
  scanf("%s", string_tmp);
  //проверка пароля на надежность
  checker = 0;
  while (checker != 1) {
    if (strlen(string_tmp) < 6 ||
        strcspn(&string_tmp, rule1) == strlen(string_tmp) ||
        strcspn(&string_tmp, rule2) == strlen(string_tmp) ||
        strcspn(&string_tmp, rule3) == strlen(string_tmp)) {
      printf("Ненадежный пароль! Пожалуйста, введите пароль не короче 6 "
             "символов и содержащий как минимум 1 цифру, 1 заглавную букву и 1 "
             "строчную букву. \n");
      scanf("%s", string_tmp);
    } else
      checker = 1;
  }
  strcpy(user.password, string_tmp);
  printf("Введите номер банковской карты : ");
  scanf("%s", &user.bankaccount);
  users = fopen("users.txt", "a");
  user.fav_value = 0;
  fprintf(users, "%s %s %s %s %d %d \n", user.login, user.password, user.name,
          user.bankaccount, user.fav_value, user.isadmin);
  fclose(users);
  printf("Регистрация прошла успешно! \n");
  return user;
}

//вход в существующий аккаунт
struct user login() {
  FILE *users;
  struct user user;
  char str[20];
  char tmp_login[20];
  char tmp_password[20];
  int i;
  int str_int;
  int checker;
  int s;

  while (checker != 1) {
    pageLogin();
    checker = 0;
    printf("Логин: ");
    scanf("%s", &tmp_login);
    printf("Пароль: ");
    scanf("%s", &tmp_password);

    i = 1;
    users = fopen("users.txt", "r");
    while (feof(users) == 0) {
      fscanf(users, "%s", &str);
      if (i % 6 == 1 && strcmp(str, tmp_login) == 0) {
        checker = 2;
        fscanf(users, "%s", &str);
        if (strcmp(str, tmp_password) == 0 && checker == 2)
          checker = 3;
      }
      i++;
    }
    fclose(users);

    if (checker == 3) {
      users = fopen("users.txt", "r");
      i = 1;
      while (feof(users) == 0) {
        fscanf(users, "%s", &str);
        if (i % 6 == 1 && strcmp(str, tmp_login) == 0) {
          strcpy(user.login, str);

          fscanf(users, "%s", &str);
          strcpy(user.password, str);
          fscanf(users, "%s", &str);
          strcpy(user.name, str);

          fscanf(users, "%s", &str);
          strcpy(user.bankaccount, str);

          fscanf(users, "%d", &str_int);
          user.fav_value = str_int;

          fscanf(users, "%d", &str_int);
          user.isadmin = str_int;
        }
        i++;
      }
      checker = 1;
      fclose(users);
    } else {
      printf("Логин или пароль неверны. \n");
      checker = 0;
    }
    printf("\033[0d\033[2J");
  }
  return user;
}

int main(void) {
  // 1 :: Login
  // 2 :: Signup
  // 1 :: Catalog
  // 2 :: Profile
  struct user user1;
  for (int i = 1; i < 4; i++) {
    if (i < 3)
      switch (pageAuth()) {
      case 1:
        user1 = login();
        break;
      case 2:
        pageSignup();
        signup(user1);
        break;
      }
    if (i > 2)
      switch (pageEnter(user1)) {
      case 1:
        printf("Добро пожаловать в каталог! ");
        break;
      case 2:
        pageProfile(user1);
        break;
      }
  }
  return 0;
}
