
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <stdio.h>

int main() {
    unsigned day, month, year;
    char response;

    do {

        printf("Geben Sie ein Datum ein [TT.MM.JJJJ]: ");
        scanf("%d.%d.%d", &day, &month, &year);
        printf("\nIhr eingegebenes Datum lautet: %d.%d.%d\n", day, month, year);

        if (year % 4 == 0 && year != 1800 && year != 1900 && year != 2100 && year != 2200) {
            printf("%d ist ein Schaltjahr.", year);
        } else {
            printf("%d ist kein Schaltjahr.", year);
        }

        printf("\n\nErneute Eingabe? (j/n)");
        scanf("%c", &response);
        while(getchar() != '\n');
    } while(response == 'j' || response == 'J');

}