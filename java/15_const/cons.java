public class cons
{
	public static  void main(String args[])
	{
		Integer i1 = 400;
		Integer i2 = 400;

		System.out.println("i1 == i2:"+(i1 == i2));
		i2 = 400;
		System.out.println("i1 = "+i1+"\n" +"i2 = "+i2);
		System.out.println("i1 == i2:"+(i1 == i2));
		System.out.println("i1 == i2:"+i1.equals(i2));
	}
}
