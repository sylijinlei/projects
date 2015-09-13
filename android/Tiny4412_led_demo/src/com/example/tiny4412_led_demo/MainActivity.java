package com.example.tiny4412_led_demo;

import android.os.ILed_demo_service;
import android.os.RemoteException;
import android.os.ServiceManager;
import android.os.Bundle;
import android.app.Activity;
import android.util.Log;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

public class MainActivity extends Activity implements OnClickListener
{
    private final static String LOG_TAG = "com.example.tiny4412_led_demo.MainActivity";

    private ILed_demo_service  Led_demo_service = null;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Led_demo_service = ILed_demo_service.Stub.asInterface(ServiceManager.getService("led_demo"));

        Button bt_on = (Button)findViewById(R.id.bt_on);
        Button bt_off = (Button)findViewById(R.id.bt_off);

        bt_on.setOnClickListener(this);
        bt_off.setOnClickListener(this);

		Button bt_on2 = (Button)findViewById(R.id.bt_on2);
		Button bt_off2 = (Button)findViewById(R.id.bt_off2);
		
		bt_on2.setOnClickListener(this);
		bt_off2.setOnClickListener(this);
		
		Button bt_on3 = (Button)findViewById(R.id.bt_on3);
		Button bt_off3 = (Button)findViewById(R.id.bt_off3);
		
		bt_on3.setOnClickListener(this);
		bt_off3.setOnClickListener(this);
		
		Button bt_on4 = (Button)findViewById(R.id.bt_on4);
		Button bt_off4 = (Button)findViewById(R.id.bt_off4);
		
		bt_on4.setOnClickListener(this);
		bt_off4.setOnClickListener(this);
		
		Log.i(LOG_TAG, "MainActivity created.");
	}

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }

    @Override
    public void onClick(View v) {
        // TODO Auto-generated method stub
        switch(v.getId())
        {
            case R.id.bt_on:
                try
                {
                    Led_demo_service.led_set_ON(1);
                    Log.e(LOG_TAG, "set led on is execute.");
                    break;
                } catch (RemoteException e)
                {
                    Log.e(LOG_TAG, "Remote Exception while set led on.");
                }

            case R.id.bt_off:
                try
                {
                    Led_demo_service.led_set_OFF(1);
                    Log.e(LOG_TAG, "set led off is execute.");
                    break;
                } catch (RemoteException e)
                {
                    Log.e(LOG_TAG, "Remote Exception while set led off.");
                }

            case R.id.bt_on2:
                try
                {
                    Led_demo_service.led_set_ON(2);
                    Log.e(LOG_TAG, "set led on is execute.");
                    break;
                } catch (RemoteException e)
                {
                    Log.e(LOG_TAG, "Remote Exception while set led on.");
                }

            case R.id.bt_off2:
                try
                {
                    Led_demo_service.led_set_OFF(2);
                    Log.e(LOG_TAG, "set led off is execute.");
                    break;
                } catch (RemoteException e)
                {
                    Log.e(LOG_TAG, "Remote Exception while set led off.");
                }

            case R.id.bt_on3:
                try
                {
                    Led_demo_service.led_set_ON(3);
                    Log.e(LOG_TAG, "set led on is execute.");
                    break;
                } catch (RemoteException e)
                {
                    Log.e(LOG_TAG, "Remote Exception while set led on.");
                }

            case R.id.bt_off3:
                try
                {
                    Led_demo_service.led_set_OFF(3);
                    Log.e(LOG_TAG, "set led off is execute.");
                    break;
                } catch (RemoteException e)
                {
                    Log.e(LOG_TAG, "Remote Exception while set led off.");
                }

            case R.id.bt_on4:
                try
                {
                    Led_demo_service.led_set_ON(4);
                    Log.e(LOG_TAG, "set led on is execute.");
                    break;
                } catch (RemoteException e)
                {
                    Log.e(LOG_TAG, "Remote Exception while set led on.");
                }

            case R.id.bt_off4:
                try
                {
                    Led_demo_service.led_set_OFF(4);
                    Log.e(LOG_TAG, "set led off is execute.");
                    break;
                } catch (RemoteException e)
                {
                    Log.e(LOG_TAG, "Remote Exception while set led off.");
                }
        }

    }

}
