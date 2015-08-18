#include "api_generator/js_helpers.h"
#include "api_generator/Api.h"

#include "logging/RhoLog.h"
#undef DEFAULT_LOGCATEGORY
#define DEFAULT_LOGCATEGORY "Cordovabarcode"




rho::String js_s_Cordovabarcode_enumerate(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);

rho::String js_Cordovabarcode_scan(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);
rho::String js_s_Cordovabarcode_def_scan(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);



rho::String js_s_Cordovabarcode_getDefaultID(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);
rho::String js_s_Cordovabarcode_getDefault(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);
rho::String js_s_Cordovabarcode_setDefaultID(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);



namespace {
  using namespace rho::apiGenerator;
  class CordovabarcodeDispatcher : public ApiHandler<Func_JS>
  {
  public:
    CordovabarcodeDispatcher() : ApiHandler("Rho:Cordovabarcode") {}
    virtual ~CordovabarcodeDispatcher() {}
    virtual void initialize();
  };
  
  void CordovabarcodeDispatcher::initialize()
  {
    ApiHandler<Func_JS>::initialize();
    
    RAWTRACE("Initializing Rho:Cordovabarcode API...");


    defineStaticMethod("enumerate", js_s_Cordovabarcode_enumerate);


    defineInstanceMethod("scan", js_Cordovabarcode_scan);
    //  should define static method !     defineStaticMethod("def_scan", js_s_Cordovabarcode_def_scan);;


    defineStaticMethod("getDefaultID", js_s_Cordovabarcode_getDefaultID);
    defineStaticMethod("getDefault", js_s_Cordovabarcode_getDefault);
    defineStaticMethod("setDefaultID", js_s_Cordovabarcode_setDefaultID);

    RAWTRACE("Rho:Cordovabarcode API - done");
  }
}

extern "C" void Init_JSAPI_Cordovabarcode(void)
{
  rho::apiGenerator::defineJSApiModule(new CordovabarcodeDispatcher);
}
