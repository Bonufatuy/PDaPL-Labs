#include <iostream>

class Figure {
public:
	virtual int getSquare() const = 0;
	virtual int getPerimeter() const = 0;
	virtual void printObject() const = 0;
	virtual ~Figure() { std::cout << "Call destructor Figure" << std::endl; }
};
class Parallelogram : public Figure {
private:
	int m_x;
	int m_y;
	int m_height_x;
public:
	Parallelogram(int x = 0, int y = 0,int h_x = 0)
		:m_x(x), m_y(y) , m_height_x(h_x){}

	int getSquare() const override { return m_x * m_height_x; }
	int getPerimeter() const override { return (m_x + m_y) * 2; }
	void printObject() const override {
		std::cout << "Parallelogram:" << std::endl
			      << "x = " << m_x << std::endl
			      << "y = " << m_y << std::endl
			      << "height_x = " << m_height_x << std::endl
			      << "Square = " << getSquare() << std::endl
			      << "Perimeter = " << getPerimeter() << std::endl;
	}
	~Parallelogram() { std::cout << "Call destructor Parallelogram" << std::endl; }
};
class Rectangle : public Parallelogram {
private:
	int m_wight;
	int m_lenght;
public:
	Rectangle(int wight = 0, int lenght = 0)
		:m_wight(wight), m_lenght(lenght){}

	int getSquare() const override { return m_wight * m_lenght; }
	int getPerimeter() const override { return (m_wight + m_lenght) * 2; }
	void printObject() const override {
		std::cout << "Rectangle:" << std::endl
			      << "Wight = " << m_wight << std::endl
			      << "Lenght = " << m_lenght << std::endl
			      << "Square = " << getSquare() << std::endl
			      << "Perimeter = " << getPerimeter() << std::endl;
	}

	~Rectangle(){ std::cout << "Call destructor Rectangle" << std::endl; }
};
class Rhombus : public Figure {
private:
	int m_side;
	int m_diagonal_x;
	int m_diagonal_y;
public:
	Rhombus(int side = 0, int diagonal_x = 0, int diagonal_y = 0)
		:m_side(side), m_diagonal_x(diagonal_x), m_diagonal_y(diagonal_y){}

	int getSquare() const override { return m_diagonal_x * m_diagonal_y; }
	int getPerimeter() const override { return m_side * 4; }
	void printObject() const override {
		std::cout << "Rhombus:" << std::endl
			<< "side = " << m_side << std::endl
			<< "diagonal_x = " << m_diagonal_x << std::endl
			<< "diagonal_y = " << m_diagonal_y << std::endl
			<< "Square = " << getSquare() << std::endl
			<< "Perimeter = " << getPerimeter() << std::endl;
	}
	~Rhombus(){ std::cout << "Call destructor Rhombus" << std::endl; }
};

int main() {

	Figure** Objects = new Figure * [3];
	Objects[0] = new Parallelogram{ 2, 3, 4 };
	Objects[1] = new Rectangle{ 3, 4 };
	Objects[2] = new Rhombus{ 4, 5, 6 };

	for (int i = 0; i < 3; i++) {
		Objects[i]->printObject(); std::cout << std::endl;
		delete Objects[i]; std::cout << std::endl;
	}
	delete[] Objects;
	return 0;
}
