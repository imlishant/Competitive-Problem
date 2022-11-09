import java.io.*;
class A{
  public void fun(){
    System.out.println("A");
  }
}
public class Test extends A{
  public void fun() throws IOException{
    System.out.println("B");  
  }
  public static void main(String[] args){
    try{ new Test().fun();}
    catch(Exception e){
      System.out.println("Exception");
    }
  }
}