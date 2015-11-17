import java.util.ArrayList;
public class Test{
	public static void main(String[] args) {
		ArrayList list = new ArrayList();
		list.add("aaa");
		list.add("bbb");
		String name = (String) list.get(1); // 1
		System.out.println("name:" + name);
		list.add(1,"ccc");
		String name2 = (String) list.get(1); // 1
		System.out.println("name:" + name2);
		String name3 = (String) list.get(2); // 1
		System.out.println("name:" + name3);
	}
} 
