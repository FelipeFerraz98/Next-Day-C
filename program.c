#include <stdio.h>

int main(void) {
  int day, year, month, february=0, trade=0;
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
  if (month == 2 && trade == 0){

    if (day == 28 || day == 29){
    
    //Leap year analysis
        if (year % 400 == 0 || year % 4 == 0){
            if (day == 29){
                day = 1;
                month++;
                trade = 1;
              }
        

            else{
                day = day + 1;
                trade = 1;
              }
        }
    }
      
        
    //If the year is not a leap year
    if (day == 28 || day == 29 && trade == 0){
      if(day == 29){
        day = 1;
        month++;
        trade = 1;
        printf("The year is not a leap year, so there is no day 29, the next day after the 28 will be: %d/%d/%d", month, day, year);
        february = 1;
        //Day 29 does not exist so the program ends here showing the possible next day
      }
    else{
    day = 1;
    month++;
    trade = 1;
      }
      
    }

    //Normal day
    if (day < 28 && trade == 0){
        day++;
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

  
  if (february == 0){
    printf("\nThe next day: %d/%d/%d", month, day, year);
  }
  
  return 0;
}
