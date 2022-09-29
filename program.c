#include <stdio.h>

int main(void) {
  int day, year, month, leapyear=0, trade=0;
  printf("Enter the date: mm/dd/yy: ");
  scanf("%d/%d/%d", &month,&day,&year);
  
 //Months with 31 days
  if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10){
    if(day == 31){
      day = 1;
      month++;
      trade = 1;
    }
    else{
      day++;
    }
  }

//Months with 30 days
  if(month == 4 || month == 6 || month == 9 || month == 11 && trade == 0){
    if(day == 30){
      day = 1;
      month++;
      trade = 1;
    }
    else{
      day++;
    }
  }

//February
  if(month == 2 && trade == 0){
    if(day == 28){
      day = 1;
      month++;
      trade = 1;
    }
    if(day < 28 && month == 2){
      day++;
    }
    
    //Leap year analysis
    if(day == 29){
      if(year % 400 == 0 || year % 4 == 0){
        day = 1;
        month++;
        trade = 1;
      }
        
      //If the year is not a leap year (leapyear=1)
      else{
        leapyear = 1;
      }
    }
  }

//December
  if(month == 12 && trade == 0){
    if(day == 31){
      day = 1;
      year++;
      month = 1;
    }
    else{
      day++;
    }
  }

  if(leapyear == 1){
    printf("Invalid date! The year is not a leap year");
  }
    
  else{
    printf("\nThe next day: %d/%d/%d", month, day, year);
  }
  
  return 0;
}
