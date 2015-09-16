package com.jinlei.mycanvas;

import android.app.Activity;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

public class MyCanvasActivity extends Activity
{

	Button btnDraw = null;

	@Override
	protected void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_my_canvas);
		// setContentView(new MyView(this));
		btnDraw = (Button) findViewById(R.id.btnDraw);
		btnDraw.setOnClickListener(new MyOnClickListener());
	}
	class MyOnClickListener implements OnClickListener
	{

		@Override
		public void onClick(View v)
		{
			// TODO Auto-generated method stub
			Log.e("MyView ","btn");
			 MyView.c.drawLine(0, 0, 300, 300, MyView.paint);  
             //»­¾ØÐÎ  
       MyView.c.drawRect(300, 300, 600, 500, MyView.paint); 
			
		}
		
		
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu)
	{
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.my_canvas, menu);
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item)
	{
		// Handle action bar item clicks here. The action bar will
		// automatically handle clicks on the Home/Up button, so long
		// as you specify a parent activity in AndroidManifest.xml.
		int id = item.getItemId();
		if (id == R.id.action_settings)
		{
			return true;
		}
		return super.onOptionsItemSelected(item);
	}
}
