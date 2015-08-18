package com.rho.cordovabarcode;

import com.rhomobile.rhodes.api.IRhoApiFactory;
import com.rhomobile.rhodes.api.IRhoApiSingletonFactory;

public interface ICordovabarcodeFactory
    extends IRhoApiFactory<ICordovabarcode>,
            IRhoApiSingletonFactory<ICordovabarcodeSingleton> {

    @Override
    ICordovabarcodeSingleton getApiSingleton();

    @Override
    ICordovabarcode getApiObject(String id);

}
