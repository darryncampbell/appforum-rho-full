//
//  CordovabarcodeImpl.cpp
#include "common/RhoStd.h"
#include "common/AutoPointer.h"
#include "common/RhodesApp.h"
#include "common/RhoConf.h"
#include "generated/cpp/CordovabarcodeBase.h"
#include "logging/RhoLog.h"

namespace rho {
    
    using namespace apiGenerator;
    using namespace common;
    
    class CCordovabarcodeSingletonImpl: public CCordovabarcodeSingletonBase
    {
    public:
        
        CCordovabarcodeSingletonImpl(): CCordovabarcodeSingletonBase(){}
        
        //methods
        // enumerate  
        virtual void enumerate(rho::apiGenerator::CMethodResult& oResult) {
            // RAWLOGC_INFO("enumerate","Cordovabarcode");
            
        } 

    };
    
    class CCordovabarcodeImpl : public CCordovabarcodeBase
    {
    public:
        virtual ~CCordovabarcodeImpl() {}

        //methods

        virtual void scan( const rho::Hashtable<rho::String, rho::String>& propertyMap, rho::apiGenerator::CMethodResult& oResult) {

        } 

    };
    
    ////////////////////////////////////////////////////////////////////////
    
    class CCordovabarcodeFactory: public CCordovabarcodeFactoryBase    {
    public:
        CCordovabarcodeFactory(){}
        
        ICordovabarcodeSingleton* createModuleSingleton()
        { 
            return new CCordovabarcodeSingletonImpl();
        }
        
        virtual ICordovabarcode* createModuleByID(const rho::String& strID){ return new CCordovabarcodeImpl(); };
        
    };
    
}

extern "C" void Init_Cordovabarcode_extension()
{
    rho::CCordovabarcodeFactory::setInstance( new rho::CCordovabarcodeFactory() );
    rho::Init_Cordovabarcode_API();
    
}