//package com.jinlei;
public class JniDemo {
	static{	
		//System.loadLibrary("native");
	}
		//public native int hello(int m);
	public static void main(String[] args) {
		JniDemo j = new JniDemo();
		JniTest t = new JniTest();
		t.hello(123);
		//1.load
		//2.建立映射
		//3.调用
		//System.out.println(j.hello(123));

	}

}
