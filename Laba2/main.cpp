#include <iostream>
#include <time.h>
#include <conio.h>
#include "Death Stranding.h"

int main(){

	setlocale(LC_ALL, "Russian");

	Death_Stranding Save_1, Save_2(0, 0, 0);
	Player Player_1;
	Death_Stranding Save[10];
	
	std::cout << "�����������!" << std::endl << "� ���� 10 ������� ���������. �� ������� - �� �������������." << std::endl;
	
	inp_save(Save_1);
	inp_player(Player_1);
	
	std::cout << "�������� ��������!" << std::endl;

	execute_save(Save_1);     std::cout << std::endl;
	execute_save(Save_2);     std::cout << std::endl;
	execute_player(Player_1); std::cout << std::endl;

	Player_1.times(Save_1);
	Player_1.times(Save_2);

	execute_save(Save_1);  std::cout << std::endl;
	execute_save(Save_2);  std::cout << std::endl;

	for (int i = 0; i < 10; i++) {
		execute_save(Save[i]);
		std::cout << std::endl;
	}
	for (int i = 0; i < 10; i++) {
		Player_1.times(Save[i]);
	}
	for (int i = 0; i < 10; i++) {
		execute_save(Save[i]);
		std::cout << std::endl;
	}

	return 0;
}