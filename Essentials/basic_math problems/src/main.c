#include <stdio.h>
#include "../header/functions.h"

/*

Following program is for practice. It helps in solving few important math problems.
  1. Function that calculate area of circle.
  2. Function that calculate area of rectangle.
  3. Function that prints first N natural numbers.
  4. Function that prints sum of first N natural numbers.
  5. Function checking for odd or even numbers.
  6. Function checking if input is prime number or not.
  7. Function that calculates factorial of input number.
  8. Function calculating permutation and combination.
  9. Function that finds next 5 prime numbers after the given input number.
  10.Function that finds LCM of given number.

*/

int main()
{
  int area = circle(5);
  printf("Area of circle is %d\n", area);
  int rectangle = Rectangle_1(10,10);
  printf("Area of Rectangle is %d \n", rectangle);

  naturalNumbers(10);

  sumNaturalNumbers(10);

  evenorodd(10);
  evenorodd(9);

  prime(1);

  factorial(5);

}

int circle (int radius){
  int area = ((22/7)*(radius*radius));
  return area;
}

int Rectangle_1(int base, int height){
  int result = ((base*height)/2);
  return result;
}

void naturalNumbers(int limit){
  printf("First %d natural numbers are: ", limit);
  for(int i=0; i<limit; i++){
    printf("%d", i+1);
    printf(" ");
  }
  printf("\n");
}

void sumNaturalNumbers(int limit){
  printf("Sum of first %d natural numbers are: ", limit);
  int total=0;
  for(int i=0; i<limit; i++){
    total+=i;
  }
  printf("%d\n",total);
}

void evenorodd(int number){
  printf("%d is: ", number);
  if ((number%2)==0){
    printf("Even\n");
  }
  else {
    printf("Odd\n");

  }
}

void prime(int number){

  int iteration, flag =0;

  for(iteration = 2; iteration<=number/2; iteration++){
    if((number%iteration) == 0)
    {
      flag = 1;
      break;
    }
  }

  if(number == 1){
    printf("1 is neither prime not composite");
  }
  else{
    if( flag == 0 ){
      printf("%d is prime number", number);
    }
    else{
      printf("%d is not a prime number", number);

    }
  }
printf("\n");
}

void factorial(int number){
  int output = 1;

  for(int i = 1; i<number+1; i++){
    output*=i;
  }
  printf("factorial of %d is: ", number);
  printf("%d\n",output);
}
