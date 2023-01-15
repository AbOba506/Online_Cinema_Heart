#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#define len 60
#define PUR printf("\033[1;35m");
#define WHT printf("\33[0m");
#define Back printf("\33[40m");
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
  char name[21];
  char login[21];
  char password[21];
  char bankaccount[17];
  int fav_value;
  int isadmin;
};

//регистрация нового аккаунта
struct user signup() {
  struct user user;
  FILE *users;
  char string_tmp[20];
  char str[20];
  char file_name[32];
  strcpy(file_name, "favourites/fav_");
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
    strcat(file_name, user.login);
  strcat(file_name, ".txt");
  users = fopen(file_name, "w");
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

//редактирование профиля в лк
struct user profile(struct user user) {
  FILE *users;
  struct user user_prev = user;
  char name_old[32]; //временные строки для работы
  strcpy(name_old, "favourites/fav_");
  strcat(name_old, user.login);
  strcat(name_old, ".txt");
  char string_tmp[20];
  char str[20];
  char rule1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char rule2[] = "abcdefghijklmnopqrstuvwxyz";
  char rule3[] = "0123456789";
  int i, checker;
  int p;
  int request = 3;
  printf("\033[0d\033[2J");
  int key = 1;
  do {
    switch (key) {
    case 87:
      if (request < 3)
        request = request + 1;
      break;
    case 119:
      if (request < 3)
        request = request + 1;
      break;
    case 83:
      if (request > 0)
        request = request - 1;
      break;
    case 115:
      if (request > 0)
        request = request - 1;
      break;
    default:
      break;
    }

    switch (request) {
    case (3):
      printf("\u250f");
      for (int i = 0; i <= len / 3; i++) {
        Back for (int j = 0; j <= len + 1; j++) {
          Back if (i == 0 && j <= len - 1) {
            printf("\u2501");
            if (j == len - 1) {
              printf("\u2513");
            }
          }
          else if (i >= 1 && i != len / 3 && ((j == 0) || (j == len + 1))) {
            printf("\u2503");
          }
          // название кинотеатра HEART
          else if (i == 1 && j == 27) {
            PUR printf("\u25b7");
          }
          else if (i == 1 && j == 28) {
            printf("H");
          }
          else if (i == 1 && j == 29) {
            printf("e");
          }
          else if (i == 1 && j == 30) {
            printf("a");
          }
          else if (i == 1 && j == 31) {
            printf("r");
          }
          else if (i == 1 && j == 32) {
            printf("t");
          }
          else if (i == 1 && j == 33) {
            printf("\u25c1");
            WHT
          }
          // (вход в существующий аккаунт)
          else if (i == 4 && j == 22) {
            printf("\u2989");
          }
          else if (i == 4 && j == 24) {
            printf("Л");
          }
          else if (i == 4 && j == 25) {
            printf("и");
          }
          else if (i == 4 && j == 26) {
            printf("ч");
          }
          else if (i == 4 && j == 27) {
            printf("н");
          }
          else if (i == 4 && j == 28) {
            printf("ы");
          }
          else if (i == 4 && j == 29) {
            printf("й");
          }
          else if (i == 4 && j == 30) {
            printf(" ");
          }
          else if (i == 4 && j == 31) {
            printf("к");
          }
          else if (i == 4 && j == 32) {
            printf("а");
          }
          else if (i == 4 && j == 33) {
            printf("б");
          }
          else if (i == 4 && j == 34) {
            printf("и");
          }
          else if (i == 4 && j == 35) {
            printf("н");
          }
          else if (i == 4 && j == 36) {
            printf("е");
          }
          else if (i == 4 && j == 37) {
            printf("т");
          }
          else if (i == 4 && j == 39) {
            printf("\u298a");
          }
          else if (i == 5 && j == 12) {
            printf("Д");
          }
          else if (i == 5 && j == 13) {
            printf("л");
          }
          else if (i == 5 && j == 14) {
            printf("я");
          }
          else if (i == 5 && j == 16) {
            printf("и");
          }
          else if (i == 5 && j == 17) {
            printf("з");
          }
          else if (i == 5 && j == 18) {
            printf("м");
          }
          else if (i == 5 && j == 19) {
            printf("е");
          }
          else if (i == 5 && j == 20) {
            printf("н");
          }
          else if (i == 5 && j == 21) {
            printf("е");
          }
          else if (i == 5 && j == 22) {
            printf("н");
          }
          else if (i == 5 && j == 23) {
            printf("и");
          }
          else if (i == 5 && j == 24) {
            printf("я");
          }
          else if (i == 5 && j == 26) {
            printf("д");
          }
          else if (i == 5 && j == 27) {
            printf("а");
          }
          else if (i == 5 && j == 28) {
            printf("н");
          }
          else if (i == 5 && j == 29) {
            printf("н");
          }
          else if (i == 5 && j == 30) {
            printf("ы");
          }
          else if (i == 5 && j == 31) {
            printf("х");
          }
          else if (i == 5 && j == 33) {
            printf("н");
          }
          else if (i == 5 && j == 34) {
            printf("а");
          }
          else if (i == 5 && j == 35) {
            printf("ж");
          }
          else if (i == 5 && j == 36) {
            printf("м");
          }
          else if (i == 5 && j == 37) {
            printf("и");
          }
          else if (i == 5 && j == 38) {
            printf("т");
          }
          else if (i == 5 && j == 39) {
            printf("е");
          }
          else if (i == 5 && j == 41) {
            printf("п");
          }
          else if (i == 5 && j == 42) {
            printf("р");
          }
          else if (i == 5 && j == 43) {
            printf("о");
          }
          else if (i == 5 && j == 44) {
            printf("б");
          }
          else if (i == 5 && j == 45) {
            printf("е");
          }
          else if (i == 5 && j == 46) {
            printf("л");
          }
          else if (i == 5 && j == 47) {
            printf(".");
          }
          //конец первой надписи (вход...)
          //начало рамочки с просьбой ввести свои данные
          else if (i == 7 && j == 13) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 7 && j > 13 && j < 47) {
            PUR printf("\u2594");
            WHT
          }
          else if (i == 7 && j == 47) {
            PUR printf("\u2551");
            WHT
          }
          else if (((i > 7 && i < 12) || (i > 12 && i < 15)) && j == 1) {
            printf("            ");
          }
          else if (i == 8 && j == 13) {
            PUR printf("\u27eb");
            WHT
          }
          else if (i == 8 && j == 15) {
            printf("Ник: %s", user.name);
            for (p = 1; p < 29 - strlen(user.name); p++)
              printf(" ");
          }
          else if (i == 8 && j == 43 - strlen(user.name)) {
            PUR printf("\u2551             ");
            WHT
          }
          else if (i == 9 && j == 13) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 9 && j == 15) {
            printf("Логин: %s", user.login);
            for (p = 1; p < 27 - strlen(user.login); p++)
              printf(" ");
          }
          else if (i == 9 && j == 41 - strlen(user.login)) {
            PUR printf("\u2551             ");
            WHT
          }
          else if (i == 10 && j == 13) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 10 && j == 15) {
            printf("Пароль: %s", user.password);
            for (p = 1; p < 26 - strlen(user.password); p++)
              printf(" ");
          }
          else if (i == 10 && j == 40 - strlen(user.password)) {
            PUR printf("\u2551             ");
            WHT
          }
          else if (i == 11 && j == 13) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 11 && j == 15) {
            printf("Номер карты: %s", user.bankaccount);
            for (p = 1; p < 21 - strlen(user.bankaccount); p++)
              printf(" ");
          }
          else if (i == 11 && j == 35 - strlen(user.bankaccount)) {
            PUR printf("\u2551             ");
            WHT
          }
          else if (i == 12 && j == 13) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 12 && j > 13 && j < 47) {
            PUR printf("\u2594");
            WHT
          }
          else if (i == 12 && j == 47) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 13 && j == 13) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 13 && j == 14) {
            printf("Кол-во избранного: %d", user.fav_value);
            for (p = 1; p < 16 - kolvo(user.fav_value); p++)
              printf(" ");
          }
          else if (i == 13 && j == 15) {
            PUR printf("\u2551             ");
            WHT
          }
          else if (i == 14 && j == 13) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 14 && j == 14) {
            printf("Статус администратора: %d", user.isadmin);
            for (p = 1; p < 10; p++)
              printf(" ");
          }
          else if (i == 14 && j == 15) {
            PUR printf("\u2551             ");
            WHT
          }
          else if (i == 15 && j > 13 && j < 47) {
            PUR printf("\u2594");
            WHT
          }
          // конец рамочки

          else if (i == len / 3 && j == 0) {
            printf("\u2517");
          }
          else if (i == len / 3 && (j > 0) && (j != len + 1)) {
            printf("\u2501");
          }
          else if (i == len / 3 && j == len + 1) {
            printf("\u251b");
          }
          else if ((i < 8 || i > 11) && (i < 13 || i > 14)) {
            printf(" ");
          }
        }
        printf("\n");
      }
      if (key == 32) {
        printf("Введите новый никнейм: ");
        scanf("%s", user.name);
      }
      break;
    case (2):
      printf("\u250f");
      for (int i = 0; i <= len / 3; i++) {
        Back for (int j = 0; j <= len + 1; j++) {
          Back if (i == 0 && j <= len - 1) {
            printf("\u2501");
            if (j == len - 1) {
              printf("\u2513");
            }
          }
          else if (i >= 1 && i != len / 3 && ((j == 0) || (j == len + 1))) {
            printf("\u2503");
          }
          // название кинотеатра HEART
          else if (i == 1 && j == 27) {
            PUR printf("\u25b7");
          }
          else if (i == 1 && j == 28) {
            printf("H");
          }
          else if (i == 1 && j == 29) {
            printf("e");
          }
          else if (i == 1 && j == 30) {
            printf("a");
          }
          else if (i == 1 && j == 31) {
            printf("r");
          }
          else if (i == 1 && j == 32) {
            printf("t");
          }
          else if (i == 1 && j == 33) {
            printf("\u25c1");
            WHT
          }
          // (вход в существующий аккаунт)
          else if (i == 4 && j == 22) {
            printf("\u2989");
          }
          else if (i == 4 && j == 24) {
            printf("Л");
          }
          else if (i == 4 && j == 25) {
            printf("и");
          }
          else if (i == 4 && j == 26) {
            printf("ч");
          }
          else if (i == 4 && j == 27) {
            printf("н");
          }
          else if (i == 4 && j == 28) {
            printf("ы");
          }
          else if (i == 4 && j == 29) {
            printf("й");
          }
          else if (i == 4 && j == 30) {
            printf(" ");
          }
          else if (i == 4 && j == 31) {
            printf("к");
          }
          else if (i == 4 && j == 32) {
            printf("а");
          }
          else if (i == 4 && j == 33) {
            printf("б");
          }
          else if (i == 4 && j == 34) {
            printf("и");
          }
          else if (i == 4 && j == 35) {
            printf("н");
          }
          else if (i == 4 && j == 36) {
            printf("е");
          }
          else if (i == 4 && j == 37) {
            printf("т");
          }
          else if (i == 4 && j == 39) {
            printf("\u298a");
          }
          else if (i == 5 && j == 12) {
            printf("Д");
          }
          else if (i == 5 && j == 13) {
            printf("л");
          }
          else if (i == 5 && j == 14) {
            printf("я");
          }
          else if (i == 5 && j == 16) {
            printf("и");
          }
          else if (i == 5 && j == 17) {
            printf("з");
          }
          else if (i == 5 && j == 18) {
            printf("м");
          }
          else if (i == 5 && j == 19) {
            printf("е");
          }
          else if (i == 5 && j == 20) {
            printf("н");
          }
          else if (i == 5 && j == 21) {
            printf("е");
          }
          else if (i == 5 && j == 22) {
            printf("н");
          }
          else if (i == 5 && j == 23) {
            printf("и");
          }
          else if (i == 5 && j == 24) {
            printf("я");
          }
          else if (i == 5 && j == 26) {
            printf("д");
          }
          else if (i == 5 && j == 27) {
            printf("а");
          }
          else if (i == 5 && j == 28) {
            printf("н");
          }
          else if (i == 5 && j == 29) {
            printf("н");
          }
          else if (i == 5 && j == 30) {
            printf("ы");
          }
          else if (i == 5 && j == 31) {
            printf("х");
          }
          else if (i == 5 && j == 33) {
            printf("н");
          }
          else if (i == 5 && j == 34) {
            printf("а");
          }
          else if (i == 5 && j == 35) {
            printf("ж");
          }
          else if (i == 5 && j == 36) {
            printf("м");
          }
          else if (i == 5 && j == 37) {
            printf("и");
          }
          else if (i == 5 && j == 38) {
            printf("т");
          }
          else if (i == 5 && j == 39) {
            printf("е");
          }
          else if (i == 5 && j == 41) {
            printf("п");
          }
          else if (i == 5 && j == 42) {
            printf("р");
          }
          else if (i == 5 && j == 43) {
            printf("о");
          }
          else if (i == 5 && j == 44) {
            printf("б");
          }
          else if (i == 5 && j == 45) {
            printf("е");
          }
          else if (i == 5 && j == 46) {
            printf("л");
          }
          else if (i == 5 && j == 47) {
            printf(".");
          }
          //конец первой надписи (вход...)
          //начало рамочки с просьбой ввести свои данные
          else if (i == 7 && j == 13) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 7 && j > 13 && j < 47) {
            PUR printf("\u2594");
            WHT
          }
          else if (i == 7 && j == 47) {
            PUR printf("\u2551");
            WHT
          }
          else if (((i > 7 && i < 12) || (i > 12 && i < 15)) && j == 1) {
            printf("            ");
          }
          else if (i == 8 && j == 13) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 8 && j == 15) {
            printf("Ник: %s", user.name);
            for (p = 1; p < 29 - strlen(user.name); p++)
              printf(" ");
          }
          else if (i == 8 && j == 43 - strlen(user.name)) {
            PUR printf("\u2551             ");
            WHT
          }
          else if (i == 9 && j == 13) {
            PUR printf("\u27eb");
            WHT
          }
          else if (i == 9 && j == 15) {
            printf("Логин: %s", user.login);
            for (p = 1; p < 27 - strlen(user.login); p++)
              printf(" ");
          }
          else if (i == 9 && j == 41 - strlen(user.login)) {
            PUR printf("\u2551             ");
            WHT
          }
          else if (i == 10 && j == 13) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 10 && j == 15) {
            printf("Пароль: %s", user.password);
            for (p = 1; p < 26 - strlen(user.password); p++)
              printf(" ");
          }
          else if (i == 10 && j == 40 - strlen(user.password)) {
            PUR printf("\u2551             ");
            WHT
          }
          else if (i == 11 && j == 13) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 11 && j == 15) {
            printf("Номер карты: %s", user.bankaccount);
            for (p = 1; p < 21 - strlen(user.bankaccount); p++)
              printf(" ");
          }
          else if (i == 11 && j == 35 - strlen(user.bankaccount)) {
            PUR printf("\u2551             ");
            WHT
          }
          else if (i == 12 && j == 13) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 12 && j > 13 && j < 47) {
            PUR printf("\u2594");
            WHT
          }
          else if (i == 12 && j == 47) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 13 && j == 13) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 13 && j == 14) {
            printf("Кол-во избранного: %d", user.fav_value);
            for (p = 1; p < 16 - kolvo(user.fav_value); p++)
              printf(" ");
          }
          else if (i == 13 && j == 15) {
            PUR printf("\u2551             ");
            WHT
          }
          else if (i == 14 && j == 13) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 14 && j == 14) {
            printf("Статус администратора: %d", user.isadmin);
            for (p = 1; p < 10; p++)
              printf(" ");
          }
          else if (i == 14 && j == 15) {
            PUR printf("\u2551             ");
            WHT
          }
          else if (i == 15 && j > 13 && j < 47) {
            PUR printf("\u2594");
            WHT
          }
          // конец рамочки

          else if (i == len / 3 && j == 0) {
            printf("\u2517");
          }
          else if (i == len / 3 && (j > 0) && (j != len + 1)) {
            printf("\u2501");
          }
          else if (i == len / 3 && j == len + 1) {
            printf("\u251b");
          }
          else if ((i < 8 || i > 11) && (i < 13 || i > 14)) {
            printf(" ");
          }
        }
        printf("\n");
      }
      if (key == 32) {
        printf("Новый логин: ");
        scanf("%s", string_tmp);

        //проверка логина на длину
        while (6 > strlen(string_tmp) || 20 < strlen(string_tmp)) {
          printf("Пожалуйста, введите логин не короче 6 и не длиннее 20 "
                 "символов. \n");
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
      }
      break;
    case (1):
      printf("\u250f");
      for (int i = 0; i <= len / 3; i++) {
        Back for (int j = 0; j <= len + 1; j++) {
          Back if (i == 0 && j <= len - 1) {
            printf("\u2501");
            if (j == len - 1) {
              printf("\u2513");
            }
          }
          else if (i >= 1 && i != len / 3 && ((j == 0) || (j == len + 1))) {
            printf("\u2503");
          }
          // название кинотеатра HEART
          else if (i == 1 && j == 27) {
            PUR printf("\u25b7");
          }
          else if (i == 1 && j == 28) {
            printf("H");
          }
          else if (i == 1 && j == 29) {
            printf("e");
          }
          else if (i == 1 && j == 30) {
            printf("a");
          }
          else if (i == 1 && j == 31) {
            printf("r");
          }
          else if (i == 1 && j == 32) {
            printf("t");
          }
          else if (i == 1 && j == 33) {
            printf("\u25c1");
            WHT
          }
          // (вход в существующий аккаунт)
          else if (i == 4 && j == 22) {
            printf("\u2989");
          }
          else if (i == 4 && j == 24) {
            printf("Л");
          }
          else if (i == 4 && j == 25) {
            printf("и");
          }
          else if (i == 4 && j == 26) {
            printf("ч");
          }
          else if (i == 4 && j == 27) {
            printf("н");
          }
          else if (i == 4 && j == 28) {
            printf("ы");
          }
          else if (i == 4 && j == 29) {
            printf("й");
          }
          else if (i == 4 && j == 30) {
            printf(" ");
          }
          else if (i == 4 && j == 31) {
            printf("к");
          }
          else if (i == 4 && j == 32) {
            printf("а");
          }
          else if (i == 4 && j == 33) {
            printf("б");
          }
          else if (i == 4 && j == 34) {
            printf("и");
          }
          else if (i == 4 && j == 35) {
            printf("н");
          }
          else if (i == 4 && j == 36) {
            printf("е");
          }
          else if (i == 4 && j == 37) {
            printf("т");
          }
          else if (i == 4 && j == 39) {
            printf("\u298a");
          }
          else if (i == 5 && j == 12) {
            printf("Д");
          }
          else if (i == 5 && j == 13) {
            printf("л");
          }
          else if (i == 5 && j == 14) {
            printf("я");
          }
          else if (i == 5 && j == 16) {
            printf("и");
          }
          else if (i == 5 && j == 17) {
            printf("з");
          }
          else if (i == 5 && j == 18) {
            printf("м");
          }
          else if (i == 5 && j == 19) {
            printf("е");
          }
          else if (i == 5 && j == 20) {
            printf("н");
          }
          else if (i == 5 && j == 21) {
            printf("е");
          }
          else if (i == 5 && j == 22) {
            printf("н");
          }
          else if (i == 5 && j == 23) {
            printf("и");
          }
          else if (i == 5 && j == 24) {
            printf("я");
          }
          else if (i == 5 && j == 26) {
            printf("д");
          }
          else if (i == 5 && j == 27) {
            printf("а");
          }
          else if (i == 5 && j == 28) {
            printf("н");
          }
          else if (i == 5 && j == 29) {
            printf("н");
          }
          else if (i == 5 && j == 30) {
            printf("ы");
          }
          else if (i == 5 && j == 31) {
            printf("х");
          }
          else if (i == 5 && j == 33) {
            printf("н");
          }
          else if (i == 5 && j == 34) {
            printf("а");
          }
          else if (i == 5 && j == 35) {
            printf("ж");
          }
          else if (i == 5 && j == 36) {
            printf("м");
          }
          else if (i == 5 && j == 37) {
            printf("и");
          }
          else if (i == 5 && j == 38) {
            printf("т");
          }
          else if (i == 5 && j == 39) {
            printf("е");
          }
          else if (i == 5 && j == 41) {
            printf("п");
          }
          else if (i == 5 && j == 42) {
            printf("р");
          }
          else if (i == 5 && j == 43) {
            printf("о");
          }
          else if (i == 5 && j == 44) {
            printf("б");
          }
          else if (i == 5 && j == 45) {
            printf("е");
          }
          else if (i == 5 && j == 46) {
            printf("л");
          }
          else if (i == 5 && j == 47) {
            printf(".");
          }
          //конец первой надписи (вход...)
          //начало рамочки с просьбой ввести свои данные
          else if (i == 7 && j == 13) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 7 && j > 13 && j < 47) {
            PUR printf("\u2594");
            WHT
          }
          else if (i == 7 && j == 47) {
            PUR printf("\u2551");
            WHT
          }
          else if (((i > 7 && i < 12) || (i > 12 && i < 15)) && j == 1) {
            printf("            ");
          }
          else if (i == 8 && j == 13) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 8 && j == 15) {
            printf("Ник: %s", user.name);
            for (p = 1; p < 29 - strlen(user.name); p++)
              printf(" ");
          }
          else if (i == 8 && j == 43 - strlen(user.name)) {
            PUR printf("\u2551             ");
            WHT
          }
          else if (i == 9 && j == 13) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 9 && j == 15) {
            printf("Логин: %s", user.login);
            for (p = 1; p < 27 - strlen(user.login); p++)
              printf(" ");
          }
          else if (i == 9 && j == 41 - strlen(user.login)) {
            PUR printf("\u2551             ");
            WHT
          }
          else if (i == 10 && j == 13) {
            PUR printf("\u27eb");
            WHT
          }
          else if (i == 10 && j == 15) {
            printf("Пароль: %s", user.password);
            for (p = 1; p < 26 - strlen(user.password); p++)
              printf(" ");
          }
          else if (i == 10 && j == 40 - strlen(user.password)) {
            PUR printf("\u2551             ");
            WHT
          }
          else if (i == 11 && j == 13) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 11 && j == 15) {
            printf("Номер карты: %s", user.bankaccount);
            for (p = 1; p < 21 - strlen(user.bankaccount); p++)
              printf(" ");
          }
          else if (i == 11 && j == 35 - strlen(user.bankaccount)) {
            PUR printf("\u2551             ");
            WHT
          }
          else if (i == 12 && j == 13) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 12 && j > 13 && j < 47) {
            PUR printf("\u2594");
            WHT
          }
          else if (i == 12 && j == 47) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 13 && j == 13) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 13 && j == 14) {
            printf("Кол-во избранного: %d", user.fav_value);
            for (p = 1; p < 16 - kolvo(user.fav_value); p++)
              printf(" ");
          }
          else if (i == 13 && j == 15) {
            PUR printf("\u2551             ");
            WHT
          }
          else if (i == 14 && j == 13) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 14 && j == 14) {
            printf("Статус администратора: %d", user.isadmin);
            for (p = 1; p < 10; p++)
              printf(" ");
          }
          else if (i == 14 && j == 15) {
            PUR printf("\u2551             ");
            WHT
          }
          else if (i == 15 && j > 13 && j < 47) {
            PUR printf("\u2594");
            WHT
          }
          // конец рамочки

          else if (i == len / 3 && j == 0) {
            printf("\u2517");
          }
          else if (i == len / 3 && (j > 0) && (j != len + 1)) {
            printf("\u2501");
          }
          else if (i == len / 3 && j == len + 1) {
            printf("\u251b");
          }
          else if ((i < 8 || i > 11) && (i < 13 || i > 14)) {
            printf(" ");
          }
        }
        printf("\n");
      }
      if (key == 32) {
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
                   "символов и содержащий как минимум 1 цифру, 1 заглавную "
                   "букву и 1 "
                   "строчную букву. \n");
            scanf("%s", string_tmp);
          } else
            checker = 1;
        }
        strcpy(user.password, string_tmp);
      }
      break;
    case (0):
      printf("\u250f");
      for (int i = 0; i <= len / 3; i++) {
        Back for (int j = 0; j <= len + 1; j++) {
          Back if (i == 0 && j <= len - 1) {
            printf("\u2501");
            if (j == len - 1) {
              printf("\u2513");
            }
          }
          else if (i >= 1 && i != len / 3 && ((j == 0) || (j == len + 1))) {
            printf("\u2503");
          }
          // название кинотеатра HEART
          else if (i == 1 && j == 27) {
            PUR printf("\u25b7");
          }
          else if (i == 1 && j == 28) {
            printf("H");
          }
          else if (i == 1 && j == 29) {
            printf("e");
          }
          else if (i == 1 && j == 30) {
            printf("a");
          }
          else if (i == 1 && j == 31) {
            printf("r");
          }
          else if (i == 1 && j == 32) {
            printf("t");
          }
          else if (i == 1 && j == 33) {
            printf("\u25c1");
            WHT
          }
          // (вход в существующий аккаунт)
          else if (i == 4 && j == 22) {
            printf("\u2989");
          }
          else if (i == 4 && j == 24) {
            printf("Л");
          }
          else if (i == 4 && j == 25) {
            printf("и");
          }
          else if (i == 4 && j == 26) {
            printf("ч");
          }
          else if (i == 4 && j == 27) {
            printf("н");
          }
          else if (i == 4 && j == 28) {
            printf("ы");
          }
          else if (i == 4 && j == 29) {
            printf("й");
          }
          else if (i == 4 && j == 30) {
            printf(" ");
          }
          else if (i == 4 && j == 31) {
            printf("к");
          }
          else if (i == 4 && j == 32) {
            printf("а");
          }
          else if (i == 4 && j == 33) {
            printf("б");
          }
          else if (i == 4 && j == 34) {
            printf("и");
          }
          else if (i == 4 && j == 35) {
            printf("н");
          }
          else if (i == 4 && j == 36) {
            printf("е");
          }
          else if (i == 4 && j == 37) {
            printf("т");
          }
          else if (i == 4 && j == 39) {
            printf("\u298a");
          }
          else if (i == 5 && j == 12) {
            printf("Д");
          }
          else if (i == 5 && j == 13) {
            printf("л");
          }
          else if (i == 5 && j == 14) {
            printf("я");
          }
          else if (i == 5 && j == 16) {
            printf("и");
          }
          else if (i == 5 && j == 17) {
            printf("з");
          }
          else if (i == 5 && j == 18) {
            printf("м");
          }
          else if (i == 5 && j == 19) {
            printf("е");
          }
          else if (i == 5 && j == 20) {
            printf("н");
          }
          else if (i == 5 && j == 21) {
            printf("е");
          }
          else if (i == 5 && j == 22) {
            printf("н");
          }
          else if (i == 5 && j == 23) {
            printf("и");
          }
          else if (i == 5 && j == 24) {
            printf("я");
          }
          else if (i == 5 && j == 26) {
            printf("д");
          }
          else if (i == 5 && j == 27) {
            printf("а");
          }
          else if (i == 5 && j == 28) {
            printf("н");
          }
          else if (i == 5 && j == 29) {
            printf("н");
          }
          else if (i == 5 && j == 30) {
            printf("ы");
          }
          else if (i == 5 && j == 31) {
            printf("х");
          }
          else if (i == 5 && j == 33) {
            printf("н");
          }
          else if (i == 5 && j == 34) {
            printf("а");
          }
          else if (i == 5 && j == 35) {
            printf("ж");
          }
          else if (i == 5 && j == 36) {
            printf("м");
          }
          else if (i == 5 && j == 37) {
            printf("и");
          }
          else if (i == 5 && j == 38) {
            printf("т");
          }
          else if (i == 5 && j == 39) {
            printf("е");
          }
          else if (i == 5 && j == 41) {
            printf("п");
          }
          else if (i == 5 && j == 42) {
            printf("р");
          }
          else if (i == 5 && j == 43) {
            printf("о");
          }
          else if (i == 5 && j == 44) {
            printf("б");
          }
          else if (i == 5 && j == 45) {
            printf("е");
          }
          else if (i == 5 && j == 46) {
            printf("л");
          }
          else if (i == 5 && j == 47) {
            printf(".");
          }
          //конец первой надписи (вход...)
          //начало рамочки с просьбой ввести свои данные
          else if (i == 7 && j == 13) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 7 && j > 13 && j < 47) {
            PUR printf("\u2594");
            WHT
          }
          else if (i == 7 && j == 47) {
            PUR printf("\u2551");
            WHT
          }
          else if (((i > 7 && i < 12) || (i > 12 && i < 15)) && j == 1) {
            printf("            ");
          }
          else if (i == 8 && j == 13) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 8 && j == 15) {
            printf("Ник: %s", user.name);
            for (p = 1; p < 29 - strlen(user.name); p++)
              printf(" ");
          }
          else if (i == 8 && j == 43 - strlen(user.name)) {
            PUR printf("\u2551             ");
            WHT
          }
          else if (i == 9 && j == 13) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 9 && j == 15) {
            printf("Логин: %s", user.login);
            for (p = 1; p < 27 - strlen(user.login); p++)
              printf(" ");
          }
          else if (i == 9 && j == 41 - strlen(user.login)) {
            PUR printf("\u2551             ");
            WHT
          }
          else if (i == 10 && j == 13) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 10 && j == 15) {
            printf("Пароль: %s", user.password);
            for (p = 1; p < 26 - strlen(user.password); p++)
              printf(" ");
          }
          else if (i == 10 && j == 40 - strlen(user.password)) {
            PUR printf("\u2551             ");
            WHT
          }
          else if (i == 11 && j == 13) {
            PUR printf("\u27eb");
            WHT
          }
          else if (i == 11 && j == 15) {
            printf("Номер карты: %s", user.bankaccount);
            for (p = 1; p < 21 - strlen(user.bankaccount); p++)
              printf(" ");
          }
          else if (i == 11 && j == 35 - strlen(user.bankaccount)) {
            PUR printf("\u2551             ");
            WHT
          }
          else if (i == 12 && j == 13) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 12 && j > 13 && j < 47) {
            PUR printf("\u2594");
            WHT
          }
          else if (i == 12 && j == 47) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 13 && j == 13) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 13 && j == 14) {
            printf("Кол-во избранного: %d", user.fav_value);
            for (p = 1; p < 16 - kolvo(user.fav_value); p++)
              printf(" ");
          }
          else if (i == 13 && j == 15) {
            PUR printf("\u2551             ");
            WHT
          }
          else if (i == 14 && j == 13) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 14 && j == 14) {
            printf("Статус администратора: %d", user.isadmin);
            for (p = 1; p < 10; p++)
              printf(" ");
          }
          else if (i == 14 && j == 15) {
            PUR printf("\u2551             ");
            WHT
          }
          else if (i == 15 && j > 13 && j < 47) {
            PUR printf("\u2594");
            WHT
          }
          // конец рамочки

          else if (i == len / 3 && j == 0) {
            printf("\u2517");
          }
          else if (i == len / 3 && (j > 0) && (j != len + 1)) {
            printf("\u2501");
          }
          else if (i == len / 3 && j == len + 1) {
            printf("\u251b");
          }
          else if ((i < 8 || i > 11) && (i < 13 || i > 14)) {
            printf(" ");
          }
        }
        printf("\n");
      }
      if (key == 32) {
        printf("Введите новый номер карты: ");
        scanf("%s", user.bankaccount);
      }
      break;
    default:
      printf("\u250f");
      for (int i = 0; i <= len / 3; i++) {
        Back for (int j = 0; j <= len + 1; j++) {
          Back if (i == 0 && j <= len - 1) {
            printf("\u2501");
            if (j == len - 1) {
              printf("\u2513");
            }
          }
          else if (i >= 1 && i != len / 3 && ((j == 0) || (j == len + 1))) {
            printf("\u2503");
          }
          // название кинотеатра HEART
          else if (i == 1 && j == 27) {
            PUR printf("\u25b7");
          }
          else if (i == 1 && j == 28) {
            printf("H");
          }
          else if (i == 1 && j == 29) {
            printf("e");
          }
          else if (i == 1 && j == 30) {
            printf("a");
          }
          else if (i == 1 && j == 31) {
            printf("r");
          }
          else if (i == 1 && j == 32) {
            printf("t");
          }
          else if (i == 1 && j == 33) {
            printf("\u25c1");
            WHT
          }
          // (вход в существующий аккаунт)
          else if (i == 4 && j == 22) {
            printf("\u2989");
          }
          else if (i == 4 && j == 24) {
            printf("Л");
          }
          else if (i == 4 && j == 25) {
            printf("и");
          }
          else if (i == 4 && j == 26) {
            printf("ч");
          }
          else if (i == 4 && j == 27) {
            printf("н");
          }
          else if (i == 4 && j == 28) {
            printf("ы");
          }
          else if (i == 4 && j == 29) {
            printf("й");
          }
          else if (i == 4 && j == 30) {
            printf(" ");
          }
          else if (i == 4 && j == 31) {
            printf("к");
          }
          else if (i == 4 && j == 32) {
            printf("а");
          }
          else if (i == 4 && j == 33) {
            printf("б");
          }
          else if (i == 4 && j == 34) {
            printf("и");
          }
          else if (i == 4 && j == 35) {
            printf("н");
          }
          else if (i == 4 && j == 36) {
            printf("е");
          }
          else if (i == 4 && j == 37) {
            printf("т");
          }
          else if (i == 4 && j == 39) {
            printf("\u298a");
          }
          else if (i == 5 && j == 12) {
            printf("Д");
          }
          else if (i == 5 && j == 13) {
            printf("л");
          }
          else if (i == 5 && j == 14) {
            printf("я");
          }
          else if (i == 5 && j == 16) {
            printf("и");
          }
          else if (i == 5 && j == 17) {
            printf("з");
          }
          else if (i == 5 && j == 18) {
            printf("м");
          }
          else if (i == 5 && j == 19) {
            printf("е");
          }
          else if (i == 5 && j == 20) {
            printf("н");
          }
          else if (i == 5 && j == 21) {
            printf("е");
          }
          else if (i == 5 && j == 22) {
            printf("н");
          }
          else if (i == 5 && j == 23) {
            printf("и");
          }
          else if (i == 5 && j == 24) {
            printf("я");
          }
          else if (i == 5 && j == 26) {
            printf("д");
          }
          else if (i == 5 && j == 27) {
            printf("а");
          }
          else if (i == 5 && j == 28) {
            printf("н");
          }
          else if (i == 5 && j == 29) {
            printf("н");
          }
          else if (i == 5 && j == 30) {
            printf("ы");
          }
          else if (i == 5 && j == 31) {
            printf("х");
          }
          else if (i == 5 && j == 33) {
            printf("н");
          }
          else if (i == 5 && j == 34) {
            printf("а");
          }
          else if (i == 5 && j == 35) {
            printf("ж");
          }
          else if (i == 5 && j == 36) {
            printf("м");
          }
          else if (i == 5 && j == 37) {
            printf("и");
          }
          else if (i == 5 && j == 38) {
            printf("т");
          }
          else if (i == 5 && j == 39) {
            printf("е");
          }
          else if (i == 5 && j == 41) {
            printf("п");
          }
          else if (i == 5 && j == 42) {
            printf("р");
          }
          else if (i == 5 && j == 43) {
            printf("о");
          }
          else if (i == 5 && j == 44) {
            printf("б");
          }
          else if (i == 5 && j == 45) {
            printf("е");
          }
          else if (i == 5 && j == 46) {
            printf("л");
          }
          else if (i == 5 && j == 47) {
            printf(".");
          }
          //конец первой надписи (вход...)
          //начало рамочки с просьбой ввести свои данные
          else if (i == 7 && j == 13) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 7 && j > 13 && j < 47) {
            PUR printf("\u2594");
            WHT
          }
          else if (i == 7 && j == 47) {
            PUR printf("\u2551");
            WHT
          }
          else if (((i > 7 && i < 12) || (i > 12 && i < 15)) && j == 1) {
            printf("            ");
          }
          else if (i == 8 && j == 13) {
            PUR printf("\u27eb");
            WHT
          }
          else if (i == 8 && j == 15) {
            printf("Ник: %s", user.name);
            for (p = 1; p < 29 - strlen(user.name); p++)
              printf(" ");
          }
          else if (i == 8 && j == 43 - strlen(user.name)) {
            PUR printf("\u2551             ");
            WHT
          }
          else if (i == 9 && j == 13) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 9 && j == 15) {
            printf("Логин: %s", user.login);
            for (p = 1; p < 27 - strlen(user.login); p++)
              printf(" ");
          }
          else if (i == 9 && j == 41 - strlen(user.login)) {
            PUR printf("\u2551             ");
            WHT
          }
          else if (i == 10 && j == 13) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 10 && j == 15) {
            printf("Пароль: %s", user.password);
            for (p = 1; p < 26 - strlen(user.password); p++)
              printf(" ");
          }
          else if (i == 10 && j == 40 - strlen(user.password)) {
            PUR printf("\u2551             ");
            WHT
          }
          else if (i == 11 && j == 13) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 11 && j == 15) {
            printf("Номер карты: %s", user.bankaccount);
            for (p = 1; p < 21 - strlen(user.bankaccount); p++)
              printf(" ");
          }
          else if (i == 11 && j == 35 - strlen(user.bankaccount)) {
            PUR printf("\u2551             ");
            WHT
          }
          else if (i == 12 && j == 13) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 12 && j > 13 && j < 47) {
            PUR printf("\u2594");
            WHT
          }
          else if (i == 12 && j == 47) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 13 && j == 13) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 13 && j == 14) {
            printf("Кол-во избранного: %d", user.fav_value);
            for (p = 1; p < 16 - kolvo(user.fav_value); p++)
              printf(" ");
          }
          else if (i == 13 && j == 15) {
            PUR printf("\u2551             ");
            WHT
          }
          else if (i == 14 && j == 13) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 14 && j == 14) {
            printf("Статус администратора: %d", user.isadmin);
            for (p = 1; p < 10; p++)
              printf(" ");
          }
          else if (i == 14 && j == 15) {
            PUR printf("\u2551             ");
            WHT
          }
          else if (i == 15 && j > 13 && j < 47) {
            PUR printf("\u2594");
            WHT
          }
          // конец рамочки

          else if (i == len / 3 && j == 0) {
            printf("\u2517");
          }
          else if (i == len / 3 && (j > 0) && (j != len + 1)) {
            printf("\u2501");
          }
          else if (i == len / 3 && j == len + 1) {
            printf("\u251b");
          }
          else if ((i < 8 || i > 11) && (i < 13 || i > 14)) {
            printf(" ");
          }
        }
        printf("\n");
      }
      break;
    }
    key = getch();
    printf("\033[0d\033[2J");
  } while (key != 27);
  
  char name_new[30];
  strcpy(name_new, "favourites/fav_");
  strcat(name_new, user.login);
  strcat(name_new, ".txt");
  rename(name_old, name_new);
  key = 0;
  return user;
}

//вырезать определенное слово из строки (нужно для редактирования)
char *cut(char str[], int num) {
  char s[100000];
  strcpy(s, str);
  char *word;
  char *p;
  int k = 0;
  for (p = strtok(s, " "); p; p = strtok(NULL, " ")) {
    k++;
    if (k == num)
      return p;
    word = p;
  }
  if (k < num)
    return word;
}

//перезапись данных аккаунта в файле
void edit(FILE *users, struct user user, struct user user_prev) {
  users = fopen("users.txt", "r");
  char str_tmp[21];
  int i = 0, j = 0;
  while (feof(users) == 0) {
    fscanf(users, "%s", &str_tmp);
    i++;
  }
  fclose(users);
  char users_info[i * 22];
  users = fopen("users.txt", "r");
  for (j = 0; j < i - 1; j++) {
    fscanf(users, "%s", &str_tmp);
    strcat(users_info, str_tmp);
    strcat(users_info, " ");
  }
  fclose(users);

  users = fopen("users.txt", "w");
  j = 1;
  while (j < i) {
    strcpy(str_tmp, cut(users_info, j));
    if (strcmp(user_prev.login, str_tmp) == 0) {
      fprintf(users, "%s ", user.login);
      fprintf(users, "%s ", user.password);
      fprintf(users, "%s ", user.name);
      fprintf(users, "%s ", user.bankaccount);
      j = j + 4;
    } else if (j % 6 == 0) {
      fprintf(users, "%s \n", str_tmp);
      j++;
    } else {
      fprintf(users, "%s ", str_tmp);
      j++;
    }
  }
  fclose(users);
}
