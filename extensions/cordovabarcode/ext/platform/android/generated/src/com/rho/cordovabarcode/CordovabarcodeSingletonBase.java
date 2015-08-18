package com.rho.cordovabarcode;

import java.util.List;
import java.util.Map;

import com.rhomobile.rhodes.api.IMethodResult;

import com.rhomobile.rhodes.api.RhoApiDefaultId;

public abstract class CordovabarcodeSingletonBase 
    extends RhoApiDefaultId<ICordovabarcode, ICordovabarcodeFactory>  {

    public CordovabarcodeSingletonBase(ICordovabarcodeFactory factory) {
        super(factory);
    } 

    public static class enumerateTask implements Runnable {
        private ICordovabarcodeSingleton mApiSingleton; 
        private IMethodResult mResult;

        public enumerateTask(ICordovabarcodeSingleton obj,         
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
