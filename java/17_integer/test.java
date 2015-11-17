public class test {  
    public static void main(String[] args) {      
        objPoolTest();  
    }  
  
    public static void objPoolTest() {  
        int i = 40;  
        int i0 = 40;  
        Integer i1 = 40;  
        Integer i2 = 40;  
        Integer i3 = 0;  
        Integer i4 = new Integer(40);  
        Integer i5 = new Integer(40);  
        Integer i6 = new Integer(0);  
		Integer i7 = Integer.class;
        Double d1=1.0;  
        Double d2=1.0;  
		String s1 = "a";
		String s2 = s1 + "b";
		String s3 = "ab";
        //在java中对于引用变量来说“==”就是判断这两个引用变量所引用的是不是同一个对象
		System.out.println("i==i0\t" + (i == i0));  
		System.out.println("i1==i2\t" + (i1 == i2));  
        System.out.println("i1==i2+i3\t" + (i1 == i2 + i3));  
        System.out.println("i4==i5\t" + (i4 == i5));  
        System.out.println("i4==i5+i6\t" + (i4 == i5 + i6));      
        System.out.println("d1==d2\t" + (d1==d2));   
		System.out.println(s2);
        System.out.println("s2==s3\t" + (s2==s3));   
		System.out.println(i7);
         
        System.out.println();          
    }  
}
