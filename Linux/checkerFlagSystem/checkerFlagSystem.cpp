// -*- C++ -*-
/*!
 * @file  checkerFlagSystem.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "checkerFlagSystem.h"

// Module specification
// <rtc-template block="module_spec">
static const char* checkerflagsystem_spec[] =
  {
    "implementation_id", "checkerFlagSystem",
    "type_name",         "checkerFlagSystem",
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
checkerFlagSystem::checkerFlagSystem(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_flagPatternIn("flagPattern", m_flagPattern)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
checkerFlagSystem::~checkerFlagSystem()
{
}



RTC::ReturnCode_t checkerFlagSystem::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("flagPattern", m_flagPatternIn);
  
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
RTC::ReturnCode_t checkerFlagSystem::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t checkerFlagSystem::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t checkerFlagSystem::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t checkerFlagSystem::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t checkerFlagSystem::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
動作未確認
*/
RTC::ReturnCode_t checkerFlagSystem::onExecute(RTC::UniqueId ec_id)
{
	if(m_flagPatternIn.isNew()){
		m_flagPatternIn.read();
		std::cout<<"flag pattern= "<<m_flagPattern.data<<std::endl;
		std::cout<<"time= "<<m_flagPattern.tm.nsec<<std::endl;
	}

	return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t checkerFlagSystem::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t checkerFlagSystem::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t checkerFlagSystem::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t checkerFlagSystem::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t checkerFlagSystem::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void checkerFlagSystemInit(RTC::Manager* manager)
  {
    coil::Properties profile(checkerflagsystem_spec);
    manager->registerFactory(profile,
                             RTC::Create<checkerFlagSystem>,
                             RTC::Delete<checkerFlagSystem>);
  }
  
};


