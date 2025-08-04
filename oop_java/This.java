import java.util.Scanner;

class Student{
    // instance variable
    String name;
    int age;

    // constructor
    Student(String name, int age){
        this.name = name;
        this.age = age;
    }

    void display(){
        System.out.println("Name: " + this.name);
        System.out.println("Age: " + this.age);
    }
}

public class This{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Name: ");
        String name = sc.nextLine();
        System.out.println("Age: ");
        int age = sc.nextInt();
        sc.close();

        Student s1 = new Student(name, age);
        s1.display();
    }
}
