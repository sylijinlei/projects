package com.jinlei.hardcontrol;

public class Led {
	
	static
	{
		System.loadLibrary("led");
	}
	public native static int ledControl(int led,int cmd);
	public native static int ledOpen();
	public native static void ledClose();
	



}