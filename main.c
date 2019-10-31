
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool schaltjahr = false;
bool validDate = true;


void is_leapYear(unsigned year) {
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
        printf("%d ist ein Schaltjahr.\n", year);
        schaltjahr = true;
    }
    else {
        printf("%d ist kein Schaltjahr.\n", year);
        schaltjahr = false;

    }
}

void is_correctYear(unsigned day, unsigned month) {
    if(month >= 1 && month <= 12) {
            if((day>=1 && day<=31) && (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)) {
                printf("Datum ist gueltig.\n");
                validDate = true;
            }
            else if((day>=1 && day<=30) && (month==4 || month==6 || month==9 || month==11)) {
                printf("Datum ist gueltig.\n");
                validDate = true;
            }
            else if((day>=1 && day<=28) && (month==2)) {
                printf("Datum ist gueltig.\n");
                validDate = true;
            }
            else if(day==29 && month==2 && schaltjahr == true) {
                printf("Datum ist gueltig.\n");
                validDate = true;
            }
            else {
                printf("Tag ist ungueltig.\n");
                validDate = false;
            }
    }
    else {
        printf("Monat ist ungueltig.\n");
        validDate = false;
    }

}


int main() {

    unsigned day, month, year;
    char response;

    printf("\n\nKalender-Programm\n");
    printf("----------------------------------------\n");

    do {
        do {
            do {
                printf("Geben Sie ein Datum ein [TT.MM.JJJJ]: ");
                scanf("%d.%d.%d", &day, &month, &year);
                while (getchar() != '\n');
                if (day == 0 || month == 0 || year == 0) {
                    printf("\nSie haben ein ungueltiges Datum eingegeben. Bitte korrigieren Sie ihre Eingabe.\n");
                }
            } while(day == 0 || month == 0 || year == 0);

            printf("\nIhr eingegebenes Datum lautet: %d.%d.%d\n", day, month, year);

            is_leapYear(year);

            is_correctYear(day, month);

        } while (validDate == false);

        printf("\n\nErneute Eingabe? (j/n)");
        response = ' ';
        scanf("%c", &response);
        while(getchar() != '\n');
    } while(response == 'j' || response == 'J');

}
