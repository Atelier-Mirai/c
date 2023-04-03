#include <stdio.h>

int main(int argc, char const *argv[]) {
  printf("EOF: %d\n", EOF);

  unsigned char uc = 0xff; // 255
  signed char sc = 0xff;   //  -1
  printf("uc: %d\n", uc);
  printf("sc: %d\n", sc);

  int i;
  double dsum = 0;
  for (i = 0; i < 100; i++) {
    dsum += 0.01;
  }
  printf("%.15f\n", dsum);

  float fsum = 0;
  for (i = 0; i < 10000000; i++) {
    fsum += 0.0000001;
  }
  printf("%.15f\n", fsum);

  return 0;
}
