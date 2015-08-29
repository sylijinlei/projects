package com.jinlei;

public class Test {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
//抽象类不能实例化,但可以有实现的方法;抽象方法不能实现
Dog an = new Dog();
an.cry();
Person person = new Person();
person.letCry(an);
	}

}
class Person
{
	public void letCry(Animal animal)
	{
		animal.cry();
	}
}
//抽象类不能实例化,但可以有实现的方法;抽象方法不能实现
abstract class Animal
{
	public abstract void cry();
	public void run()
	{}
}
class Dog extends Animal
{
	public void cry()
	{
		System.out.println("我是一只狗，汪汪！");
	}
}