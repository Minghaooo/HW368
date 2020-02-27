// Minghao Tang
//student ID: 9081592546
// this file is the main body of the project.

//reference 1. https://www.mathsisfun.com/numbers/rounding-methods.html
//reference 2. https://www.programiz.com/c-programming/examples/hcf-recursion

#include "MathLib.h"

//using namespace std;

int absVal(int input){      // return value according to the input
  if (input >= 0)
    return input;
  else 
    return -input;
}

long absVal(long input){   // long type for absVal
  if (input >= 0)
    return input;
  else 
    return -input;
}

double absVal(double input){ //double type
  if (input >= 0)
    return input;
  else 
    return -input;
}

long ceiling(double input){
  
    if (long(input) == input)   //if the input is an interger , then retuen it self. 
      return input;
    else if(input >= 0)         // if input >0. return +1
    return long(long(input)+1);
    else 
    return long(long(input));   // if input < 0 . return itself;
}

long floor(double input){       
    if (long(input) == input)
      return input;
    else if(input >= 0)
      return long( input);    // the floor of a positive number is its integer part
    else
    {
      return long(input-1);
    }
}

double pow(double base, long expon){
  long exp = absVal(expon);
  double ans = 1;

  if (expon ==0)
    return 1;                            
  else if (expon>0){
    for (int i =0; i<exp; i++)      // use for to do the calcultaion.
      ans = ans*base;
  } 
  else if(expon<0){                 // if <0. (1/n)^a
    for (int i = 0;i<exp;i++ )
      ans = ans *(1/base);  
  }
  return ans;
}


long round (double input, enumType RoundingRule ){

  long output =0;

switch (RoundingRule)
{
  case ROUND_DOWN: { output= floor( input); break;}    // round down is get the floor

  case ROUND_UP:  { output= ceiling( input); break;}    // round up is get the ceiling 

  case ROUND_TO_ZERO: {               // input >0, get floor
    if(input >=0)                     //       <0  use ceiling
      output = floor(input);
    else 
      output = ceiling(input);
    break;
  }

  case ROUND_AWAY_ZERO: {             //input > 0,return ceiling 
    if(input <= 0)
      output = floor(input);          // input <0 get floor
    else 
      output = ceiling(input);
    break;
  }

  case ROUND_HALF_UP:{
    if(absVal(input -int(input)) > 0.5 ){    // if the decimal part >=0.5
        if (input >0)                            //when input >=0
            output = ceiling(input);
        else
            output= floor(input);
    }    
    else if (absVal(input -int(input)) < 0.5){  //
      if (input >0)
            output = floor(input);
        else
            output= ceiling(input);
      }
      else {
            output= ceiling(input);
      }
    break;
  }

  case ROUND_HALF_DOWN :{
      if(absVal(input -int(input)) > 0.5 ){    // if the decimal part >=0.5
        if (input >0)                            //when input >=0
            output = ceiling(input);
        else
            output= floor(input);
    }    
    else if (absVal(input -int(input)) < 0.5){
      if (input >0)
            output = floor(input);
        else
            output= ceiling(input);
      }
      else {
            output= floor(input);
      }
    break;
  }

  case ROUND_HALF_TO_ZERO :{
    if(absVal(input -int(input)) > 0.5 )
      output = input/absVal(input)*ceiling(absVal(input));
    else if (absVal(input -int(input)) <=0.5)
      output= input/absVal(input)*floor(absVal(input));
    break;
  }

  case ROUND_HALF_AWAY_ZERO :{
   if(absVal(input -int(input)) >= 0.5 )
      output = input/absVal(input)*ceiling(absVal(input));
    else if (absVal(input -int(input)) <0.5)
      output= input/absVal(input)*floor(absVal(input));
    break;
  }

  case ROUND_HALF_TO_ODD :{
    if (absVal(input-int(input)) == 0.5 ){
        if (absVal(floor(absVal(input))%2 == 1))                // if odd 
          output= input/absVal(input)*floor(absVal(input));       //use  floor so just remove the decimal
        else                                                      // if even, use ceiling 
          output = input/absVal(input)*ceiling(absVal(input));
      break;
    }

    if (absVal(input-int(input)) > 0.5 )                        // others as usual, when >0.5, ceiling
      output = input/absVal(input)*ceiling(absVal(input));

    if (absVal(input -int(input)) <0.5)
      output= input/absVal(input)*floor(absVal(input));         // when <0.5 floor

    
      break;
  }

  case ROUND_HALF_TO_EVEN :{
    if (absVal(input-int(input)) == 0.5 ){   //if decimal  == 0.5 
        if (absVal(ceiling(absVal(input))%2 == 1))                //if odd  
          output= input/absVal(input)*floor(absVal(input));           //floor£¬ so round to even
        else                                                      // if even, 
          output = input/absVal(input)*ceiling(absVal(input));        // floor 
    }

    if (absVal(input-int(input)) > 0.5 )                              // same as round half to odd.
      output = input/absVal(input)*ceiling(absVal(input));

    if (absVal(input -int(input)) <0.5)
      output= input/absVal(input)*floor(absVal(input));

      break;
    }


    default:  break;
    }
  return output;
}

std::string toString(int num, unsigned int radix, bool form){
  if (radix > 36)
    return "Radix too large.";

    // define different string number£¬ upper and lower
  char lower[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o',
  'p','q','r','s','t','u','v','w','x','y','z'};
  char upper[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O',
  'P','Q','R','S','T','U','V','W','X','Y','Z'};

  unsigned int temp;
  bool sign = false;
  std::string str;

  if(num >= 0)   // find the sign of the number 
    temp = num;   // save the sign to bool (sign)
  else {
    temp = -num;
    sign = true;
  }
if (form){        // use % radix to do the calculation. if form >0. then out put the lower part 
  do {
    str= lower[temp % radix] +str;
  }while((temp/=radix)>0);
}
else {
  do {
    str= upper[temp % radix] +str;    // if form <0  then use the upper 
  }while((temp/=radix)>0);
}

if (sign)
  str = '-'+str;      // add sign to the string
  return str;
}

int gcd(int a, int b){   // use % to get the result. 
  
    if (b == 0)
      return absVal(a);
    else 
      return absVal(gcd(b, a%b));

}