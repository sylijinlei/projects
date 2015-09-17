package com.jinlei.binder;

import android.app.Activity;
import android.os.Bundle;
import android.os.RemoteException;
import android.support.v4.media.session.IMediaControllerCallback.Stub;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.os.*;

public class BinderActivity extends Activity {
	private ILedService iLedService = null;
	private Button btnTest;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_binder);
		btnTest = (Button)findViewById(R.id.btnTest);
		btnTest.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				iLedService = ILedService.Stub.asInterface(ServiceManager.getService("led"));
				try {
					iLedService.ledCtrl(1, 2);
				} catch (RemoteException e) {
					// TODO Auto-generated catch block
					Log.e("this", "error");
					e.printStackTrace();
				}
			}
		});
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.binder, menu);
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		// Handle action bar item clicks here. The action bar will
		// automatically handle clicks on the Home/Up button, so long
		// as you specify a parent activity in AndroidManifest.xml.
		int id = item.getItemId();
		if (id == R.id.action_settings) {
			return true;
		}
		return super.onOptionsItemSelected(item);
	}
}
