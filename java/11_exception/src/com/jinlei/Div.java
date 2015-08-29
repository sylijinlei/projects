package com.jinlei;

public class Div {

	/**
	 * @param args
	 */

	public static void main(String[] args) {
		// TODO Auto-generated method stub
	int a = 0;
	int b = 0;
		try {
	
			a = Integer.parseInt(args[0]);
			b = Integer.parseInt(args[1]);
			
		} catch (Exception e) {
			
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		try {
			System.out.println("resuld = "+div(a, b));
		} catch (Exception e) {
			// TODO Auto-generated catch block
			System.out.println("“Ï≥£¥¶¿Ì");

		}finally
		{
			System.out.println("this is finally!");
		}
	}
	public static int div(int m, int n) throws Exception
	{
		int r = 0;
	
			try {
				r =  m / n;
			} catch (Exception e) {
				// TODO Auto-generated catch block
				System.out.println("div:" +e);
				throw e;
			}
	
		System.out.println("end!");
		return r;
	}
}


