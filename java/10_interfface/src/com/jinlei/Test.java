package com.jinlei;

public class Test {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Camera  cam1 = new Camera();
		cam1.start();
		Computer computer = new Computer();
		computer.usbUsb(cam1);
		Usb usb = new Camera();
		usb.start();
	}

}
//�ӿ�����ķ�������ʵ�֣��ӿ��Ǹ��ӳ���ĳ����࣬һ�������ʵ�ֶ���ӿ�,�ӿ��еı������뱻��ʼ��
interface Usb
{
	int a = 1;   //��̬�ģ�������final
	public void start();
	public void stop();
}
interface Keyboard
{
	public void write();
}
class Camera implements Usb,Keyboard
{
	public void start()
	{
		
		System.out.println("�����������Ҫ��ʼ������!");
	}
	public void stop()
	{
		
		System.out.println("�����������Ҫֹͣ������!");
	}
	public void write()
	{
		
	}
}
class Phone implements Usb
{
	public void start()
	{
		
		System.out.println("�����ֻ�����Ҫ��ʼ������!");
	}
	public void stop()
	{
		
		System.out.println("�����ֻ�����Ҫֹͣ������!");
	}
}
class Computer
{
	public void usbUsb(Usb usb)
	{
		usb.start();
		usb.stop();
	
		System.out.println("a = " + Usb.a);
	
		}
}