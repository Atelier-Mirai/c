#include <stdio.h>

int main(int argc, char const *argv[]) {
  char mark_1[][5] = {"zyx", "wv23", "utsr", "qpo", "nmlk"};
  char *mark_2[5] = {"cba@#!", "Xd", "ihgf", "lkj", "ponm"};
  char *pt_1, **pt_2;

  pt_1 = *mark_1;
  printf(" mark_1   : %p\n", mark_1);
  printf("&mark_1[0]: %p\n", &mark_1[0]);
  printf("pt_1      : %p\n", pt_1);

  printf("mark_1[1]      : %p\n", mark_1[1]);
  printf("mark_1[1]      : %s\n", mark_1[1]);
  printf("mark_1[2]      : %p\n", mark_1[2]);
  printf("mark_1[2]      : %s\n", mark_1[2]);
  printf("mark_1[1] + 1  : %s\n", mark_1[1] + 1);
  printf("mark_1[2] + 1  : %s\n", mark_1[2] + 1);
  printf("pt_1           : %s\n", pt_1);
  printf("pt_1 + 1       : %p\n", pt_1 + 1);
  printf("pt_1 + 1       : %s\n", pt_1 + 1);

  //  char *mark_2[5]  = { "cba", "ed", "ihgh", "lkj", "ponm" };
  /*char ** */ pt_2 = mark_2;
  printf("pt_2           : %p\n", pt_2);
  printf("mark_2         : %p\n", mark_2);
  printf("*pt_2          : %p\n", *pt_2);
  printf("mark_2[0]      : %p\n", mark_2[0]);
  printf("*pt_2          : %s\n", *pt_2);
  printf("mark_2[0]      : %s\n", mark_2[0]);
  printf("*pt_2 + 2      : %s\n", *pt_2 + 2);
  printf("**pt_2 + 2     : %c\n", **pt_2 + 2);
  printf("**pt_2 + 0     : %c\n", **pt_2 + 0);
  printf("**pt_2 + 3     : %c\n", **pt_2 + 3);
  printf("*(pt_2 + 2) + 0: %s\n", *(pt_2 + 2) + 0);
  printf("pt_2[2]     + 0: %s\n", pt_2[2] + 0);
  printf("*(pt_2 + 2) + 2: %s\n", *(pt_2 + 2) + 2);

  return 0;
}
