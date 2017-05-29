/*
  Author  : Shiva Gaire
  email   : geeksambhu@gmail.com
  License : MIT
*/

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
  char* numbers;
  int   productMax;
  int   rangeLowest;
  int   rangeHighest;
  int   windowSize;
  int   noOfDigits;
} GreatestProduct;

/* A constructor to create new instance of GreatestProduct */
GreatestProduct* newGP(char* numbers, int windowSize, int noOfDigits){

  GreatestProduct* gp = malloc(sizeof(GreatestProduct));
  gp->numbers         = numbers;
  gp->windowSize      = windowSize;
  gp->noOfDigits      = noOfDigits;
  gp->productMax      = 0;

}

void find(GreatestProduct* data){
  /*
    Define the upper feasible boundry so that we wont have to iterate over unnecessary/irrelevant digits.
    Example: lets say the numbers are "1,2,3,4,5,6,7" and the window-size is 3
      - say, i  = `5`, the the outerBound = `7`, which makes no sense as noOfDigits[7] has garbage.
      - so we limit the upperBoundry to lowest possible relevant value
  */
  int upperBoundry = data->noOfDigits - data->windowSize;
  for(int i=0; i <= upperBoundry; i++){
    int outerBound = i + data->windowSize - 1;
    int product = 1;
    int j;

    if(outerBound < data -> noOfDigits) // if only window points to valid digits but not garbage
      for(j = i; j <= outerBound; j++){
        char numFromChar = data->numbers[j] - '0'; // convert char `1` to int `1`, i.e. 98-97=1
        product         *= numFromChar;
      }

    if(data->productMax < product){
      data->productMax   = product;
      data->rangeLowest  = i;
      data->rangeHighest = j - 1;
    }
  }
}

void main(){
  /*
    For now, this function will only comprise the test-cases
  */
  GreatestProduct* data = newGP("8878", 2, 4); // 2 -> WINDOW SIZE, whereas data-size is 4 digits
  find(data);
  assert(data->productMax == 64);

  GreatestProduct* data1 = newGP("887812", 2, 6); // 2 -> WINDOW SIZE, whereas data-size is 6 digits
  find(data1);
  assert(data1->productMax == 64);

  GreatestProduct* data2 = newGP("887899", 2, 6); // 2 -> WINDOW SIZE, whereas data-size is 6 digits
  find(data2);
  assert(data2->productMax == 81);

  GreatestProduct* data3 = newGP("887899", 3, 6); // 3 -> WINDOW SIZE, whereas data-size is 6 digits
  find(data3);
  assert(data3->productMax == 8*9*9);

  GreatestProduct* data4 = newGP("001001010101", 3, 12); // 3 -> WINDOW SIZE, whereas data-size is 12 digits
  find(data4);
  assert(data4->productMax == 0);

  GreatestProduct* data41 = newGP("001001230101", 3, 12); // 3 -> WINDOW SIZE, whereas data-size is 12 digits
  find(data41);
  assert(data41->productMax == 1*2*3);

  GreatestProduct* data5 = newGP("222222", 3, 6); // 3 -> WINDOW SIZE, whereas data-size is 6 digits
  find(data5);
  assert(data5->productMax == pow(2,3));

  GreatestProduct* data6 = newGP(
        "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101"\
        "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101"\
        "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101"\
        "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101"\
        "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101"\
        "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101"\
        "0101010101010101010101010101010101234567891234010101010101010101010101010101010101010101010101010101"\
        "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101"\
        "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101"\
        "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", 13, 1000);
        // 13 -> WINDOW SIZE, whereas data-size is 1000 digits

  find(data6);
  assert(data6->productMax == 1*2*3*4*5*6*7*8*9*1*2*3*4);
}
