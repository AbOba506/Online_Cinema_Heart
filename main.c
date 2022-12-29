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

void print_window(){
  Back
  printf("\u250f");
  for(int i = 0; i <= len/3; i++){
    Back
    for(int j = 0; j <= len+1; j++){
      Back
      if(i == 0 && j <= len-1){
        printf("\u2501");
        if(j == len-1){
          printf("\u2513");
          }
      }
      else if(i >= 1 && i!= len/3 && ((j == 0)||(j == len+1))){
        printf("\u2503");
      }
      // название кинотеатра HEART
      else if(i == 1 && j == 27){
        PUR
        printf("\u25b7");
      }
      else if(i == 1 && j == 28){
        printf("H");
      }
      else if(i == 1 && j == 29){
        printf("e");
      }
      else if(i == 1 && j == 30){
        printf("a");
      }
      else if(i == 1 && j == 31){
        printf("r");
      }
      else if(i == 1 && j == 32){
        printf("t");
      }
      else if(i == 1 && j == 33){
        printf("\u25c1");
        WHT
      } 
      // конец названия кинотеатра 
      else if(i == len/3 && j == 0){
        printf("\u2517");
      }
      else if(i == len/3 && (j > 0) && (j != len+1)){
        printf("\u2501");
      }
      else if(i == len/3 && j == len+1){
        printf("\u251b");
      }
      //карточки
      else if((j == 3 || j == 18 || j == 43 || j == 58) && (i>4 && i<16)){
        printf("\u2503");//вертикальная линия
      }
      else if((i == 4 || i == 16) && ((j>3 && j <18) || (j>43 && j<58))) {
        printf("\u2501");//горизонтальная линия
      }
      //углы левой
      else if (i == 4 && j == 3) {
        printf("\u250f");//левый верхний угол
      }
      else if (i == 4 && j == 18){
        printf("\u2513");//правый верхний угол
      }
      else if (i == 16 && j == 3) {
        printf("\u2517");//левый нижний угол
      }
      else if (i == 16 && j == 18) {
        printf("\u251b");//правый нижний угол
      }
      //углы правой
      else if (i == 4 && j == 43) {
        printf("\u250f");//левый верхний угол
      }
      else if (i == 4 && j == 58){
        printf("\u2513");//правый верхний угол
      }
      else if (i == 16 && j == 43) {
        printf("\u2517");//левый нижний угол
      }
      else if (i == 16 && j == 58) {
        printf("\u251b");//правый нижний угол
      }  
        //средняя карточка
      else if ((j == 21 || j == 40) && (i > 2 && i < 18)) {
        PUR
        printf("\u2503");//вертикальная линия
        WHT
      }
      else if ((i == 2 || i == 18) && (j > 21 && j < 40)) {
        PUR
        printf("\u2501");//горизонтальная линия
        WHT
      }
        //углы
      else if (i == 2 && j == 21) {
        PUR
        printf("\u250f");//левый верхний угол
        WHT
      }
      else if (i == 2 && j == 40){
        PUR
        printf("\u2513");//правый верхний угол
        WHT
      }
      else if (i == 18 && j == 21) {
        PUR
        printf("\u2517");//левый нижний угол
        WHT
      }
      else if (i == 18 && j == 40) {
        PUR
        printf("\u251b");//правый нижний угол
        WHT
      }  
        //стрелочки
      else if (j == 19 && i == 10) {
        printf("<");
      }
      else if (j == 20 && i == 10) {
        printf("=");
      }
      else if (j == 42 && i == 10) {
        printf(">");
      }
      else if (j == 41 && i == 10) {
        printf("=");
      }
        // фильмы
      // else if () {
        
      // }
      else{
        printf(" ");
      }
    }
    printf("\n");
  }
}

int main(void) {
  setlocale(LC_ALL,"ru");

  //считывание фильмов
  Node *head = init();
  head = scan_films(head);
  print_window();

  //список избранного

  char request[10];
  strcpy(request, pageAutho());
  return 0;
}
