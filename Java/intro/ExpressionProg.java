package tk106;

import java.util.Arrays;

/**
 * This program creates and evaluates some arithmetic expressions
 */
public class ExpressionProg {

  private static final int LENGTH = 10;
     

  public static void main(String[] args) {

    Expression first = new WholeNumber(5);
    System.out.print("The first number is ");
    System.out.println(first);

    Expression second = new WholeNumber(5);
    System.out.print("The second number is ");
    System.out.println(second);
 
    System.out.print("The first object is ");
    String equal = first == second ? "equal" : "not equal";
    System.out.printf("%s to the second\n", equal);
    
    System.out.print("The first number is ");
    equal = first.equals(second) ? "equal" : "not equal";
    System.out.printf("%s to the second\n", equal);

    System.out.println();
    System.out.println("Creating array of Expressions ...");

    Expression[] nums = new Expression[LENGTH];

    for (int i = 0; i < nums.length; i++) {
      nums[i] = new WholeNumber((int) (Math.random() * 100));
    }

    System.out.printf(
      "The numbers are %s\n", java.util.Arrays.toString(nums));

    Arrays.sort(nums);
    System.out.printf(
      "After sorting, the numbers are %s\n",
      Arrays.toString(nums)
    );

  }
}
