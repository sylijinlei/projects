package com.jinlei;

public class InnerDemo {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
Outer out = new Outer();
Outer.Inner in = out.new Inner();

in.printInfo(); 
out.outprint();
//Outer.Inner in2 = new Outer.Inner();
	}

}
class Outer {
	
	private static int a = 10;
	public void outprint()
	{
	
			System.out.println("out print");
	}
	 class  Inner{
		public void printInfo()
		{
			System.out.println("a = " + a);
			outprint();
		}
	}
}
