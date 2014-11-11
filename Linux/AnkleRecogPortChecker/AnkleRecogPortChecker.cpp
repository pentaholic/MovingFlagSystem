// -*- C++ -*-
/*!
 * @file  AnkleRecogPortChecker.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "AnkleRecogPortChecker.h"

// Module specification
// <rtc-template block="module_spec">
static const char* anklerecogportchecker_spec[] =
  {
    "implementation_id", "AnkleRecogPortChecker",
    "type_name",         "AnkleRecogPortChecker",
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
AnkleRecogPortChecker::AnkleRecogPortChecker(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_statusIn("status", m_status),
    m_rightAnkleIn("rightAnkle", m_rightAnkle),
    m_leftAnkleIn("leftAnkle", m_leftAnkle)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
AnkleRecogPortChecker::~AnkleRecogPortChecker()
{
}



RTC::ReturnCode_t AnkleRecogPortChecker::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("status", m_statusIn);
  addInPort("rightAnkle", m_rightAnkleIn);
  addInPort("leftAnkle", m_leftAnkleIn);
  
  // Set OutPort buffer
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t AnkleRecogPortChecker::onFinalize()
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t AnkleRecogPortChecker::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t AnkleRecogPortChecker::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t AnkleRecogPortChecker::onActivated(RTC::UniqueId ec_id)
{
  //インポートから読み込み
  m_statusIn.read();
  m_rightAnkleIn.read();
  m_leftAnkleIn.read();

  //std::cout<<"test1"<<std::endl;
  
  std::cout<<"右足のX座標＝"<<m_rightAnkle.data[0] <<", 右足のY座標＝"<<m_rightAnkle.data[1] <<", 右足のZ座標＝"<<m_rightAnkle.data[2] <<std::endl;
  std::cout<<"左足のX座標＝"<<m_leftAnkle.data[0]  <<", 左足のY座標＝"<<m_leftAnkle.data[1]  <<", 左足のZ座標＝"<<m_leftAnkle.data[2]  <<std::endl;

  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t AnkleRecogPortChecker::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t AnkleRecogPortChecker::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t AnkleRecogPortChecker::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t AnkleRecogPortChecker::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t AnkleRecogPortChecker::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t AnkleRecogPortChecker::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t AnkleRecogPortChecker::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void AnkleRecogPortCheckerInit(RTC::Manager* manager)
  {
    coil::Properties profile(anklerecogportchecker_spec);
    manager->registerFactory(profile,
                             RTC::Create<AnkleRecogPortChecker>,
                             RTC::Delete<AnkleRecogPortChecker>);
  }
  
};


