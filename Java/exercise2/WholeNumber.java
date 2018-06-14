package exercise2;

public class WholeNumber implements Expression{
  private int value;

  public WholeNumber(int val){
    value = val;
  }

  @Override
  public String toString(){
    return String.valueOf(value);
  }

  @Override
  public boolean equals(Object obj){
    if(obj == null){ return false;}
    if(! (obj instanceof WholeNumber)){ return false;}

    WholeNumber that = (WholeNumber) obj;
    return this.value == that.value;
  }

  @Override
  public int evaluate(){
    return this.value;
  }
}
