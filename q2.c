/*
  Author  : Shiva Gaire
  email   : geeksambhu@gmail.com
  License : MIT

  This code is compiled with GCC version 6.3.0 20170406

  Note    : While compiling you need to pass `-lm` switch to let linker to link to additional files
            required by the library. Because only the declaration is in `pow` of `math.h`, defintion
            is elsewhere.
  fixme:  This program has places for optimization; number of loops can be reduced. 
*/

#include <math.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  int num1;
  int num2;
  int product;
} Palindrom;

int checkPalindrome(int num){
  int dup = num;
  int temp = 0;
  while(num>0){
   int  digit =  num%10;
   temp = digit + temp*10;
   num /= 10;
  }
  if(temp == dup)
    return 1;
  else
    return 0;
}

Palindrom* find(int noOfDigits){
  Palindrom* data = malloc(sizeof(Palindrom));
  data->product   = 0;
  int upperBound  = pow(10, noOfDigits) - 1;
  int lowerBound  = pow(10, noOfDigits - 1);

  for(int i = upperBound; i >= lowerBound; i--){
    /* upperBound-- is to reduce the number of loops */
    for(int j = upperBound--; j >= lowerBound; j--){
      if(checkPalindrome(i*j) && data->product < i*j){
        data->product = i*j;
        data->num1 = j;
        data->num2 = i;
      }
    }
  }
  return data;
}

void displayOutput(Palindrom* response){
  printf("%d = %d x %d\n", response->product, response->num1, response->num2);
}

void main(){
  assert(checkPalindrome(9) == 1);

  // Greatest Palindromic product of 1 digit numbers.
  Palindrom* response = find(1);
  assert(response->product  == 9);
  assert(response->num1     == 1);
  assert(response->num2     == 9);

  // Greatest Palindromic product of 2 digit numbers.
  Palindrom* response2 = find(2);
  assert(response2->product  == 9009);
  assert(response2->num1     == 91);
  assert(response2->num2     == 99);

  // Greatest Palindromic product of 3 digit numbers.
  Palindrom* response3 = find(3);
  assert(response3->product  == 906609);
  assert(response3->num1     == 913);
  assert(response3->num2     == 993);

  displayOutput(response3);
}

/* SAMPLE OUTPUT
  906609 = 913 x 993
*/
