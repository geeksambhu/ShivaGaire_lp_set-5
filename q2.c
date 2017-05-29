/*
  Author  : Shiva Gaire
  email   : geeksambhu@gmail.com
  License : MIT

  This code is compiled with GCC version 6.3.0 20170406
*/

#include <stdio.h>
#include <assert.h>

typedef struct{
  int num1;
  int num2;
  int product;
} Palindrom;

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

}
