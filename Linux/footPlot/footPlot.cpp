// -*- C++ -*-
/*!
 * @file  footPlot.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "footPlot.h"

// Module specification
// <rtc-template block="module_spec">
static const char* footplot_spec[] =
  {
    "implementation_id", "footPlot",
    "type_name",         "footPlot",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "VenderName",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
footPlot::footPlot(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_rightFootPos3drIn("rightFootPos3dr", m_rightFootPos3dr),
    m_leftFootPos3drIn("leftFootPos3dr", m_leftFootPos3dr),
    m_footUrg3dIn("footUrg3d", m_footUrg3d)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
footPlot::~footPlot()
{
}



RTC::ReturnCode_t footPlot::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("rightFootPos3dr", m_rightFootPos3drIn);
  addInPort("leftFootPos3dr", m_leftFootPos3drIn);
  addInPort("footUrg3d", m_footUrg3dIn);

  // Set OutPort buffer
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>

  
  pv_x = new std::vector<double> ( 2 );
  pv_y = new std::vector<double> ( 2 );
  pv_r = new std::vector<double> ( 2 );
  pv_footUrg3d = new std::vector<double> ( MAX_POINT_URG*3);
  
  return RTC::RTC_OK;
}


RTC::ReturnCode_t footPlot::onFinalize()
{
  delete [] pv_x;
  delete [] pv_y;
  delete [] pv_r;
  delete [] pv_footUrg3d;

  return RTC::RTC_OK;
}


/*
RTC::ReturnCode_t footPlot::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t footPlot::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t footPlot::onActivated(RTC::UniqueId ec_id)
{
  chart_t.start( cmod_plotCircle<double>( "-1000:1000", "0:3000", pv_x, pv_y, pv_r, pv_footUrg3d ), true ); //表示範囲

  return RTC::RTC_OK;
}



RTC::ReturnCode_t footPlot::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}



RTC::ReturnCode_t footPlot::onExecute(RTC::UniqueId ec_id)
{
  if( m_rightFootPos3drIn.isNew() && m_leftFootPos3drIn.isNew() )
  {
    m_rightFootPos3drIn.read();
    m_leftFootPos3drIn.read();

    for( size_t _lp=0; _lp<pv_x->size(); _lp++ ){ pv_x->at(_lp)=0; pv_y->at(_lp)=0; }

    pv_x->at(0) = m_rightFootPos3dr.data[0];
    pv_y->at(0) = m_rightFootPos3dr.data[1];
    pv_r->at(0) = m_rightFootPos3dr.data[3];

    pv_x->at(1) = m_leftFootPos3dr.data[0];
    pv_y->at(1) = m_leftFootPos3dr.data[1];
    pv_r->at(1) = m_leftFootPos3dr.data[3];

  }

  if( m_footUrg3dIn.isNew() )
  {
    m_footUrg3dIn.read();
    for( size_t _lp=0; _lp<m_footUrg3d.data.length(); _lp++ )
    {
      pv_footUrg3d->at( _lp ) = m_footUrg3d.data[_lp];
    }
  }


  return RTC::RTC_OK;
}


/*
RTC::ReturnCode_t footPlot::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t footPlot::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t footPlot::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t footPlot::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t footPlot::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void footPlotInit(RTC::Manager* manager)
  {
    coil::Properties profile(footplot_spec);
    manager->registerFactory(profile,
                             RTC::Create<footPlot>,
                             RTC::Delete<footPlot>);
  }
  
};


