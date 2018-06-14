package exercise2;

public class Division extends BinaryExpression {
  public Division (Expression ex1, Expression ex2) throws WholeDivisionUndefined
{
    super(ex1, ex2);
    throw new WholeDivisionUndefined();
  }

  public int evaluate(){
    return expression1.evaluate() / expression2.evaluate();
  }
}
