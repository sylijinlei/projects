public class Var
{
	static
	{
		System.out.println("Var loaded!");
	}
	public static  void main(String args[])
	{
		//Stu stu1 = new Stu("小明", 10, 100);
		//Stu stu2 = new Stu("小华", 11, 200);
		//System.out.println("total fee :"+stu1.getTotalFee());
		//System.out.println("child total:"+Child.total);
		//System.out.println(Stu.ch1.age);
		try
		{
			Stu.ch1.cry();

		}catch (Exception e) {
			// TODO Auto-generated catch block

			System.out.println(e);
		}
		System.out.println("i will exit!");
	}
}
//final作为类的成员变量必须在定义时或构造函数中初始化
final class Stu
{
	String name;
	int age;
	int fee ;
	public static final Child ch1 = new Child();
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
	int age = 12;
	static int total = 99;
	static
	{
		System.out.println("Child loaded!");
	}
	public  void cry()
	{
		System.out.println("I am a child!");
	}

}
