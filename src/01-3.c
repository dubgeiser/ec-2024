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

int score_triplets(char c1, char c2, char c3) {
  if (c1 == 'x') {
    return score_pairs(c2, c3);
  }
  if (c2 == 'x') {
    return score_pairs(c1, c3);
  }
  if (c3 == 'x') {
    return score_pairs(c1, c2);
  }
  return score(c1) + score(c2) + score(c3) + 6;
}

int main(void) {
  char c[3];
  int sum = 0;
  FILE *f = fopen("data/01-3.dat", "r");
  if (NULL == f) {
    perror("Error opening file");
    return 1;
  }
  while (EOF != (c[0] = fgetc(f))) {
    c[1] = fgetc(f);
    c[2] = fgetc(f); // we got 9000 (IT'S NOT OVER!)
    sum += score_triplets(c[0], c[1], c[2]);
  }
  fclose(f);
  printf("%d", sum);
  return 0;
}
