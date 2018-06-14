#include<iostream>
#include<fstream>

using namespace std;

class Expression {
	public:
		virtual int value() const = 0;
		virtual void print(ostream&) const = 0;
	// friend ostream& operator<< (ostream& o, const Expression);
};

static ostream& operator <<(ostream& o, const Expression& e){
	e.print(o);
	return o << " = " << e.value();
};

class Number : public Expression {
	private:
		int number_value;
	public:
		Number(int value) : number_value(value) {
		}
		virtual int value() const {
			return number_value;
		}

		virtual void print(ostream& o) const {
			o << number_value;
		}
};

class LBinary : public Expression {
	private:
		Expression& left_expr;
		Expression& right_expr;
	protected:
		virtual int calculate(int v1, int v2) const = 0;
	public:
		LBinary(Expression& left, Expression& right)
			: left_expr(left), right_expr(right) {
		}
		Expression& left() const {
			return left_expr;
		}
		Expression& right() const {
			return right_expr;
		}
		virtual const char* symbol() const = 0;
		virtual int value() const {
			int left_value = left_expr.value();
			int right_value = right_expr.value();
			return calculate(left_value, right_value);
		}
		virtual void print(ostream& o) const {
			bool left_lower = true;

			if(left_lower){
				o << "(";
			}
			left_expr.print(o);
			if(left_lower){
				o << ")";
			}

			o << symbol();
			bool right_lower = true;

			if(right_lower){
				o << "(";
			}
			right_expr.print(o);
			if(right_lower){
				o << ")";
			}
		}
};

class Addition : public LBinary {
	protected:
		virtual int calculate(int v1, int v2) const {
			return v1 + v2;
		}
	public:
		Addition(Expression& left, Expression& right) : LBinary(left, right) {
		}
		virtual const char* symbol() const {
			return "+";
		}

};

class Multiplication : public LBinary {
	protected:
		virtual int calculate(int v1, int v2) const {
			return v1 * v2;
		}
	public:
		Multiplication(Expression& left, Expression& right)
			: LBinary(left, right) {
		}
		virtual const char* symbol() const {
			return "*";
		}
};
