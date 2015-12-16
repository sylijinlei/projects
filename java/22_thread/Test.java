class Test
{
	public static void main(String args[])
	{
		//FirstThread ft = new FirstThread();
		//ft.start();
		RunnableImpl ri = new RunnableImpl();
		Thread t = new Thread(ri);
		System.out.println(t.getPriority());
		//优先级最大是10最小是1
		t.setPriority(Thread.MIN_PRIORITY);
		t.start(); 
		for(int  i = 0; i < 100; i++)
		{
			System.out.println("main-->"+i);
		}

	}
}
