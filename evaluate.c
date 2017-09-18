#include <stdio.h>
#include <stdlib.h>

/*
 * Author: Edward Kim
 * This program takes an input arithmetic expression and solves it.
 */


float s_exp(float sub_exp, char op), get_num();
char get_op();

int main(){
  float expression;     /* Input the next number */
  char operator, more;  /* Input for the next operator and yes or no value respectively */

  printf("Enter the simple arithmetic expression: ");
  expression = get_num();
  operator = get_op();
  printf("%g", s_exp(expression, operator)); /* Calculate and display the result */
  printf("\nWould you like to enter more arithmetic expressions? (Y or N) ");
  more = getchar();
  if(more == 'Y' || more == 'y'){  /* Recursively call main() */
    main();
  }
  else{                            /* User does not want to enter more expressions, so end */
    exit(0);
  }
  return 0;
}

/*
 * Function returns the value of the expression using recursion by getting next_num
 * and next_op. Then use 'sub_exp op next_num' and 'next_op' to recursively call.
 */  
float s_exp(float sub_exp, char op){
  if(op != '\n'){
    switch(op){
    case ' ':      /* To handle spaces */
      break;
    case '+':      /* When there's a plus sign, add sub_exp and next_num */
      sub_exp = sub_exp + get_num();
      break;
    case '-':      /* When there's a minus sign, subtract sub_exp and next_num */
      sub_exp = sub_exp - get_num();
      break;
    default:       /* Handle invalid operators */
      printf("Error: Non-valid input operator.");
      exit(0);
    }
    op = get_op(); /* Get 'next_op' and set it as op */
    sub_exp = s_exp(sub_exp, op); /* The 'sub_exp op next_num' portion */
  }
  return sub_exp;  
}

/*
 * Function returns the next operator ('next_op') by using getchar(). The operator 
 * can be +, - or '\n'.
 */
char get_op(){
  char next_op = getchar();
  return next_op;
}

/*
 * Function returns next number ('next_num') by using scanf.
 */
float get_num(){
  float next_num;
  scanf("%f", &next_num);
  return next_num;
}





























