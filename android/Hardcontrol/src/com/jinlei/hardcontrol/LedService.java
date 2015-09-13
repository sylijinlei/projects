package com.jinlei.hardcontrol;

import android.util.Log;

 public class LedService extends ILedService.Stub{
	public LedService()
	{
		System.loadLibrary("myled");
		native_ledOpen();
	}
	public int ledCtrl(int which, int status)
	{
		Log.e("LedService","interface ledCtrl" + which+ "  "+status);
		return native_ledControl(which, status);
	}
	public native static int native_ledControl(int which,int status);
	public native static int native_ledOpen();
	public native static void native_ledClose();
}
interface ILedService
{
	public int ledCtrl(int which, int status);
	public static abstract class Stub implements com.jinlei.hardcontrol.ILedService
	{
		
		public static com.jinlei.hardcontrol.ILedService asInterface(ILedService m)
		{
			return m;
		}
	}
}