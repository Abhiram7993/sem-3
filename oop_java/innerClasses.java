public class innerClasses{
    public static void main(String[] args){
        Outer o = new Outer("Abhiram", 20);
        // we cant call display method directly since its initiated on inner class
        Outer.Inner i = o.new Inner();
        i.display();  
    }
}


class Outer{
    String Name;
    int age;

    Outer(String Name, int age){
        this.Name = Name;
        this.age = age; 
    }

    // Normal/Member inner class, which can access all the things in Outer class.
    class Inner{
        void display(){
            System.out.println(Name+" has "+ age+ " years old");
        }
    }
}