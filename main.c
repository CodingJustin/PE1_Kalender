/*Kalender-Programm*/

#define _CRT_SECURE_NO_WARNINGS 1

//Benötigte Bibliotheken
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

//Funktion zur Berechnung der Kalenderwoche (ZUSATZAUFGABE)
unsigned getCalenderWeek(unsigned day, unsigned month, unsigned year) {
    unsigned daysOfTheYear = day_Number(day, month, year);
    unsigned weekdayOfFirstJanuary = weekdayDate(1, 1, year);

    if(weekdayOfFirstJanuary >= 5) {
        weekdayOfFirstJanuary = weekdayOfFirstJanuary - 7;
    }
    if((daysOfTheYear + weekdayOfFirstJanuary) <= 1) {
        return getCalenderWeek(31, 12, year - 1);
    }

    unsigned calendarWeek = ((daysOfTheYear + weekdayOfFirstJanuary + 5) / 7);

    if(calendarWeek == 53) {
        if ((weekdayOfFirstJanuary != 4)
            && (weekdayOfFirstJanuary != -3)
            && ((weekdayOfFirstJanuary != 3) && is_leapYear(year))
            && ((weekdayOfFirstJanuary != -4) && is_leapYear(year)))
            calendarWeek = 1;

    }

    return calendarWeek;
}
//---------------------------------------------------------------------------------------------------------------------

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
        printf("\nDer %d.%d ist der %d-te Tag im Jahr %d.\n", day, month, day_Number(day, month, year), year);
//---------------------------------------------------------------------------------------------------------------------
        //Aufgabe 4 (Erster Wochentag des Jahres)
        if(year > 1900 && year <= 2100) {
            printf("Der Wochentag des 1.1 des Jahres %d: %s\n", year, dayNames[firstweekdayYear(year)]);
        }
//---------------------------------------------------------------------------------------------------------------------
        //Aufgabe 5 (Wochentag des Datums)
        printf("Wochentag des %d.%d.%d: %s\n", day, month, year, dayNames[weekdayDate(day, month, year)]);
//---------------------------------------------------------------------------------------------------------------------
        //Zusatzaufgabe (Kalenderwoche)
        printf("Kalenderwoche des %d.%d.%d: %d\n", day, month, year, getCalenderWeek(day, month, year));
//---------------------------------------------------------------------------------------------------------------------

        printf("----------------------------------------");
        printf("\n\nErneute Eingabe? (j/n)");
        response = ' ';
        scanf("%c", &response);
        while(getchar() != '\n');
    } while(response == 'j' || response == 'J');
    printf("Kalender beendet!\n");
}