package com.rho.lightsensor;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import com.rhomobile.rhodes.api.IMethodResult;
import com.rhomobile.rhodes.api.RhoApiObject;


public class LightsensorBase extends RhoApiObject {

    public LightsensorBase(String id) {
        super(id);

    }


    public static class getDelayTask implements Runnable {
        private ILightsensor mApiObject; 
        private IMethodResult mResult;

        public getDelayTask(ILightsensor obj, 
                IMethodResult result) {
            this.mApiObject = obj; 
            this.mResult = result;
        }

        @Override
        public void run() {
            try {
                mApiObject.getDelay(mResult);
            } catch (Throwable ex) {
                mResult.set(ex);
            }
        }
    }


    public static class setDelayTask implements Runnable {
        private ILightsensor mApiObject; 
        private int delay;
        private IMethodResult mResult;

        public setDelayTask(ILightsensor obj, 
                int delay, 
                IMethodResult result) {
            this.mApiObject = obj; 
            this.delay = delay;
            this.mResult = result;
        }

        @Override
        public void run() {
            try {
                mApiObject.setDelay(
                    delay, mResult);
            } catch (Throwable ex) {
                mResult.set(ex);
            }
        }
    }


    public static class startListeningTask implements Runnable {
        private ILightsensor mApiObject; 
        private Map<String, String> propertyMap;
        private IMethodResult mResult;

        public startListeningTask(ILightsensor obj, 
                Map<String, String> propertyMap, 
                IMethodResult result) {
            this.mApiObject = obj; 
            this.propertyMap = propertyMap;
            this.mResult = result;
        }

        @Override
        public void run() {
            try {
                mApiObject.startListening(
                    propertyMap, mResult);
            } catch (Throwable ex) {
                mResult.set(ex);
            }
        }
    }


    public static class stopListeningTask implements Runnable {
        private ILightsensor mApiObject; 
        private IMethodResult mResult;

        public stopListeningTask(ILightsensor obj, 
                IMethodResult result) {
            this.mApiObject = obj; 
            this.mResult = result;
        }

        @Override
        public void run() {
            try {
                mApiObject.stopListening(mResult);
            } catch (Throwable ex) {
                mResult.set(ex);
            }
        }
    }

}
