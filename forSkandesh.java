import java.util.Scanner;
public class StudentDB4 {
    int roll_no;
    String name;
    static String cname="REVA";
    Scanner s=new Scanner(System.in);
void read()
{
    name=s.nextLine();
    roll_no=s.nextInt();
}
void display()
{
    System.out.print("Student roll number=" + roll_no+", ");
    System.out.print("Student name=" + name+", ");
    System.out.print("College name=" + cname+"\n ");
}

public static void main(String args[])
{
    Scanner s=new Scanner(System.in);
    System.out.println("Enter no of students");
    int n=s.nextInt();
    StudentDB4 a[]=new StudentDB4[n];
    for(int i=0;i<n;i++) {
    a[i]=new StudentDB4();
    System.out.println("Enter name and srn of student " + (i+1));
    a[i].read();
}
System.out.println("\n");
for(int i=0;i<n;i++)
{
    System.out.println("Details of Student " + (i+1)+":");
    a[i].display();
    }
    }
}
