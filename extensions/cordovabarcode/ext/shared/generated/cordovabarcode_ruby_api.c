#include "ruby.h"

static VALUE rb_api_mParent;
static VALUE rb_api_mCordovabarcode;

VALUE rb_s_Cordovabarcode_enumerate(int argc, VALUE *argv);
VALUE rb_Cordovabarcode_scan(int argc, VALUE *argv, VALUE obj);
VALUE rb_s_Cordovabarcode_def_scan(int argc, VALUE *argv);



VALUE rb_Cordovabarcode_s_default(VALUE klass);
VALUE rb_Cordovabarcode_s_setDefault(VALUE klass, VALUE obj);


VALUE getRuby_Cordovabarcode_Module(){ return rb_api_mCordovabarcode; }



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

void Init_RubyAPI_Cordovabarcode(void)
{

    VALUE tmpParent = Qnil;
    rb_api_mParent = rb_define_module("Rho");
    

	rb_api_mCordovabarcode = rb_define_class_under(rb_api_mParent, "Cordovabarcode", rb_cObject);

	rb_define_alloc_func(rb_api_mCordovabarcode, _allocate_class_object);
    //Constructor should be not available in case of static members
    //rb_undef_alloc_func(rb_api_mCordovabarcode);

    rb_define_singleton_method(rb_api_mCordovabarcode, "enumerate", rb_s_Cordovabarcode_enumerate, -1);
    rb_define_method(rb_api_mCordovabarcode, "scan", rb_Cordovabarcode_scan, -1);
    rb_define_singleton_method(rb_api_mCordovabarcode, "scan", rb_s_Cordovabarcode_def_scan, -1);



    rb_define_singleton_method(rb_api_mCordovabarcode, "getDefault", rb_Cordovabarcode_s_default, 0);
    rb_define_singleton_method(rb_api_mCordovabarcode, "setDefault", rb_Cordovabarcode_s_setDefault, 1);






}

