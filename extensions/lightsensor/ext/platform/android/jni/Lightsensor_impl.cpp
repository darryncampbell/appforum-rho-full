#include "rhodes.h"
#include "Lightsensor.h"

#include "logging/RhoLog.h"
#undef DEFAULT_LOGCATEGORY
#define DEFAULT_LOGCATEGORY "Lightsensor_impl"

#define LIGHTSENSOR_FACTORY_CLASS "com.rho.lightsensor.LightsensorFactory"

extern "C" void Init_Lightsensor_API(void);

extern "C" void Init_Lightsensor(void)
{
    RAWTRACE(__FUNCTION__);

    JNIEnv *env = jnienv();
    if(env)
    {
        jclass cls = rho_find_class(env, LIGHTSENSOR_FACTORY_CLASS);
        if(!cls)
        {
            RAWLOG_ERROR1("Failed to find java class: %s", LIGHTSENSOR_FACTORY_CLASS);
            return;
        }
        jmethodID midFactory = env->GetMethodID(cls, "<init>", "()V");
        if(!midFactory)
        {
            RAWLOG_ERROR1("Failed to get constructor for java class %s", LIGHTSENSOR_FACTORY_CLASS);
            return;
        }
        jobject jFactory = env->NewObject(cls, midFactory);
        if(env->IsSameObject(jFactory, NULL))
        {
            RAWLOG_ERROR1("Failed to create %s instance", LIGHTSENSOR_FACTORY_CLASS);
            return;
        }
        
        RAWTRACE("Initializing Java factory");

        rho::CLightsensorBase::setJavaFactory(env, jFactory);

        RAWTRACE("Deleting JNI reference");

        env->DeleteLocalRef(jFactory);

        RAWTRACE("Initializing API");

        Init_Lightsensor_API();

        RAWTRACE("Init_Lightsensor succeeded");
    }
    else
    {
        RAWLOG_ERROR("Failed to initialize Lightsensor API: jnienv() is failed");
    }

}

extern "C" void Init_Lightsensor_extension() {
    Init_Lightsensor();
}
