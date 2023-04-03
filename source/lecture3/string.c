#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  // string subject0 = "Kokugo";
  char subject0[] = "Kokugo";
  char subject1[] = "Sansuu";

  // string subject[] =  { "Kokugo", "Sansuu" };
  char subject[][20] = {"Kokugo", "Sansuu"};
  int i;

  printf("%s\n", subject0);
  printf("%s\n", subject1);

  printf("%s\n", subject[0]);
  printf("%s\n", subject[1]);

  for (i = 0; i < 2; i++) {
    printf("%s\n", subject[i]);
  }

  return 0;
}
