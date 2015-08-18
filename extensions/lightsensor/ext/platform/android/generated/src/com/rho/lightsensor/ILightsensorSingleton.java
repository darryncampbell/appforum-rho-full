package com.rho.lightsensor;



import java.util.Map;
import java.util.List;

import com.rhomobile.rhodes.api.IMethodResult;

import com.rhomobile.rhodes.api.IRhoApiDefaultId;


public interface ILightsensorSingleton
       extends IRhoApiDefaultId  {


    static final String FAST = "1";
    static final String NORMAL = "0";

  // hash keys used in properties and parameters

    static final String HK_LUX = "lux"; 
    static final String PROPERTY_DELAY = "delay"; 


    void enumerate(IMethodResult result); 

}
