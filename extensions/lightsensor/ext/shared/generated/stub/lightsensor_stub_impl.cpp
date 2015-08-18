//
//  LightsensorImpl.cpp
#include "common/RhoStd.h"
#include "common/AutoPointer.h"
#include "common/RhodesApp.h"
#include "common/RhoConf.h"
#include "generated/cpp/LightsensorBase.h"
#include "logging/RhoLog.h"

namespace rho {
    
    using namespace apiGenerator;
    using namespace common;
    
    class CLightsensorSingletonImpl: public CLightsensorSingletonBase
    {
    public:
        
        CLightsensorSingletonImpl(): CLightsensorSingletonBase(){}
        
        //methods
        // enumerate  
        virtual void enumerate(rho::apiGenerator::CMethodResult& oResult) {
            // RAWLOGC_INFO("enumerate","Lightsensor");
            
        } 

    };
    
    class CLightsensorImpl : public CLightsensorBase
    {
    public:
        virtual ~CLightsensorImpl() {}

        //methods

        virtual void getDelay(rho::apiGenerator::CMethodResult& oResult) {

        } 

        virtual void setDelay( int delay, rho::apiGenerator::CMethodResult& oResult) {

        } 

        virtual void startListening( const rho::Hashtable<rho::String, rho::String>& propertyMap, rho::apiGenerator::CMethodResult& oResult) {

        } 

        virtual void stopListening(rho::apiGenerator::CMethodResult& oResult) {

        } 

    };
    
    ////////////////////////////////////////////////////////////////////////
    
    class CLightsensorFactory: public CLightsensorFactoryBase    {
    public:
        CLightsensorFactory(){}
        
        ILightsensorSingleton* createModuleSingleton()
        { 
            return new CLightsensorSingletonImpl();
        }
        
        virtual ILightsensor* createModuleByID(const rho::String& strID){ return new CLightsensorImpl(); };
        
    };
    
}

extern "C" void Init_Lightsensor_extension()
{
    rho::CLightsensorFactory::setInstance( new rho::CLightsensorFactory() );
    rho::Init_Lightsensor_API();
    
}