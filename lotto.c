#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// reads one number between 1 and 49, returns -1 if its wrong
int readNumber() {
    int n;
    printf("Pick a number between 1 and 49: ");
    if (scanf("%d", &n) != 1) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF); // clear wrong input
        return -1;
    }
    if (n < 1 || n > 49) return -1;
    return n;
}

void play() {
    int win[3], pick[3];

    // 3 random winning numbers
    for (int i = 0; i < 3; i++) {
        win[i] = rand() % 49 + 1;
    }

    for (int i = 0; i < 3; i++) {
        pick[i] = readNumber();
        if (pick[i] == -1) {
            printf("Sorry, that is not a valid number\n\n");
            return;
        }
    }

    // count how many numbers are right
    int hits = 0;
    for (int i = 0; i < 3; i++) {
        if (pick[i] == win[i]) hits++;
    }

    printf("Winning numbers: %d %d %d\n", win[0], win[1], win[2]);

    if (hits == 3)      printf("Congrats, you won 100 EUR!\n\n");
    else if (hits == 2) printf("Congrats, you won 70 EUR!\n\n");
    else if (hits == 1) printf("Congrats, you won 30 EUR!\n\n");
    else                printf("Sorry, you lost...\n\n");
}

int playAgain() {
    char answer[5];
    printf("Play again? (yes/no): ");
    if (scanf("%4s", answer) != 1) return 0;
    if (strcmp(answer, "yes") == 0 || strcmp(answer, "y") == 0) return 1;
    printf("Thanks for playing\n");
    return 0;
}

int main() {
    srand(time(NULL));
    printf("Welcome to the lottery!\n\n");

    do {
        play();
    } while (playAgain());

    return 0;
}
