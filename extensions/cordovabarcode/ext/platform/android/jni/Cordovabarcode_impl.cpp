#include "rhodes.h"
#include "Cordovabarcode.h"

#include "logging/RhoLog.h"
#undef DEFAULT_LOGCATEGORY
#define DEFAULT_LOGCATEGORY "Cordovabarcode_impl"

#define CORDOVABARCODE_FACTORY_CLASS "com.rho.cordovabarcode.CordovabarcodeFactory"

extern "C" void Init_Cordovabarcode_API(void);

extern "C" void Init_Cordovabarcode(void)
{
    RAWTRACE(__FUNCTION__);

    JNIEnv *env = jnienv();
    if(env)
    {
        jclass cls = rho_find_class(env, CORDOVABARCODE_FACTORY_CLASS);
        if(!cls)
        {
            RAWLOG_ERROR1("Failed to find java class: %s", CORDOVABARCODE_FACTORY_CLASS);
            return;
        }
        jmethodID midFactory = env->GetMethodID(cls, "<init>", "()V");
        if(!midFactory)
        {
            RAWLOG_ERROR1("Failed to get constructor for java class %s", CORDOVABARCODE_FACTORY_CLASS);
            return;
        }
        jobject jFactory = env->NewObject(cls, midFactory);
        if(env->IsSameObject(jFactory, NULL))
        {
            RAWLOG_ERROR1("Failed to create %s instance", CORDOVABARCODE_FACTORY_CLASS);
            return;
        }
        
        RAWTRACE("Initializing Java factory");

        rho::CCordovabarcodeBase::setJavaFactory(env, jFactory);

        RAWTRACE("Deleting JNI reference");

        env->DeleteLocalRef(jFactory);

        RAWTRACE("Initializing API");

        Init_Cordovabarcode_API();

        RAWTRACE("Init_Cordovabarcode succeeded");
    }
    else
    {
        RAWLOG_ERROR("Failed to initialize Cordovabarcode API: jnienv() is failed");
    }

}

extern "C" void Init_Cordovabarcode_extension() {
    Init_Cordovabarcode();
}
