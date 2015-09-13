//package com.jinlei;

public class Anony {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//	B b = new B();
		//testFunc(b);
		//testFunc(new B());
		//testFunc(new A(){
		//public void printInfo(){
		//System.out.println("Hello, world!");

		//}
		//});
		//testFunc(new B());
		testFunc(new A(){
			public	void printInfo(){

				System.out.println("A :Hello, world!");
			}
		});
		A a = new A(){
			public	void printInfo(){

				System.out.println("C :Hello, world!");
			}
		};
		(new A(){
			public	void printInfo(){

				System.out.println("D :Hello, world!");
			}
		}).printInfo();

		testFunc(a);
		(new D()).printC();
		G g= new G();
		A ag = A.E.asInterface(g);
		ag.printInfo();
	}

	public static void testFunc(A a) {
		a.printInfo();
	}

}
class C {
	public void  printC()
	{
		System.out.println("C :print");
	}
}
class D extends C
{

}
interface A {
	public abstract static class E implements A
	{
		public static A asInterface(A a)
		{
			return  a ;
		}
				
	}
	public void printInfo();
}
class G implements A
{
	public void printInfo()
	{
		System.out.println("g :Hello, world!");
	}
}
	 
class B implements A {

	public void printInfo() {
		System.out.println("B :Hello, world!");
	}

}
