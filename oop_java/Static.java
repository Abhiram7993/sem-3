public class Static{

    public static void main(String[] args){
        Student s1 = new Student("arun");
        Student s2 = new Student("akhil");

        System.out.println(s1.name + " and "+ s2.name + " are in same college " + Student.college); // Note how we call static variable
        System.out.println("Square of 2 is: " + Math.square(2)); // Note how I called static method
    }
}


class Student{
    String name;
    static String college = "ABC College"; // static variable, it is accessible in every objects of this class.

    Student(String name){
        this.name = name;
    }
}


class Math{
    static int square(int x){
        return x*x;
    }
}