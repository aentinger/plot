/**
 * \author Alexander Entinger
 */

#ifndef SRC_PLOTBASE_H_
#define SRC_PLOTBASE_H_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <string>

#include "gnuplot-iostream.h"

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
