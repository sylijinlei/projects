package com.jinlei;

public class InnerDemo {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
Outer out = new Outer();
Outer.Inner in = new Outer.Inner();
in.printInfo(); 
	}

}
class Outer {
	
	private static int a = 10;
	static class  Inner{
		public void printInfo()
		{
			System.out.println("a = " + a);
		}
	}
}