#include <iostream>

class Figure {
private:
	int m_x;
	int m_y;
public:
	Figure(int x = 0, int y = 0)
		:m_x(x), m_y(y) {}
	int getX() const { return m_x; }
	int getY() const { return m_y; }
	friend std::ostream& operator << (std::ostream& out, const Figure& object) {
		out << "x = " << object.getX() << std::endl
			<< "y = " << object.getY() << std::endl;
		return out;
	}
	~Figure() { std::cout << "Call destructor Figure" << std::endl; }
};
class Parallelogram : protected virtual Figure {
private:
	int m_width;
	int m_lenght;
public:
	Parallelogram(int x = 0, int y = 0, int wight = 0, int lenght = 0)
		:Figure(x, y), m_width(wight), m_lenght(lenght){}
	int getWight() const { return m_width; }
	int getLenght() const { return m_lenght; }
	friend std::ostream& operator << (std::ostream& out, const Parallelogram& object) {
		out << "x = " << object.getX() << std::endl
			<< "y = " << object.getY() << std::endl
			<< "Wight = " << object.getWight() << std::endl
			<< "Lenght = " << object.getLenght() << std::endl;
		return out;
	}
	~Parallelogram() { std::cout << "Call destructor Parallelogram" << std::endl; }
};
class Rectangle : protected Parallelogram {
private:
	std::string m_color;
	bool m_transparency;
public:
	Rectangle(int x = 0, int y = 0, int wight = 0, int lenght = 0, std::string color = " ", bool trans = false)
		:Parallelogram(x, y, wight, lenght), m_color(color), m_transparency(trans){}
	std::string getColor() const { return m_color; }
	bool getTransparency() const { return m_transparency; }
	friend std::ostream& operator << (std::ostream& out, const Rectangle& object) {
		out << "x = " << object.getX() << std::endl
			<< "y = " << object.getY() << std::endl
			<< "Wight = " << object.getWight() << std::endl
			<< "Lenght = " << object.getLenght() << std::endl
			<< "Color = " << object.getColor() << std::endl
			<< "Transparency = " << object.getTransparency() << std::endl;
		return out;
	}
	~Rectangle(){ std::cout << "Call destructor Rectangle" << std::endl; }
};
class Quadrangle : protected virtual Figure {
private:
	int m_Weight_x;
	int m_Weight_y;
public:
	Quadrangle(int x = 0, int y = 0, int Weight_x = 0, int Weight_y = 0)
		:Figure(x,y), m_Weight_x(Weight_x), m_Weight_y(Weight_y){}
	int getWeight_x() const { return m_Weight_x; }
	int getWeight_y() const { return m_Weight_y; }
	friend std::ostream& operator << (std::ostream& out, const Quadrangle& object) {
		out << "x = " << object.getX() << std::endl
			<< "y = " << object.getY() << std::endl
			<< "Weight_x = " << object.getWeight_x() << std::endl
			<< "Weight_y = " << object.getWeight_y() << std::endl;
		return out;
	}
	~Quadrangle() { std::cout << "Call destructor Quadrangle" << std::endl; }
};
class Rhombus : protected Quadrangle {
private:
	int m_diagonal_x;
	int m_diagonal_y;
public:
	Rhombus(int x = 0, int y = 0, int Weight_x = 0, int Weight_y = 0, int diagonal_x = 0, int diagonal_y = 0)
		:Quadrangle(x, y, Weight_x, Weight_y), m_diagonal_x(diagonal_x), m_diagonal_y(diagonal_y){}
	int getDiagonal_x() const { return m_diagonal_x; }
	int getDiagonal_y() const { return m_diagonal_y; }

	friend std::ostream& operator << (std::ostream& out, const Rhombus& object) {
		out << "x = " << object.getX() << std::endl
			<< "y = " << object.getY() << std::endl
			<< "weight_x = " << object.getWeight_x() << std::endl
			<< "weight_y = " << object.getWeight_y() << std::endl
			<< "diagonal_x = " << object.getDiagonal_x() << std::endl
			<< "diagonal_y = " << object.getDiagonal_y() << std::endl;
			return out;
	}
	~Rhombus(){ std::cout << "Call destructor Rhombus" << std::endl; }
};
class Square : protected Rhombus, protected Rectangle {
private:
	int m_internal_radius;
	int m_external_radius;
public:
	Square(int x = 0, int y = 0, int Weight_x = 0, int Weight_y = 0, int diagonal_x = 0, int diagonal_y = 0,
		int wight = 0, int lenght = 0, std::string color = " ", bool trans = false, int internal_radius = 0,
		int external_radius = 0) 
		:Figure(x, y), Rhombus(x, y, Weight_x, Weight_y, diagonal_x, diagonal_y),
		Rectangle(x, y, wight, lenght, color, trans), m_internal_radius(internal_radius), m_external_radius(external_radius){}
	friend std::ostream& operator << (std::ostream& out, const Square& object) {
		out << "x = " << object.getX() << std::endl
			<< "y = " << object.getY() << std::endl
			<< "weight_x = " << object.getWeight_x() << std::endl
			<< "weight_y = " << object.getWeight_y() << std::endl
			<< "diagonal_x = " << object.getDiagonal_x() << std::endl
			<< "diagonal_y = " << object.getDiagonal_y() << std::endl
			<< "wight = " << object.getWight() << std::endl
			<< "lenght = " << object.getLenght() << std::endl
			<< "color = " << object.getColor() << std::endl
			<< "transparency = " << object.getTransparency() << std::endl
			<< "internal radius = " << object.getInternal_radius() << std::endl
			<< "external radius = " << object.getExternal_radius() << std::endl << std::endl;
		return out;
	}
	int getInternal_radius() const { return m_internal_radius; }
	int getExternal_radius() const { return m_external_radius; }
	~Square() { std::cout << "Call destructor Square" << std::endl; }
};

int SetValid();
enum Parameters {
	X = 1,
	Y,
	Weight_x,
	Weight_y,
	Diagonal_x,
	Diagonal_y,
	Wight,
	Lenght,
	Internal_radius,
	External_radius
};

int main() {
	std::string color;
tryAgain_color:
	std::cout << "Color: ";
	std::cin >> color;
	for (unsigned int i = 0; i < color.length(); i++)
		if (color[i] > '0' && color[i] < '9') {
			std::cout << "Please try again." << std::endl;
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			goto tryAgain_color;
		}
	
	bool transparency;
	std::cout << "Transparency: ";
	std::cin >> transparency;
	std::cin.clear();
	std::cin.ignore(32767, '\n');

	std::cout << "Please print others paremeter: " << std:: endl;
	int Array[] = { 0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < 10; i++) {
		switch (i+1){
		case X: std::cout << "X: "; break;
		case Y: std::cout << "Y: "; break;
		case Weight_x: std::cout << "Weight_x: "; break;
		case Weight_y: std::cout << "Weight_y: "; break;
		case Diagonal_x: std::cout << "Diagonal_x: "; break;
		case Diagonal_y: std::cout << "Diagonal_y: "; break;
		case Wight: std::cout << "Wight: "; break;
		case Lenght: std::cout << "Lenght: "; break;
		case Internal_radius: std::cout << "Internal_radius: "; break;
		case External_radius: std::cout << "External_radius: "; break;
		} 
		Array[i] = SetValid();
	}
	std::cout << std::endl << std::endl;

	Square* object_1 = new Square(Array[0], Array[1], Array[2], Array[3],Array[4],
		Array[5], Array[6], Array[7], color, transparency, Array[8], Array[9]);
	std::cout << *object_1;
	delete object_1;
	
	return 0;
}

int SetValid() {
	while (true) {
		int parameter;
		std::cin >> parameter;
		if (std::cin.fail() || parameter < 0) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Please try again." << std::endl;
		}
		else {
			std::cin.ignore(32767, '\n');
			return parameter;
		}
	}
};
