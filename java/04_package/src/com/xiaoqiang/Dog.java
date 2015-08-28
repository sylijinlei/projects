package com.xiaoqiang;

public class Dog {
	public String name;
	private int age;
	private int price;

	public void cry()
	{
		System.out.println("I am xiaoqiang's dog");
	}
	//提供一个访问price的方法
	public void setPrice(int price)
	{
		this.price = price;
	}
	public int getPrice()
	{
		return this.price;
	}
	public String getName()
	{
		return this.name;
	}
}
