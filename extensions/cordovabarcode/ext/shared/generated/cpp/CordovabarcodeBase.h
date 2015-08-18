#pragma once

#include "ICordovabarcode.h"
#include "logging/RhoLog.h"
#include "common/StringConverter.h"
#include "common/ExtManager.h"


namespace rho {

using namespace rho::apiGenerator;
using namespace rho;

// hash keys used in properties and parameters 
namespace cordovabarcode {

    static const char HK_DATA[] = "data"; 
 
} 

class CCordovabarcodeFactoryBase : public CModuleFactoryBase<ICordovabarcode, ICordovabarcodeSingleton, ICordovabarcodeFactory>
{
protected:
    static rho::common::CAutoPtr<CCordovabarcodeFactoryBase> m_pInstance;
    HashtablePtr<rho::String,ICordovabarcode*> m_hashModules;

public:

    static void setInstance(CCordovabarcodeFactoryBase* pInstance){ m_pInstance = pInstance; }
    static CCordovabarcodeFactoryBase* getInstance(){ return m_pInstance; }

    static ICordovabarcodeSingleton* getCordovabarcodeSingletonS(){ return getInstance()->getModuleSingleton(); }

    virtual ICordovabarcode* getModuleByID(const rho::String& strID)
    {
        if ( !m_hashModules.containsKey(strID) )
        {
            ICordovabarcode* pObj = createModuleByID(strID);
            m_hashModules.put(strID, pObj );

            return pObj;
        }

        return m_hashModules[strID];
    }

    virtual ICordovabarcode* createModuleByID(const rho::String& strID){ return (ICordovabarcode*)0; };
    virtual void deleteModuleByID(const rho::String& strID)
    {
        m_hashModules.remove(strID);
    }

};

class CCordovabarcodeSingletonBase : public CModuleSingletonBase< ICordovabarcodeSingleton >, public rho::common::IRhoExtension
{
protected:
    DEFINE_LOGCLASS;


    rho::String m_strDefaultID;




public:
    virtual rho::LogCategory getModuleLogCategory(){ return getLogCategory(); }

    CCordovabarcodeSingletonBase();
    ~CCordovabarcodeSingletonBase();




    virtual void setDefaultID(const rho::String& strDefaultID){ m_strDefaultID = strDefaultID; }
    virtual rho::String getDefaultID()
    { 
        if ( m_strDefaultID.length() == 0 )
            setDefaultID(getInitialDefaultID());
        return m_strDefaultID; 
    }

};

class CCordovabarcodeBase: public ICordovabarcode
{
protected:
    DEFINE_LOGCLASS;


public:


    CCordovabarcodeBase();



    static CCordovabarcodeBase* getInstance(){ return static_cast< CCordovabarcodeBase* >(CCordovabarcodeFactoryBase::getInstance()->getModuleByID(CCordovabarcodeFactoryBase::getCordovabarcodeSingletonS()->getDefaultID())); }
 

};

extern "C" void Init_Cordovabarcode_API();


}
