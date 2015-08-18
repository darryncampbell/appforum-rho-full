package com.rho.lightsensor;

import com.rhomobile.rhodes.api.IRhoApiFactory;
import com.rhomobile.rhodes.api.IRhoApiSingletonFactory;

public interface ILightsensorFactory
    extends IRhoApiFactory<ILightsensor>,
            IRhoApiSingletonFactory<ILightsensorSingleton> {

    @Override
    ILightsensorSingleton getApiSingleton();

    @Override
    ILightsensor getApiObject(String id);

}
