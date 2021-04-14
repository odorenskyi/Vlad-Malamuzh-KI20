#include <math.h>


double calculations_s(double x, double y, double z)
{
    double s = M_PI*x+pow(M_E,abs(y))-sqrt(abs(pow(z,2)-y)) ;
    return s;
}
