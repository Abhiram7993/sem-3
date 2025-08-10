public class staticInnerclass{
    public static void main(String[] args){
        Outer o = new Outer();
        o.name = "Abhiram";
        Outer.displaySchool inner = new Outer.displaySchool();
        inner.display();
    }
}


class Outer{
    String name;
    static String college;
    static{
        college = "ABC college";
    }

    // static inner class only access static variables in the outer class
    static class displaySchool{
        void display(){
            System.out.println(college);
        }
    }
}