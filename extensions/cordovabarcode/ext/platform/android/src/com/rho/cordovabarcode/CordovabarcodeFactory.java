package com.rho.cordovabarcode;

import com.rhomobile.rhodes.api.RhoApiFactory;
import android.util.Log;

import android.app.Dialog;
import android.content.Intent;
import android.content.res.Configuration;
import android.os.Bundle;
import android.view.KeyEvent;

import com.rhomobile.rhodes.RhodesActivity;
import com.rhomobile.rhodes.RhodesService;
import com.rhomobile.rhodes.api.RhoApiFactory;
import com.rhomobile.rhodes.extmanager.IRhoExtManager;
import com.rhomobile.rhodes.extmanager.IRhoListener;
public class CordovabarcodeFactory
        extends RhoApiFactory< Cordovabarcode, CordovabarcodeSingleton>
        implements ICordovabarcodeFactory, IRhoListener {
    
    private String defaultId;

    @Override
    protected CordovabarcodeSingleton createSingleton() {
        return new CordovabarcodeSingleton(this);
    }

    @Override
    protected Cordovabarcode createApiObject(String id) {
		defaultId = id;
        return new Cordovabarcode(id);
    }
            
    @Override
    public void onCreateApplication(IRhoExtManager extManager) {
        Log.d("rho", "CORDOVA BARCODE FACTORY CREATE");
        extManager.addRhoListener(this);
    }
    
    @Override
    public void onActivityResult(RhodesActivity activity, int requestCode, int resultCode, Intent intent) {
        Log.d("rho", "CORDOVA BARCODE FACTORY ACTIVITY RESULT");
        getApiObject(defaultId).onActivityResult(/*activity, */requestCode, resultCode, intent);
    }
            
                @Override
    public void onCreate(RhodesActivity activity, Intent intent) {
        // TODO Auto-generated method stub
    }

    @Override
    public void onStart(RhodesActivity activity) {
        // TODO Auto-generated method stub
    }

    @Override
    public void onResume(RhodesActivity activity) {
        // TODO Auto-generated method stub
    }

    @Override
    public void onPause(RhodesActivity activity) {
        // TODO Auto-generated method stub
    }

    @Override
    public void onStop(RhodesActivity activity) {
        // TODO Auto-generated method stub
    }

    @Override
    public void onDestroy(RhodesActivity activity) {
        // TODO Auto-generated method stub
    }

    @Override
    public void onNewIntent(RhodesActivity activity, Intent intent) {
        // TODO Auto-generated method stub
    }

    @Override
    public Dialog onCreateDialog(RhodesActivity activity, int id) {
        // TODO Auto-generated method stub
        return null;
    }

    @Override
    public void onConfigurationChanged(RhodesActivity activity, Configuration newConfig) {
        // TODO Auto-generated method stub
    }

    @Override
    public boolean onKey(int keyCode, KeyEvent event) {
        return false;
    }

    @Override
    public void onNewIntent(RhodesService service, Intent intent) {
        // TODO Auto-generated method stub
    }

    @Override
    public void onSaveInstanceState(Bundle outState) {
        // TODO Auto-generated method stub
    }
            
            
	@Override
	public void onEBLicenseVisible() { }

	@Override
	public void onEBLicenseHidden() { }

	@Override
	public void onEBLicenseDestroyed() { }
}
