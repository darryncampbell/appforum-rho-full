#include "Cordovabarcode.h"

#include "MethodResultJni.h"

#include "ext/rho/rhoruby.h"
#include "rhodes/JNIRhoRuby.h"

#include "logging/RhoLog.h"
#undef DEFAULT_LOGCATEGORY
#define DEFAULT_LOGCATEGORY "CordovabarcodeRUBY"


typedef rho::CCordovabarcodeProxy<ArgumentsAdapter<std::vector<VALUE> > > ObjectProxy;

using namespace rho::apiGenerator;
extern "C"
{

VALUE getRuby_Cordovabarcode_Module();


VALUE rb_Cordovabarcode_s_default(VALUE klass)
{
    RAWTRACE("rb_Cordovabarcode_s_default");
    return rho_ruby_create_object_with_id(klass, rho::CCordovabarcodeBase::getDefaultID().c_str());
}

VALUE rb_Cordovabarcode_s_setDefault(VALUE klass, VALUE valObj)
{
    RAWTRACE("rb_Cordovabarcode_s_set_default");

    const char* szID = rho_ruby_get_object_id(valObj);
    rho::CCordovabarcodeBase::setDefaultID(szID);

    return rho_ruby_get_NIL();
} 


VALUE rb_s_Cordovabarcode_enumerate(int argc, VALUE *argv)
{
    RAWTRACE2("%s - argc: %d", __FUNCTION__, argc);
    MethodResultJni result(true);
    if(!result)
    {
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        result.setError("JNI error: failed to initialize MethodResult java object");
        return CMethodResultConvertor().toRuby(result, false);
    }
    
    RAWTRACE("MethodResultJni instance is created");


    if((argc < 0) || (argc > 2))
    {
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        result.setArgError("Wrong number of arguments");
        return CMethodResultConvertor().toRuby(result, false);
    }
    
    unsigned realParamCount = (argc < 0) ? argc : 0;
    std::vector<VALUE> arguments(argv, argv + realParamCount);
    
    RAWTRACE1("Count of passed arguments: %d", arguments.size());
    
    if(argc > 0)
    {
        if (rho_ruby_is_proc(argv[0]) || rho_ruby_is_method(argv[0]))
        {
            result.setRubyProcCallBack(argv[0]);
            RAWTRACE("Ruby proc callback is set");
        } else
        {
            if(argc > 1)
                result.setCallBack(argv[0], argv[1]);
            else
                result.setCallBack(argv[0]);
            
            RAWTRACE("Callback URL is set");
        }
        if(!result.hasCallback())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return CMethodResultConvertor().toRuby(result, false);
        }
    }

    result.setObjectClassPath("Rho::Cordovabarcode");
    RAWTRACE("Object class path is set");

    ObjectProxy::enumerate(argumentsAdapter(arguments), result); 
    RAWTRACE("Native metod has invoked, converting result");
    VALUE res = CMethodResultConvertor().toRuby(result, false);
    RAWTRACE(__FUNCTION__);
    return res;
}

static VALUE Cordovabarcode_scan(int argc, VALUE *argv, const rho::String& id)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, id.c_str());
    MethodResultJni result(true);
    if(!result)
    {
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        result.setError("JNI error: failed to initialize MethodResult java object");
        return CMethodResultConvertor().toRuby(result, false);
    }
    
    RAWTRACE("MethodResultJni instance is created");

    ObjectProxy cordovabarcode(id);

    if((argc < 2) || (argc > 3))
    {
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        result.setArgError("Wrong number of arguments");
        return CMethodResultConvertor().toRuby(result, false);
    }
    
    unsigned realParamCount = (argc < 1) ? argc : 1;
    std::vector<VALUE> arguments(argv, argv + realParamCount);
    
    RAWTRACE1("Count of passed arguments: %d", arguments.size());
    
    if(argc > 1)
    {
        if (rho_ruby_is_proc(argv[1]) || rho_ruby_is_method(argv[1]))
        {
            result.setRubyProcCallBack(argv[1]);
            RAWTRACE("Ruby proc callback is set");
        } else
        {
            if(argc > 2)
                result.setCallBack(argv[1], argv[2]);
            else
                result.setCallBack(argv[1]);
            
            RAWTRACE("Callback URL is set");
        }
        if(!result.hasCallback())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return CMethodResultConvertor().toRuby(result, false);
        }
    }

    cordovabarcode.scan(argumentsAdapter(arguments), result); 
    RAWTRACE("Native metod has invoked, converting result");
    VALUE res = CMethodResultConvertor().toRuby(result, false);
    RAWTRACE(__FUNCTION__);
    return res;
}
VALUE rb_Cordovabarcode_scan(int argc, VALUE *argv, VALUE obj)
{
    rho::String id = rho_ruby_get_object_id(obj);
    return Cordovabarcode_scan(argc, argv, id);
}

VALUE rb_s_Cordovabarcode_def_scan(int argc, VALUE *argv)
{
    rho::String id = ObjectProxy::getDefaultID();
    return Cordovabarcode_scan(argc, argv, id);
}
}
