package com.rho.lightsensor;

import java.util.List;
import java.util.Map;

import com.rhomobile.rhodes.api.IMethodResult;

import com.rhomobile.rhodes.api.RhoApiDefaultId;

public abstract class LightsensorSingletonBase 
    extends RhoApiDefaultId<ILightsensor, ILightsensorFactory>  {

    public LightsensorSingletonBase(ILightsensorFactory factory) {
        super(factory);
    } 

    public static class enumerateTask implements Runnable {
        private ILightsensorSingleton mApiSingleton; 
        private IMethodResult mResult;

        public enumerateTask(ILightsensorSingleton obj,         
                IMethodResult result) {
            this.mApiSingleton = obj;         
            this.mResult = result;
        }

        @Override
        public void run() {
            try {
                mApiSingleton.enumerate( mResult);
            } catch (Throwable ex) {
                mResult.set(ex);
            }
        }
    }

    
}
