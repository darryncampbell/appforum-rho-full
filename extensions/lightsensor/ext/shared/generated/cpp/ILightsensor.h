#pragma once

#include "common/RhoStd.h"
#include "api_generator/MethodResult.h"
#include "api_generator/BaseClasses.h"


namespace rho {
///////////////////////////////////////////////////////////



struct ILightsensor
{
//constants

    static const char FAST[];// "1" 
    static const char NORMAL[];// "0" 

//methods
    virtual ~ILightsensor(){}

    virtual void getDelay(rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void setDelay( int delay, rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void startListening( const rho::Hashtable<rho::String, rho::String>& propertyMap, rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void stopListening(rho::apiGenerator::CMethodResult& oResult) = 0;

};

struct ILightsensorSingleton
{
//constants


    virtual ~ILightsensorSingleton(){}

//methods
    virtual void enumerate(rho::apiGenerator::CMethodResult& oResult) = 0;


    virtual rho::String getDefaultID() = 0;
    virtual rho::String getInitialDefaultID() = 0;
    virtual void setDefaultID(const rho::String& strID) = 0;

    virtual void addCommandToQueue(rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor) = 0;
    virtual void callCommandInThread(rho::common::IRhoRunnable* pFunctor) = 0;
};

struct ILightsensorFactory
{
    virtual ~ILightsensorFactory(){}

    virtual ILightsensorSingleton* getModuleSingleton() = 0;


    virtual ILightsensor* getModuleByID(const rho::String& strID) = 0;

};


}
