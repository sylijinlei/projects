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
		cat1.cry();
	}

}
class Animal
{
	String name;
	int age;
	public void cry()
	{
		
		System.out.println("我是动物，我不知道怎么叫！");
	}
}
class Dog  extends Animal
{
	public void cry()
	{
		System.out.println("汪汪，我是一只狗！");
		
	}
	
}
class Cat  extends Animal
{
	public void cry()
	{
		System.out.println("喵喵，我是一只猫！");
		
	}
	
}

