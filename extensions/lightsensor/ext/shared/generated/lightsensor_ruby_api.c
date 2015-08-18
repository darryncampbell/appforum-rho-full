#include "ruby.h"

static VALUE rb_api_mParent;
static VALUE rb_api_mLightsensor;

VALUE rb_Lightsensor_getDelay(int argc, VALUE *argv, VALUE obj);
VALUE rb_s_Lightsensor_def_getDelay(int argc, VALUE *argv);
VALUE rb_Lightsensor_setDelay(int argc, VALUE *argv, VALUE obj);
VALUE rb_s_Lightsensor_def_setDelay(int argc, VALUE *argv);
VALUE rb_s_Lightsensor_enumerate(int argc, VALUE *argv);
VALUE rb_Lightsensor_startListening(int argc, VALUE *argv, VALUE obj);
VALUE rb_s_Lightsensor_def_startListening(int argc, VALUE *argv);
VALUE rb_Lightsensor_stopListening(int argc, VALUE *argv, VALUE obj);
VALUE rb_s_Lightsensor_def_stopListening(int argc, VALUE *argv);



VALUE rb_Lightsensor_s_default(VALUE klass);
VALUE rb_Lightsensor_s_setDefault(VALUE klass, VALUE obj);


VALUE getRuby_Lightsensor_Module(){ return rb_api_mLightsensor; }



static void _free_class_object(void *p)
{
    ruby_xfree(p);
}

static VALUE _allocate_class_object(VALUE klass)
{
    VALUE valObj = 0;
    char ** ppString = NULL;
    void* pData = ALLOC(void*);
    memset( pData, 0, sizeof(pData) );
    
	valObj = Data_Wrap_Struct(klass, 0, _free_class_object, pData);

    Data_Get_Struct(valObj, char *, ppString);
    *ppString = xmalloc(10);
    sprintf(*ppString, "%X", valObj);

    return valObj;
}

void Init_RubyAPI_Lightsensor(void)
{

    VALUE tmpParent = Qnil;
    rb_api_mParent = rb_define_module("Rho");
    

	rb_api_mLightsensor = rb_define_class_under(rb_api_mParent, "Lightsensor", rb_cObject);

	rb_define_alloc_func(rb_api_mLightsensor, _allocate_class_object);
    //Constructor should be not available in case of static members
    //rb_undef_alloc_func(rb_api_mLightsensor);

    rb_define_method(rb_api_mLightsensor, "delay", rb_Lightsensor_getDelay, -1);
    rb_define_singleton_method(rb_api_mLightsensor, "delay", rb_s_Lightsensor_def_getDelay, -1);
    rb_define_method(rb_api_mLightsensor, "delay=", rb_Lightsensor_setDelay, -1);
    rb_define_singleton_method(rb_api_mLightsensor, "delay=", rb_s_Lightsensor_def_setDelay, -1);
    rb_define_singleton_method(rb_api_mLightsensor, "enumerate", rb_s_Lightsensor_enumerate, -1);
    rb_define_method(rb_api_mLightsensor, "startListening", rb_Lightsensor_startListening, -1);
    rb_define_singleton_method(rb_api_mLightsensor, "startListening", rb_s_Lightsensor_def_startListening, -1);
    rb_define_method(rb_api_mLightsensor, "stopListening", rb_Lightsensor_stopListening, -1);
    rb_define_singleton_method(rb_api_mLightsensor, "stopListening", rb_s_Lightsensor_def_stopListening, -1);



    rb_define_singleton_method(rb_api_mLightsensor, "getDefault", rb_Lightsensor_s_default, 0);
    rb_define_singleton_method(rb_api_mLightsensor, "setDefault", rb_Lightsensor_s_setDefault, 1);



    rb_const_set(rb_api_mLightsensor, rb_intern("FAST"), rb_str_new2("1") );
    rb_const_set(rb_api_mLightsensor, rb_intern("NORMAL"), rb_str_new2("0") );



}

