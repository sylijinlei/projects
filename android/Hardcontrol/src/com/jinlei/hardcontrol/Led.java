package com.jinlei.hardcontrol;

public class Led {
	
	static
	{
		System.loadLibrary("myled");
	}
	public native static int ledControl(int which,int status);
	public native static int ledOpen();
	public native static void ledClose();
}
