/*TODO: 3.Zusatzaufgabe: Berechnen Sie, in welcher Kalenderwoche der gegebene Tag ist (nach ISO 8601).*/

#define _CRT_SECURE_NO_WARNINGS 1
//Benötigte Bibliotheken
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//Benötigte Arrays
char dayNames[] [11] = {"Montag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag", "Samstag", "Sonntag"};
unsigned monthLength[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 21};

//---------------------------------------------------------------------------------------------------------------------

//Bool-Funktion die testet, ob das eingegebene Jahr ein Schaltjahr ist. (AUFGABE 1)
bool is_leapYear(unsigned year) {
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
        return true;
    }
    else {
        return false;
    }
}

//---------------------------------------------------------------------------------------------------------------------

//Methode die testet, ob das eingegebene Datum korrekt ist. (AUFGABE 2)
bool validDate;
void is_correctDate(unsigned day, unsigned month, unsigned year) {
    if(month >= 1 && month <= 12) {
        if((day >= 1 && day <= 31) && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)) {
            validDate = true;
        }
        else if((day >= 1 && day <= 30) && (month == 4 || month == 6 || month == 9 || month == 11)) {
            validDate = true;
        }
        else if((day >= 1 && day <= 28) && (month == 2)) {
            validDate = true;
        }
        else if(day == 29 && month == 2 && is_leapYear(year) == true) {
            validDate = true;
        }
        else {
            printf("\nIhr eingegebener Tag ist ungueltig.\nBitte korrigieren Sie Ihre Eingabe.\n");
            validDate = false;
        }
    }
    else if(day > 31 && month > 12) {
        printf("\nIhr eingegebener Tag und Monat sind ungueltig.\nBitte korrigieren Sie Ihre Eingabe.\n");
        validDate = false;
    }
    else {
        printf("\nIhr eingegebener Monat ist ungueltig.\nBitte korrigieren Sie Ihre Eingabe.\n");
        validDate = false;
    }
}

//---------------------------------------------------------------------------------------------------------------------

//Methode zur Berechnung der Tagesnummer im Jahr. (AUFGABE 3)
void day_Number(unsigned day, unsigned month, unsigned year) {
    int dayNum = 0, diffNum =0, i;

    if(is_leapYear(year) == true) {
        monthLength[1] = 29;
    }
    for(i = 0; i < month; i++) {
        dayNum = monthLength[i] + dayNum;
    }
    diffNum = monthLength[month - 1] - day;
    dayNum = dayNum - diffNum;

    printf("\nDer %d.%d ist der %d-te Tag im Jahr %d.\n", day, month, dayNum, year);
}

//---------------------------------------------------------------------------------------------------------------------

//Methode zur Berechnung des Wochentages des 1.1 des jeweiligen Jahres. (AUFGABE 4)
void firstweekdayYear(unsigned year) {
    int i, rest, weekday = 1; // 1 = Dienstag

    for(i = 1901; i <= year; i++) {
        weekday++;
        if(is_leapYear(i - 1) == true) {
            weekday++;
        }
        if(weekday >= 7) {
            rest = weekday - 7;
            weekday = 0;
            weekday = weekday + rest;
        }
    }
    weekday = weekday - 1;
    if(weekday < 0) {
        weekday = 6;
    }
    printf("Der Wochentag des 1.1 des Jahres %d ist ein %s.\n", year, dayNames[weekday]);
}

//---------------------------------------------------------------------------------------------------------------------

//Methode zur Berechnung des Wochentages des eingegebenen Datums.
void weekdayDate(unsigned day, unsigned month, unsigned year) {
    unsigned int weekday = 0;

    weekday = (day  + ((153 * (month + 12 * ((14 - month) / 12) - 3) + 2) / 5)
               + (365 * (year + 4800 - ((14 - month) / 12)))
               + ((year + 4800 - ((14 - month) / 12)) / 4)
               - ((year + 4800 - ((14 - month) / 12)) / 100)
               + ((year + 4800 - ((14 - month) / 12)) / 400)
               - 32045) % 7;

    printf("Der %d.%d.%d ist ein %s.\n", day, month, year, dayNames[weekday]);
}

//Start der Main-Funktion
int main() {

    //Benötigte Variablen
    unsigned day, month, year;
    char response;

    printf("\n\nKalender-Programm\n");
    printf("----------------------------------------");

    do {
        do {
            do {
                day = 0;
                month = 0;
                year = 0;
                printf("\nGeben Sie ein Datum ein [TT.MM.JJJJ]:\n");
                scanf("%d.%d.%d", &day, &month, &year);
                while (getchar() != '\n');
                if (day == 0 || month == 0 || year == 0) {
                    printf("\nSie haben ein ungueltiges Datum eingegeben.\nBitte korrigieren Sie ihre Eingabe.\n");
                }
            } while(day == 0 || month == 0 || year == 0);

            printf("----------------------------------------");
            printf("\nIhr eingegebenes Datum lautet: %d.%d.%d\n", day, month, year);


            //Aufgabe 1 (Schaltjahr)
            is_leapYear(year);
            if(is_leapYear(year) == true) {
                printf("%d ist ein Schaltjahr.", year);
            }
            else {
                printf("%d ist kein Schaltjahr.", year);
            }
//---------------------------------------------------------------------------------------------------------------------
            //Aufgabe 2 (Korrektes Datum)
            is_correctDate(day, month, year);
            if(validDate == true) {
                printf("\nIhr eingegebenes Datum ist gueltig.");
            }
        } while (validDate == false);
//---------------------------------------------------------------------------------------------------------------------
        //Aufgabe 3 (Nummer des Tages im Jahr)
        day_Number(day, month, year);
//---------------------------------------------------------------------------------------------------------------------
        //Aufgabe 4 (Erster Wochentag des Jahres)
        if(year > 1900 && year <= 2100) {
            firstweekdayYear(year);
        }
//---------------------------------------------------------------------------------------------------------------------
        //Aufgabe 5 (Wochentag des Datums)
        weekdayDate(day, month, year);

        printf("----------------------------------------");
        printf("\n\nErneute Eingabe? (j/n)");
        response = ' ';
        scanf("%c", &response);
        while(getchar() != '\n');
    } while(response == 'j' || response == 'J');

}