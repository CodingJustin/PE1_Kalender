/*TODO: 3.Zusatzaufgabe: Berechnen Sie, in welcher Kalenderwoche der gegebene Tag ist (nach ISO 8601).*/

#define _CRT_SECURE_NO_WARNINGS 1
//Benötigte Bibliotheken
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//Benötigte Arrays
char dayNames[] [11] = {"Montag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag", "Samstag", "Sonntag"};
unsigned monthLength[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

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

//Funktion zur Berechnung der Tagesnummer im Jahr. (AUFGABE 3)
unsigned int day_Number(unsigned day, unsigned month, unsigned year) {
    int dayNum = 0, diffNum =0, i;

    if(is_leapYear(year) == true) {
        monthLength[1] = 29;
    }
    for(i = 0; i < month; i++) {
        dayNum = monthLength[i] + dayNum;
    }
    diffNum = monthLength[month - 1] - day;
    dayNum = dayNum - diffNum;

    return(dayNum);
}

//---------------------------------------------------------------------------------------------------------------------

//Funktion zur Berechnung des Wochentages des 1.1 des jeweiligen Jahres. (AUFGABE 4)
unsigned int firstweekdayYear(unsigned year) {
    int i, rest, firstWeekday = 1; // 1 = Dienstag

    for(i = 1901; i <= year; i++) {
        firstWeekday++;
        if(is_leapYear(i - 1) == true) {
            firstWeekday++;
        }
        if(firstWeekday >= 7) {
            rest = firstWeekday - 7;
            firstWeekday = 0;
            firstWeekday = firstWeekday + rest;
        }
    }
    firstWeekday = firstWeekday - 1;
    if(firstWeekday < 0) {
        firstWeekday = 6;
    }
    return(firstWeekday);
}

//---------------------------------------------------------------------------------------------------------------------

//Funktion zur Berechnung des Wochentages des eingegebenen Datums.
unsigned int weekdayDate(unsigned day, unsigned month, unsigned year) {
    unsigned int weekday = 0;

    weekday = (day  + ((153 * (month + 12 * ((14 - month) / 12) - 3) + 2) / 5)
               + (365 * (year + 4800 - ((14 - month) / 12)))
               + ((year + 4800 - ((14 - month) / 12)) / 4)
               - ((year + 4800 - ((14 - month) / 12)) / 100)
               + ((year + 4800 - ((14 - month) / 12)) / 400)
               - 32045) % 7;

    return(weekday);
}

//---------------------------------------------------------------------------------------------------------------------
/*
//Funktion zur Berechnung der Kalenderwoche (ZUSATZAUFGABE)
unsigned int calenderWeek(unsigned day, unsigned month, unsigned year) {
    int calenderWeek;

    calenderWeek = day_Number(day, month, year) / 7;

    if(calenderWeek == 0) {
        if (calenderWeek == 0 && weekdayDate(1, 1, year - 1) == 3 && weekdayDate(31, 12, year - 1) == 3
            || is_leapYear(year - 1) == true && weekdayDate(1, 1, year - 1) == 2 && weekdayDate(31, 12, year - 1) == 3
            ||
            is_leapYear(year - 1) == true && weekdayDate(1, 1, year - 1) == 3 && weekdayDate(31, 12, year - 1) == 4) {
            calenderWeek = 53;
        }
        else {
            calenderWeek = 52;
        }
    }

    return(calenderWeek);
}
*/


//Start der Main-Funktion
int main() {

    //Benötigte Variablen
    unsigned day, month, year;
    char response;
    unsigned int dayNum, firstWeekday, weekday, week;

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
        dayNum = day_Number(day, month, year);
        printf("\nDer %d.%d ist der %d-te Tag im Jahr %d.\n", day, month, dayNum, year);
//---------------------------------------------------------------------------------------------------------------------
        //Aufgabe 4 (Erster Wochentag des Jahres)
        if(year > 1900 && year <= 2100) {
            firstWeekday = firstweekdayYear(year);
            printf("Der Wochentag des 1.1 des Jahres %d ist ein %s.\n", year, dayNames[firstWeekday]);
        }
//---------------------------------------------------------------------------------------------------------------------
        //Aufgabe 5 (Wochentag des Datums)
        weekday = weekdayDate(day, month, year);
        printf("Der %d.%d.%d ist ein %s.\n", day, month, year, dayNames[weekday]);

//---------------------------------------------------------------------------------------------------------------------
       /* //Zusatzaufgabe (Kalenderwoche)
        week = calenderWeek(day, month, year);
        printf("Der %d.%d befindet sich in der %d-ten Kalenderwoche des Jahres %d.\n", day, month, week, year);
        */
//---------------------------------------------------------------------------------------------------------------------

        printf("----------------------------------------");
        printf("\n\nErneute Eingabe? (j/n)");
        response = ' ';
        scanf("%c", &response);
        while(getchar() != '\n');
    } while(response == 'j' || response == 'J');

}