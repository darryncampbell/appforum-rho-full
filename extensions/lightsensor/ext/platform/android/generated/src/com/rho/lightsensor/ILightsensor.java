package com.rho.lightsensor;



import java.util.Map;
import java.util.List;

import com.rhomobile.rhodes.api.IMethodResult;
import com.rhomobile.rhodes.api.IRhoApiObject;


public interface ILightsensor extends IRhoApiObject {

    void getDelay(IMethodResult result);
    void setDelay(int delay, IMethodResult result);
    void startListening(Map<String, String> propertyMap, IMethodResult result);
    void stopListening(IMethodResult result);
};
