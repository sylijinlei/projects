package com.jinlei;

public class Test {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Dog dog1 = new Dog();
		dog1.cry();
		Cat cat1 = new Cat();
		cat1.cry2();
	}

}
class Animal
{
	String name;
	int age;
	//final ���ܱ����า��
	public void cry()
	{
		
		System.out.println("���Ƕ���Ҳ�֪����ô�У�");
	}
	final public void run()  //���ɱ��̳�
	{
		System.out.println("�һ����ߣ�");
	}
}
class Dog  extends Animal
{
	public void cry()
	{
		System.out.println("����������һֻ����");
		
	}
	
}
class Cat  extends Animal
{
	public void cry()
	{
		System.out.println("����������һֻè��");	
	}
	public void cry2()
	{
		this.cry();
		super.cry();
	}
	
}

