#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  FILE *fp;
  char c;
  char str[8];

  if ((fp = fopen("sample.c", "r")) == NULL) {
    printf("file open error!");
    exit(1);
  }

  while ((c = getc(fp)) != EOF) {
    printf("%c", c);
  }
  fclose(fp);

  if ((fp = fopen("test.txt", "r")) == NULL) {
    printf("file open error!");
    exit(1);
  }

  while (fgets(str, 7, fp)) {
    printf("%s", str);
  }
  fclose(fp);
}
