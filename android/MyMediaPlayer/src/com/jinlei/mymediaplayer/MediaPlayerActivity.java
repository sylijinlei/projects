package com.jinlei.mymediaplayer;

import java.io.IOException;

import android.app.Activity;
import android.media.AudioManager;
import android.media.MediaPlayer;
import android.net.Uri;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;


public class MediaPlayerActivity extends Activity {

	Button btnStart;
	Button btnStop;
	MediaPlayer mediaPlayer ;
	SurfaceView mSurfaceView;
	SurfaceHolder mSurfaceHolder;   
	Uri uri;
	String str;
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_media_player);
        btnStart = (Button)findViewById(R.id.btnStart);
      uri = Uri.parse("/mnt/sdcard/test.mp4");
       
      // mediaPlayer = new MediaPlayer();
        str = "/mnt/sdcard/test.mp3";
        mSurfaceView = (SurfaceView)findViewById(R.id.surfaceView);
        mSurfaceHolder = mSurfaceView.getHolder();
      //mSurfaceHolder.setFixedSize(100, 400); 
      //  mSurfaceHolder.setType(SurfaceHolder.SURFACE_TYPE_PUSH_BUFFERS);  
        
        btnStart.setOnClickListener(new OnClickListener()
		{
			
			@Override
			public void onClick(View v)
			{
				// TODO Auto-generated method stub

			/*	 
				System.out.println(Environment.getExternalStorageDirectory().getPath());
				//.setDataSource(str);
					  try
					{
						mediaPlayer.prepare();
					} catch (IllegalStateException e)
					{
						// TODO Auto-generated catch block
						Log.e("this", "prepare error 1");
						e.printStackTrace();
					} catch (IOException e)
					{
						// TODO Auto-generated catch block
						Log.e("this", "prepare error 2");
						e.printStackTrace();
					}
					  mediaPlayer.start();*/
				//  mediaPlayer.reset();//»Ö¸´µ½Î´³õÊ¼»¯µÄ×´Ì¬  
				//mediaPlayer = MediaPlayer.create(MediaPlayerActivity.this, uri);
				mediaPlayer = new MediaPlayer();
				try
				{
					mediaPlayer.setDataSource("/mnt/sdcard/test.mp4");
				} catch (IllegalArgumentException e1)
				{
					// TODO Auto-generated catch block
					e1.printStackTrace();
				} catch (SecurityException e1)
				{
					// TODO Auto-generated catch block
					e1.printStackTrace();
				} catch (IllegalStateException e1)
				{
					// TODO Auto-generated catch block
					e1.printStackTrace();
				} catch (IOException e1)
				{
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
				  mediaPlayer.setAudioStreamType(AudioManager.STREAM_MUSIC);  
		            mediaPlayer.setDisplay(mSurfaceHolder);//ÉèÖÃÆÁÄ»  
				try
				{
					mediaPlayer.prepare();
				} catch (IllegalStateException e)
				{
					// TODO Auto-generated catch block
					e.printStackTrace();
				} catch (IOException e)
				{
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				mediaPlayer.start();
			}
		});
    }


    @Override
	protected void onStop()
	{
		// TODO Auto-generated method stub
		super.onStop();
		Log.e("this", "on stop");
	}


	@Override
	protected void onDestroy()
	{
		// TODO Auto-generated method stub
		super.onDestroy();
		System.exit(0);
		Log.e("this", "on destroy");
	}


	@Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.media_player, menu);
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
