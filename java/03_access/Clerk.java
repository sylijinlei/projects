class Clerk
{
	public String name;
	private int age;
	 private float salary;
	 static
	 {
	 	System.out.println("clerk class static block!");
	 }
	 public static void main(String args[])
	 {
	 	System.out.println("clerk class main!");
	 }
	public Clerk(String name, int age, float salary)
	{
		this.name = name;
		this.age = age;
		this.salary = salary;
	}
	public float getSalary()
	{
		return salary;
	}


}

