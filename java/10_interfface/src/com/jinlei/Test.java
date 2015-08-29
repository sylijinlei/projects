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
//接口里面的方法不能实现，接口是更加抽象的抽象类，一个类可以实现多个接口,接口中的变量必须被初始化
interface Usb
{
	int a = 1;   //静态的，而且是final
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
		
		System.out.println("我是相机，我要开始工作了!");
	}
	public void stop()
	{
		
		System.out.println("我是相机，我要停止工作了!");
	}
	public void write()
	{
		
	}
}
class Phone implements Usb
{
	public void start()
	{
		
		System.out.println("我是手机，我要开始工作了!");
	}
	public void stop()
	{
		
		System.out.println("我是手机，我要停止工作了!");
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