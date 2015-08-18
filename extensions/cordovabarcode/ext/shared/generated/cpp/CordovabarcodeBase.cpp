#include "CordovabarcodeBase.h"
#include "common/RhodesApp.h"


namespace rho {

IMPLEMENT_LOGCLASS(CCordovabarcodeSingletonBase, "Cordovabarcode");
IMPLEMENT_LOGCLASS(CCordovabarcodeBase, "Cordovabarcode");

rho::common::CAutoPtr< CCordovabarcodeFactoryBase> CCordovabarcodeFactoryBase::m_pInstance;



///////////////////////////////////////
//string constants definiton 

////////////////////////////////////////////////

CCordovabarcodeBase::CCordovabarcodeBase()
{

}
CCordovabarcodeSingletonBase::CCordovabarcodeSingletonBase()
{
    RHODESAPP().getExtManager().registerExtension( "Cordovabarcode", this );
}

CCordovabarcodeSingletonBase::~CCordovabarcodeSingletonBase()
{
    CCordovabarcodeFactoryBase::setInstance(0);
}


}
