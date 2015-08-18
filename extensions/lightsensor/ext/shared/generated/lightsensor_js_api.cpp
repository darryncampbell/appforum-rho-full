#include "api_generator/js_helpers.h"
#include "api_generator/Api.h"

#include "logging/RhoLog.h"
#undef DEFAULT_LOGCATEGORY
#define DEFAULT_LOGCATEGORY "Lightsensor"




rho::String js_Lightsensor_getDelay(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);
rho::String js_s_Lightsensor_def_getDelay(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);

rho::String js_Lightsensor_setDelay(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);
rho::String js_s_Lightsensor_def_setDelay(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);

rho::String js_s_Lightsensor_enumerate(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);

rho::String js_Lightsensor_startListening(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);
rho::String js_s_Lightsensor_def_startListening(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);

rho::String js_Lightsensor_stopListening(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);
rho::String js_s_Lightsensor_def_stopListening(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);



rho::String js_s_Lightsensor_getDefaultID(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);
rho::String js_s_Lightsensor_getDefault(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);
rho::String js_s_Lightsensor_setDefaultID(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);



namespace {
  using namespace rho::apiGenerator;
  class LightsensorDispatcher : public ApiHandler<Func_JS>
  {
  public:
    LightsensorDispatcher() : ApiHandler("Rho:Lightsensor") {}
    virtual ~LightsensorDispatcher() {}
    virtual void initialize();
  };
  
  void LightsensorDispatcher::initialize()
  {
    ApiHandler<Func_JS>::initialize();
    
    RAWTRACE("Initializing Rho:Lightsensor API...");


    defineInstanceMethod("delay", js_Lightsensor_getDelay);
    //  should define static method !     defineStaticMethod("def_delay", js_s_Lightsensor_def_getDelay);;


    defineInstanceMethod("delay=", js_Lightsensor_setDelay);
    //  should define static method !     defineStaticMethod("def_delay=", js_s_Lightsensor_def_setDelay);;


    defineStaticMethod("enumerate", js_s_Lightsensor_enumerate);


    defineInstanceMethod("startListening", js_Lightsensor_startListening);
    //  should define static method !     defineStaticMethod("def_startListening", js_s_Lightsensor_def_startListening);;


    defineInstanceMethod("stopListening", js_Lightsensor_stopListening);
    //  should define static method !     defineStaticMethod("def_stopListening", js_s_Lightsensor_def_stopListening);;


    defineStaticMethod("getDefaultID", js_s_Lightsensor_getDefaultID);
    defineStaticMethod("getDefault", js_s_Lightsensor_getDefault);
    defineStaticMethod("setDefaultID", js_s_Lightsensor_setDefaultID);

    RAWTRACE("Rho:Lightsensor API - done");
  }
}

extern "C" void Init_JSAPI_Lightsensor(void)
{
  rho::apiGenerator::defineJSApiModule(new LightsensorDispatcher);
}
