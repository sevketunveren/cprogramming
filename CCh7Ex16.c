#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bit_print.h"

void parseDate(char*, unsigned char*, unsigned char*, unsigned char*);
unsigned short pack(unsigned char, unsigned char, unsigned char);
void unpack(unsigned short, unsigned char*, unsigned char*, unsigned char*);

int main(){
    char strDate[10];
    unsigned char day, month, year;
    unsigned short date;
    printf("Enter date in this format dd/MM/yyyy: ");
    scanf("%s", strDate);
    parseDate(strDate, &day, &month, &year);
    date = pack(day, month, year);
    bit_print(date);
    //date = 0b1010001010110101;//20/5/1953
    unpack(date, &day, &month, &year);
    printf("%d/%d/19%d\n", day, month, year);
    return 0;
}

void parseDate(char* strDate, unsigned char* day, unsigned char* month, unsigned char* year){
    const char delimiter[] = "/";
    char* ptr = strtok(strDate, delimiter);
    char counter = 1;
    while(ptr != NULL)
    {
        switch (counter++) {
            case 1:
                *day = atoi(ptr);
            break;
            case 2:
                *month = atoi(ptr);
            break;
            case 3:
                *year = atoi(ptr);
                *year -=1900;
            break;
        default:
                printf("Error while parsing date\n");
            break;
        }
        ptr = strtok(NULL, delimiter);
    }
    free(ptr);
}

unsigned short pack(unsigned char day, unsigned char month, unsigned char year){
    unsigned short date = 0x0000000000000000; //16 bits
    date |= day;
    date <<= 4;
    date |= month;
    date <<=7;
    return date | year;
}

void unpack(unsigned short date, unsigned char* day, unsigned char* month, unsigned char* year){
    *year = date & 127;
    date >>=7;
    *month = date & 15;
    date >>=4;
    *day = date;
}
