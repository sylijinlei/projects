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
		System.out.println("��");
	}
}
class Bone extends Food
{
	public void showName()
	{
		System.out.println("��ͷ");
	}
}
class Master
{
	//������ιʳ��
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
		System.out.println("�Ҳ�֪����ô�У�");
	}
	public void eat()
	{
		System.out.println("��֪����ʲô");
	}
}

class Dog extends Animal {
	public void cry() {
		System.out.println("����һֻ��������");
	}
	public void eat()
	{
		System.out.println("�����Թ�ͷ!");
	}
}

class Cat extends Animal {
	public void cry() {
		System.out.println("����һֻè������");
	}
	public void eat()
	{
		System.out.println("è�����㣡");
	}

}