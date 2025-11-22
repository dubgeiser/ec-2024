#include <stdio.h>

int main(void) {
    char c;
    int p1 = 0;
    FILE *f = fopen("data/01-1.dat", "r");
    if (f == NULL) {
        perror("Error opening file");
        return 1;
    }
    while (EOF != (c = fgetc(f))) {
        switch (c) {
            case 'A': break;
            case 'B': p1++; break;
            case 'C': p1 += 3; break;
        }
    }
    fclose(f);
    printf("%d", p1);
    return 0;
}
