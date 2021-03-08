#include <iostream>

class String {
public:
	String() {
		value = new char[1];
		value[0] = '\0';
		length = 1;
	}

	String(const char* value) {
		length = 0;
		while (value[length] != '\0') {
			length++;
		}

		this->value = new char[length + 1];
		for (int i = 0; i < length; i++) {
			this->value[i] = value[i];
		}
		this->value[length] = '\0';
	}
	
	String(String& other) {
		this->length = other.length;
		this->value = new char[this->length + 1];
		for (int i = 0; i < this->length; i++) {
			this->value[i] = other.value[i];
		}
		this->value[length] = '\0';
	}
	void Print() {
		std::cout << value << ";";
	}

	~String() {
		delete[] value;
	}

	char GetChar(int index) {
		if (index < 0 || index > length) {
			throw "Invalid index";
		}
		return value[index];
	}

	void SetChar(int index, char newValue) {
		if (index < 0 || index > length) {
			throw "Invalid index";
		}
		value[index] = newValue;
	}

	bool operator==(String other) {
		int maxLen;
		if (this->length > other.length) {
			maxLen = this->length;
		}
		else {
			maxLen = other.length;
		}

		for (int i = 0; i < maxLen; i++) {
			if (this->value[i] != other.value[i]) {
				return false;
			}
		}
		return true;
	}

	int operator-(String other) {
		return this->length - other.length;
	}

	friend std::ostream& operator<< (std::ostream& out, const String& other) {
		out << other.value;
		return out;
	}

	void BublleSort() {
		char buffer;
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < length - 1; j++) {
				if (value[j] < value[j + 1]) {
					buffer = value[j];
					value[j] = value[j + 1];
					value[j + 1] = buffer;
				}
			}
		}
	}

	int GetLenght(String object) {
		return object.length;
	}

private:
	char* value;
	int length;
};

int main() {
	String str1("Hello"), str2("Hello");
	std::cout << str1 << std::endl;
	std::cout << str2 << std::endl;
	std::cout << (str1 - str2) << std::endl;
	std::cout << (str1 == str2) << std::endl << std::endl;

	String* str3 = new String("Airline");
	String* str4 = new String(*str3);
	(*str3).BublleSort();
	(*str3).Print();
	(*str4).Print();
	
	String* strArr = new String[2]{"Hello", "World"};
	std::cout << "\n\n" << strArr[0] << ", " << strArr[1] << "\n";

	delete[] strArr;
	return 0;
}
