public class returnObj{
    public static void main(String[] args){
        Rectangle r1 = new Rectangle(5, 10);
        Rectangle r2 = new Rectangle(4, 13);
        r1.larger(r2).display();       // Here the return value of larger itself is a class Rectangle. We are calling display method of that object.
    }
}


class Rectangle{
    int length;
    int breadth;

    Rectangle(int l, int b){
        this.length = l;
        this.breadth = b;
    }

    Rectangle larger(Rectangle r2){
        int a1 = this.length * this.breadth;
        int a2 = r2.length * r2.breadth;

        if (a1 > a2){
            return this;
        }
        else{
            return r2;
        }
    }

    void display(){
        System.out.println("Bigger one has area: "+ this.length*this.breadth);
    }
}

   