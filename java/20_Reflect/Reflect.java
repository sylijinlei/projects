package a.b.c.d
class Person{
	private String name;
	void setName(String name)
	{
		this.name = name;
	}
	String getName()
	{
		return this.name;
	}
}
public class Reflect
{
	public static void main(String args[])
	{
		Person p = new Person();
		System.out.println(p.getClass().getName());
	}

}
