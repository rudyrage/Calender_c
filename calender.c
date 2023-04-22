#include <stdio.h>
#include <stdlib.h>

int day_number(int day, int month, int year);
int is_leap_year(int year);
void month_name(int month);
void print_calender(int day, int month, int year);


int main(void) {
   int year;
   printf("enter year: ");
   scanf("%d", &year);

   putchar('\n');
   for (int i = 1; i <= 12; i++) {
      print_calender(1, i, year);
   }
   return 0;
}

int day_number(int day, int month, int year) {
   int t[] = {
               0, 3, 2, 5, 0, 3,
               5, 1, 4, 6, 2, 4
             };

   year -= month < 3;
   return (year + year / 4
         - year / 100
         + year / 400
         + t[month - 1] + day)
     % 7;
}

int is_leap_year(int year) {
   return (!(year % 100) && !(year % 4) && year % 400);
}

void month_name(int month) {
   switch(month) {
      case 1:
         printf("%22s\n", "January");
         break;
      case 2:
         printf("%22s\n", "February");
         break;
      case 3:
         printf("%22s\n", "March");
         break;
      case 4:
         printf("%22s\n", "April");
         break;
      case 5:
         printf("%22s\n", "May");
         break;
      case 6:
         printf("%22s\n", "June");
         break;
      case 7:
         printf("%22s\n", "July");
         break;
      case 8:
         printf("%22s\n", "August");
         break;
      case 9:
         printf("%22s\n", "September");
         break;
      case 10:
         printf("%22s\n", "October");
         break;
      case 11:
         printf("%22s\n", "November");
         break;
      case 12:
         printf("%22s\n", "December");
         break;

   }
}

void print_calender(int day, int month, int year) {
   month_name(month);
   printf
      (
         "%5s%5s%5s%5s%5s%5s%5s",
         "Sun", "Mon", "Tue",
         "Wed", "Thu", "Fri", "Sat"
      );

   putchar('\n');


   int curr = day_number(day, month, year);
   int total_days;

   switch (month) {
      case 1: case 3: case 5: case 7: case 8: case 10: case 31:
         total_days = 31;
         break;

      case 4: case 6: case 9: case 11:
         total_days = 30;
         break;

      case 2:
         if (is_leap_year(year))
            total_days = 29;
         else
            total_days = 28;
         break;
   }

   for (int i = 0; i < curr; i++) {
      printf("%4s ", " ");
   }


   for (int i = curr, j = 1; i < total_days+curr; i++) {
      if (i % 7 == 0)
         putchar('\n');
      printf("%4d ", j++);
   }

   printf("\n\n\n");
}
