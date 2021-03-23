#pragma once
#include <cstddef>
class Vector
{
private:
	size_t size;
	int* arr;
public:
	Vector();
	Vector(const size_t n);
	Vector(const Vector& obj);
	Vector& operator=(const Vector& obj);
	~Vector();

	void setVector();

	int getValue(const int position) const;
	size_t getSize() const;

	Vector  operator+ (Vector const& obj);
	Vector& operator+= (Vector const& obj);
	Vector  operator* (int mult); 
	Vector& operator*= (int mult); 
	Vector operator/(int div);
	Vector& operator/=(int div);
	const int& operator[](size_t idx) const;
	int& operator[](size_t index);
	bool operator==(Vector const& obj);
	bool operator!=(Vector const& obj);
	const bool operator<(Vector const& obj) const;
	const bool operator<=(Vector const& obj) const;
	const bool operator>(Vector const& obj) const;
	const bool operator>=(Vector const& obj) const;
	int operator*(Vector const& obj); //Scalar product

	void putValue(const int position, const int el);
	void add(const Vector& obj);
	int scalarProduct (Vector const& obj) const;
	double vectorLength() const; 
	void printVector();
};