#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
//
//
//
//
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
typedef struct movie {
  char name[100];
  char date[10];
  char country[100];
  char genre[100];
  char rate[10];
} movie;

typedef struct Node {
  struct Node *next;
  struct Node *prev;
  movie Film;
  int count;
  int favourite;
} Node;

Node *init() {
  Node *list;
  list = (Node *)malloc(sizeof(Node));
  // list->Film = Film;
  list->next = list;
  list->prev = list;
  return (list);
}

void insert(Node *head, movie Film) {
  Node *tmp, *q = head->next;
  tmp = (Node*)malloc(sizeof(Node));
  head->next = tmp;
  strcpy(tmp->Film.name, Film.name);
  strcpy(tmp->Film.date, Film.date);
  strcpy(tmp->Film.country, Film.country);
  strcpy(tmp->Film.genre, Film.genre);
  strcpy(tmp->Film.rate, Film.rate);
  tmp->prev = head;
  tmp->next = q;
  q->prev = tmp;
}

void list_print(Node *head) {
  Node *p;
  p = head;
  do {
    printf("%s %s %s %s %s\n", p->Film.name, p->Film.date, p->Film.country, p->Film.genre, p->Film.rate);
    p = p->next;
  } while (p != head);
}

void list_print_back(Node *head) {
  for (Node *p = head->prev; p != head; p = p->prev) {
    printf("%s %s %s %s %s\n", p->Film.name, p->Film.date, p->Film.country,
           p->Film.genre, p->Film.rate);
  }
}

Node* scan_films(Node *head) {
  FILE *films = fopen("films.txt", "r");
  if (films == NULL) {//проверка на существование файла
    printf("Текстового файла с фильмами не существует(");
    return 0;
  }
  movie Film;
  while(!feof(films)) {
    fgets(Film.name, 100, films); // name
    Film.name[strcspn(Film.name, "\n")] = 0;
    fgets(Film.date, 10, films); // date
    Film.date[strcspn(Film.date, "\n")] = 0;
    fgets(Film.country, 100, films); //страна
    Film.country[strcspn(Film.country, "\n")] = 0;
    fgets(Film.genre, 100, films); //;жанр
    Film.genre[strcspn(Film.genre, "\n")] = 0;
    fgets(Film.rate, 10, films); //рейтинг
    Film.rate[strcspn(Film.rate, "\n")] = 0;
  
    insert(head, Film);
  }
  fclose(films);
  return head;
}

void print_cards_films(Node *head) {
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 83; j++) {
      //левая карточка
      if (((i == 2) || (i == 17)) && j < 25) {
        printf("_");
      } else if (j == 25 && i > 2 && i < 18) {
        printf("|");
      }
      // средняя карточка
      else if ((i == 0 || i == 19) && j > 28 && j < 53) {
        printf("_");
      } else if ((j == 28 || j == 53) && i != 0) {
        printf("|");
      }
      // правая карточка
      else if (((i == 2) || (i == 12)) && j > 56 && j < 82) {
        printf("_");
      } else if ((j == 57 || j == 82) && (i > 2) && (i < 14)) {
        printf("|");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}


int main(void) {
  // setlocale(LC_ALL,"ru");

  //считывание фильмов
  Node *head = init();
  scan_films(head);

  //список избранного

  char request[10];
  strcpy(request, pageAutho());
  return 0;
}
