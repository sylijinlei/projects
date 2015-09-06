public class array
{
	public static  void main(String args[])
	{
		System.out.println("hello");
		int[] arr = new int[100];
		for(int i = 0; i < 100; i++)
		{
			arr[i] = i;
		}
		for(int i = 0; i < 100; i++)
		{
			//System.out.println("arr["+ i+ "] = "+arr[i]);
		}
		System.out.println(arr);
		CharSequence cs = "jackylee";
		System.out.println(cs);
	}
}
