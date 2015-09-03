public class Test
{
	public static void main(String args[])
	{
		Dog dog[] = new Dog[4];
		System.out.println(dog.length);
		
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
