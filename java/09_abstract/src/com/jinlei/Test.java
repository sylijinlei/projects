package com.jinlei;

public class Test {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
//�����಻��ʵ����,��������ʵ�ֵķ���;���󷽷�����ʵ��
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
//�����಻��ʵ����,��������ʵ�ֵķ���;���󷽷�����ʵ��
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
		System.out.println("����һֻ����������");
	}
}