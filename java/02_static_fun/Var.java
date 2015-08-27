public class Var
{
	static
	{
		System.out.println("Var loaded!");
	}
	public static  void main(String args[])
	{
		Stu stu1 = new Stu("小明", 10, 100);
		Stu stu2 = new Stu("小华", 11, 200);
		System.out.println("total fee :"+stu1.getTotalFee());
		System.out.println("child total:"+Child.total);
	}
}
class Stu
{
	String name;
	int age;
	int fee;
	static int totalFee;
	public Stu(String name, int age, int fee)
	{
		this.name = name;
		this.age = age;
		this.fee = fee;
		totalFee += fee;
	}
	public static int getTotalFee()
	{
		return totalFee;	
	}
}
class Child
{
	String name;
	int age;
	static int total = 99;
	static
	{
		System.out.println("Child loaded!");
	}

}
