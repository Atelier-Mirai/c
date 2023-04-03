#include <stdio.h>
#include <string.h>

typedef struct {
  char name[20];
  int age;
} user;

int main(int argc, char const *argv[]) {
  user person;
  char name[20];
  int age;

  printf("名前を入れてください\n");
  // scanf("%s", name);
  scanf("%s", person.name);

  printf("年齢を入れてください\n");
  // scanf("%d", age);
  // scanf("%d", &age);
  scanf("%d", &person.age);

  // printf("%sさん %d 才ですね\n", name, age);
  printf("%sさん %d 才ですね\n", person.name, person.age);

  return 0;
}
