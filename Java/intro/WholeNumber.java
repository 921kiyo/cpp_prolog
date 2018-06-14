package intro;

/**
 * This class represents a whole number
 */
public class WholeNumber implements Expression {
  
  private int value;

  public WholeNumber(int val) {
    value = val;
  }

  public String toString() {
    return String.valueOf(value);
  }

  public boolean equals(Object obj) {
    if (obj == null)                    { return false; }
    if (! (obj instanceof WholeNumber)) { return false; }

    WholeNumber that = (WholeNumber) obj;
    return this.value == that.value;
  }

  public int evaluate() {
    return this.value;
  }

}
