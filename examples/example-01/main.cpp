/**
 * \author Alexander Entinger
 */

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#define USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>

#include <iostream>

#include <plot/Plot2D.h>
#include <plot/Plot3D.h>

/**************************************************************************************
 * MAIN
 **************************************************************************************/

int main(int argc, char **argv)
{
  /**************************************************************************************
   * Plot2D
   **************************************************************************************/

  {
    Plot2D::DataPointVect data_point_vect;

    for(double x = 0.0; x < 4.0*2.0*M_PI; x += M_PI/10.0)
    {
      Plot2D::DataPoint const data_point(x, cos(x));

      data_point_vect.push_back(data_point);
    }

    Plot2D::SingleGraphData const data("y = cos(x)", "linespoints", data_point_vect);

    Plot2D plot_2d("Plot2D Demo", "Plot2D Demo Title", "x label", "y label", "", "", data);
  }

  /**************************************************************************************
   * Plot3D
   **************************************************************************************/

  {
    Plot3D::DataPointVect data_point_vect;

    for(double x = 0.0; x < 4.0*2.0*M_PI; x += M_PI/10.0)
    {
      double const A = 1.0;
      double const I = A * cos(x);
      double const Q = A * sin(x);

      Plot3D::DataPoint const data_point(x, I, Q);

      data_point_vect.push_back(data_point);
    }

    Plot3D::SingleGraphData const data("f(x) = IQ(x)", "linespoints", data_point_vect);

    Plot3D plot_3d("Plot3D Demo", "Plot3D Demo Title", "x label", "y label", "z label", "", "", "", data);
  }

  return EXIT_SUCCESS;
}
