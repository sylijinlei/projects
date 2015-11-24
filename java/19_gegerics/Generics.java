interface  Person<T>{
	public void setAge(T age);
	public T getAge();
}
public class Generics{
	public static void main(String args[])
	{
		//Person<String> p1 = new Person<String>();
		//p1.setAge("3 years old");
		//System.out.println(p1.getAge());

		//Person<Integer> p2 = new Person<Integer>();
		//p2.setAge(4);
		////System.out.println(p2.getAge());
		//printInfo(p2);
		//printInfo2(p2);
		//Person<?> p3;
		//p3 = p2;
		////p3.setAge(6); //不可用
		//p3.getAge();
		Student<Integer> s = new Student<Integer>();
		s.setAge(9);
		printInfo(s);
		Student2 s2 = new Student2();
		s2.setAge("11");
		printInfo(s2);

	}
		public static void printInfo(Person<?> p)
		{
			System.out.println(p.getAge());
		}
		public static <T> void printInfo2(Person<T> p)
		{
			System.out.println(p.getAge());
		}
}
/*Integer, Float, 上限是Number*/
/*下限super在使用时候定义*/
class Student<T extends Number> implements Person<T>
{
	private T age ;
	public void setAge(T age)
	{
		this.age = age;
	}
	public T getAge()
	{
		return this.age;
	}
}
class Student2 implements Person<String>
{
	private String age ;
	public void setAge(String age)
	{
		this.age = age;
	}
	public String getAge()
	{
		return this.age;
	}
}
