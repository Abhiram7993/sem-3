/*
 If we call a method which is defined in both parent class and subclass, then the method which will be called is determined by
 the class we initialized on object...
 */

public class P_OR{
    public static void main(String[] args){
        Animal d = new Dog();  // Barks
        Animal c = new Animal(); // Sound of animal ; cuz we initialsed with Animal()
        Animal c1 = new Cat(); // Meow

        d.sound();
        c.sound();
        c1.sound();
    }
}


class Animal{
    void sound(){
        System.out.println("Sound of an animal");
    }
}


class Dog extends Animal{
    void sound(){
        System.out.println("Barks");
    }
}


class Cat extends Animal{
    void sound(){
        System.out.println("Meow");
    }
}