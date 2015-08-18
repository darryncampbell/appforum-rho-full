package com.rho.cordovabarcode;

public class CordovabarcodeFactorySingleton {
    private static ICordovabarcodeFactory mFactory;
    public static void setInstance(ICordovabarcodeFactory factory) {
        mFactory = factory;
    }
    public static ICordovabarcodeFactory getInstance() {
        return mFactory;
    }
}
