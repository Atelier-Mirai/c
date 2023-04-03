#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  /* code */
  int computer;

  srand(time(NULL));
  computer = rand() % 3 + 1;
  printf("コンピュータは %d: ", computer);

  if (computer == 1){
    printf("グー");
  } else if (computer == 2){
    printf("チョキ");
  } else {
    printf("パー");
  }

  return 0;
}
