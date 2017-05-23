package com.ecantalejos.cpp;

import android.content.Context;
import android.content.pm.PackageManager;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;

import org.cocos2dx.lib.Cocos2dxActivity;

public class Gyroscope implements SensorEventListener{

    private static Gyroscope instance;
    private Sensor gyroscope;
    private boolean hasGyroscope;
    private Vec3 data;


    private static Gyroscope createGyroscope(){
        if(instance==null){
            instance=new Gyroscope();
            instance.hasGyroscope = Cocos2dxActivity.getContext().getPackageManager().hasSystemFeature(PackageManager.FEATURE_SENSOR_GYROSCOPE);
            instance.data=new Vec3();
        }
        return instance;
    }

    public static void startGyroscope(){
       if(instance==null)
           instance=createGyroscope();
        if(instance.hasGyroscope){
            SensorManager sensorManager = (SensorManager) Cocos2dxActivity.getContext().getSystemService(Context.SENSOR_SERVICE);
            instance.gyroscope = sensorManager.getDefaultSensor(Sensor.TYPE_GYROSCOPE);
            sensorManager.registerListener(instance, instance.gyroscope,
                    SensorManager.SENSOR_DELAY_NORMAL);
        }
    }

    public static float getDataX() {
        if(instance==null)
            return 0;
        return instance.data.x;
    }

    public static float getDataY() {
        if(instance==null)
            return 0;
        return instance.data.y;
    }

    public static float getDataZ() {
        if(instance==null)
            return 0;
        return instance.data.z;
    }

    public static void stopGyroscope(){
        SensorManager sensorManager = (SensorManager) Cocos2dxActivity.getContext().getSystemService(Context.SENSOR_SERVICE);
        sensorManager.unregisterListener(instance);
        instance=null;
    }

    @Override
    public void onSensorChanged(SensorEvent event) {
        instance.data.x = event.values[0];
        instance.data.y = event.values[1];
        instance.data.z = event.values[2];
    }

    @Override
    public void onAccuracyChanged(Sensor sensor, int accuracy) {

    }

    static class Vec3{

        public float x=0;
        public float y=0;
        public float z=0;
    }
}
