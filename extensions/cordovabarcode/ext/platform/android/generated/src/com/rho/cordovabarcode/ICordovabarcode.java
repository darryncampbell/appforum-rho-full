package com.rho.cordovabarcode;



import java.util.Map;
import java.util.List;

import com.rhomobile.rhodes.api.IMethodResult;
import com.rhomobile.rhodes.api.IRhoApiObject;


public interface ICordovabarcode extends IRhoApiObject {

    void scan(Map<String, String> propertyMap, IMethodResult result);
};
