package com.jinlei;
import java.io.*;
import java.net.*;
public class Test {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
			//����쳣1.���ļ�
		
		try {
//			FileReader fr=new FileReader("D:\\aa.txt");
//			System.out.println("go on!");
//			Socket s=new Socket("137.0.0.1",1212);
		//	int a = 5/2;
			//�����쳣�ĵط���ִֹ�д��룬Ȼ��ֱ�ӽ���catch
			//����ж��catch�������ƥ���쳣��catch
			System.out.println("go on!");
		
		} catch (Exception e) {
			// ���쳣����Ϣ���
			System.out.println("Exception\n");
			e.printStackTrace();	
		}finally
		{
			System.out.println("finally");
		}

		System.out.println("OK1");
		//����һ��192.168.12.12�Ķ˿ں�4567
		
		//Socket s=new Socket("192.168.12.12",4567);
		
		//�����쳣
	// int a=4/0;
		//int a[]={1,2,3};
		//System.out.println(a[82]);
		//�ڴ�ľ�
	}

}
