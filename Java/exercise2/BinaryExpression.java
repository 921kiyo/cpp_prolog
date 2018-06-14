package exercise2;

public abstract class BinaryExpression implements Expression{
  protected Expression expression1;
  protected Expression expression2;

  public BinaryExpression(Expression ex1, Expression ex2){
    expression1 = ex1;
    expression2 = ex2;
  }

  @Override
  public String toString(){
    return String.valueOf(evaluate());
  }



}
