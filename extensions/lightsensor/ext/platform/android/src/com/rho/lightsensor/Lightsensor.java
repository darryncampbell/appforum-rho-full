package com.rho.lightsensor;

import java.util.Map;
import org.json.JSONArray;

import com.rhomobile.rhodes.api.IMethodResult;
import com.rhomobile.rhodes.api.MethodResult;
import com.rhomobile.rhodes.RhodesActivity;

import android.content.Intent;
import android.util.Log;
import android.content.Context;

import android.hardware.Sensor;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.hardware.SensorEvent;


public class Lightsensor extends LightsensorBase implements ILightsensor, SensorEventListener {
    
    private SensorManager mSensorManager;
    private Sensor mLight;
    private IMethodResult sensorOutput;
    private int mDelay;
    
    public Lightsensor(String id) {
        super(id);
        mSensorManager = (SensorManager) RhodesActivity.safeGetInstance().getSystemService(Context.SENSOR_SERVICE);
        mLight = mSensorManager.getDefaultSensor(Sensor.TYPE_LIGHT);
        mDelay = SensorManager.SENSOR_DELAY_NORMAL;
    }

    @Override
    public void startListening(Map<String, String> propertyMap, IMethodResult result) {
          sensorOutput = result;
          if (propertyMap.containsKey("delay"))
          {
              setDelay(Integer.parseInt(propertyMap.get("delay")), new MethodResult(false));
          }	
          Log.d("Light Sensor", "Registering Listener");
          mSensorManager.registerListener(this, mLight, mDelay);
    }


    @Override
    public void stopListening(IMethodResult result) {
          mSensorManager.unregisterListener(this);
          result.set(true);	
    }
    
    @Override
    public void getDelay(IMethodResult result) {
          if (mDelay == SensorManager.SENSOR_DELAY_NORMAL)  
          {
              result.set("NORMAL");
          }
          else
          {
            result.set("FAST");	
          }
    }
    
    @Override
    public void setDelay(int delay, IMethodResult result) {
          //  If you change the delay then you need to stop and start the listener again
          if (delay == 0)
          {
            Log.d("Light Sensor", "Setting Delay to Normal");
            mDelay = SensorManager.SENSOR_DELAY_NORMAL;
          }
          else
          {
            Log.d("Light Sensor", "Setting Delay to Fastest");
            mDelay = SensorManager.SENSOR_DELAY_FASTEST;
          }
          result.set(true);	
    }

    @Override
    public final void onAccuracyChanged(Sensor sensor, int accuracy) {
      // Do something here if sensor accuracy changes.
    }
    
    @Override
    public final void onSensorChanged(SensorEvent event) {
      // The light sensor returns a single value.
      // Many sensors return 3 values, one for each axis.
      float lux = event.values[0];
      this.sensorOutput.set(lux);
      // Do something with this sensor value.
    }

}