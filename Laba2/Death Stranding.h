#pragma once
#include <iostream>
#include <string>

class Death_Stranding {
public:
	Death_Stranding() { id = 0; time = 0; level = 0; };
	Death_Stranding(int id, int time, int level) {
		this->id = id;
		this->time = time;
		this->level = level;
	};
	~Death_Stranding() {
		std::cout << "Деструктор!" << std::endl;
	};

	void set_id(int);
	void set_time(int);
	void set_level(int);
	int get_id();
	int get_time();
	int get_level();

	friend class Player;
	friend void execute_save(Death_Stranding& Save);
	friend void inp_save(Death_Stranding& Save);

private:

	int id;
	int time;
	int level;
};
class Player {
public:

	void set_name(std::string name);
	void set_pass(std::string pass);
	void times(Death_Stranding& Save);
	std::string get_name();
	std::string get_pass();

	friend void inp_player(Player& Player);
	friend void execute_player(Player& Player);

private:

	std::string name;
	std::string pass;
};

