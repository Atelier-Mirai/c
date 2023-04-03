/**********************************************************
 * 構造体(structure)
 *********************************************************/
#include <stdio.h>
#include <string.h>

typedef struct {
  int x0, y0, x1, y1;
  double area;
} rectangle;

double square_area(rectangle r) { return (r.x1 - r.x0) * (r.y1 - r.y0); }

int main(int argc, char const *argv[]) {
  rectangle rect[3];
  int number[3];
  rect[0].x0 = 100;
  rect[0].y0 = 100;
  rect[0].x1 = 500;
  rect[0].y1 = 800;

  rect[1].x0 = 400;
  rect[1].y0 = 600;
  rect[1].x1 = 800;
  rect[1].y1 = 1000;

  rect[2].x0 = 400;
  rect[2].y0 = 600;
  rect[2].x1 = 500;
  rect[2].y1 = 800;

  rect[0].area = square_area(rect[0]);
  printf("面積: %5.2f\n", rect[0].area);
  rect[1].area = square_area(rect[1]);
  printf("面積: %5.2f\n", rect[1].area);
  rect[2].area = square_area(rect[2]);
  printf("面積: %5.2f\n", rect[2].area);

  return 0;
}
