
#include "LightsensorBase.h"

#include "logging/RhoLog.h"
#undef DEFAULT_LOGCATEGORY
#define DEFAULT_LOGCATEGORY "Lightsensor"

#include "api_generator/RubyResultConvertor.h"

#include "ruby/ext/rho/rhoruby.h"
#include "common/StringConverter.h"
#include "common/AutoPointer.h"

using namespace rho;
using namespace rho::common;
using namespace rho::apiGenerator;

extern "C"
{
void rho_os_impl_performOnUiThread(rho::common::IRhoRunnable* pTask);
VALUE getRuby_Lightsensor_Module();


VALUE rb_Lightsensor_s_default(VALUE klass)
{
    rho::String strDefaultID = rho::CLightsensorFactoryBase::getLightsensorSingletonS()->getDefaultID();

    return rho_ruby_create_object_with_id( klass, strDefaultID.c_str() );
}

VALUE rb_Lightsensor_s_setDefault(VALUE klass, VALUE valObj)
{
    const char* szID = rho_ruby_get_object_id( valObj );
    rho::CLightsensorFactoryBase::getLightsensorSingletonS()->setDefaultID(szID);

    return rho_ruby_get_NIL();
}


static void string_iter(const char* szVal, int valueLen, void* par)
{
    rho::Vector<rho::String>& ar = *((rho::Vector<rho::String>*)(par));
    ar.addElement( rho::String(szVal,valueLen) );
}

static void getStringArrayFromValue(VALUE val, rho::Vector<rho::String>& res)
{
    rho_ruby_enum_strary_json(val, string_iter, &res);
}

static void hash_eachstr(const char* szName, const char* szVal, int valueLen, void* par)
{
    rho::Hashtable<rho::String, rho::String>& hash = *((rho::Hashtable<rho::String, rho::String>*)(par));
    hash.put( szName, rho::String(szVal,valueLen) );
}

static void getStringHashFromValue(VALUE val, rho::Hashtable<rho::String, rho::String>& res)
{
    rho_ruby_enum_strhash_json(val, hash_eachstr, &res);
}
    
static rho::String getStringObjectFromValue(VALUE val)
{
    return rho::String(getStringFromValue(val),getStringLenFromValue(val));
}


static VALUE _api_generator_Lightsensor_getDelay(int argc, VALUE *argv, rho::ILightsensor* pObj)
{
    rho::apiGenerator::CMethodResult oRes;

    oRes.setRequestedType(CMethodResult::eInt);
    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(0) );
        return oRes.toRuby();
    }
    if ( bUseCallback )
    {
        pFunctor = rho_makeInstanceClassFunctor1( pObj, &rho::ILightsensor::getDelay,  oRes );
        rho::CLightsensorFactoryBase::getLightsensorSingletonS()->addCommandToQueue( pFunctor );
    }
    else 
    {

        pObj->getDelay(  oRes );
    }
    
    return oRes.toRuby();
}



VALUE rb_Lightsensor_getDelay(int argc, VALUE *argv, VALUE obj)
{
    const char* szID = rho_ruby_get_object_id( obj );
    if (!szID)
        rho_ruby_raise_runtime("Object was deleted.");

    VALUE res = 0;
    rho::ILightsensor* pObj =  rho::CLightsensorFactoryBase::getInstance()->getModuleByID(szID);

    res = _api_generator_Lightsensor_getDelay(argc, argv, pObj);

    return res;
}



VALUE rb_s_Lightsensor_def_getDelay(int argc, VALUE *argv)
{
    rho::String strDefaultID = rho::CLightsensorFactoryBase::getLightsensorSingletonS()->getDefaultID();
    rho::ILightsensor* pObj = rho::CLightsensorFactoryBase::getInstance()->getModuleByID(strDefaultID);

    return _api_generator_Lightsensor_getDelay(argc, argv, pObj);
}


static VALUE _api_generator_Lightsensor_setDelay(int argc, VALUE *argv, rho::ILightsensor* pObj)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    nCallbackArg = 1;
    if ( argc == 0 )
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toRuby();
    }
    int arg0 = 0;
    if ( argc > 0 )
    {
        if ( rho_ruby_is_integer(argv[0]) )
            arg0 = rho_ruby_get_int(argv[0]);
        else if (!rho_ruby_is_NIL(argv[0]))
        {
            oRes.setArgError("Type error: argument " "0" " should be " "integer" );
            return oRes.toRuby();
        }
    }

    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toRuby();
    }
    if ( bUseCallback )
    {
        pFunctor = rho_makeInstanceClassFunctor2( pObj, &rho::ILightsensor::setDelay, arg0,  oRes );
        rho::CLightsensorFactoryBase::getLightsensorSingletonS()->addCommandToQueue( pFunctor );
    }
    else 
    {

        pObj->setDelay( arg0,  oRes );
    }
    
    return oRes.toRuby();
}



VALUE rb_Lightsensor_setDelay(int argc, VALUE *argv, VALUE obj)
{
    const char* szID = rho_ruby_get_object_id( obj );
    if (!szID)
        rho_ruby_raise_runtime("Object was deleted.");

    VALUE res = 0;
    rho::ILightsensor* pObj =  rho::CLightsensorFactoryBase::getInstance()->getModuleByID(szID);

    res = _api_generator_Lightsensor_setDelay(argc, argv, pObj);

    return res;
}



VALUE rb_s_Lightsensor_def_setDelay(int argc, VALUE *argv)
{
    rho::String strDefaultID = rho::CLightsensorFactoryBase::getLightsensorSingletonS()->getDefaultID();
    rho::ILightsensor* pObj = rho::CLightsensorFactoryBase::getInstance()->getModuleByID(strDefaultID);

    return _api_generator_Lightsensor_setDelay(argc, argv, pObj);
}


VALUE rb_s_Lightsensor_enumerate(int argc, VALUE *argv)
{
    rho::apiGenerator::CMethodResult oRes;

    oRes.setParamName( "result" );
    oRes.setRubyObjectClass( getRuby_Lightsensor_Module() );
    oRes.setRequestedType(CMethodResult::eStringArray);
    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    if ( argc > nCallbackArg )
    {

        if ( rho_ruby_is_proc(argv[nCallbackArg]) || rho_ruby_is_method(argv[nCallbackArg]) )
        {
            oRes.setRubyCallbackProc( argv[nCallbackArg] );
        }else if ( rho_ruby_is_string(argv[nCallbackArg]) )
        {
            oRes.setRubyCallback( getStringObjectFromValue(argv[nCallbackArg]) );
        }else
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toRuby();
        }

        oRes.setCallInUIThread(false);
        if ( argc > nCallbackArg + 1 )
        {
            if ( !rho_ruby_is_NIL(argv[nCallbackArg + 1]) )
            {
                if ( !rho_ruby_is_string(argv[nCallbackArg + 1]) )
                {
                    oRes.setArgError("Type error: callback parameter should be String");
                    return oRes.toRuby();
                }

                oRes.setCallbackParam( getStringObjectFromValue(argv[nCallbackArg + 1]) );
            }
        }
        
        bUseCallback = true;
    }
    if ( bUseCallback )
    {
        pFunctor = rho_makeInstanceClassFunctor1( rho::CLightsensorFactoryBase::getLightsensorSingletonS(), &rho::ILightsensorSingleton::enumerate,  oRes );
        rho::CLightsensorFactoryBase::getLightsensorSingletonS()->addCommandToQueue( pFunctor );
    }
    else 
    {

        rho::CLightsensorFactoryBase::getLightsensorSingletonS()->enumerate(  oRes );
    }
    
    return oRes.toRuby();
}






static VALUE _api_generator_Lightsensor_startListening(int argc, VALUE *argv, rho::ILightsensor* pObj)
{
    rho::apiGenerator::CMethodResult oRes;

    oRes.setRequestedType(CMethodResult::eStringHash);
    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    nCallbackArg = 1;
    if ( argc == 0 )
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toRuby();
    }
    rho::Hashtable<rho::String, rho::String> arg0;
    if ( argc > 0 )
    {
        if ( rho_ruby_is_hash(argv[0]) )
        {
            rho::String res;
            rho_value_to_typed_hash<rho::String, rho::String>(argv[0], arg0, res);
        }
        else if (!rho_ruby_is_NIL(argv[0]))
        {
            oRes.setArgError("Type error: argument " "0" " should be " "hash" );
            return oRes.toRuby();
        }
    }

    if ( argc > nCallbackArg )
    {

        if ( rho_ruby_is_proc(argv[nCallbackArg]) || rho_ruby_is_method(argv[nCallbackArg]) )
        {
            oRes.setRubyCallbackProc( argv[nCallbackArg] );
        }else if ( rho_ruby_is_string(argv[nCallbackArg]) )
        {
            oRes.setRubyCallback( getStringObjectFromValue(argv[nCallbackArg]) );
        }else
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toRuby();
        }

        oRes.setCallInUIThread(false);
        if ( argc > nCallbackArg + 1 )
        {
            if ( !rho_ruby_is_NIL(argv[nCallbackArg + 1]) )
            {
                if ( !rho_ruby_is_string(argv[nCallbackArg + 1]) )
                {
                    oRes.setArgError("Type error: callback parameter should be String");
                    return oRes.toRuby();
                }

                oRes.setCallbackParam( getStringObjectFromValue(argv[nCallbackArg + 1]) );
            }
        }
        
        bUseCallback = true;
    }
    else
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(2) + ".Mandatory Callback parameter is mised." );
        return oRes.toRuby();
    }
    if ( bUseCallback )
    {
        pFunctor = rho_makeInstanceClassFunctor2( pObj, &rho::ILightsensor::startListening, arg0,  oRes );
        rho::CLightsensorFactoryBase::getLightsensorSingletonS()->addCommandToQueue( pFunctor );
    }
    else 
    {

        pObj->startListening( arg0,  oRes );
    }
    
    return oRes.toRuby();
}



VALUE rb_Lightsensor_startListening(int argc, VALUE *argv, VALUE obj)
{
    const char* szID = rho_ruby_get_object_id( obj );
    if (!szID)
        rho_ruby_raise_runtime("Object was deleted.");

    VALUE res = 0;
    rho::ILightsensor* pObj =  rho::CLightsensorFactoryBase::getInstance()->getModuleByID(szID);

    res = _api_generator_Lightsensor_startListening(argc, argv, pObj);

    return res;
}



VALUE rb_s_Lightsensor_def_startListening(int argc, VALUE *argv)
{
    rho::String strDefaultID = rho::CLightsensorFactoryBase::getLightsensorSingletonS()->getDefaultID();
    rho::ILightsensor* pObj = rho::CLightsensorFactoryBase::getInstance()->getModuleByID(strDefaultID);

    return _api_generator_Lightsensor_startListening(argc, argv, pObj);
}


static VALUE _api_generator_Lightsensor_stopListening(int argc, VALUE *argv, rho::ILightsensor* pObj)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(0) );
        return oRes.toRuby();
    }
    if ( bUseCallback )
    {
        pFunctor = rho_makeInstanceClassFunctor1( pObj, &rho::ILightsensor::stopListening,  oRes );
        rho::CLightsensorFactoryBase::getLightsensorSingletonS()->addCommandToQueue( pFunctor );
    }
    else 
    {

        pObj->stopListening(  oRes );
    }
    
    return oRes.toRuby();
}



VALUE rb_Lightsensor_stopListening(int argc, VALUE *argv, VALUE obj)
{
    const char* szID = rho_ruby_get_object_id( obj );
    if (!szID)
        rho_ruby_raise_runtime("Object was deleted.");

    VALUE res = 0;
    rho::ILightsensor* pObj =  rho::CLightsensorFactoryBase::getInstance()->getModuleByID(szID);

    res = _api_generator_Lightsensor_stopListening(argc, argv, pObj);

    return res;
}



VALUE rb_s_Lightsensor_def_stopListening(int argc, VALUE *argv)
{
    rho::String strDefaultID = rho::CLightsensorFactoryBase::getLightsensorSingletonS()->getDefaultID();
    rho::ILightsensor* pObj = rho::CLightsensorFactoryBase::getInstance()->getModuleByID(strDefaultID);

    return _api_generator_Lightsensor_stopListening(argc, argv, pObj);
}



}