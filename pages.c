#include <stdio.h>
#define len 60
#define PUR printf("\033[1;35m");
#define WHT printf("\33[0m");
#define Back printf("\33[40m");
struct user {
  char name[20];
  char login[20];
  char password[20];
  char bankaccount[17];
  int fav_value;
  int isadmin;
};
int kolvo(int n) {
  int kol = 1;
  if (n == 0)
    return 2;
  else if (n > 0)
    while (n > 0) {
      n = n / 10;
      kol += 1;
    }
  return kol;
}
//\u250f - левый верхний угол
//\u2513 - правый верхний угол
//\u2517 - левый нижний угол
//\u251b - правый нижний угол
//\u2501 - горизонтальная прямая
//\u2503 - вертикальная прямая
int pageAuth() {
  int request;
  printf("\033[0d\033[2J");
  int key = 1;
  do {
    switch (key) {

    case 87:
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
          // конец названия кинотеатра
          // начало (вход)
          else if ((i == 7 || i == 8 || i == 9) && (j == 20)) {
            PUR printf("\u27ea");
            WHT
          }
          else if ((i == 7 || i == 8 || i == 9) && (j == 40)) {
            PUR printf("\u27eb");
            WHT
          }
          else if (i == 7 && j > 20 && j < 40) {
            PUR printf("\u2594");
            WHT
          }
          else if (i == 8 && j == 28) {
            printf("В");
          }
          else if (i == 8 && j == 29) {
            printf("х");
          }
          else if (i == 8 && j == 30) {
            printf("о");
          }
          else if (i == 8 && j == 31) {
            printf("д");
          }
          else if (i == 10 && j < 40 && j > 20) {
            PUR printf("\u2594");
            WHT
          }
          // конец (вход)
          // начало (регистр)
          else if ((i == 10 || i == 11 || i == 12) && (j == 20 || j == 40)) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 11 && j == 25) {
            printf("Р");
          }
          else if (i == 11 && j == 26) {
            printf("е");
          }
          else if (i == 11 && j == 27) {
            printf("г");
          }
          else if (i == 11 && j == 28) {
            printf("и");
          }
          else if (i == 11 && j == 29) {
            printf("с");
          }
          else if (i == 11 && j == 30) {
            printf("т");
          }
          else if (i == 11 && j == 31) {
            printf("р");
          }
          else if (i == 11 && j == 32) {
            printf("а");
          }
          else if (i == 11 && j == 33) {
            printf("ц");
          }
          else if (i == 11 && j == 34) {
            printf("и");
          }
          else if (i == 11 && j == 35) {
            printf("я");
          }
          else if (i == 13 && j < 40 && j > 20) {
            PUR printf("\u2594");
            WHT
          }
          else if (i == len / 3 && j == 0) {
            printf("\u2517");
          }
          else if (i == len / 3 && (j > 0) && (j != len + 1)) {
            printf("\u2501");
          }
          else if (i == len / 3 && j == len + 1) {
            printf("\u251b");
          }
          else {
            printf(" ");
          }
        }
        printf("\n");
      }
      request = 1;
      break;
    case 119:
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
          // конец названия кинотеатра
          // начало (вход)
          else if ((i == 7 || i == 8 || i == 9) && (j == 20)) {
            PUR printf("\u27ea");
            WHT
          }
          else if ((i == 7 || i == 8 || i == 9) && (j == 40)) {
            PUR printf("\u27eb");
            WHT
          }
          else if (i == 7 && j > 20 && j < 40) {
            PUR printf("\u2594");
            WHT
          }
          else if (i == 8 && j == 28) {
            printf("В");
          }
          else if (i == 8 && j == 29) {
            printf("х");
          }
          else if (i == 8 && j == 30) {
            printf("о");
          }
          else if (i == 8 && j == 31) {
            printf("д");
          }
          else if (i == 10 && j < 40 && j > 20) {
            PUR printf("\u2594");
            WHT
          }
          // конец (вход)
          // начало (регистр)
          else if ((i == 10 || i == 11 || i == 12) && (j == 20 || j == 40)) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 11 && j == 25) {
            printf("Р");
          }
          else if (i == 11 && j == 26) {
            printf("е");
          }
          else if (i == 11 && j == 27) {
            printf("г");
          }
          else if (i == 11 && j == 28) {
            printf("и");
          }
          else if (i == 11 && j == 29) {
            printf("с");
          }
          else if (i == 11 && j == 30) {
            printf("т");
          }
          else if (i == 11 && j == 31) {
            printf("р");
          }
          else if (i == 11 && j == 32) {
            printf("а");
          }
          else if (i == 11 && j == 33) {
            printf("ц");
          }
          else if (i == 11 && j == 34) {
            printf("и");
          }
          else if (i == 11 && j == 35) {
            printf("я");
          }
          else if (i == 13 && j < 40 && j > 20) {
            PUR printf("\u2594");
            WHT
          }
          else if (i == len / 3 && j == 0) {
            printf("\u2517");
          }
          else if (i == len / 3 && (j > 0) && (j != len + 1)) {
            printf("\u2501");
          }
          else if (i == len / 3 && j == len + 1) {
            printf("\u251b");
          }
          else {
            printf(" ");
          }
        }
        printf("\n");
      }
      request = 1;
      break;

    case 83:
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
          // конец названия кинотеатра
          // начало (вход)
          else if ((i == 7 || i == 8 || i == 9) && (j == 20)) {
            PUR printf("\u2551");
            WHT
          }
          else if ((i == 7 || i == 8 || i == 9) && (j == 40)) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 7 && j > 20 && j < 40) {
            PUR printf("\u2594");
            WHT
          }
          else if (i == 8 && j == 28) {
            printf("В");
          }
          else if (i == 8 && j == 29) {
            printf("х");
          }
          else if (i == 8 && j == 30) {
            printf("о");
          }
          else if (i == 8 && j == 31) {
            printf("д");
          }
          else if (i == 10 && j < 40 && j > 20) {
            PUR printf("\u2594");
            WHT
          }
          // конец (вход)
          // начало (регистр)
          else if ((i == 10 || i == 11 || i == 12) && (j == 20)) {
            PUR printf("\u27ea");
            WHT
          }
          else if ((i == 10 || i == 11 || i == 12) && j == 40) {
            PUR printf("\u27eb");
            WHT
          }
          else if (i == 11 && j == 25) {
            printf("Р");
          }
          else if (i == 11 && j == 26) {
            printf("е");
          }
          else if (i == 11 && j == 27) {
            printf("г");
          }
          else if (i == 11 && j == 28) {
            printf("и");
          }
          else if (i == 11 && j == 29) {
            printf("с");
          }
          else if (i == 11 && j == 30) {
            printf("т");
          }
          else if (i == 11 && j == 31) {
            printf("р");
          }
          else if (i == 11 && j == 32) {
            printf("а");
          }
          else if (i == 11 && j == 33) {
            printf("ц");
          }
          else if (i == 11 && j == 34) {
            printf("и");
          }
          else if (i == 11 && j == 35) {
            printf("я");
          }
          else if (i == 13 && j < 40 && j > 20) {
            PUR printf("\u2594");
            WHT
          }
          else if (i == len / 3 && j == 0) {
            printf("\u2517");
          }
          else if (i == len / 3 && (j > 0) && (j != len + 1)) {
            printf("\u2501");
          }
          else if (i == len / 3 && j == len + 1) {
            printf("\u251b");
          }
          else {
            printf(" ");
          }
        }
        printf("\n");
      }
      request = 2;
      break;
    case 115:
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
          // конец названия кинотеатра
          // начало (вход)
          else if ((i == 7 || i == 8 || i == 9) && (j == 20)) {
            PUR printf("\u2551");
            WHT
          }
          else if ((i == 7 || i == 8 || i == 9) && (j == 40)) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 7 && j > 20 && j < 40) {
            PUR printf("\u2594");
            WHT
          }
          else if (i == 8 && j == 28) {
            printf("В");
          }
          else if (i == 8 && j == 29) {
            printf("х");
          }
          else if (i == 8 && j == 30) {
            printf("о");
          }
          else if (i == 8 && j == 31) {
            printf("д");
          }
          else if (i == 10 && j < 40 && j > 20) {
            PUR printf("\u2594");
            WHT
          }
          // конец (вход)
          // начало (регистр)
          else if ((i == 10 || i == 11 || i == 12) && (j == 20)) {
            PUR printf("\u27ea");
            WHT
          }
          else if ((i == 10 || i == 11 || i == 12) && j == 40) {
            PUR printf("\u27eb");
            WHT
          }
          else if (i == 11 && j == 25) {
            printf("Р");
          }
          else if (i == 11 && j == 26) {
            printf("е");
          }
          else if (i == 11 && j == 27) {
            printf("г");
          }
          else if (i == 11 && j == 28) {
            printf("и");
          }
          else if (i == 11 && j == 29) {
            printf("с");
          }
          else if (i == 11 && j == 30) {
            printf("т");
          }
          else if (i == 11 && j == 31) {
            printf("р");
          }
          else if (i == 11 && j == 32) {
            printf("а");
          }
          else if (i == 11 && j == 33) {
            printf("ц");
          }
          else if (i == 11 && j == 34) {
            printf("и");
          }
          else if (i == 11 && j == 35) {
            printf("я");
          }
          else if (i == 13 && j < 40 && j > 20) {
            PUR printf("\u2594");
            WHT
          }
          else if (i == len / 3 && j == 0) {
            printf("\u2517");
          }
          else if (i == len / 3 && (j > 0) && (j != len + 1)) {
            printf("\u2501");
          }
          else if (i == len / 3 && j == len + 1) {
            printf("\u251b");
          }
          else {
            printf(" ");
          }
        }
        printf("\n");
      }
      request = 2;
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
          // конец названия кинотеатра
          // начало (вход)
          else if ((i == 7 || i == 8 || i == 9) && (j == 20 || j == 40)) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 7 && j > 20 && j < 40) {
            PUR printf("\u2594");
            WHT
          }
          else if (i == 8 && j == 28) {
            printf("В");
          }
          else if (i == 8 && j == 29) {
            printf("х");
          }
          else if (i == 8 && j == 30) {
            printf("о");
          }
          else if (i == 8 && j == 31) {
            printf("д");
          }
          else if (i == 10 && j < 40 && j > 20) {
            PUR printf("\u2594");
            WHT
          }
          // конец (вход)
          // начало (регистр)
          else if ((i == 10 || i == 11 || i == 12) && (j == 20 || j == 40)) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 11 && j == 25) {
            printf("Р");
          }
          else if (i == 11 && j == 26) {
            printf("е");
          }
          else if (i == 11 && j == 27) {
            printf("г");
          }
          else if (i == 11 && j == 28) {
            printf("и");
          }
          else if (i == 11 && j == 29) {
            printf("с");
          }
          else if (i == 11 && j == 30) {
            printf("т");
          }
          else if (i == 11 && j == 31) {
            printf("р");
          }
          else if (i == 11 && j == 32) {
            printf("а");
          }
          else if (i == 11 && j == 33) {
            printf("ц");
          }
          else if (i == 11 && j == 34) {
            printf("и");
          }
          else if (i == 11 && j == 35) {
            printf("я");
          }
          else if (i == 13 && j < 40 && j > 20) {
            PUR printf("\u2594");
            WHT
          }
          else if (i == len / 3 && j == 0) {
            printf("\u2517");
          }
          else if (i == len / 3 && (j > 0) && (j != len + 1)) {
            printf("\u2501");
          }
          else if (i == len / 3 && j == len + 1) {
            printf("\u251b");
          }
          else {
            printf(" ");
          }
        }
        printf("\n");
      }
    }
    key = getch();
    printf("\033[0d\033[2J");
  } while (key != 10);
  key = 0;
  return request;
}
int pageEnter(struct user user) {
  int p;
  int request;
  printf("\033[0d\033[2J");
  int key = 1;
  do {
    switch (key) {

    case 87:
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
          // конец названия кинотеатра
          // начало (вход)
          else if (i == 4 && j == 22) {
            printf("Д");
          }
          else if (i == 4 && j == 23) {
            printf("о");
          }
          else if (i == 4 && j == 24) {
            printf("б");
          }
          else if (i == 4 && j == 25) {
            printf("р");
          }
          else if (i == 4 && j == 26) {
            printf("о");
          }
          else if (i == 4 && j == 28) {
            printf("п");
          }
          else if (i == 4 && j == 29) {
            printf("о");
          }
          else if (i == 4 && j == 30) {
            printf("ж");
          }
          else if (i == 4 && j == 31) {
            printf("а");
          }
          else if (i == 4 && j == 32) {
            printf("л");
          }
          else if (i == 4 && j == 33) {
            printf("о");
          }
          else if (i == 4 && j == 34) {
            printf("в");
          }
          else if (i == 4 && j == 35) {
            printf("а");
          }
          else if (i == 4 && j == 36) {
            printf("т");
          }
          else if (i == 4 && j == 37) {
            printf("ь");
          }
          else if (i == 4 && j == 38) {
            printf(",");
          }
          else if (i == 5 && j < (60 - strlen(user.name)) / 2) {
            printf(" ");
          }
          else if (i == 5 && j == (60 - strlen(user.name)) / 2) {
            printf("%s", user.name);
          }
          else if (i == 5 && j >= (60 - strlen(user.name)) / 2 &&
                   j <= (60 - strlen(user.name) + 1)) {
            printf(" ");
          }
          else if ((i == 7 || i == 8 || i == 9) && (j == 20)) {
            PUR printf("\u27ea");
            WHT
          }
          else if ((i == 7 || i == 8 || i == 9) && (j == 40)) {
            PUR printf("\u27eb");
            WHT
          }
          else if (i == 7 && j > 20 && j < 40) {
            PUR printf("\u2594");
            WHT
          }
          else if (i == 8 && j == 27) {
            printf("К");
          }
          else if (i == 8 && j == 28) {
            printf("а");
          }
          else if (i == 8 && j == 29) {
            printf("т");
          }
          else if (i == 8 && j == 30) {
            printf("а");
          }
          else if (i == 8 && j == 31) {
            printf("л");
          }
          else if (i == 8 && j == 32) {
            printf("о");
          }
          else if (i == 8 && j == 33) {
            printf("г");
          }
          else if (i == 10 && j < 40 && j > 20) {
            PUR printf("\u2594");
            WHT
          }
          // конец (вход)
          // начало (регистр)
          else if ((i == 10 || i == 11 || i == 12) && (j == 20 || j == 40)) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 11 && j == 24) {
            printf("Л");
          }
          else if (i == 11 && j == 25) {
            printf("и");
          }
          else if (i == 11 && j == 26) {
            printf("ч");
          }
          else if (i == 11 && j == 27) {
            printf("н");
          }
          else if (i == 11 && j == 28) {
            printf("ы");
          }
          else if (i == 11 && j == 29) {
            printf("й");
          }

          else if (i == 11 && j == 31) {
            printf("к");
          }
          else if (i == 11 && j == 32) {
            printf("а");
          }
          else if (i == 11 && j == 33) {
            printf("б");
          }
          else if (i == 11 && j == 34) {
            printf("и");
          }
          else if (i == 11 && j == 35) {
            printf("н");
          }
          else if (i == 11 && j == 36) {
            printf("е");
          }
          else if (i == 11 && j == 37) {
            printf("т");
          }
          else if (i == 13 && j < 40 && j > 20) {
            PUR printf("\u2594");
            WHT
          }
          else if (i == len / 3 && j == 0) {
            printf("\u2517");
          }
          else if (i == len / 3 && (j > 0) && (j != len + 1)) {
            printf("\u2501");
          }
          else if (i == len / 3 && j == len + 1) {
            printf("\u251b");
          }
          else if (i != 5) {
            printf(" ");
          }
        }
        printf("\n");
      }
      request = 1;
      break;
    case 119:
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
          // конец названия кинотеатра
          // начало (вход)
          else if (i == 4 && j == 22) {
            printf("Д");
          }
          else if (i == 4 && j == 23) {
            printf("о");
          }
          else if (i == 4 && j == 24) {
            printf("б");
          }
          else if (i == 4 && j == 25) {
            printf("р");
          }
          else if (i == 4 && j == 26) {
            printf("о");
          }
          else if (i == 4 && j == 28) {
            printf("п");
          }
          else if (i == 4 && j == 29) {
            printf("о");
          }
          else if (i == 4 && j == 30) {
            printf("ж");
          }
          else if (i == 4 && j == 31) {
            printf("а");
          }
          else if (i == 4 && j == 32) {
            printf("л");
          }
          else if (i == 4 && j == 33) {
            printf("о");
          }
          else if (i == 4 && j == 34) {
            printf("в");
          }
          else if (i == 4 && j == 35) {
            printf("а");
          }
          else if (i == 4 && j == 36) {
            printf("т");
          }
          else if (i == 4 && j == 37) {
            printf("ь");
          }
          else if (i == 4 && j == 38) {
            printf(",");
          }
          else if (i == 5 && j < (60 - strlen(user.name)) / 2) {
            printf(" ");
          }
          else if (i == 5 && j == (60 - strlen(user.name)) / 2) {
            printf("%s", user.name);
          }
          else if (i == 5 && j >= (60 - strlen(user.name)) / 2 &&
                   j <= (60 - strlen(user.name) + 1)) {
            printf(" ");
          }
          else if ((i == 7 || i == 8 || i == 9) && (j == 20)) {
            PUR printf("\u27ea");
            WHT
          }
          else if ((i == 7 || i == 8 || i == 9) && (j == 40)) {
            PUR printf("\u27eb");
            WHT
          }
          else if (i == 7 && j > 20 && j < 40) {
            PUR printf("\u2594");
            WHT
          }
          else if (i == 8 && j == 27) {
            printf("К");
          }
          else if (i == 8 && j == 28) {
            printf("а");
          }
          else if (i == 8 && j == 29) {
            printf("т");
          }
          else if (i == 8 && j == 30) {
            printf("а");
          }
          else if (i == 8 && j == 31) {
            printf("л");
          }
          else if (i == 8 && j == 32) {
            printf("о");
          }
          else if (i == 8 && j == 33) {
            printf("г");
          }
          else if (i == 10 && j < 40 && j > 20) {
            PUR printf("\u2594");
            WHT
          }
          // конец (вход)
          // начало (регистр)
          else if ((i == 10 || i == 11 || i == 12) && (j == 20 || j == 40)) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 11 && j == 24) {
            printf("Л");
          }
          else if (i == 11 && j == 25) {
            printf("и");
          }
          else if (i == 11 && j == 26) {
            printf("ч");
          }
          else if (i == 11 && j == 27) {
            printf("н");
          }
          else if (i == 11 && j == 28) {
            printf("ы");
          }
          else if (i == 11 && j == 29) {
            printf("й");
          }

          else if (i == 11 && j == 31) {
            printf("к");
          }
          else if (i == 11 && j == 32) {
            printf("а");
          }
          else if (i == 11 && j == 33) {
            printf("б");
          }
          else if (i == 11 && j == 34) {
            printf("и");
          }
          else if (i == 11 && j == 35) {
            printf("н");
          }
          else if (i == 11 && j == 36) {
            printf("е");
          }
          else if (i == 11 && j == 37) {
            printf("т");
          }
          else if (i == 13 && j < 40 && j > 20) {
            PUR printf("\u2594");
            WHT
          }
          else if (i == len / 3 && j == 0) {
            printf("\u2517");
          }
          else if (i == len / 3 && (j > 0) && (j != len + 1)) {
            printf("\u2501");
          }
          else if (i == len / 3 && j == len + 1) {
            printf("\u251b");
          }
          else if (i != 5) {
            printf(" ");
          }
        }
        printf("\n");
      }
      request = 1;
      break;

    case 83:
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
          // конец названия кинотеатра
          // начало (вход)
          else if (i == 4 && j == 22) {
            printf("Д");
          }
          else if (i == 4 && j == 23) {
            printf("о");
          }
          else if (i == 4 && j == 24) {
            printf("б");
          }
          else if (i == 4 && j == 25) {
            printf("р");
          }
          else if (i == 4 && j == 26) {
            printf("о");
          }
          else if (i == 4 && j == 28) {
            printf("п");
          }
          else if (i == 4 && j == 29) {
            printf("о");
          }
          else if (i == 4 && j == 30) {
            printf("ж");
          }
          else if (i == 4 && j == 31) {
            printf("а");
          }
          else if (i == 4 && j == 32) {
            printf("л");
          }
          else if (i == 4 && j == 33) {
            printf("о");
          }
          else if (i == 4 && j == 34) {
            printf("в");
          }
          else if (i == 4 && j == 35) {
            printf("а");
          }
          else if (i == 4 && j == 36) {
            printf("т");
          }
          else if (i == 4 && j == 37) {
            printf("ь");
          }
          else if (i == 4 && j == 38) {
            printf(",");
          }
          else if (i == 5 && j < (60 - strlen(user.name)) / 2) {
            printf(" ");
          }
          else if (i == 5 && j == (60 - strlen(user.name)) / 2) {
            printf("%s", user.name);
          }
          else if (i == 5 && j >= (60 - strlen(user.name)) / 2 &&
                   j <= (60 - strlen(user.name) + 1)) {
            printf(" ");
          }
          else if ((i == 7 || i == 8 || i == 9) && (j == 20)) {
            PUR printf("\u2551");
            WHT
          }
          else if ((i == 7 || i == 8 || i == 9) && (j == 40)) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 7 && j > 20 && j < 40) {
            PUR printf("\u2594");
            WHT
          }
          else if (i == 8 && j == 27) {
            printf("К");
          }
          else if (i == 8 && j == 28) {
            printf("а");
          }
          else if (i == 8 && j == 29) {
            printf("т");
          }
          else if (i == 8 && j == 30) {
            printf("а");
          }
          else if (i == 8 && j == 31) {
            printf("л");
          }
          else if (i == 8 && j == 32) {
            printf("о");
          }
          else if (i == 8 && j == 33) {
            printf("г");
          }
          else if (i == 10 && j < 40 && j > 20) {
            PUR printf("\u2594");
            WHT
          }
          // конец (вход)
          // начало (регистр)
          else if ((i == 10 || i == 11 || i == 12) && (j == 20)) {
            PUR printf("\u27ea");
            WHT
          }
          else if ((i == 10 || i == 11 || i == 12) && j == 40) {
            PUR printf("\u27eb");
            WHT
          }
          else if (i == 11 && j == 24) {
            printf("Л");
          }
          else if (i == 11 && j == 25) {
            printf("и");
          }
          else if (i == 11 && j == 26) {
            printf("ч");
          }
          else if (i == 11 && j == 27) {
            printf("н");
          }
          else if (i == 11 && j == 28) {
            printf("ы");
          }
          else if (i == 11 && j == 29) {
            printf("й");
          }

          else if (i == 11 && j == 31) {
            printf("к");
          }
          else if (i == 11 && j == 32) {
            printf("а");
          }
          else if (i == 11 && j == 33) {
            printf("б");
          }
          else if (i == 11 && j == 34) {
            printf("и");
          }
          else if (i == 11 && j == 35) {
            printf("н");
          }
          else if (i == 11 && j == 36) {
            printf("е");
          }
          else if (i == 11 && j == 37) {
            printf("т");
          }
          else if (i == 13 && j < 40 && j > 20) {
            PUR printf("\u2594");
            WHT
          }
          else if (i == len / 3 && j == 0) {
            printf("\u2517");
          }
          else if (i == len / 3 && (j > 0) && (j != len + 1)) {
            printf("\u2501");
          }
          else if (i == len / 3 && j == len + 1) {
            printf("\u251b");
          }
          else if (i != 5) {
            printf(" ");
          }
        }
        printf("\n");
      }
      request = 2;
      break;
    case 115:
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
          // конец названия кинотеатра
          // начало (вход)
          else if (i == 4 && j == 22) {
            printf("Д");
          }
          else if (i == 4 && j == 23) {
            printf("о");
          }
          else if (i == 4 && j == 24) {
            printf("б");
          }
          else if (i == 4 && j == 25) {
            printf("р");
          }
          else if (i == 4 && j == 26) {
            printf("о");
          }
          else if (i == 4 && j == 28) {
            printf("п");
          }
          else if (i == 4 && j == 29) {
            printf("о");
          }
          else if (i == 4 && j == 30) {
            printf("ж");
          }
          else if (i == 4 && j == 31) {
            printf("а");
          }
          else if (i == 4 && j == 32) {
            printf("л");
          }
          else if (i == 4 && j == 33) {
            printf("о");
          }
          else if (i == 4 && j == 34) {
            printf("в");
          }
          else if (i == 4 && j == 35) {
            printf("а");
          }
          else if (i == 4 && j == 36) {
            printf("т");
          }
          else if (i == 4 && j == 37) {
            printf("ь");
          }
          else if (i == 4 && j == 38) {
            printf(",");
          }
          else if (i == 5 && j < (60 - strlen(user.name)) / 2) {
            printf(" ");
          }
          else if (i == 5 && j == (60 - strlen(user.name)) / 2) {
            printf("%s", user.name);
          }
          else if (i == 5 && j >= (60 - strlen(user.name)) / 2 &&
                   j <= (60 - strlen(user.name) + 1)) {
            printf(" ");
          }
          else if ((i == 7 || i == 8 || i == 9) && (j == 20)) {
            PUR printf("\u2551");
            WHT
          }
          else if ((i == 7 || i == 8 || i == 9) && (j == 40)) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 7 && j > 20 && j < 40) {
            PUR printf("\u2594");
            WHT
          }
          else if (i == 8 && j == 27) {
            printf("К");
          }
          else if (i == 8 && j == 28) {
            printf("а");
          }
          else if (i == 8 && j == 29) {
            printf("т");
          }
          else if (i == 8 && j == 30) {
            printf("а");
          }
          else if (i == 8 && j == 31) {
            printf("л");
          }
          else if (i == 8 && j == 32) {
            printf("о");
          }
          else if (i == 8 && j == 33) {
            printf("г");
          }
          else if (i == 10 && j < 40 && j > 20) {
            PUR printf("\u2594");
            WHT
          }
          // конец (вход)
          // начало (регистр)
          else if ((i == 10 || i == 11 || i == 12) && (j == 20)) {
            PUR printf("\u27ea");
            WHT
          }
          else if ((i == 10 || i == 11 || i == 12) && j == 40) {
            PUR printf("\u27eb");
            WHT
          }
          else if (i == 11 && j == 24) {
            printf("Л");
          }
          else if (i == 11 && j == 25) {
            printf("и");
          }
          else if (i == 11 && j == 26) {
            printf("ч");
          }
          else if (i == 11 && j == 27) {
            printf("н");
          }
          else if (i == 11 && j == 28) {
            printf("ы");
          }
          else if (i == 11 && j == 29) {
            printf("й");
          }

          else if (i == 11 && j == 31) {
            printf("к");
          }
          else if (i == 11 && j == 32) {
            printf("а");
          }
          else if (i == 11 && j == 33) {
            printf("б");
          }
          else if (i == 11 && j == 34) {
            printf("и");
          }
          else if (i == 11 && j == 35) {
            printf("н");
          }
          else if (i == 11 && j == 36) {
            printf("е");
          }
          else if (i == 11 && j == 37) {
            printf("т");
          }
          else if (i == 13 && j < 40 && j > 20) {
            PUR printf("\u2594");
            WHT
          }
          else if (i == len / 3 && j == 0) {
            printf("\u2517");
          }
          else if (i == len / 3 && (j > 0) && (j != len + 1)) {
            printf("\u2501");
          }
          else if (i == len / 3 && j == len + 1) {
            printf("\u251b");
          }
          else if (i != 5) {
            printf(" ");
          }
        }
        printf("\n");
      }
      request = 2;
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
          // конец названия кинотеатра
          // начало (вход)
          else if (i == 4 && j == 22) {
            printf("Д");
          }
          else if (i == 4 && j == 23) {
            printf("о");
          }
          else if (i == 4 && j == 24) {
            printf("б");
          }
          else if (i == 4 && j == 25) {
            printf("р");
          }
          else if (i == 4 && j == 26) {
            printf("о");
          }
          else if (i == 4 && j == 28) {
            printf("п");
          }
          else if (i == 4 && j == 29) {
            printf("о");
          }
          else if (i == 4 && j == 30) {
            printf("ж");
          }
          else if (i == 4 && j == 31) {
            printf("а");
          }
          else if (i == 4 && j == 32) {
            printf("л");
          }
          else if (i == 4 && j == 33) {
            printf("о");
          }
          else if (i == 4 && j == 34) {
            printf("в");
          }
          else if (i == 4 && j == 35) {
            printf("а");
          }
          else if (i == 4 && j == 36) {
            printf("т");
          }
          else if (i == 4 && j == 37) {
            printf("ь");
          }
          else if (i == 4 && j == 38) {
            printf(",");
          }
          else if (i == 5 && j < (60 - strlen(user.name)) / 2) {
            printf(" ");
          }
          else if (i == 5 && j == (60 - strlen(user.name)) / 2) {
            printf("%s", user.name);
          }
          else if (i == 5 && j >= (60 - strlen(user.name)) / 2 &&
                   j <= (60 - strlen(user.name) + 1)) {
            printf(" ");
          }
          else if ((i == 7 || i == 8 || i == 9) && (j == 20 || j == 40)) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 7 && j > 20 && j < 40) {
            PUR printf("\u2594");
            WHT
          }
          else if (i == 8 && j == 27) {
            printf("К");
          }
          else if (i == 8 && j == 28) {
            printf("а");
          }
          else if (i == 8 && j == 29) {
            printf("т");
          }
          else if (i == 8 && j == 30) {
            printf("а");
          }
          else if (i == 8 && j == 31) {
            printf("л");
          }
          else if (i == 8 && j == 32) {
            printf("о");
          }
          else if (i == 8 && j == 33) {
            printf("г");
          }
          else if (i == 10 && j < 40 && j > 20) {
            PUR printf("\u2594");
            WHT
          }
          // конец (вход)
          // начало (регистр)
          else if ((i == 10 || i == 11 || i == 12) && (j == 20 || j == 40)) {
            PUR printf("\u2551");
            WHT
          }
          else if (i == 11 && j == 24) {
            printf("Л");
          }
          else if (i == 11 && j == 25) {
            printf("и");
          }
          else if (i == 11 && j == 26) {
            printf("ч");
          }
          else if (i == 11 && j == 27) {
            printf("н");
          }
          else if (i == 11 && j == 28) {
            printf("ы");
          }
          else if (i == 11 && j == 29) {
            printf("й");
          }

          else if (i == 11 && j == 31) {
            printf("к");
          }
          else if (i == 11 && j == 32) {
            printf("а");
          }
          else if (i == 11 && j == 33) {
            printf("б");
          }
          else if (i == 11 && j == 34) {
            printf("и");
          }
          else if (i == 11 && j == 35) {
            printf("н");
          }
          else if (i == 11 && j == 36) {
            printf("е");
          }
          else if (i == 11 && j == 37) {
            printf("т");
          }
          else if (i == 13 && j < 40 && j > 20) {
            PUR printf("\u2594");
            WHT
          }
          else if (i == len / 3 && j == 0) {
            printf("\u2517");
          }
          else if (i == len / 3 && (j > 0) && (j != len + 1)) {
            printf("\u2501");
          }
          else if (i == len / 3 && j == len + 1) {
            printf("\u251b");
          }
          else if (i != 5) {
            printf(" ");
          }
        }
        printf("\n");
      }
    }
    key = getch();
    printf("\033[0d\033[2J");
  } while (key != 10);
  key = NULL;
  return request;
}
void pageSignup() {
  printf("\033[0d\033[2J");
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
      //регистрация новгого пользователя
      else if (i == 4 && j == 13) {
        printf("\u2989");
      }
      else if (i == 4 && j == 15) {
        printf("Р");
      }
      else if (i == 4 && j == 16) {
        printf("е");
      }
      else if (i == 4 && j == 17) {
        printf("г");
      }
      else if (i == 4 && j == 18) {
        printf("и");
      }
      else if (i == 4 && j == 19) {
        printf("с");
      }
      else if (i == 4 && j == 20) {
        printf("т");
      }
      else if (i == 4 && j == 21) {
        printf("р");
      }
      else if (i == 4 && j == 22) {
        printf("а");
      }
      else if (i == 4 && j == 23) {
        printf("ц");
      }
      else if (i == 4 && j == 24) {
        printf("и");
      }
      else if (i == 4 && j == 25) {
        printf("я");
      }
      else if (i == 4 && j == 27) {
        printf("н");
      }
      else if (i == 4 && j == 28) {
        printf("о");
      }
      else if (i == 4 && j == 29) {
        printf("в");
      }
      else if (i == 4 && j == 30) {
        printf("о");
      }
      else if (i == 4 && j == 31) {
        printf("г");
      }
      else if (i == 4 && j == 32) {
        printf("о");
      }
      else if (i == 4 && j == 34) {
        printf("п");
      }
      else if (i == 4 && j == 35) {
        printf("о");
      }
      else if (i == 4 && j == 36) {
        printf("л");
      }
      else if (i == 4 && j == 37) {
        printf("ь");
      }
      else if (i == 4 && j == 38) {
        printf("з");
      }
      else if (i == 4 && j == 39) {
        printf("о");
      }
      else if (i == 4 && j == 40) {
        printf("в");
      }
      else if (i == 4 && j == 41) {
        printf("а");
      }
      else if (i == 4 && j == 42) {
        printf("т");
      }
      else if (i == 4 && j == 43) {
        printf("е");
      }
      else if (i == 4 && j == 44) {
        printf("л");
      }
      else if (i == 4 && j == 45) {
        printf("я");
      }
      else if (i == 4 && j == 47) {
        printf("\u298a");
      }
      // конец надписи (регистрация)
      // фиолетовая рамочка с текстом
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
      else if (i == 8 && (j == 13 || j == 47)) {
        PUR printf("\u2551");
        WHT
      }
      else if (i == 8 && j == 15) {
        printf("П");
      }
      else if (i == 8 && j == 16) {
        printf("p");
      }
      else if (i == 8 && j == 17) {
        printf("и");
      }
      else if (i == 8 && j == 18) {
        printf("д");
      }
      else if (i == 8 && j == 19) {
        printf("у");
      }
      else if (i == 8 && j == 20) {
        printf("м");
      }
      else if (i == 8 && j == 21) {
        printf("а");
      }
      else if (i == 8 && j == 22) {
        printf("й");
      }
      else if (i == 8 && j == 23) {
        printf("т");
      }
      else if (i == 8 && j == 24) {
        printf("е");
      }
      else if (i == 8 && j == 25) {
        printf(",");
      }
      else if (i == 8 && j == 27) {
        printf("п");
      }
      else if (i == 8 && j == 28) {
        printf("о");
      }
      else if (i == 8 && j == 29) {
        printf("ж");
      }
      else if (i == 8 && j == 30) {
        printf("а");
      }
      else if (i == 8 && j == 31) {
        printf("л");
      }
      else if (i == 8 && j == 32) {
        printf("у");
      }
      else if (i == 8 && j == 33) {
        printf("й");
      }
      else if (i == 8 && j == 34) {
        printf("с");
      }
      else if (i == 8 && j == 35) {
        printf("т");
      }
      else if (i == 8 && j == 36) {
        printf("а");
      }
      else if (i == 8 && j == 37) {
        printf(",");
      }
      else if (i == 8 && j == 39) {
        printf("л");
      }
      else if (i == 8 && j == 40) {
        printf("о");
      }
      else if (i == 8 && j == 41) {
        printf("г");
      }
      else if (i == 8 && j == 42) {
        printf("и");
      }
      else if (i == 8 && j == 43) {
        printf("н");
      }
      else if (i == 8 && j == 45) {
        printf("и");
      }
      else if ((i == 9 || i == 10 || i == 11 || i == 12 || i == 13) &&
               (j == 13 || j == 47)) {
        PUR printf("\u2551");
        WHT
      }
      else if (i == 10 && j == 18) {
        printf("н");
      }
      else if (i == 10 && j == 19) {
        printf("a");
      }
      else if (i == 10 && j == 20) {
        printf("д");
      }
      else if (i == 10 && j == 21) {
        printf("ё");
      }
      else if (i == 10 && j == 22) {
        printf("ж");
      }
      else if (i == 10 && j == 23) {
        printf("н");
      }
      else if (i == 10 && j == 24) {
        printf("ы");
      }
      else if (i == 10 && j == 25) {
        printf("й");
      }
      else if (i == 10 && j == 27) {
        printf("п");
      }
      else if (i == 10 && j == 28) {
        printf("а");
      }
      else if (i == 10 && j == 29) {
        printf("р");
      }
      else if (i == 10 && j == 30) {
        printf("о");
      }
      else if (i == 10 && j == 31) {
        printf("л");
      }
      else if (i == 10 && j == 32) {
        printf("ь");
      }
      else if (i == 10 && j == 33) {
        printf(",");
      }
      else if (i == 10 && j == 35) {
        printf("а");
      }
      else if (i == 10 && j == 37) {
        printf("т");
      }
      else if (i == 10 && j == 38) {
        printf("а");
      }
      else if (i == 10 && j == 39) {
        printf("к");
      }
      else if (i == 10 && j == 40) {
        printf("ж");
      }
      else if (i == 10 && j == 41) {
        printf("е");
      }
      else if (i == 12 && j == 15) {
        printf("в");
      }
      else if (i == 12 && j == 16) {
        printf("в");
      }
      else if (i == 12 && j == 17) {
        printf("е");
      }
      else if (i == 12 && j == 18) {
        printf("д");
      }
      else if (i == 12 && j == 19) {
        printf("и");
      }
      else if (i == 12 && j == 20) {
        printf("т");
      }
      else if (i == 12 && j == 21) {
        printf("е");
      }
      else if (i == 12 && j == 23) {
        printf("д");
      }
      else if (i == 12 && j == 24) {
        printf("а");
      }
      else if (i == 12 && j == 25) {
        printf("н");
      }
      else if (i == 12 && j == 26) {
        printf("н");
      }
      else if (i == 12 && j == 27) {
        printf("ы");
      }
      else if (i == 12 && j == 28) {
        printf("е");
      }
      else if (i == 12 && j == 30) {
        printf("б");
      }
      else if (i == 12 && j == 31) {
        printf("а");
      }
      else if (i == 12 && j == 32) {
        printf("н");
      }
      else if (i == 12 && j == 33) {
        printf("к");
      }
      else if (i == 12 && j == 34) {
        printf("о");
      }
      else if (i == 12 && j == 35) {
        printf("в");
      }
      else if (i == 12 && j == 36) {
        printf("с");
      }
      else if (i == 12 && j == 37) {
        printf("к");
      }
      else if (i == 12 && j == 38) {
        printf("о");
      }
      else if (i == 12 && j == 39) {
        printf("й");
      }
      else if (i == 12 && j == 41) {
        printf("к");
      }
      else if (i == 12 && j == 42) {
        printf("а");
      }
      else if (i == 12 && j == 43) {
        printf("р");
      }
      else if (i == 12 && j == 44) {
        printf("т");
      }
      else if (i == 12 && j == 45) {
        printf("ы");
      }
      else if (i == 14 && j > 13 && j < 47) {
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
      else {
        printf(" ");
      }
    }
    printf("\n");
  }
}
void pageLogin() {
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
      else if (i == 4 && j == 15) {
        printf("\u2989");
      }
      else if (i == 4 && j == 17) {
        printf("В");
      }
      else if (i == 4 && j == 18) {
        printf("х");
      }
      else if (i == 4 && j == 19) {
        printf("о");
      }
      else if (i == 4 && j == 20) {
        printf("д");
      }
      else if (i == 4 && j == 21) {
        printf(" ");
      }
      else if (i == 4 && j == 22) {
        printf("в");
      }
      else if (i == 4 && j == 23) {
        printf(" ");
      }
      else if (i == 4 && j == 24) {
        printf("с");
      }
      else if (i == 4 && j == 25) {
        printf("у");
      }
      else if (i == 4 && j == 26) {
        printf("щ");
      }
      else if (i == 4 && j == 27) {
        printf("е");
      }
      else if (i == 4 && j == 28) {
        printf("с");
      }
      else if (i == 4 && j == 29) {
        printf("т");
      }
      else if (i == 4 && j == 30) {
        printf("в");
      }
      else if (i == 4 && j == 31) {
        printf("у");
      }
      else if (i == 4 && j == 32) {
        printf("ю");
      }
      else if (i == 4 && j == 33) {
        printf("щ");
      }
      else if (i == 4 && j == 34) {
        printf("и");
      }
      else if (i == 4 && j == 35) {
        printf("й");
      }
      else if (i == 4 && j == 36) {
        printf(" ");
      }
      else if (i == 4 && j == 37) {
        printf("а");
      }
      else if (i == 4 && j == 38) {
        printf("к");
      }
      else if (i == 4 && j == 39) {
        printf("к");
      }
      else if (i == 4 && j == 40) {
        printf("а");
      }
      else if (i == 4 && j == 41) {
        printf("у");
      }
      else if (i == 4 && j == 42) {
        printf("н");
      }
      else if (i == 4 && j == 43) {
        printf("т");
      }
      else if (i == 4 && j == 45) {
        printf("\u298a");
      }
      //конец первой надписи (вход...)
      //начало рамочки с просьбой ввести свои данные
      else if (i == 7 && j == 15) {
        PUR printf("\u2551");
        WHT
      }
      else if (i == 7 && j > 15 && j < 45) {
        PUR printf("\u2594");
        WHT
      }
      else if (i == 7 && j == 45) {
        PUR printf("\u2551");
        WHT
      }
      else if (i == 8 && j == 15) {
        PUR printf("\u2551");
        WHT
      }
      else if (i == 8 && j == 21) {
        printf("В");
      }
      else if (i == 8 && j == 22) {
        printf("в");
      }
      else if (i == 8 && j == 23) {
        printf("е");
      }
      else if (i == 8 && j == 24) {
        printf("д");
      }
      else if (i == 8 && j == 25) {
        printf("и");
      }
      else if (i == 8 && j == 26) {
        printf("т");
      }
      else if (i == 8 && j == 27) {
        printf("е");
      }
      else if (i == 8 && j == 28) {
        printf(",");
      }
      else if (i == 8 && j == 30) {
        printf("п");
      }
      else if (i == 8 && j == 31) {
        printf("о");
      }
      else if (i == 8 && j == 32) {
        printf("ж");
      }
      else if (i == 8 && j == 33) {
        printf("а");
      }
      else if (i == 8 && j == 34) {
        printf("л");
      }
      else if (i == 8 && j == 35) {
        printf("у");
      }
      else if (i == 8 && j == 36) {
        printf("й");
      }
      else if (i == 8 && j == 37) {
        printf("с");
      }
      else if (i == 8 && j == 38) {
        printf("т");
      }
      else if (i == 8 && j == 39) {
        printf("а");
      }
      else if (i == 8 && j == 45) {
        PUR printf("\u2551");
        WHT
      }
      else if (i == 9 && (j == 15 || j == 45)) {
        PUR printf("\u2551");
        WHT
      }
      else if (i == 10 && (j == 15 || j == 45)) {
        PUR printf("\u2551");
        WHT
      }
      else if (i == 10 && j == 24) {
        printf("л");
      }
      else if (i == 10 && j == 25) {
        printf("o");
      }
      else if (i == 10 && j == 26) {
        printf("г");
      }
      else if (i == 10 && j == 27) {
        printf("и");
      }
      else if (i == 10 && j == 28) {
        printf("н");
      }
      else if (i == 10 && j == 30) {
        printf("и");
      }
      else if (i == 10 && j == 32) {
        printf("п");
      }
      else if (i == 10 && j == 33) {
        printf("a");
      }
      else if (i == 10 && j == 34) {
        printf("р");
      }
      else if (i == 10 && j == 35) {
        printf("о");
      }
      else if (i == 10 && j == 36) {
        printf("л");
      }
      else if (i == 10 && j == 37) {
        printf("ь");
      }
      else if (i == 11 && (j == 15 || j == 45)) {
        PUR printf("\u2551");
        WHT
      }
      else if (i == 12 && j > 15 && j < 45) {
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
      else {
        printf(" ");
      }
    }
    printf("\n");
  }
}
struct user pageProfile(struct user user) {
  int p;
  int request = 0;
  printf("\033[0d\033[2J");
  int key = 1;
  do {
    switch (key) {
    case 87:
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
      request = request + 1;
      break;
    case 119:
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
      request = request + 1;
      break;
    case 83:
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
      request = request - 1;
      break;
    case 115:
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
      request = request - 1;
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
      request = request - 1;
      break;
    }
    key = getch();
    printf("\033[0d\033[2J");
  } while (key != 10);
  key = 0;
  return user;
}
