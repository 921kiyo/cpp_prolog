#ifndef EXPRESSION_H
#define EXPRESSION_H
// #include<iostream>
// #include<fstream>
//
// using namespace std;
//
// ostream& operator <<(ostream& o, const Expression& e){
//
// }
//
// class Expression {
// 	public:
// 		virtual int value() const = 0;
// };
//
// class Number : public Expression {
// 	private:
// 		int number_value;
// 	public:
// 		Number(int value) : number_value(value) {
// 		}
// 		virtual int value() const {
// 			return number_value;
// 		}
// };
//
// class LBinary : public Expression {
// 	private:
// 		Expression& left_expr;
// 		Expression& right_expr;
// 	protected:
// 		virtual int calculate(int v1, int v2) const = 0;
// 	public:
// 		LBinary(Expression& left, Expression& right)
// 			: left_expr(left), right_expr(right) {
// 		}
// 		Expression& left() const {
// 			return left_expr;
// 		}
// 		Expression& right() const {
// 			return right_expr;
// 		}
// 		virtual const char* symbol() const = 0;
// 		virtual int value() const {
// 			int left_value = left_expr.value();
// 			int right_value = right_expr.value();
// 			return calculate(left_value, right_value);
// 		}
// };
//
// class Addition : public LBinary {
// 	protected:
// 		virtual int calculate(int v1, int v2);
// 	public:
// 		Addition(Expression& left, Expression& right) : LBinary(left, right);
// 		virtual const char* symbol() = 0;
// };
//
// class Multiplication : public LBinary {
// 	protected:
// 		virtual int calculate(int v1, int v2) const {
// 			return v1 * v2;
// 		}
// 	public:
// 		Multiplication(Expression& left, Expression& right)
// 			: LBinary(left, right) {
// 		}
// 		virtual const char* symbol() const {
// 			return "*";
// 		}
// };

#endif
