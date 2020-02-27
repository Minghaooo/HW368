// Minghao Tang
//student ID: 9081592546
//netID mtang64
// this is the test file 

#include "MathLib.h"
#include <iostream>

int main()
{
  std::cout << "absVal = "<< absVal(-3.3) << std::endl;
  std::cout << "ceilling"<<ceiling(-3.3)<<std::endl;
  std::cout <<"floor"<<floor(-3.3)<<std::endl;
  std::cout <<"pow = "<<pow(3,-3)<<std::endl;
  std::cout <<"gcd = "<<gcd(100,15)<<std::endl;
  std::cout <<"round up = "<<round(-42.5,ROUND_DOWN)<<std::endl;
  std::cout <<"round down = "<<round(2.3,ROUND_UP)<<std::endl;
  std::cout <<"round to zero = "<<round(12.5,ROUND_TO_ZERO)<<std::endl;
  std::cout <<"round away zero = "<<round(12.5,ROUND_AWAY_ZERO)<<std::endl;
  std::cout <<"round half down = "<<round(-42.5,ROUND_HALF_DOWN)<<std::endl;
  std::cout <<"round half up = "<<round(-42.5,ROUND_HALF_UP)<<std::endl;
  std::cout <<"round half t0 zero = "<<round(12.5,ROUND_HALF_TO_ZERO)<<std::endl;
  std::cout <<"round half away zero= "<<round(12.5,ROUND_HALF_AWAY_ZERO)<<std::endl;
  std::cout <<"round half to even = "<<round(12.5,ROUND_HALF_TO_EVEN)<<std::endl;
  std::cout <<"round half to ODD = "<<round(12.5,ROUND_HALF_TO_ODD)<<std::endl;
  std::cout <<"toString = "<<toString(-25,13,false)<<std::endl;
}
