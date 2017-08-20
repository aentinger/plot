/**    
 * libplot is a C++ 2D/3D plotting library based on gnuplot.
 * Copyright (C) 2017 Alexander Entinger
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SRC_PLOTBASE_H_
#define SRC_PLOTBASE_H_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <string>

#include <gnuplot-iostream/gnuplot-iostream.h>

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class PlotBase
{

public:

  PlotBase(std::string const & window_title,
           std::string const & plot_title,
           std::string const & x_label,
           std::string const & y_label,
           std::string const & z_label,
           std::string const & x_range,
           std::string const & y_range,
           std::string const & z_range);
  ~PlotBase();

protected:

  Gnuplot _gp;

private:

  void setWindowTitle (std::string const & window_title );
  void setPlotTitle   (std::string const & plot_title   );
  void setXLabel      (std::string const & x_label      );
  void setYLabel      (std::string const & y_label      );
  void setZLabel      (std::string const & z_label      );
  void setXRange      (std::string const & x_range      );
  void setYRange      (std::string const & y_range      );
  void setZRange      (std::string const & z_range      );
  void setXAutoScale  (                                 );
  void setYAutoScale  (                                 );
  void setZAutoScale  (                                 );

};

#endif /* SRC_PLOTBASE_H_ */
