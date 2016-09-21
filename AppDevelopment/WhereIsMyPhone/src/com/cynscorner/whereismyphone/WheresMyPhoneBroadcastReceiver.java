package com.cynscorner.whereismyphone;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.telephony.*;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.widget.Toast;
import android.location.*;


public class WheresMyPhoneBroadcastReceiver extends BroadcastReceiver implements LocationListener {

    
    String loc = "Location Unknown";
    LocationManager mgr;
    String provider;
    
    
    @Override
    public void onReceive(Context context, Intent intent) {
        // TODO Auto-generated method stub
        SharedPreferences passwdfile = context.getSharedPreferences("passwd", 0);
        String password = passwdfile.getString("passwd", null);
        
        mgr = (LocationManager)context.getSystemService(Context.LOCATION_SERVICE);
        Criteria criteria = new Criteria();
        criteria.setAccuracy(Criteria.ACCURACY_FINE);
        criteria.setPowerRequirement(Criteria.POWER_LOW);
        criteria.setCostAllowed(true);
        
        provider = mgr.getBestProvider(criteria, true);
        mgr.requestLocationUpdates(provider, 0, 0, this);
        Location lastLocation = mgr.getLastKnownLocation(provider);
        if (lastLocation != null) {
            loc = "Findme Latitude: " + lastLocation.getLatitude() + "Longitude: " + lastLocation.getLongitude();
        }
        
        // Get the messages - PDU = Protocol Description Unit
        Bundle bundle = intent.getExtras();
        Object[] pdusObj = (Object[])bundle.get("pdus");
        SmsMessage[] messages = new SmsMessage[pdusObj.length];
        
        for (int i = 0; i < pdusObj.length; i++) {
            messages[i] = SmsMessage.createFromPdu((byte[])pdusObj[i]);
        }
        Toast.makeText(context, "The controller is receiving", Toast.LENGTH_LONG).show();
        System.out.println("controller is getting data using password: " + password);
        
        for (SmsMessage msg : messages) {
            // Make sure it's a findme message
            System.out.println("MSG body: " + msg.getDisplayMessageBody());
            if (msg.getMessageBody().contains("Findme: "+password)) {
                System.out.println("found a matching message");
                String to = msg.getDisplayOriginatingAddress();
                SmsManager sm = SmsManager.getDefault();
                sm.sendTextMessage(to, null, loc, null, null);
                Toast.makeText(context, "Location sent to: " + to + " using provider: " + provider, Toast.LENGTH_LONG).show();
            }
        }
                
    }


    @Override
    public void onLocationChanged(Location location) {
        // TODO Auto-generated method stub
        if (location == null) {
            location = mgr.getLastKnownLocation(provider);
        }
        
        loc = "Findme Latitude: " + location.getLatitude() + "Longitude: " + location.getLongitude();
    }


    //@Override
    public void onProviderDisabled(String provider) {
        // TODO Auto-generated method stub
        
    }


    //@Override
    public void onProviderEnabled(String provider) {
        // TODO Auto-generated method stub
        
    }


    //@Override
    public void onStatusChanged(String provider, int status, Bundle extras) {
        // TODO Auto-generated method stub
        
    }

}
