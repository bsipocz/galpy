#include <math.h>
#include <galpy_potentials.h>
#include <interp_2d.h>
//interpRZpotential
//2 remaining arguments: amp, logR
double interpRZPotentialEval(double R,double z, double phi,
			     double t,
			     struct potentialArg * potentialArgs){
  int nargs= potentialArgs->nargs;
  double * args= potentialArgs->args;
  //Get args
  double y;
  double amp= *args++;
  int logR= (int) *args;
  if ( logR == 1)
    y= log(R);
  else
    y= R;
  //Calculate potential through interpolation
  return amp * interp_2d_eval_cubic_bspline(potentialArgs->i2d,y,fabs(z),
					    potentialArgs->acc);
}