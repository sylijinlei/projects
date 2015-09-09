public class Test
{
	public static void main(String args[])
	{
		Dog dog[] = new Dog[4];
		int arr[] = new int[4];
		System.out.println(dog.length);
		
		arr[0] = 12;
		arr[1] = 13;
		arr[2] = 14;
		arr[3] = 15;
		printArr(arr);
	}
	static  void printArr(int[]a)
	{
		System.out.println(a[0]);
		System.out.println(a[1]);
		System.out.println(a[2]);
		System.out.println(a[3]);
		System.out.println(a[4]);
	}
}
class Dog
{
	private String name;
	private int weight;
	public void setName(String name)
	{
		this.name = name;
	}
	public String getName()
	{
		return name;
	}
	public void setWeight(int weight)
	{
		this.weight= weight;
	}
	public int getWeight()
	{
		return weight;
	}
}
