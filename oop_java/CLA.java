public class CLA{
    
    public static void main(String[] args){
        // args.length will give the length of array args
        for (int i=0; i<args.length; i++){
            System.out.println("Command Line Argument "+ i + " is " + args[i]);   // in java the file name during fn call is not considered as CLA 
        }
    }
}