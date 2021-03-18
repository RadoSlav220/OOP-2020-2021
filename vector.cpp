#include <iostream>
#include <cmath>
#include "vector.h"

//The big four (five)
Vector::Vector()
{
	size = 3;
	try {
		arr = new int[size];
	}
	catch (const std::exception& e){
		std::cout << e.what();
		size = 0;
	}
	for (size_t i=0; i<size; i++){
		arr[i] = 0;
	}
}

Vector::Vector(const size_t n)
{ 
	if (n == 0){
		std::cout << "The size is changed to 1" << std::endl;
		size = 1;
	}
	else {
		size = n;
	}
	try {
		arr = new int[n];
	}
	catch (const std::exception& e){
		std::cout << e.what();
		size = 0;
	}
}

Vector::Vector(const Vector& obj)
{
	size = obj.size;
	try {
		this->arr = new int[size];
	}
	catch (const std::exception& e){
		std::cout << e.what();
		size = 0;
	}
	for (size_t i=0; i<size; i++){
		this->arr[i] = obj.arr[i];
	}
}
 
Vector& Vector::operator=(const Vector& obj)
{
	if (this == &obj){
		return *this;
	}
	if (size != obj.size){
		int* new_arr;	
		try {
           	new_arr = new int[obj.size];
		}
		catch (const std::exception& e){
			std::cout << e.what();
		}
        
        delete [] arr;
        
        arr = new_arr;
        size = obj.size;
    }
    
    for (size_t i=0; i<size; i++){
    	arr[i] = obj.arr[i];
    }
    return *this;
}

Vector::~Vector()
{
	delete [] arr;
}


//Setters
void Vector::setVector()
{
	int x;
	for (size_t i=0; i<size; i++){
		std::cin >> x;
		putValue(i, x);
	}
} 

void Vector::putValue(const int position, const int el)
{
	if (position >= size || position < 0){
		std::cerr << "Invalid position" << std::endl;
		return;
	}
	arr[position] = el; 
}


//Getters
size_t Vector::getSize() const {return size;}

int Vector::getValue(const int position) const {
	if (position >= size || position < 0){
		std::cerr << "Invalid position" << std::endl;
		return -1;
	}
	return arr[position];
}


//Operators
Vector& Vector::operator+= (Vector const& obj) {
	if (size != obj.size){
		std::cerr << "Sizes are not equal! The operation cannot be done!"<< std::endl;
		return *this;
	}
	for (size_t i = 0; i < size; i++) {
		arr[i] += obj.arr[i];
	}
	return *this;
}

Vector Vector::operator+ (Vector const& obj) {
	Vector result(*this);
	if (result.size != obj.size){
		std::cerr << "Sizes are not equal! The operation cannot be done"<< std::endl;
		return result;
	}
	result += obj;
	return result;
}

const int& Vector::operator[](size_t index) const {
	if (index >= size){
		std::cerr << "Invalid index" << std::endl;
		return arr[index - size]; //overflow
	}
	return arr[index];
}

int& Vector::operator[](size_t index) {
	if (index >= size){
		std::cerr << "Invalid index" << std::endl;
		return arr[index - size]; //overflow
	}
	return arr[index];
}

bool Vector::operator==(Vector const& obj)
{
	if (size != obj.size) {
		return false;
	}
	for (size_t i = 0; i<size; i++) {
		if (arr[i] != obj.arr[i]) {
			return false;
		}
	}
	return true;
}

bool Vector::operator!=(Vector const& obj)
{
	return !(*this == obj);
}

Vector Vector::operator* (int mult)
{
	Vector result(*this);
	for (size_t i=0; i<size; i++){
		result.arr[i] *= mult;
	}
	return result;
}

Vector& Vector::operator*= (int mult)
{
	for (size_t i=0; i<size; i++){
		arr[i] *= mult;
	}
	return *this;
}

Vector Vector::operator/(int div)
{
	if (div == 0){
		std::cerr << "Division by zero is forbidden" << std::endl;
		return *this;
	}
	Vector result(*this);
	bool willChange = false;
	for (size_t i=0; i<result.size && !willChange; i++){
		if (result.arr[i] % div != 0){
			willChange = true;	
		}
	}
	if (willChange){
		std::cout << "The division result is not abosolutely correct" << std::endl;
	}
	for (size_t i=0; i<result.size; i++){
		result.arr[i] /= div;
	}
	return result;
}

Vector& Vector::operator/=(int div)
{
	if (div == 0){
		std::cerr << "Division by zero is forbidden" << std::endl;
		return *this;
	}
	bool willChange = false;
	for (size_t i=0; i<size && !willChange; i++){
		if (arr[i] % div != 0){
			willChange = true;	
		}
	}
	if (willChange){
		std::cout << "The division result is not abosolutely correct" << std::endl;
	}
	for (size_t i=0; i<size; i++){
		arr[i] /= div;
	}
	return *this;
}

const bool Vector::operator<(Vector const& obj) const
{
	if (size != obj.size){
		return false;
	}
	for (size_t i=0; i<size; i++){
		if (arr[i] >= obj.arr[i]){
			return false;
		}
	}
	return true;
}

const bool Vector::operator<=(Vector const& obj) const
{
	if (size != obj.size){
		return false;
	}
	for (size_t i=0; i<size; i++){
		if (arr[i] > obj.arr[i]){
			return false;
		}
	}
	return true;
}

const bool Vector::operator>(Vector const& obj) const
{
	if (size != obj.size){
		return false;
	}
	for (size_t i=0; i<size; i++){
		if (arr[i] <= obj.arr[i]){
			return false;
		}
	}
	return true;
}

const bool Vector::operator>=(Vector const& obj) const
{
	if (size != obj.size){
		return false;
	}
	for (size_t i=0; i<size; i++){
		if (arr[i] < obj.arr[i]){
			return false;
		}
	}
	return true;
}

int Vector::operator*(Vector const& obj)
{
	return scalarProduct(obj);
}


//Other Methods
void Vector::add(const Vector& obj) {
	if (size != obj.size){
		std::cerr << "The vectors are with different sizes! The operation cannot be done" << std::endl;
		return;
	}
	for (size_t i = 0; i < getSize();i++) {
		arr[i] += obj.arr[i];
	}
}

void Vector::printVector()
{
	std::cout << "(" << arr[0];
	for (size_t i=1; i<size; i++){
		std::cout << ", " << arr[i];
	}
	std::cout << ")" << std::endl;
}

int Vector::scalarProduct (Vector const& obj) const
{
	int scalarPr = 0;
	if (size != obj.size){
		std::cerr << "ERROR: Vectors have different sizes" << std:: endl; 
		return -1;
	}
	for (size_t i=0; i<size; i++){
		scalarPr += arr[i] * obj.arr[i];
	}
	return scalarPr;
}

double Vector::vectorLength() const
{
	int result = 0;
	for (size_t i=0; i<size; i++){
		result += arr[i]*arr[i];
	}
	return sqrt(result);
}
