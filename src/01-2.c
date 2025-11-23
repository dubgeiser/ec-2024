#include <stdio.h>

int score(char c) {
  switch (c) {
  case 'B':
    return 1;
  case 'C':
    return 3;
  case 'D':
    return 5;
  }
  return 0;
}

int score_pairs(char c1, char c2) {
  if (c1 == 'x') {
    return score(c2);
  }
  if (c2 == 'x') {
    return score(c1);
  }
  return score(c1) + score(c2) + 2;
}

int main(void) {
  FILE *f = fopen("data/01-2.dat", "r");
  if (NULL == f) {
    perror("Error opening file");
    return 1;
  }
  char c[2];
  int sum = 0;
  int n;
  while ((n = fread(c, 1, 2, f)) > 0) {
    sum += score_pairs(c[0], c[1]);
  }
  fclose(f);
  printf("%d", sum);
  return 0;
}
