#include "authorization.h"
#include "pages.h"
#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#define len 60
#define PUR printf("\033[1;35m");
#define WHT printf("\33[0m");
#define Back printf("\33[40m");

// \u250f - левый верхний угол
// \u2513 - правый верхний угол
// \u2517 - левый нижний угол
// \u251b - правый нижний угол
// \u2501 - горизонтальная прямая
// \u2503 - вертикальная прямая
// \u2B9C - стрелка влево
// \u2B9E - стрелка вправо

int main(void) {
  setlocale(LC_ALL, "");
  Node *head = init();
  int key = 1;
  head = scan_films(head);
  // print_window();

  // 1 :: Login
  // 2 :: Signup
  // 1 :: Catalog
  // 2 :: Profile
  struct user user1;
  struct user user_prev;
  FILE *users;
  for (int i = 1; i < 4; i++) {
    if (i < 3)
      switch (pageAuth()) {
      case 1:
        user1 = login();
        break;
      case 2:
        pageSignup();
        user1 = signup();
        break;
      }
    user_prev = user1;
    if (i > 2)
      while (key != 27)
        switch (pageEnter(user1, key)) {
        case 1:
          page_Katalog(head);
          break;
        case 2:
          user1 = profile(user1);
          edit(users, user1, user_prev);
          break;
        }
  }
  return 0;
}
