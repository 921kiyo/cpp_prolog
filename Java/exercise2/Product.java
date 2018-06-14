package exercise2;

public class Product extends BinaryExpression{

  public Product(Expression ex1, Expression ex2){
    super(ex1, ex2);
  }

  public int evaluate(){
    return expression1.evaluate() + expression2.evaluate();
  }

}
