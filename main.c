#include "authorization.h"
#include "pages.h"


#define len 60
#define PUR printf("\033[1;35m");
#define WHT printf("\33[0m");
#define Back printf("\033[100m");

// \u250f - левый верхний угол
// \u2513 - правый верхний угол
// \u2517 - левый нижний угол
// \u251b - правый нижний угол
// \u2501 - горизонтальная прямая
// \u2503 - вертикальная прямая
// \u2B9C - стрелка влево
// \u2B9E - стредка вправо

struct user {
  char name[20];
  char login[20];
  char password[20];
  char bankaccount[17];
  int fav_value;
  int isadmin;
};

typedef struct movie {
    char name[100];
    char date[10];
    char country[100];
    char genre[100];
    char rate[10];
    int count;
}movie;

typedef struct Node {
    struct Node *next;
    struct Node *prev;
    movie Film;
}Node; 

Node* init(){
    Node *list;
    list = (Node*)malloc(sizeof(Node));
    // list->Film = Film;
    list->next = list;
    list->prev = list;
    return(list);
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
        printf("%s %s %s %s %s\n", p->Film.name, p->Film.date, p->Film.country, p->Film.genre, p->Film.rate);
        p = p->next;
    } while (p != head);
}

void list_print_back(Node *head) {
    for(Node *p = head->prev; p != head; p = p->prev) {
        printf("%s %s %s %s %s\n", p->Film.name, p->Film.date, p->Film.country, p->Film.genre, p->Film.rate);
    }
}

Node* scan_films(Node *head) {
  FILE *films = fopen("films.txt", "r");
  if (films == NULL) {//проверка на существование файла
    printf("Текстового файла с фильмами не существует(");
    return 0;
  }
  int count = 1;
  movie Film;
  while(!feof(films)) {
    fgets(Film.name, 100, films); // name
    Film.name[strcspn(Film.name, "\n")] = 0;
    fgets(Film.date, 6, films); // date
    Film.date[strcspn(Film.date, "\n")] = 0;
    fgets(Film.country, 100, films); //страна
    Film.country[strcspn(Film.country, "\n")] = 0;
    fgets(Film.genre, 100, films); //;жанр
    Film.genre[strcspn(Film.genre, "\n")] = 0;
    fgets(Film.rate, 10, films); //рейтинг
    Film.rate[strcspn(Film.rate, "\n")] = 0;
    Film.count = count;
    count += 1;
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
      // Окно кинотеатра
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
        // личный кабинет
      else if ((j == 43 || j == 58) && i == 2) {
        PUR
        printf("\u2503");//вертикальная линия
        WHT
      }
      else if ((i == 1 || i == 3) && (j > 43 && j < 58)) {
        PUR
        printf("\u2501");//горизонтальная линия
        WHT
      }
      else if (j == 43 && i == 1) {
        PUR
        printf("\u250f");//левый верхний угол
        WHT
      }
      else if (j == 43 && i == 3) {
        PUR
        printf("\u2517");//левый нижний угол
        WHT
      }
      else if (j == 58 && i == 1) {
        PUR
        printf("\u2513");//правый верхний угол
        WHT
      }
      else if (j == 58 && i == 3) {
        PUR
        printf("\u251b");//правый нижний угол
        WHT
      }
      else if (j == 44 && i == 2) {
        PUR
        printf("Л");
      }
      else if (j == 45 && i == 2) {
        printf("И");
      }
      else if (j == 46 && i == 2) {
        printf("Ч");
      }
      else if (j == 47 && i == 2) {
        printf("Н");
      }
      else if (j == 48 && i == 2) {
        printf("Ы");
      }
      else if (j == 49 && i == 2) {
        printf("Й");
      }
      else if (j == 50 && i == 2) {
        printf(" ");
      }
      else if (j == 51 && i == 2) {
        printf("К");
      }
      else if (j == 52 && i == 2) {
        printf("А");
      }
      else if (j == 53 && i == 2) {
        printf("Б");
      }
      else if (j == 54 && i == 2) {
        printf("И");
      }
      else if (j == 55 && i == 2) {
        printf("Н");
      }
      else if (j == 56 && i == 2) {
        printf("Е");
      }
      else if (j == 57 && i == 2) {
        printf("Т");
        WHT
      }
      else{
        printf(" ");
      }
    }
    printf("%d", i);
    printf("\n");
  }
  
}

int main(void){
    setlocale(LC_ALL,"");
    Node *head = init();
    head = scan_films(head);
    // print_window();


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
      user1 = signup();
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
