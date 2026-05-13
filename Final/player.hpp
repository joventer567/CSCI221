
#include <string>
#include <vector>
#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player {
    
    private:
        int health;
        int max_special_points;
        int special_points;
        bool strength;
        std::vector<std::string> inventory;
        std::vector<std::string> specials;

    public:
        Player();
        ~Player();

        bool health_pack();
        bool harmonica();
        bool heal();
        bool strengthen();
        bool fire();
        bool bounce();
        bool smash_attack();
        void show_items();
        void show_specials();
        void hit();
        void guard_hit();
        bool dead();
        int return_health();
        int return_special_points();
        void add_item(std::string item);
        void lose_sp(int sp);
        void add_fire();
        void add_bounce();
        void restore_sp();
        void raise_sp();
        void sort_inventory();

};

#endif