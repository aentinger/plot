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

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <plot/PlotBase.h>

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

PlotBase::PlotBase(std::string const & window_title,
                   std::string const & plot_title,
                   std::string const & x_label,
                   std::string const & y_label,
                   std::string const & z_label,
                   std::string const & x_range,
                   std::string const & y_range,
                   std::string const & z_range)
{
  setWindowTitle  (window_title);
  setPlotTitle    (plot_title  );

  if(!x_label.empty()) setXLabel(x_label);
  if(!y_label.empty()) setYLabel(y_label);
  if(!z_label.empty()) setZLabel(z_label);

  x_range.empty() ? setXAutoScale() : setXRange(x_range);
  y_range.empty() ? setYAutoScale() : setYRange(y_range);
  z_range.empty() ? setZAutoScale() : setZRange(z_range);
}

PlotBase::~PlotBase()
{

}

/**************************************************************************************
 * PRIVATE MEMBER FUNCTIONS
 **************************************************************************************/

void PlotBase::setWindowTitle(std::string const & window_title)
{
  _gp << "set term wxt title '" << window_title << "'" << std::endl;
}

void PlotBase::setPlotTitle(std::string const & plot_title)
{
  _gp << "set title '" << plot_title << "'" << std::endl;
}

void PlotBase::setXLabel(std::string const & x_label)
{
  _gp << "set xlabel '" << x_label << "'" << std::endl;
}

void PlotBase::setYLabel(std::string const & y_label)
{
  _gp << "set ylabel '" << y_label << "'" << std::endl;
}

void PlotBase::setZLabel(std::string const & z_label)
{
  _gp << "set zlabel '" << z_label << "'" << std::endl;
}

void PlotBase::setXRange(std::string const & x_range)
{
  _gp << "set xrange [" << x_range << "]" << std::endl;
}

void PlotBase::setYRange(std::string const & y_range)
{
  _gp << "set yrange [" << y_range << "]" << std::endl;
}

void PlotBase::setZRange(std::string const & z_range)
{
  _gp << "set zrange [" << z_range << "]" << std::endl;
}

void PlotBase::setXAutoScale()
{
  _gp << "set xrange [*:*]" << std::endl;
}

void PlotBase::setYAutoScale()
{
  _gp << "set yrange [*:*]" << std::endl;
}

void PlotBase::setZAutoScale()
{
  _gp << "set zrange [*:*]" << std::endl;
}
