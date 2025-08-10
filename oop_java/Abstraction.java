public class Abstraction{
    public static void main(String[] args){
        Animal a1 = new Dog();
        a1.makeSound();
    }
}


abstract class Animal{
    abstract void makeSound();   // There is no body for abstract methods, they are implemented in subclasses.
}


class Dog extends Animal{
    void makeSound(){
        System.out.println("Barks");
    }
}