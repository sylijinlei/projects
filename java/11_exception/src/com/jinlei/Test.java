package com.jinlei;
import java.io.*;
import java.net.*;
public class Test {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
			//检查异常1.打开文件
		
		try {
//			FileReader fr=new FileReader("D:\\aa.txt");
//			System.out.println("go on!");
//			Socket s=new Socket("137.0.0.1",1212);
		//	int a = 5/2;
			//出现异常的地方中止执行代码，然后直接进入catch
			//如果有多个catch，则进入匹配异常的catch
			System.out.println("go on!");
		
		} catch (Exception e) {
			// 把异常的信息输出
			System.out.println("Exception\n");
			e.printStackTrace();	
		}finally
		{
			System.out.println("finally");
		}

		System.out.println("OK1");
		//接连一个192.168.12.12的端口号4567
		
		//Socket s=new Socket("192.168.12.12",4567);
		
		//运行异常
	// int a=4/0;
		//int a[]={1,2,3};
		//System.out.println(a[82]);
		//内存耗尽
	}

}
