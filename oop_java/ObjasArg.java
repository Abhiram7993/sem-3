import java.util.Scanner;


public class ObjasArg{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.err.print("Name: ");
        String name = sc.nextLine();
        System.err.print("Age: ");
        int age = sc.nextInt();
        sc.close();
        
        Student s = new Student(name, age);
        display_classes d = new display_classes();
        d.student_d(s);

    }
}


class Student{
    String name;
    int age;

    // constructor
    Student(String name, int age){
        this.name = name;
        this.age = age;
    }

    void display(){
        System.out.println(this.name + " is " + this.age + " years old.");
    }
}


class display_classes{
    void student_d(Student s){
        s.display();
    }
}