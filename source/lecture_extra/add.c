#include <stdio.h>

// 関数のプロトタイプ（原型）宣言
int calc(int a, int b, char op);
int add(int n, int m);

int main(int argc, char const *argv[]) {
  char op = '+';
  int num1 = 3;
  int num2 = 5;
  int answer;

  answer = calc(num1, num2, op);
  printf("%d\n", answer);
  return 0;
}

int calc(int a, int b, char op) {
  int ans;
  if (op == '+') {
    // ans = a + b;
    ans = add(a, b);
  } else if (op == '-') {
    ans = a - b;
  } else if (op == '*') {
    ans = a * b;
  } else if (op == '/') {
    ans = a / b;
  }

  switch (op) {
  case '+':
    ans = a + b;
    break;
  case '-':
    ans = a - b;
    break;
  case '*':
    ans = a * b;
    break;
  case '/':
    ans = a / b;
    break;
  }

  return ans;
}

int add(int n, int m) { return n + m; }
