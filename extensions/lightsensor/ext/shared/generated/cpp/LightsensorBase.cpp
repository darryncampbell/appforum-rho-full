#include "LightsensorBase.h"
#include "common/RhodesApp.h"


namespace rho {

IMPLEMENT_LOGCLASS(CLightsensorSingletonBase, "Lightsensor");
IMPLEMENT_LOGCLASS(CLightsensorBase, "Lightsensor");

rho::common::CAutoPtr< CLightsensorFactoryBase> CLightsensorFactoryBase::m_pInstance;



///////////////////////////////////////
//string constants definiton 
const char ILightsensor::FAST[] = "1"; 
const char ILightsensor::NORMAL[] = "0"; 

////////////////////////////////////////////////

CLightsensorBase::CLightsensorBase()
{

}
CLightsensorSingletonBase::CLightsensorSingletonBase()
{
    RHODESAPP().getExtManager().registerExtension( "Lightsensor", this );
}

CLightsensorSingletonBase::~CLightsensorSingletonBase()
{
    CLightsensorFactoryBase::setInstance(0);
}


}
