package exercise2;

public class Sum extends BinaryExpression{

  public Sum(Expression ex1, Expression ex2){
    super(ex1, ex2);
  }
  public int evaluate(){
    return expression1.evaluate() + expression2.evaluate();
  }
}
