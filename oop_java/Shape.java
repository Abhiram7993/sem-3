import java.util.Scanner;

public class Shape{
    public static void main(String[] args){
        Circle c1 = new Circle();   // If I declared using parent class Shape, then I can only use variables and methods declared there.
        Scanner sc = new Scanner(System.in);
        System.err.println("Radius: ");
        c1.radius = sc.nextInt();
        sc.close();
        c1.area();
    }
}


abstract class Geometry{
    abstract void area();
}


class Circle extends Geometry{
    int radius;
    
    void area(){
        double a = (Math.PI)*this.radius*this.radius;
        System.out.println("Area: " + a);
    }
}