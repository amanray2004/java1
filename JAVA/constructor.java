package JAVA;

// public class constructor {
//     static class Student{
//         int rno;
//         String name;
//         float marks;


//         Student(){
//             this.rno=13;
//             this.name="aman";
//             this.marks=97.88f;
//         }
//     }
// //     The error you encountered is due to the fact that the inner class Student is not a static class and requires an instance of the outer class classes to be accessed. Since the main method is a static method, it does not have an associated instance of the outer class. Therefore, you need to make the inner class Student static in order to create an instance of it within the main method.

// // Here's an updated version of your code with the Student class declared as static:

//     public  static void main(String[] args) {
//         Student s1;
//         s1= new Student();
//         System.out.println(s1.marks);
//         Student s2 =new Student (12,"rahul",22.45f);
//     }

    
// }

import java.util.*;
public class constructor{
    static class Student{
        String name;
        int rno;
        int marks;

        Student(){
            name="aman";
            this.rno=12;
            this.marks=99;
        }
        void greeting(){
            System.out.println("hello "+this.name);
        }
    }

    public static void main(String[] args) {
        Student s1=new Student();
        System.out.println(s1.name);
        //Student s2=new Student("rahul",14,89);
        s1.name="ananya ";
        s1.greeting();
    }
}



//note:


// the class student is static,which means that it does not need an object to access it     and the same is happening=> see u are creating Student aman =new Student();   so you are accessing Student class (as it static and does not need objects for accessing) and inside the static class ,static things can be acceseed without objects such as Student() constructor and non static things need objects like name,rno,marks that ius why object aman is created.
