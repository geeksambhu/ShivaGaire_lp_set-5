/*
  Author  : Shiva Gaire
  email   : geeksambhu@gmail.com
  License : MIT
*/

#include <stdio.h>
#include <assert.h>
#include <math.h>

typedef struct{
  char* numbers;
  int   productMax;
  int   rangeLowest;
  int   rangeHighest;
  int   windowSize;
} GreatestProduct;

GreatestProduct* newGP(char* numbers, int windowSize){}
void find(GreatestProduct* data){}

void main(){
  /*
    For now, this function will only comprise the test-cases
  */
  GreatestProduct* data = newGP("8878", 2); // 2 -> WINDOW SIZE, whereas data-size is 4 digits
  find(data);
  assert(data->productMax == 64);

  GreatestProduct* data1 = newGP("887812", 2); // 2 -> WINDOW SIZE, whereas data-size is 4 digits
  find(data1);
  assert(data1->productMax == 64);

  GreatestProduct* data2 = newGP("887899", 2); // 2 -> WINDOW SIZE, whereas data-size is 6 digits
  find(data2);
  assert(data2->productMax == 81);

  GreatestProduct* data3 = newGP("887899", 3); // 3 -> WINDOW SIZE, whereas data-size is 6 digits
  find(data3);
  assert(data3->productMax == 8*9*9);

  GreatestProduct* data4 = newGP("001001010101", 3); // 3 -> WINDOW SIZE, whereas data-size is 12 digits
  find(data4);
  assert(data4->productMax == 0);

  GreatestProduct* data5 = newGP("222222", 3); // 3 -> WINDOW SIZE, whereas data-size is 6 digits
  find(data5);
  assert(data5->productMax == pow(2,3));
}
