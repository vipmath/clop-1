/////////////////////////////////////////////////////////////////////////////
//
// CPNonQuadraticND.cpp
//
// Rémi Coulom
//
// February, 2009
//
/////////////////////////////////////////////////////////////////////////////
#include "CPNonQuadraticND.h"
#include "CLogistic.h"

/////////////////////////////////////////////////////////////////////////////
// Quadratic strength function
/////////////////////////////////////////////////////////////////////////////
double CPNonQuadraticND::GetStrength(const double v[]) const
{
 double Sum = 0;
 for (int i = Dimensions; --i >= 0;)
 {
  double d = v[i] + 0.2;
  if (d > 0)
   Sum -= std::sqrt(d+2.0) - std::sqrt(2.0);
  else
   Sum -= 2 * std::sqrt(-d+0.5) - std::sqrt(2.0);
 }
 
 return 1.0 + Sum;
}

/////////////////////////////////////////////////////////////////////////////
// Optimal Proba
/////////////////////////////////////////////////////////////////////////////
double CPNonQuadraticND::GetOptimalProba() const
{
 return CLogistic::f(1.0);
}

/////////////////////////////////////////////////////////////////////////////
// Optimal Parameters
/////////////////////////////////////////////////////////////////////////////
void CPNonQuadraticND::GetOptimalParameters(double v[]) const
{
 std::fill(v, v + Dimensions, -0.2);
}