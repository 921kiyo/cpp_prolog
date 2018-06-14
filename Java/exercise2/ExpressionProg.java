package exercise2;

import java.util.*;

public class ExpressionProg{
  private static final int SIZE = 10;

  public static void main(String[] args){
    // Expression first = new WholeNumber(5);
    // System.out.print("The first number is ");
    // System.out.println(first);
    //
    // Expression second = new WholeNumber(5);
    // System.out.print("The second number is ");
    // System.out.println(second);
    //
    // System.out.print("The object is ");
    // String equal = first == second ? "equal" : "not equal";
    // System.out.printf("%s to the second\n", equal);
    //
    // System.out.print("The object is ");
    // equal = first.equals(second) ? "equal" : "not equal";
    // System.out.printf("%s to the second\n", equal);
    //
    // System.out.println();
    // System.out.println("Creating array of Expressions ...");
    //
    // Expression[] nums = new Expression[SIZE];
    //
    // for(int i = 0; i < nums.length; i++){
    //   nums[i] = new WholeNumber((int) (Math.random() * 100));
    // }
    //
    // System.out.printf("The numbers are %s\n", java.util.Arrays.toString(nums));
    //
    // Arrays.sort(nums);
    // System.out.printf("After sorting, the numbers are %s\n", Arrays.toString(nums));

    List<Expression> nums = new LinkedList<Expression>();
      do {
        nums.add(randomExpression(4));
      } while (Math.random() < 0.95);

      Iterator<Expression> itr = nums.iterator();

      while(itr.hasNext()){
        Expression ex = itr.next();
        System.out.printf("Expression %s\n", ex);
      }

    System.out.printf("the random expression is %s\n", randomExpression(10));

    // Map map = new HashMap();


  }

  private static Expression randomExpression(int maxDepth){
    if(maxDepth == 1){
      // System.out.printf("exiting expression...\n");
      return new WholeNumber(maxDepth);
    }

    double threshold = Math.random();
    if(threshold <= 0.2){
      int num1 = new Random().nextInt(maxDepth);
      return new WholeNumber(num1);
    }
    else if(threshold > 0.2 && threshold <= 0.5){
      maxDepth--;
      System.out.printf("Product maxDepth %s\n", maxDepth);
      return new Product(randomExpression(maxDepth), randomExpression(maxDepth));
    }
    else if(threshold > 0.5 && threshold <= 0.75){
      maxDepth--;
      System.out.printf("Product maxDepth %s\n", maxDepth);
        try{
          return new Division(randomExpression(maxDepth), randomExpression(maxDepth));
        }catch(WholeDivisionUndefined e){
          e.printError();
          System.exit(1);
        }
    }
      maxDepth--;
      System.out.printf("Sum maxDepth %s\n", maxDepth);
      return new Sum(randomExpression(maxDepth), randomExpression(maxDepth));
  }
}
