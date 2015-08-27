public class Var
{
	public static  void main(String args[])
	{
		Clerk clerk1 = new Clerk("小明", 20, 1000.01f);
		Clerk clerk2 = new Clerk("小华", 21, 2000.11f);
		System.out.println(clerk1.name+"的工资是:" + clerk1.getSalary());
	}
}
//class Clerk
//{
	//public String name;
	//private int age;
	 //private float salary;
	//public Clerk(String name, int age, float salary)
	//{
		//this.name = name;
		//this.age = age;
		//this.salary = salary;
	//}
	//public float getSalary()
	//{
		//return salary;
	//}


//}
