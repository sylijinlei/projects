package com.xiaoming;
import com.xiaoqiang.*;
public class Test {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("This is xiaoming's test class!");
		com.xiaoqiang.Dog  dog1 = new com.xiaoqiang.Dog();
		dog1.name = "huahua";
		dog1.setPrice(100);
		String dog1Name = dog1.getName();
		System.out.println("dog1�ļ۸��ǣ�"+dog1.getPrice());
		System.out.println("dog1�������ǣ�"+dog1Name);
		dog1.cry();
		Dog dog2 = new Dog();
		dog2.age = 11;
	}

}
