import java.util.HashMap;
public class Test
{
	public static void main(String args[])
	{
		Student s1 = new Student("小明", 8);
		Student s2 = new Student("小红", 5);
		HashMap<String, Student> hm = new HashMap<String, Student>();
		hm.put("001", s1);
		hm.put("002", s2);
		Student s3 = (Student)hm.get("002");
		System.out.println(s3.name+"--> age: "+ s3.age);
	
	}
}
class Student
{
	Student(String name, int age){
		this.name = name;
		this.age = age;
	}
	String name;
	int age;
}



