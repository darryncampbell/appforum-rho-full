#include "Cordovabarcode.h"


namespace rho {

IMPLEMENT_LOGCLASS(CCordovabarcodeBase, "CordovabarcodeJNI");

//CordovabarcodeFactorySingleton staff
const char* const CCordovabarcodeBase::FACTORY_SINGLETON_CLASS = "com.rho.cordovabarcode.CordovabarcodeFactorySingleton";
jclass CCordovabarcodeBase::s_clsFactorySingleton = 0;
jmethodID CCordovabarcodeBase::s_midFactorySetInstance;
jmethodID CCordovabarcodeBase::s_midFactoryGetInstance;

//CordovabarcodeFactory staff
const char* const CCordovabarcodeBase::IFACTORY_CLASS = "com.rho.cordovabarcode.ICordovabarcodeFactory";
jclass CCordovabarcodeBase::s_clsIFactory = 0;
jmethodID CCordovabarcodeBase::s_midGetApiSingleton;
jmethodID CCordovabarcodeBase::s_midGetApiObject;

//CordovabarcodeSingletonBase staff
const char* const CCordovabarcodeBase::SINGLETON_BASE_CLASS = "com.rho.cordovabarcode.CordovabarcodeSingletonBase";
jclass CCordovabarcodeBase::s_clsSingletonBase = 0;

//CordovabarcodeBase staff
const char* const CCordovabarcodeBase::OBJECT_BASE_CLASS = "com.rho.cordovabarcode.CordovabarcodeBase";
jclass CCordovabarcodeBase::s_clsObjectBase = 0;


//IRhoApiDefaultId staff
const char* const CCordovabarcodeBase::IDEFAULTID_CLASS = "com.rhomobile.rhodes.api.IRhoApiDefaultId";
jclass CCordovabarcodeBase::s_clsIDefaultId = 0;
jmethodID CCordovabarcodeBase::s_midGetDefaultID;
jmethodID CCordovabarcodeBase::s_midSetDefaultID;


//Method tasks

const char* const CCordovabarcodeBase::ENUMERATE_TASK_CLASS = 
        "com.rho.cordovabarcode.CordovabarcodeSingletonBase$enumerateTask";

jclass CCordovabarcodeBase::s_clsenumerateTask = 0;
jmethodID CCordovabarcodeBase::s_midenumerateTask;

const char* const CCordovabarcodeBase::SCAN_TASK_CLASS = 
        "com.rho.cordovabarcode.CordovabarcodeBase$scanTask";

jclass CCordovabarcodeBase::s_clsscanTask = 0;
jmethodID CCordovabarcodeBase::s_midscanTask;


//----------------------------------------------------------------------------------------------------------------------

JNIEnv* CCordovabarcodeBase::jniInit()
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

JNIEnv* CCordovabarcodeBase::jniInit(JNIEnv* env)
{
    static bool initialized = false;
    env = MethodExecutorJni::jniInit(env);
    if (!env) {
        LOG(FATAL) + "JNI init failed";
        return 0;
    }

    if(!initialized)
    {
        //init CordovabarcodeFactorySingleton JNI
        s_clsFactorySingleton = loadClass(env, FACTORY_SINGLETON_CLASS);
        if (!s_clsFactorySingleton) return 0;

        s_midFactorySetInstance = env->GetStaticMethodID(s_clsFactorySingleton, "setInstance", "(Lcom/rho/cordovabarcode/ICordovabarcodeFactory;)V");
        if(!s_midFactorySetInstance)
        {
            LOG(FATAL) + "Failed to get method 'setInstance' for java class " + FACTORY_SINGLETON_CLASS;
            return NULL;
        }
        s_midFactoryGetInstance = env->GetStaticMethodID(s_clsFactorySingleton, "getInstance", "()Lcom/rho/cordovabarcode/ICordovabarcodeFactory;");
        if(!s_midFactoryGetInstance)
        {
            LOG(FATAL) + "Failed to get method 'getInstance' for java class " + FACTORY_SINGLETON_CLASS;
            return NULL;
        }

        //init ICordovabarcodeFactory JNI
        s_clsIFactory = loadClass(env, IFACTORY_CLASS);
        if (!s_clsIFactory) return 0;
        s_midGetApiSingleton = env->GetMethodID(s_clsIFactory, "getApiSingleton", "()Lcom/rho/cordovabarcode/ICordovabarcodeSingleton;");
        if(!s_midGetApiSingleton)
        {
            LOG(FATAL) + "Failed to get method 'getApiSingleton' for java class " + IFACTORY_CLASS;
            return NULL;
        }
        s_midGetApiObject = env->GetMethodID(s_clsIFactory, "getApiObject", "(Ljava/lang/String;)Lcom/rho/cordovabarcode/ICordovabarcode;");
        if(!s_midGetApiObject)
        {
            LOG(FATAL) + "Failed to get method 'getApiObject' for java class " + IFACTORY_CLASS;
            return NULL;
        }

        s_clsSingletonBase = loadClass(env, SINGLETON_BASE_CLASS);
        if (!s_clsSingletonBase) return 0;
        s_clsObjectBase = loadClass(env, OBJECT_BASE_CLASS);
        if (!s_clsObjectBase) return 0;



        s_clsenumerateTask = loadClass(env, ENUMERATE_TASK_CLASS);
        if (!s_clsenumerateTask) return 0;
        s_midenumerateTask = env->GetMethodID(s_clsenumerateTask, "<init>",
                        "(Lcom/rho/cordovabarcode/ICordovabarcodeSingleton;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midenumerateTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + ENUMERATE_TASK_CLASS;
            return NULL;
        }

        s_clsscanTask = loadClass(env, SCAN_TASK_CLASS);
        if (!s_clsscanTask) return 0;
        s_midscanTask = env->GetMethodID(s_clsscanTask, "<init>",
                        "(Lcom/rho/cordovabarcode/ICordovabarcode;Ljava/util/Map;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midscanTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + SCAN_TASK_CLASS;
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
        LOG(TRACE) + "CCordovabarcode JNI init succeeded";
    }
    return env;
}
//----------------------------------------------------------------------------------------------------------------------

void CCordovabarcodeBase::setJavaFactory(JNIEnv* env, jobject jFactory)
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

rho::String CCordovabarcodeBase::getDefaultID()
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

void CCordovabarcodeBase::setDefaultID(const rho::String& id)
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

jobject CCordovabarcodeBase::getFactory(JNIEnv* env)
{
    jobject res = env->CallStaticObjectMethod(s_clsFactorySingleton, s_midFactoryGetInstance);
    return res;
}
//----------------------------------------------------------------------------------------------------------------------

jobject CCordovabarcodeBase::getSingleton(JNIEnv* env)
{
    jhobject jhFactory = getFactory(env);
    jobject res = env->CallObjectMethod(jhFactory.get(), s_midGetApiSingleton);
    return res;
}
//----------------------------------------------------------------------------------------------------------------------

jobject CCordovabarcodeBase::getObject(JNIEnv* env)
{
    jhstring jhId = rho_cast<jstring>(env, m_id);
    jhobject jhFactory = getFactory(env);
    jobject res = env->CallObjectMethod(jhFactory.get(), s_midGetApiObject, jhId.get());
    return res;
}
//----------------------------------------------------------------------------------------------------------------------


}
