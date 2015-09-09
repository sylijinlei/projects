package com.jinlei.hellojni;



public class Hello {
	static
	{
		System.loadLibrary("hello");	
	}
	public static void hello()
	{
		
		System.out.println("java hello!");
	}
	public native static int sayhello(int a, int b);
	
}
