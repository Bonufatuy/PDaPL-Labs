#include <iostream>
#include <conio.h>
#include <time.h>
#include <string>
#include "Death Stranding.h"

void Death_Stranding::set_id(int id) {
    Death_Stranding::id = id;
}
void Death_Stranding::set_time(int time) {
    Death_Stranding::time = time;
}
void Death_Stranding::set_level(int level){
    Death_Stranding::level = level;
}
int Death_Stranding::get_id() {
    return Death_Stranding::id;
}
int Death_Stranding::get_time() {
    return Death_Stranding::time;
}
int Death_Stranding::get_level() {
    return Death_Stranding::level;
}
void Player::set_name(std::string name) {
    Player::name = name;
}
void Player::set_pass(std::string pass) {
    Player::pass = pass;
}
 std::string Player::get_name() {
     return Player::name;
}
 std::string Player::get_pass() {
     return Player::pass;
 }
 void Player::times(Death_Stranding& Save) {

     int start = 0, stop = 0;
     std::cout << "Начинаем цикл! Для прерывания цикла нажмите Esc" << std::endl;
     do {
         start = clock();
     } while (_getche() != 27);
     stop = clock(); std::cout << "1";
     Save.set_time(stop - start);
 }
 void execute_player(Player& Player) {
     std::cout << "Name: " << Player.get_name() << std::endl
         << "Pass: " << Player.get_pass() << std::endl;
 }
 void inp_player(Player& Player) {
     std::string name, pass;

     std::cout << "Name: "; std::cin >> name;
     std::cout << "Pass: "; std::cin >> pass;

     Player.set_name(name);
     Player.set_pass(pass);
 }
 void execute_save(Death_Stranding& Save) {
     std::cout << "Level: " << Save.get_level() << std::endl
         << "Id: " << Save.get_id() << std::endl
         << "Time: " << Save.get_time() << std::endl;
 }
 void inp_save(Death_Stranding& Save) {

     int level = 0; int id = 0; float time = 0;

     do {
         std::cout << "Id: "; std::cin >> id;
     } while (id < 0);
     do {
         std::cout << "Level: "; std::cin >> level;
     } while (level < 0 || level > 10);

     Save.set_level(level);
     Save.set_id(id);
 }