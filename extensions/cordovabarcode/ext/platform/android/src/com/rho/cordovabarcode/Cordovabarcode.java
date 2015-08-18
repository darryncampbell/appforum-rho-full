package com.rho.cordovabarcode;

import java.util.Map;
import org.json.JSONArray;
import android.content.Intent;
import android.util.Log;

import com.rho.cordovabarcode.BarcodeScanner;

import com.rhomobile.rhodes.api.IMethodResult;
import com.rhomobile.rhodes.api.MethodResult;

public class Cordovabarcode extends CordovabarcodeBase implements ICordovabarcode {
    
	private static BarcodeScanner b = null;
	
    public Cordovabarcode(String id) {
        super(id);
    }

    @Override
    public void scan(Map<String,String> params, IMethodResult result) {
        b = new BarcodeScanner(result);
        JSONArray args = new JSONArray();
        b.scan(args);
    }

	public void onActivityResult(int requestCode, int resultCode, Intent intent)
    {
        Log.d("rho", "CORDOVA BARCODE ACTIVITY RESULT");
        b.onActivityResult(requestCode, resultCode, intent);
    }

}