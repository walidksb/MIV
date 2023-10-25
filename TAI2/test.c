#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include <sys/wait.h>

void P1() {

    printf("p1\n");
    FILE *evenFile = fopen("even_numbers.txt", "w");
    FILE *file = fopen("numbers.txt", "r");

    if (evenFile == NULL || file == NULL) {
        perror("Error opening files");
        exit(1);
    }

    int num;
    while (fscanf(file, "%d", &num) != EOF) {
        if (num % 2 == 0) {
            fprintf(evenFile, "%d\n", num);
        }
    }

    fclose(file);
    fclose(evenFile);

    exit(0);
}

void P2() {

    printf("p2\n");
    FILE *oddFile = fopen("odd_numbers.txt", "w");
    FILE *file = fopen("numbers.txt", "r");

    if (oddFile == NULL || file == NULL) {
        perror("Error opening files");
        exit(1);
    }

    int num;
    while (fscanf(file, "%d", &num) != EOF) {
        if (num % 2 != 0) {
            fprintf(oddFile, "%d\n", num);
        }
    }

    fclose(file);
    fclose(oddFile);

    exit(0);
}

void P3() {

    printf("p3\n");
    FILE *evenFile = fopen("even_numbers.txt", "r");
    if (evenFile == NULL) {
        perror("Error opening even_numbers.txt");
        exit(1);
    }

    int num;
    while (fscanf(evenFile, "%d", &num) != EOF) {
        printf("Even: %d\n", num);
    }

    fclose(evenFile);

    exit(0);
}

void P4() {

    printf("p4\n");
    FILE *oddFile = fopen("odd_numbers.txt", "r");
    if (oddFile == NULL) {
        perror("Error opening odd_numbers.txt");
        exit(1);
    }

    int num;
    while (fscanf(oddFile, "%d", &num) != EOF) {
        printf("Odd: %d\n", num);
    }

    fclose(oddFile);

    exit(0);
}

void P(void) {
    int id1, id2, id3, id4;

    // Create the numbers.txt file in the parent process
    FILE *file = fopen("numbers.txt", "w");
    if (file == NULL) {
        perror("Error creating numbers.txt");
        exit(1);
    }

    for (int i = 1; i <= 100; i++) {
        fprintf(file, "%d\n", i);
    }

    fclose(file);

    printf("le pere\n");

    id1 = fork();
    if (id1 == 0)
        P1();
    id2 = fork();
    if (id2 == 0)
        P2();
    wait(0); wait(0);

    printf("2éme partie\n");

    id3 = fork();
    if (id3 == 0)
        P3();
    id4 = fork();
    if (id4 == 0)
        P4();
    wait(0); wait(0);

    printf("fini\n");
}

int main(int argc, char *argv[]) {
    P();

    return 0;
}