// Minghao Tang
//student ID: 9081592546
// NetID: mtang64
// this is the header  
#ifndef MATHLIB_H
#define MATHLIB_H
  #include <string>

int absVal(int input);
long absVal(long input);
double absVal(double input);

long ceiling(double input);
long floor(double input);

enum enumType {ROUND_DOWN,ROUND_UP, ROUND_TO_ZERO, ROUND_AWAY_ZERO, ROUND_HALF_UP, ROUND_HALF_DOWN, ROUND_HALF_TO_ZERO,
  ROUND_HALF_AWAY_ZERO, ROUND_HALF_TO_EVEN, ROUND_HALF_TO_ODD} ;

long round (double inpiut, enumType RoundingRule = ROUND_HALF_DOWN );
double pow(double base, long expon);
int gcd(int a, int b);

std::string toString(int num, unsigned int radix=10, bool form=true);
#endif /* IFNDEF_H */