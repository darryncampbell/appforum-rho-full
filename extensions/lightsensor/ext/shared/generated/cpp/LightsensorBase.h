#pragma once

#include "ILightsensor.h"
#include "logging/RhoLog.h"
#include "common/StringConverter.h"
#include "common/ExtManager.h"


namespace rho {

using namespace rho::apiGenerator;
using namespace rho;

// hash keys used in properties and parameters 
namespace lightsensor {

    static const char HK_LUX[] = "lux"; 

    static const char PROPERTY_DELAY[] = "delay"; 
 
} 

class CLightsensorFactoryBase : public CModuleFactoryBase<ILightsensor, ILightsensorSingleton, ILightsensorFactory>
{
protected:
    static rho::common::CAutoPtr<CLightsensorFactoryBase> m_pInstance;
    HashtablePtr<rho::String,ILightsensor*> m_hashModules;

public:

    static void setInstance(CLightsensorFactoryBase* pInstance){ m_pInstance = pInstance; }
    static CLightsensorFactoryBase* getInstance(){ return m_pInstance; }

    static ILightsensorSingleton* getLightsensorSingletonS(){ return getInstance()->getModuleSingleton(); }

    virtual ILightsensor* getModuleByID(const rho::String& strID)
    {
        if ( !m_hashModules.containsKey(strID) )
        {
            ILightsensor* pObj = createModuleByID(strID);
            m_hashModules.put(strID, pObj );

            return pObj;
        }

        return m_hashModules[strID];
    }

    virtual ILightsensor* createModuleByID(const rho::String& strID){ return (ILightsensor*)0; };
    virtual void deleteModuleByID(const rho::String& strID)
    {
        m_hashModules.remove(strID);
    }

};

class CLightsensorSingletonBase : public CModuleSingletonBase< ILightsensorSingleton >, public rho::common::IRhoExtension
{
protected:
    DEFINE_LOGCLASS;


    rho::String m_strDefaultID;




public:
    virtual rho::LogCategory getModuleLogCategory(){ return getLogCategory(); }

    CLightsensorSingletonBase();
    ~CLightsensorSingletonBase();




    virtual void setDefaultID(const rho::String& strDefaultID){ m_strDefaultID = strDefaultID; }
    virtual rho::String getDefaultID()
    { 
        if ( m_strDefaultID.length() == 0 )
            setDefaultID(getInitialDefaultID());
        return m_strDefaultID; 
    }

};

class CLightsensorBase: public ILightsensor
{
protected:
    DEFINE_LOGCLASS;


public:


    CLightsensorBase();



    static CLightsensorBase* getInstance(){ return static_cast< CLightsensorBase* >(CLightsensorFactoryBase::getInstance()->getModuleByID(CLightsensorFactoryBase::getLightsensorSingletonS()->getDefaultID())); }
 

};

extern "C" void Init_Lightsensor_API();


}
