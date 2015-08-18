package com.rho.lightsensor;

public class LightsensorFactorySingleton {
    private static ILightsensorFactory mFactory;
    public static void setInstance(ILightsensorFactory factory) {
        mFactory = factory;
    }
    public static ILightsensorFactory getInstance() {
        return mFactory;
    }
}
