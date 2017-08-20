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

#ifndef SRC_PLOT2D_H_
#define SRC_PLOT2D_H_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <plot/PlotBase.h>

#include <vector>

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class Plot2D : public PlotBase
{

public:

  /**************************************************************************************
   * Plot2D::DataPoint
   **************************************************************************************/

  class DataPoint
  {
  public:

    double x;
    double y;

    DataPoint(double const x, double const y);
  };

  /**************************************************************************************
   * Plot2D::SingleGraphData
   **************************************************************************************/

  typedef std::vector<DataPoint> DataPointVect;

  class SingleGraphData
  {
  public:

    SingleGraphData(std::string const & title, std::string const & point_type, DataPointVect const & data_point_vect);

    inline std::string    title           () const { return this->_title;           }
    inline std::string    point_type      () const { return this->_point_type;      }
    inline DataPointVect  data_point_vect () const { return this->_data_point_vect; }

  private:

    std::string   _title;
    std::string   _point_type;
    DataPointVect _data_point_vect;

  };

  /**************************************************************************************
   * Plot2D
   **************************************************************************************/

   Plot2D(std::string     const & window_title,
          std::string     const & plot_title,
          std::string     const & x_label,
          std::string     const & y_label,
          std::string     const & x_range,
          std::string     const & y_range,
          SingleGraphData const & data);
  ~Plot2D();

private:

  typedef std::vector<std::pair<double, double> > GnuplotDataVect;

  void            plot                    (SingleGraphData const & data);
  GnuplotDataVect convertToGnuplotDataVect(DataPointVect   const & data) const;

};

#endif /* SRC_PLOT2D_H_ */
