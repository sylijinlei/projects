package com.polymophic;

public class Test {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		Dog dog1 = new Dog();
//		dog1.cry();
//		Animal an = new Dog();
//		an.cry();
//		an = new Cat();
//		an.cry();
//		
		Master master = new Master();
		master.feed(new Dog(),new Bone());
		
	}

}
class Food
{
	String name;
	public void showName()
	{
		
	}
}
class Fish extends Food
{
	public void showName()
	{
		System.out.println("鱼");
	}
}
class Bone extends Food
{
	public void showName()
	{
		System.out.println("骨头");
	}
}
class Master
{
	//给动物喂食物
	public void  feed (Animal an, Food f)
	{
		an.eat();
		f.showName();
		
	}
}

class Animal {

	private String name;
	private int age;

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getAge() {
		return age;
	}

	public void setAge(int age) {
		this.age = age;
	}

	public void cry() {
		System.out.println("我不知道怎么叫！");
	}
	public void eat()
	{
		System.out.println("不知道吃什么");
	}
}

class Dog extends Animal {
	public void cry() {
		System.out.println("我是一只狗，旺旺");
	}
	public void eat()
	{
		System.out.println("狗爱吃骨头!");
	}
}

class Cat extends Animal {
	public void cry() {
		System.out.println("我是一只猫，喵喵");
	}
	public void eat()
	{
		System.out.println("猫爱吃鱼！");
	}

}