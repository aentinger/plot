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

#include <plot/Plot2D.h>

/**************************************************************************************
 * Plot2D::DataPoint
 **************************************************************************************/

Plot2D::DataPoint::DataPoint(double const x, double const y)
{
  this->x = x;
  this->y = y;
}

/**************************************************************************************
 * Plot2D::SingleGraphData
 **************************************************************************************/

Plot2D::SingleGraphData::SingleGraphData(std::string const & title, std::string const & line_type, std::string const & point_type, DataPointVect const & data_point_vect)
{
  this->_title           = title;
  this->_line_type       = line_type;
  this->_point_type      = point_type;
  this->_data_point_vect = data_point_vect;
}

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

Plot2D::Plot2D(std::string     const & window_title,
               std::string     const & plot_title,
               std::string     const & x_label,
               std::string     const & y_label,
               std::string     const & x_range,
               std::string     const & y_range,
               SingleGraphData const & data)
:
  PlotBase(window_title, plot_title, x_label, y_label, std::string(""), x_range, y_range, std::string(""))
{
  plot(data);
}

Plot2D::~Plot2D()
{

}

/**************************************************************************************
 * PRIVATE MEMBER FUNCTIONS
 **************************************************************************************/

void Plot2D::plot(SingleGraphData const & data)
{
  _gp << "plot "
      << _gp.file1d(convertToGnuplotDataVect(data.data_point_vect()))
      << "with "      << data.line_type()
      << " pointtype" << data.point_type()
      << " title '" << data.title() << "'"
      << std::endl;
}

Plot2D::GnuplotDataVect Plot2D::convertToGnuplotDataVect(DataPointVect const & data) const
{
  GnuplotDataVect data_point_vect(data.size());

  for(size_t i = 0; i < data.size(); i++)
  {
    data_point_vect[i] = std::make_pair(data[i].x, data[i].y);
  }

  return data_point_vect;
}
