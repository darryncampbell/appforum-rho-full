

#include "logging/RhoLog.h"
#undef DEFAULT_LOGCATEGORY
#define DEFAULT_LOGCATEGORY "Lightsensor"

#include "LightsensorBase.h"
#include "api_generator/js_helpers.h"
#include "api_generator/JSONResultConvertor.h"

#include "common/StringConverter.h"

extern "C" void rho_os_impl_performOnUiThread(rho::common::IRhoRunnable* pTask);

#ifdef OS_ANDROID
#include <jni.h>
extern "C" void* rho_nativethread_start();
JNIEnv* jnienv();
#endif //OS_ANDROID

using namespace rho;
using namespace rho::json;
using namespace rho::common;
using namespace rho::apiGenerator;


rho::String js_Lightsensor_getDelay(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    RAWTRACE4("getDelay(strObjID = %s, argc = %d, strCallbackID = %s, strJsVmID = %s)", strObjID.c_str(), argv.getSize(), strCallbackID.c_str(), strJsVmID.c_str());

#ifdef OS_ANDROID
    if ( jnienv() == 0 )
    {
        rho_nativethread_start();
    }
#endif

    rho::apiGenerator::CMethodResult oRes;


    oRes.setRequestedType(CMethodResult::eInt);

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    int argc = argv.getSize();

    rho::ILightsensor* pObj = rho::CLightsensorFactoryBase::getInstance()->getModuleByID(strObjID);

    if ( oRes.hasCallback() )
    {
        pFunctor = rho_makeInstanceClassFunctor1( pObj, &rho::ILightsensor::getDelay,  oRes );
        rho::CLightsensorFactoryBase::getLightsensorSingletonS()->addCommandToQueue( pFunctor );
    }
    else 
    {

        pObj->getDelay(  oRes );
    }
    
    return oRes.toJSON();

}

rho::String js_Lightsensor_setDelay(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    RAWTRACE4("setDelay(strObjID = %s, argc = %d, strCallbackID = %s, strJsVmID = %s)", strObjID.c_str(), argv.getSize(), strCallbackID.c_str(), strJsVmID.c_str());

#ifdef OS_ANDROID
    if ( jnienv() == 0 )
    {
        rho_nativethread_start();
    }
#endif

    rho::apiGenerator::CMethodResult oRes;



    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    int argc = argv.getSize();

    rho::ILightsensor* pObj = rho::CLightsensorFactoryBase::getInstance()->getModuleByID(strObjID);

    if ( argc == 0 )
    {
        oRes.setArgError( "Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toJSON();
    }
    
    int arg0 = 0;
    if ( argc > 0 )
    {
        if ( argv[0].isInteger() )
            arg0 = argv[0].getInt();
        else if (!argv[0].isNull())
        {
            oRes.setArgError("Type error: argument " "0" " should be " "integer" );
            return oRes.toJSON();
        }
    }

    if ( oRes.hasCallback() )
    {
        pFunctor = rho_makeInstanceClassFunctor2( pObj, &rho::ILightsensor::setDelay, arg0,  oRes );
        rho::CLightsensorFactoryBase::getLightsensorSingletonS()->addCommandToQueue( pFunctor );
    }
    else 
    {

        pObj->setDelay( arg0,  oRes );
    }
    
    return oRes.toJSON();

}

rho::String js_s_Lightsensor_enumerate(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    RAWTRACE4("enumerate(strObjID = %s, argc = %d, strCallbackID = %s, strJsVmID = %s)", strObjID.c_str(), argv.getSize(), strCallbackID.c_str(), strJsVmID.c_str());

#ifdef OS_ANDROID
    if ( jnienv() == 0 )
    {
        rho_nativethread_start();
    }
#endif

    rho::apiGenerator::CMethodResult oRes;


    oRes.setParamName( "result" );
    oRes.setJSObjectClassPath( "Rho.Lightsensor" );
    oRes.setRequestedType(CMethodResult::eStringArray);

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    int argc = argv.getSize();

    oRes.setCallInUIThread(false);
    oRes.setJSCallback( strCallbackID );
    oRes.setCallbackParam( strCallbackParam );

    if ( oRes.hasCallback() )
    {
        pFunctor = rho_makeInstanceClassFunctor1( rho::CLightsensorFactoryBase::getLightsensorSingletonS(), &rho::ILightsensorSingleton::enumerate,  oRes );
        rho::CLightsensorFactoryBase::getLightsensorSingletonS()->addCommandToQueue( pFunctor );
    }
    else 
    {

        rho::CLightsensorFactoryBase::getLightsensorSingletonS()->enumerate(  oRes );
    }
    
    return oRes.toJSON();

}

rho::String js_Lightsensor_startListening(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    RAWTRACE4("startListening(strObjID = %s, argc = %d, strCallbackID = %s, strJsVmID = %s)", strObjID.c_str(), argv.getSize(), strCallbackID.c_str(), strJsVmID.c_str());

#ifdef OS_ANDROID
    if ( jnienv() == 0 )
    {
        rho_nativethread_start();
    }
#endif

    rho::apiGenerator::CMethodResult oRes;


    oRes.setRequestedType(CMethodResult::eStringHash);

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    int argc = argv.getSize();

    rho::ILightsensor* pObj = rho::CLightsensorFactoryBase::getInstance()->getModuleByID(strObjID);

    if ( argc == 0 )
    {
        oRes.setArgError( "Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toJSON();
    }
    
    rho::Hashtable<rho::String, rho::String> arg0;
    if ( argc > 0 )
    {
        CJSONEntry value(argv[0]);
        if ( value.isObject() )
        {
            
            CJSONStructIterator objIter(value);

            for( ; !objIter.isEnd(); objIter.next() )
            {
                arg0[objIter.getCurKey()] = objIter.getCurString();
            }
            
        }
        else if (!value.isNull())
        {
            oRes.setArgError("Type error: argument " "0" " should be " "hash" );
            return oRes.toJSON();
        }
    }

    oRes.setCallInUIThread(false);
    oRes.setJSCallback( strCallbackID );
    oRes.setCallbackParam( strCallbackParam );

    if ( !oRes.hasCallback() )
    {
        oRes.setArgError("Callback argument is missed");
        return oRes.toJSON();
    }

    if ( oRes.hasCallback() )
    {
        pFunctor = rho_makeInstanceClassFunctor2( pObj, &rho::ILightsensor::startListening, arg0,  oRes );
        rho::CLightsensorFactoryBase::getLightsensorSingletonS()->addCommandToQueue( pFunctor );
    }
    else 
    {

        pObj->startListening( arg0,  oRes );
    }
    
    return oRes.toJSON();

}

rho::String js_Lightsensor_stopListening(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    RAWTRACE4("stopListening(strObjID = %s, argc = %d, strCallbackID = %s, strJsVmID = %s)", strObjID.c_str(), argv.getSize(), strCallbackID.c_str(), strJsVmID.c_str());

#ifdef OS_ANDROID
    if ( jnienv() == 0 )
    {
        rho_nativethread_start();
    }
#endif

    rho::apiGenerator::CMethodResult oRes;



    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    int argc = argv.getSize();

    rho::ILightsensor* pObj = rho::CLightsensorFactoryBase::getInstance()->getModuleByID(strObjID);

    if ( oRes.hasCallback() )
    {
        pFunctor = rho_makeInstanceClassFunctor1( pObj, &rho::ILightsensor::stopListening,  oRes );
        rho::CLightsensorFactoryBase::getLightsensorSingletonS()->addCommandToQueue( pFunctor );
    }
    else 
    {

        pObj->stopListening(  oRes );
    }
    
    return oRes.toJSON();

}



rho::String js_s_Lightsensor_getDefaultID(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    rho::apiGenerator::CMethodResult oRes;
    rho::String strDefaultID = rho::CLightsensorFactoryBase::getLightsensorSingletonS()->getDefaultID();
    oRes.set(strDefaultID);

    return oRes.toJSON();
}

rho::String js_s_Lightsensor_getDefault(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    rho::apiGenerator::CMethodResult oRes;
    rho::String strDefaultID = rho::CLightsensorFactoryBase::getLightsensorSingletonS()->getDefaultID();
    oRes.set(strDefaultID);
    oRes.setJSObjectClassPath("Rho.Lightsensor");

    return oRes.toJSON();
}

rho::String js_s_Lightsensor_setDefaultID(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    rho::apiGenerator::CMethodResult oRes;
    rho::json::CJSONEntry el = argv[0];

    if (el.isString()) {
        rho::CLightsensorFactoryBase::getLightsensorSingletonS()->setDefaultID(el.getString());
    } else {
        oRes.setError("Method parameter should be defined as string!");
    }

    return oRes.toJSON();
}


