public class BoxingUnboxing {

    public static void main(String[] args){
        
        // Declaring primitive datatype
        int n = 89;

        // converting primitive data to object (Auto Boxing)
        Integer N = n;

        // converting object back to primitive data (Auto Unboxing)
        int m = N;

        System.out.println("Primitive datatype: "+ n);
        System.out.println("Auto Boxed Object: "+ N);
        System.out.println("Auto unboxed primitive data: "+ m);
    }
}