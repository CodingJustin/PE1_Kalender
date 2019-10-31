
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


//Funktion die testet, ob das eingegebene Jahr ein Schaltjahr ist.
bool schaltjahr = false;
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

//Funktion die testet, ob das eigegebene Datum korrekt ist.
bool validDate = true;
void is_correctDate(unsigned day, unsigned month) {
    if(month >= 1 && month <= 12) {
            if((day>=1 && day<=31) && (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)) {
                printf("Eingegebenes Datum ist gueltig.\n");
                validDate = true;
            }
            else if((day>=1 && day<=30) && (month==4 || month==6 || month==9 || month==11)) {
                printf("Eingegebenes Datum ist gueltig.\n");
                validDate = true;
            }
            else if((day>=1 && day<=28) && (month==2)) {
                printf("Eingegebenes Datum ist gueltig.\n");
                validDate = true;
            }
            else if(day==29 && month==2 && schaltjahr == true) {
                printf("Eingegebenes Datum ist gueltig.\n");
                validDate = true;
            }
            else {
                printf("Eingegebener Tag ist ungueltig.\n");
                validDate = false;
            }
    }
    else {
        printf("Eingegebener Monat ist ungueltig.\n");
        validDate = false;
    }
}

//Funktion zur Berechnung der Tagesnummer im Jahr
int dayNum, i, diffNum;
unsigned monthLength[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 21};
unsigned day_Number(unsigned day, unsigned month, unsigned year) {
    dayNum = 0;
    diffNum = 0;
    if(schaltjahr == true) {
        monthLength[1] = 29;
    }
    for(i = 0; i < month; i++) {
        dayNum = monthLength[i] + dayNum;
    }
    diffNum = monthLength[month - 1] - day;
    dayNum = dayNum - diffNum;

    printf("Der %d.%d ist der %d-te Tag im Jahr %d.", day, month, dayNum, year);
}



int main() {

    unsigned day, month, year;
    char response;

    printf("\n\nKalender-Programm\n");
    printf("----------------------------------------\n");

    do {
        do {
            do {
                day = 0;
                month = 0;
                year = 0;
                printf("Geben Sie ein Datum ein [TT.MM.JJJJ]: ");
                scanf("%d.%d.%d", &day, &month, &year);
                while (getchar() != '\n');
                if (day == 0 || month == 0 || year == 0) {
                    printf("\nSie haben ein ungueltiges Datum eingegeben.\nBitte korrigieren Sie ihre Eingabe.\n");
                }
            } while(day == 0 || month == 0 || year == 0);

            printf("\nIhr eingegebenes Datum lautet: %d.%d.%d\n", day, month, year);

            is_leapYear(year);

            is_correctDate(day, month);

        } while (validDate == false);

        day_Number(day, month, year);

        printf("\n\nErneute Eingabe? (j/n)");
        response = ' ';
        scanf("%c", &response);
        while(getchar() != '\n');
    } while(response == 'j' || response == 'J');

}