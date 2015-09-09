package com.jinlei.hellojni;



public class Hello {
	static
	{
		System.loadLibrary("hello");	
	}

	public native static int sayhello(int a, int b);
	public native static String printString(String str);
	public native static int[] printArray(int[]a, int[]b);
	
	
}
