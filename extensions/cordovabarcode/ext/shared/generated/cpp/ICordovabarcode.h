#pragma once

#include "common/RhoStd.h"
#include "api_generator/MethodResult.h"
#include "api_generator/BaseClasses.h"


namespace rho {
///////////////////////////////////////////////////////////



struct ICordovabarcode
{
//constants


//methods
    virtual ~ICordovabarcode(){}

    virtual void scan( const rho::Hashtable<rho::String, rho::String>& propertyMap, rho::apiGenerator::CMethodResult& oResult) = 0;

};

struct ICordovabarcodeSingleton
{
//constants


    virtual ~ICordovabarcodeSingleton(){}

//methods
    virtual void enumerate(rho::apiGenerator::CMethodResult& oResult) = 0;


    virtual rho::String getDefaultID() = 0;
    virtual rho::String getInitialDefaultID() = 0;
    virtual void setDefaultID(const rho::String& strID) = 0;

    virtual void addCommandToQueue(rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor) = 0;
    virtual void callCommandInThread(rho::common::IRhoRunnable* pFunctor) = 0;
};

struct ICordovabarcodeFactory
{
    virtual ~ICordovabarcodeFactory(){}

    virtual ICordovabarcodeSingleton* getModuleSingleton() = 0;


    virtual ICordovabarcode* getModuleByID(const rho::String& strID) = 0;

};


}
