import java.util.*;
public class test {  
	public static void main(String[] args) {      
		objPoolTest();  
	}  
	public static void objPoolTest() {  
		Person p1 = new Person("小明",12);
		Person p2 = new Person("小强",13);
		List<Person> list = new ArrayList<Person>();
		list.add(p1);
		list.add(p2);
		Person p = (Person)list.get(0);
		System.out.println(p.age);
	}  
}
class Person{
	String name;
	int age;
	public Person(String name, int age)
	{
		this.name = name;
		this.age = age;
	}
}
