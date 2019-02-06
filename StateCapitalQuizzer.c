/* Author: Nathan Gardner
   This program quizzes the user over the USA's state capitals.
   The program asks the user to enter a string using the fgets function.
   This function reads data until a null terminator is found, or the max
   character length is met minus one (to account for the null terminator). 
   The user's array of characters is then compared to the specific pointer 
   of the capital names' array using the string comparison function strcmp, 
   and then a value of 0 (false) is returned if they are equal. 
   This function takes the number of questions the user answered, 
   the number of questions the user correctly answered, and the percentage 
   of questions the user correctly answered, and prints these data items on the screen.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "statesAndCapitals.h"

int main() {
   srand(time(NULL));

   int sentinel = 1;
   char garbage;
   unsigned int question;
   unsigned int total_questions = 0, correct_answers = 0;
   char userAnswer[MAX_CAPITAL_LEN + 1] = {""};

   puts("Do you know your state capitals?");

   while (1 == sentinel) {
      question = rand() % 50;
      printf("\nWhat is the capital of %s?\n", states[question]);

      fgets(userAnswer, MAX_CAPITAL_LEN + 1, stdin);

      if (0 == strcmp(userAnswer, capitals[question])) {
         printf("You are correct. The capital of %s is %s\n", states[question], capitals[question]);
	 correct_answers++;
      } 
      else {
         printf("You are incorrect. The capital of %s is %s\n", states[question], capitals[question]);
      }

      total_questions++;

      puts("Enter 1 for another question, 0 to end.");
      scanf("%d", &sentinel);

      while (sentinel != 0 && sentinel != 1) {
         printf("You entered %d.  This is an incorrect value.\n", sentinel);
	 puts("Make sure to input a zero to quit or a 1 to continue\n");
	 puts("Enter 1 for another question, 0 to end.");
	      
	 scanf("%d", &sentinel)
      }

      scanf("%c", &garbage);//collect leftover text so that it is not absorbed into the next scanf
   }
   double percent = ((double)correct_answers / total_questions) * 100;
   printf("\nYou answered %d correctly out of %d for %f percent correct.", correct_answers, total_questions, percent);
   
   return 0;
}
