package com.jinlei.myvideoview;

import java.io.File;

import android.app.Activity;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.MediaController;
import android.widget.VideoView;

public class ViewActivity extends Activity implements OnClickListener
{
	VideoView videoView;
	File fVideo;
	MediaController mediaControl;
	Button btnStart;
	Button btnStop;


	@Override

	protected void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_video);
		videoView = (VideoView) findViewById(R.id.vvVideo);
		fVideo = new File("/mnt/sdcard/test.mp4");
		btnStart = (Button)findViewById(R.id.btnStart);
		btnStop = (Button)findViewById(R.id.btnStop);
		btnStart.setOnClickListener(this);
		btnStop.setOnClickListener(this);
		
		mediaControl = new MediaController(this);
		
		if (fVideo.exists())
		{
			// VideoView与MediaController进行关联

			
		} else
		{
			Log.e("ViewActivity","file not exist!");
		}

	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu)
	{
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.view, menu);
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

	@Override
	public void onClick(View v)
	{
		// TODO Auto-generated method stub
		switch (v.getId())
		{
		case R.id.btnStart:
			
			if (fVideo.exists())
			{
				// VideoView与MediaController进行关联
				videoView.setVideoPath(fVideo.getAbsolutePath());
				videoView.setMediaController(mediaControl);
				mediaControl.setMediaPlayer(videoView);
				// 让VideiView获取焦点
				videoView.requestFocus();
				videoView.start();
			} else
			{
				Log.e("ViewActivity","file not exist!");
			}

			break;
		
		}

	}
}
