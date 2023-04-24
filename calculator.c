#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

void addYellowColor ();
void addRedColor ();
void removeColors ();
void printWelcomeMessage ();
void printError (char message[]);

int main (void) {
  float valueOne;
  float valueTwo;
  char operator;
  float answer;

  printWelcomeMessage();

  int validInput = 0;
  do {
    if (scanf("%f %c %f", &valueOne, &operator, &valueTwo) != 3) {
      printError("Invalid input");
      printf("Info: Please enter in the format [number] [operator] [number]\n");
      while(getchar() != '\n');
      continue;
    }
    if (!isdigit(operator) && operator != '+' && operator != '-' && operator != '*' && operator != '/' && operator != '^' && operator != ' ') {
      printError("Invalid operator");
      printf("Info: Please enter a valid operator (+, -, *, /, ^, or space for square root)\n");
      while(getchar() != '\n');
      continue;
    }
    if (operator == ' ' && valueOne < 0) {
      printError("Square root of negative number is not defined");
      printf("Info: Please enter a positive number for square root\n");
      while(getchar() != '\n');
      continue;
    }
    validInput = 1;
  } while (!validInput);

  switch(operator) {
    case '/': 
      if (valueTwo == 0) {
        printError("Division by zero");
        printf("Info: Try again\n");
        return 1;
      }
      answer = valueOne/valueTwo;
      break;
    case '*': 
      answer = valueOne*valueTwo;
      break;
    case '+': 
      answer = valueOne+valueTwo;
      break;
    case '-': 
      answer = valueOne-valueTwo;
      break;
    case '^': 
      answer = pow(valueOne, valueTwo);
      break;
    case ' ': 
      answer = sqrt(valueTwo);
      break;
    default: 
      printError("Invalid operator");
      printf("Info: Try again\n");
      return 1;
  }

  printf("\n");
  printf("You result is: %.9g %c %.9g = %.6g\n", valueOne, operator, valueTwo, answer);
  printf("\n");

  return 0;
}


void addYellowColor () {
  printf("\033[1;33m");
}

void addRedColor () {
  printf("\033[1;31m");
}

void removeColors () {
  printf("\033[0m");
}

void printError (char message[]) {
  printf("\n");
  addRedColor();
  printf("Error: %s\n", message);
  removeColors();
  printf("\n");
}

void printWelcomeMessage () {
  addYellowColor();
  printf("Info: Welcome to the Calculator!\n");
  printf("Info: Please use format: [number] [operator] [number]\n");
  printf("Info: For example: 3 * 3\n");
  printf("\n");
  removeColors();
}