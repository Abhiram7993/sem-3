public class classesAndobjects{

    public static void main(String[] args){
        
        // declaring a new Student object and assigning values
        Student s1 = new Student();
        s1.name = "Amal";
        s1.std = 11;
        s1.display();

        // declaring and initializing a object having constructor.
        Child c1 = new Child("Amal", 17);
        c1.display();
    } 

}

// we are defining default classes and methods for our coding purpose.
class Student{

    // setting fields
    String name;
    int std;

    // setting a method
    void display(){
        System.out.println("Student: " + name);
        System.out.println("Class: " + std);
    }
}


// defining a class with constructor
class Child{
    String name;
    int age;

    // defining constructor, 
    // its not a fn. donot requires return value.
    // Its used to assign values during intialization of object
    Child(String n, int a){
        name = n;
        age = a;
    }

    // displaying method
    void display(){
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
    }

} 