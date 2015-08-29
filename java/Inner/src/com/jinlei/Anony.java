package com.jinlei;

public class Anony {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
	//	B b = new B();
		//testFunc(b);
		//testFunc(new B());
		testFunc(new A(){
			public void printInfo(){
				System.out.println("Hello, world!");
				
			}
		});
	}

	public static void testFunc(A a) {
		a.printInfo();
	}

}

interface A {
	public void printInfo();
}

class B implements A {

	public void printInfo() {
		System.out.println("Hello, world!");
	}

}
