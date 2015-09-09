package com.jinlei.hardcontrol;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.CompoundButton.OnCheckedChangeListener;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.Toast;

public class HardcontrolActivity extends Activity
{
	// 声明控件对象
	Button btnControl = null;
	RadioGroup rdoGupLed = null;
	RadioButton rdoLed0 = null;
	RadioButton rdoLed1 = null;
	RadioButton rdoLed2 = null;
	RadioButton rdoLed3 = null;
	CheckBox chkLed[];

	@Override
	protected void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_hardcontrol);
		// 通过控件ID获得控件对象
		btnControl = (Button) findViewById(R.id.btnControl);
		rdoGupLed = (RadioGroup) findViewById(R.id.rdoGupLed);
		rdoLed0 = (RadioButton) findViewById(R.id.rdoLed0);
		rdoLed1 = (RadioButton) findViewById(R.id.rdoLed1);
		rdoLed2 = (RadioButton) findViewById(R.id.rdoLed2);
		rdoLed3 = (RadioButton) findViewById(R.id.rdoLed3);

		chkLed = new CheckBox[4];
		chkLed[0] = (CheckBox) findViewById(R.id.chkLed0);
		chkLed[1] = (CheckBox) findViewById(R.id.chkLed1);
		chkLed[2] = (CheckBox) findViewById(R.id.chkLed2);
		chkLed[3] = (CheckBox) findViewById(R.id.chkLed3);

		Led.ledOpen();
		// 设置btnControl监听器
		btnControl.setOnClickListener(new OnClickListener()
		{
			public void onClick(View v)
			{
				// TODO Auto-generated method stub
				Led.ledControl(0, 0);
				Led.ledControl(1, 0);
				Led.ledControl(2, 0);
				Led.ledControl(3, 0);
			}
		});
		// 设置rdoGupLed监听
		rdoGupLed.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener()
		{
			public void onCheckedChanged(RadioGroup group, int checkedId)
			{


				if (checkedId == rdoLed0.getId())
				{
					Toast.makeText(HardcontrolActivity.this, "rdoLed0 chedked", Toast.LENGTH_SHORT).show();
				} else if (checkedId == rdoLed1.getId())
				{
					Toast.makeText(HardcontrolActivity.this, "rdoLed1 chedked", Toast.LENGTH_SHORT).show();
				} else if (checkedId == rdoLed2.getId())
				{
					Toast.makeText(HardcontrolActivity.this, "rdoLed3 chedked", Toast.LENGTH_SHORT).show();
				} else if (checkedId == rdoLed3.getId())
				{
					Toast.makeText(HardcontrolActivity.this, "rdoLed4 chedked", Toast.LENGTH_SHORT).show();
				}

			}
		});
		// 设置chkLed0监听器
		for (int i = 0; i < chkLed.length; i++)
		{
			chkLed[i].setOnCheckedChangeListener(new ChkLedChangeListener());
		}
	}

	class ChkLedChangeListener implements OnCheckedChangeListener
	{
		@Override
		public void onCheckedChanged(CompoundButton buttonView, boolean isChecked)
		{
			// TODO Auto-generated method stub
			switch (buttonView.getId())
			{
			case R.id.chkLed0:
				if (isChecked)
				{
					Led.ledControl(0, 1);
					Toast.makeText(HardcontrolActivity.this, "Led0 chedked", Toast.LENGTH_SHORT).show();
				} else
				{
					Led.ledControl(0, 0);
					Toast.makeText(HardcontrolActivity.this, "Led0 unchedked", Toast.LENGTH_SHORT).show();
				}
				break;
			case R.id.chkLed1:
				if (isChecked)
				{
					Led.ledControl(1, 1);
					Toast.makeText(HardcontrolActivity.this, "chkLed1 chedked", Toast.LENGTH_SHORT).show();
				} else
				{
					Led.ledControl(1, 0);
					Toast.makeText(HardcontrolActivity.this, "chkLed1 unchedked", Toast.LENGTH_SHORT).show();
				}
				break;
			case R.id.chkLed2:
				if (isChecked)
				{
					Led.ledControl(2, 1);
					Toast.makeText(HardcontrolActivity.this, "chkLed2 chedked", Toast.LENGTH_SHORT).show();
				} else
				{
					Led.ledControl(2, 0);
					Toast.makeText(HardcontrolActivity.this, "chkLed2 unchedked", Toast.LENGTH_SHORT).show();
				}
				break;
			case R.id.chkLed3:
				if (isChecked)
				{
					Led.ledControl(3, 1);
					Toast.makeText(HardcontrolActivity.this, "chkLed3 chedked", Toast.LENGTH_SHORT).show();
				} else
				{
					Led.ledControl(3, 0);
					Toast.makeText(HardcontrolActivity.this, "chkLed3 unchedked", Toast.LENGTH_SHORT).show();
				}
				break;
			default:
				break;
			}
		}
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu)
	{
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.hardcontrol, menu);
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
