package com.rho.cordovabarcode;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import com.rhomobile.rhodes.api.IMethodResult;
import com.rhomobile.rhodes.api.RhoApiObject;


public class CordovabarcodeBase extends RhoApiObject {

    public CordovabarcodeBase(String id) {
        super(id);

    }


    public static class scanTask implements Runnable {
        private ICordovabarcode mApiObject; 
        private Map<String, String> propertyMap;
        private IMethodResult mResult;

        public scanTask(ICordovabarcode obj, 
                Map<String, String> propertyMap, 
                IMethodResult result) {
            this.mApiObject = obj; 
            this.propertyMap = propertyMap;
            this.mResult = result;
        }

        @Override
        public void run() {
            try {
                mApiObject.scan(
                    propertyMap, mResult);
            } catch (Throwable ex) {
                mResult.set(ex);
            }
        }
    }

}
