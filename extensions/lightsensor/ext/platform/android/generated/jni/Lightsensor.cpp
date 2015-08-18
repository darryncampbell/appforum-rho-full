#include "Lightsensor.h"


namespace rho {

IMPLEMENT_LOGCLASS(CLightsensorBase, "LightsensorJNI");

//LightsensorFactorySingleton staff
const char* const CLightsensorBase::FACTORY_SINGLETON_CLASS = "com.rho.lightsensor.LightsensorFactorySingleton";
jclass CLightsensorBase::s_clsFactorySingleton = 0;
jmethodID CLightsensorBase::s_midFactorySetInstance;
jmethodID CLightsensorBase::s_midFactoryGetInstance;

//LightsensorFactory staff
const char* const CLightsensorBase::IFACTORY_CLASS = "com.rho.lightsensor.ILightsensorFactory";
jclass CLightsensorBase::s_clsIFactory = 0;
jmethodID CLightsensorBase::s_midGetApiSingleton;
jmethodID CLightsensorBase::s_midGetApiObject;

//LightsensorSingletonBase staff
const char* const CLightsensorBase::SINGLETON_BASE_CLASS = "com.rho.lightsensor.LightsensorSingletonBase";
jclass CLightsensorBase::s_clsSingletonBase = 0;

//LightsensorBase staff
const char* const CLightsensorBase::OBJECT_BASE_CLASS = "com.rho.lightsensor.LightsensorBase";
jclass CLightsensorBase::s_clsObjectBase = 0;


//IRhoApiDefaultId staff
const char* const CLightsensorBase::IDEFAULTID_CLASS = "com.rhomobile.rhodes.api.IRhoApiDefaultId";
jclass CLightsensorBase::s_clsIDefaultId = 0;
jmethodID CLightsensorBase::s_midGetDefaultID;
jmethodID CLightsensorBase::s_midSetDefaultID;


//Method tasks

const char* const CLightsensorBase::GETDELAY_TASK_CLASS = 
        "com.rho.lightsensor.LightsensorBase$getDelayTask";

jclass CLightsensorBase::s_clsgetDelayTask = 0;
jmethodID CLightsensorBase::s_midgetDelayTask;

const char* const CLightsensorBase::SETDELAY_TASK_CLASS = 
        "com.rho.lightsensor.LightsensorBase$setDelayTask";

jclass CLightsensorBase::s_clssetDelayTask = 0;
jmethodID CLightsensorBase::s_midsetDelayTask;

const char* const CLightsensorBase::ENUMERATE_TASK_CLASS = 
        "com.rho.lightsensor.LightsensorSingletonBase$enumerateTask";

jclass CLightsensorBase::s_clsenumerateTask = 0;
jmethodID CLightsensorBase::s_midenumerateTask;

const char* const CLightsensorBase::STARTLISTENING_TASK_CLASS = 
        "com.rho.lightsensor.LightsensorBase$startListeningTask";

jclass CLightsensorBase::s_clsstartListeningTask = 0;
jmethodID CLightsensorBase::s_midstartListeningTask;

const char* const CLightsensorBase::STOPLISTENING_TASK_CLASS = 
        "com.rho.lightsensor.LightsensorBase$stopListeningTask";

jclass CLightsensorBase::s_clsstopListeningTask = 0;
jmethodID CLightsensorBase::s_midstopListeningTask;


//----------------------------------------------------------------------------------------------------------------------

JNIEnv* CLightsensorBase::jniInit()
{
    JNIEnv *env = jnienv();
    if(!env)
    {
        LOG(FATAL) + "JNI init failed: JNIEnv is null";
        return 0;
    }
    return jniInit(env);
}
//----------------------------------------------------------------------------------------------------------------------

JNIEnv* CLightsensorBase::jniInit(JNIEnv* env)
{
    static bool initialized = false;
    env = MethodExecutorJni::jniInit(env);
    if (!env) {
        LOG(FATAL) + "JNI init failed";
        return 0;
    }

    if(!initialized)
    {
        //init LightsensorFactorySingleton JNI
        s_clsFactorySingleton = loadClass(env, FACTORY_SINGLETON_CLASS);
        if (!s_clsFactorySingleton) return 0;

        s_midFactorySetInstance = env->GetStaticMethodID(s_clsFactorySingleton, "setInstance", "(Lcom/rho/lightsensor/ILightsensorFactory;)V");
        if(!s_midFactorySetInstance)
        {
            LOG(FATAL) + "Failed to get method 'setInstance' for java class " + FACTORY_SINGLETON_CLASS;
            return NULL;
        }
        s_midFactoryGetInstance = env->GetStaticMethodID(s_clsFactorySingleton, "getInstance", "()Lcom/rho/lightsensor/ILightsensorFactory;");
        if(!s_midFactoryGetInstance)
        {
            LOG(FATAL) + "Failed to get method 'getInstance' for java class " + FACTORY_SINGLETON_CLASS;
            return NULL;
        }

        //init ILightsensorFactory JNI
        s_clsIFactory = loadClass(env, IFACTORY_CLASS);
        if (!s_clsIFactory) return 0;
        s_midGetApiSingleton = env->GetMethodID(s_clsIFactory, "getApiSingleton", "()Lcom/rho/lightsensor/ILightsensorSingleton;");
        if(!s_midGetApiSingleton)
        {
            LOG(FATAL) + "Failed to get method 'getApiSingleton' for java class " + IFACTORY_CLASS;
            return NULL;
        }
        s_midGetApiObject = env->GetMethodID(s_clsIFactory, "getApiObject", "(Ljava/lang/String;)Lcom/rho/lightsensor/ILightsensor;");
        if(!s_midGetApiObject)
        {
            LOG(FATAL) + "Failed to get method 'getApiObject' for java class " + IFACTORY_CLASS;
            return NULL;
        }

        s_clsSingletonBase = loadClass(env, SINGLETON_BASE_CLASS);
        if (!s_clsSingletonBase) return 0;
        s_clsObjectBase = loadClass(env, OBJECT_BASE_CLASS);
        if (!s_clsObjectBase) return 0;



        s_clsgetDelayTask = loadClass(env, GETDELAY_TASK_CLASS);
        if (!s_clsgetDelayTask) return 0;
        s_midgetDelayTask = env->GetMethodID(s_clsgetDelayTask, "<init>",
                        "(Lcom/rho/lightsensor/ILightsensor;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midgetDelayTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + GETDELAY_TASK_CLASS;
            return NULL;
        }

        s_clssetDelayTask = loadClass(env, SETDELAY_TASK_CLASS);
        if (!s_clssetDelayTask) return 0;
        s_midsetDelayTask = env->GetMethodID(s_clssetDelayTask, "<init>",
                        "(Lcom/rho/lightsensor/ILightsensor;ILcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midsetDelayTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + SETDELAY_TASK_CLASS;
            return NULL;
        }

        s_clsenumerateTask = loadClass(env, ENUMERATE_TASK_CLASS);
        if (!s_clsenumerateTask) return 0;
        s_midenumerateTask = env->GetMethodID(s_clsenumerateTask, "<init>",
                        "(Lcom/rho/lightsensor/ILightsensorSingleton;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midenumerateTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + ENUMERATE_TASK_CLASS;
            return NULL;
        }

        s_clsstartListeningTask = loadClass(env, STARTLISTENING_TASK_CLASS);
        if (!s_clsstartListeningTask) return 0;
        s_midstartListeningTask = env->GetMethodID(s_clsstartListeningTask, "<init>",
                        "(Lcom/rho/lightsensor/ILightsensor;Ljava/util/Map;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midstartListeningTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + STARTLISTENING_TASK_CLASS;
            return NULL;
        }

        s_clsstopListeningTask = loadClass(env, STOPLISTENING_TASK_CLASS);
        if (!s_clsstopListeningTask) return 0;
        s_midstopListeningTask = env->GetMethodID(s_clsstopListeningTask, "<init>",
                        "(Lcom/rho/lightsensor/ILightsensor;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midstopListeningTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + STOPLISTENING_TASK_CLASS;
            return NULL;
        }


        s_clsIDefaultId = loadClass(env, IDEFAULTID_CLASS);
        if (!s_clsIDefaultId) return 0;
        s_midGetDefaultID = env->GetMethodID(s_clsIDefaultId, "getDefaultID", "()Ljava/lang/String;");
        if(!s_midGetDefaultID)
        {
            LOG(FATAL) + "Failed to get method 'getDefaultID' for java class " + IDEFAULTID_CLASS;
            return NULL;
        }
        s_midSetDefaultID = env->GetMethodID(s_clsIDefaultId, "setDefaultID", "(Ljava/lang/String;)V");
        if(!s_midSetDefaultID)
        {
            LOG(FATAL) + "Failed to get method 'setDefaultID' for java class " + IDEFAULTID_CLASS;
            return NULL;
        }


        initialized = true;
        LOG(TRACE) + "CLightsensor JNI init succeeded";
    }
    return env;
}
//----------------------------------------------------------------------------------------------------------------------

void CLightsensorBase::setJavaFactory(JNIEnv* env, jobject jFactory)
{
    LOG(TRACE) + "setJavaFactory";

    env = jniInit(env);
    if (!env) {
        LOG(FATAL) + "JNI initialization failed";
        return;
    }

    env->CallStaticVoidMethod(s_clsFactorySingleton, s_midFactorySetInstance, jFactory);

    LOG(TRACE) + "setJavaFactory succeeded";
}
//----------------------------------------------------------------------------------------------------------------------

rho::String CLightsensorBase::getDefaultID()
{
    LOG(TRACE) + "getDefaultID";

    JNIEnv *env = jniInit();
    if (!env) {
        LOG(FATAL) + "JNI initialization failed";
        return rho::String();
    }

    jhobject jhSingleton = getSingleton(env);
    jhstring res = static_cast<jstring>(env->CallObjectMethod(jhSingleton.get(), s_midGetDefaultID));
    return rho_cast<rho::String>(env, res);
}
//----------------------------------------------------------------------------------------------------------------------

void CLightsensorBase::setDefaultID(const rho::String& id)
{
    LOG(TRACE) + "setDefaultID: " + id;

    JNIEnv *env = jniInit();
    if (!env) {
        LOG(FATAL) + "JNI initialization failed";
        return;
    }

    jhobject instance = getSingleton(env);
    jhstring jhId = rho_cast<jstring>(env, id);
    env->CallVoidMethod(instance.get(), s_midSetDefaultID, jhId.get());
}
//----------------------------------------------------------------------------------------------------------------------

jobject CLightsensorBase::getFactory(JNIEnv* env)
{
    jobject res = env->CallStaticObjectMethod(s_clsFactorySingleton, s_midFactoryGetInstance);
    return res;
}
//----------------------------------------------------------------------------------------------------------------------

jobject CLightsensorBase::getSingleton(JNIEnv* env)
{
    jhobject jhFactory = getFactory(env);
    jobject res = env->CallObjectMethod(jhFactory.get(), s_midGetApiSingleton);
    return res;
}
//----------------------------------------------------------------------------------------------------------------------

jobject CLightsensorBase::getObject(JNIEnv* env)
{
    jhstring jhId = rho_cast<jstring>(env, m_id);
    jhobject jhFactory = getFactory(env);
    jobject res = env->CallObjectMethod(jhFactory.get(), s_midGetApiObject, jhId.get());
    return res;
}
//----------------------------------------------------------------------------------------------------------------------


}
