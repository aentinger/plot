/**
 * \author Alexander Entinger
 */

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <plot/Plot3D.h>

/**************************************************************************************
 * Plot3D::DataPoint
 **************************************************************************************/

Plot3D::DataPoint::DataPoint(double const x, double const y, double const z)
{
  this->x = x;
  this->y = y;
  this->z = z;
}

/**************************************************************************************
 * Plot3D::SingleGraphData
 **************************************************************************************/

Plot3D::SingleGraphData::SingleGraphData(std::string const & title, std::string const & point_type, DataPointVect const & data_point_vect)
{
  this->_title = title;
  this->_point_type = point_type;
  this->_data_point_vect = data_point_vect;
}

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

Plot3D::Plot3D(std::string     const & window_title,
               std::string     const & plot_title,
               std::string     const & x_label,
               std::string     const & y_label,
               std::string     const & z_label,
               std::string     const & x_range,
               std::string     const & y_range,
               std::string     const & z_range,
               SingleGraphData const & data)
:
  PlotBase(window_title, plot_title, x_label, y_label, z_label, x_range, y_range, z_range)
{
  plot(data);
}

Plot3D::~Plot3D()
{

}

/**************************************************************************************
 * PRIVATE MEMBER FUNCTIONS
 **************************************************************************************/

void Plot3D::plot(SingleGraphData const & data)
{
  _gp << "splot "
      << _gp.file1d(convertToGnuplotDataVect(data.data_point_vect()), "record")
      << "with "    << data.point_type()
      << " title '" << data.title() << "'"
      << std::endl;
}

Plot3D::GnuplotDataVect Plot3D::convertToGnuplotDataVect(DataPointVect const & data) const
{
  GnuplotDataVect data_point_vect(data.size());

  for(size_t i = 0; i < data.size(); i++)
  {
    data_point_vect[i] = boost::make_tuple(data[i].x, data[i].y, data[i].z);
  }

  return data_point_vect;
}
