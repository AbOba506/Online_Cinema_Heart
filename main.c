#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//
//
//
//

typedef struct movie {
  char name[100];
  char date[6];
  char country[30];
  char genre[100];
  char rate[5];
} movie;

typedef struct Node {
  struct Node *next;
  struct Node *prev;
  movie Film;
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
  tmp->Film = Film;
  tmp->prev = head;
  tmp->next = q;
  q->prev = tmp;
}

void list_print(Node *head) {
  Node *p;
  p = head;
  do {
    printf("%s %s %s %s %s\n", p->Film.name, p->Film.date, p->Film.country,
           p->Film.genre, p->Film.rate);
    p = p->next;
  } while (p != head);
}

void list_print_back(Node *head) {
  for (Node *p = head->prev; p != head; p = p->prev) {
    printf("%s %s %s %s %s\n", p->Film.name, p->Film.date, p->Film.country,
           p->Film.genre, p->Film.rate);
  }
}

Node* scan_films(FILE *films, Node *head) {
  struct movie Film;
  char arr[100];
  while(feof(films) != 0) {
    fgets(arr, sizeof(Film.name), films); // name
    strcpy(Film.name, arr);
    fgets(arr, sizeof(Film.date), films); // date
    strcpy(Film.date, arr);
    fgets(arr, sizeof(Film.country), films); //страна
    strcpy(Film.country, arr);
    fgets(arr, sizeof(Film.genre), films); //;жанр
    strcpy(Film.genre, arr);
    fgets(arr, sizeof(Film.rate), films); //рейтинг
    strcpy(Film.rate, arr);
    insert(head, Film);
  }
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

// void print_()
int main(void) {
  // setlocale(LC_ALL,"ru");

  //считывание фильмов
  
  Node *head = init();
  FILE *films = fopen("films.txt", "r");
  if (films == NULL) {//проверка на существование файла
    printf("Текстового файла с фильмами не существует(");
    return 0;
  }

  head = scan_films(films, head);
  list_print(head);
  // print_cards_films(head);
  fclose(films);
  return 0;
}