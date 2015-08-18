package com.rho.cordovabarcode;



import java.util.Map;
import java.util.List;

import com.rhomobile.rhodes.api.IMethodResult;

import com.rhomobile.rhodes.api.IRhoApiDefaultId;


public interface ICordovabarcodeSingleton
       extends IRhoApiDefaultId  {



  // hash keys used in properties and parameters

    static final String HK_DATA = "data"; 


    void enumerate(IMethodResult result); 

}
