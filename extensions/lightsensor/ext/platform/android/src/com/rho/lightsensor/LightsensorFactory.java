package com.rho.lightsensor;

import com.rhomobile.rhodes.api.RhoApiFactory;

public class LightsensorFactory
        extends RhoApiFactory< Lightsensor, LightsensorSingleton>
        implements ILightsensorFactory {

    @Override
    protected LightsensorSingleton createSingleton() {
        return new LightsensorSingleton(this);
    }

    @Override
    protected Lightsensor createApiObject(String id) {
        return new Lightsensor(id);
    }
}
