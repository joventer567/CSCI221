#include "player.hpp"
#include <iostream>

using namespace std;


Player::Player() {
    health = 15;
    max_special_points = 10;
    special_points = 10;
    strength = false;
    inventory.push_back("health pack");
    inventory.push_back("smash attack");
    specials.push_back("heal (3sp)");
    specials.push_back("strengthen (5sp)");
}

Player::~Player() {

}

bool Player::health_pack() {
    for (int i = 0; i < (int)inventory.size(); i++) {
        if (inventory[i] == "health pack") {
            inventory.erase(inventory.begin() + i);
            health += 5;
            if (health >= 15) {
                health = 15;
            }
            return true;
        }
    }
    return false;
}

bool Player::harmonica() {
    for (int i = 0; i < (int)inventory.size(); i++) {
        if (inventory[i] == "harmonica") {
            inventory.erase(inventory.begin() + i);
            return true;
        }
    }
    return false;
}

bool Player::heal() {
    if (special_points < 3) {
        return false;
    }
    special_points -= 3;
    health += 5;
    if (health > 15) {
        health = 15;
    }
    return true;
}

bool Player::strengthen() {
    if (special_points < 5) {
        return false;
    }
    special_points -= 5;
    return true;
}

bool Player::fire() {
    if (special_points < 4) {
        return false;
    }
    special_points -= 4;
    return true;
}

bool Player::bounce() {
    if (special_points < 4) {
        return false;
    }
    special_points -= 4;
    return true;

}
bool Player::smash_attack() {
    for (int i = 0; i < (int)inventory.size(); i++) {
        if (inventory[i] == "smash attack") {
            inventory.erase(inventory.begin() + i);
            return true;
        }
    }
    return false;
}

void Player::show_items() {
    for (int i = 0; i < (int)inventory.size(); i++) {
        cout << inventory[i] << "  ";
    }
}

void Player::show_specials() {
    for (int i = 0; i < (int)specials.size(); i++) {
        cout << specials[i] << "  ";
    }
}

void Player::hit() {
        health -=4;
    }

void Player::guard_hit() {
    health -= 1;
}

bool Player::dead() {
    if (health <= 0) {
        return true;
    }
    return false;
}

int Player::return_health() {
    return health;
}

int Player::return_special_points() {
    return special_points;
}

void Player::add_item(string item) {
    inventory.push_back(item);
}

void Player::lose_sp(int sp) {
    special_points -= sp;
}

void Player::add_fire() {
    specials.push_back("fire (4sp)");
}

void Player::add_bounce() {
    specials.push_back("bounce (4sp)");
}

void Player::restore_sp() {
    special_points = max_special_points;
}

void Player::raise_sp() {
    max_special_points += 5;
}

void Player::sort_inventory() {
    for (int i = 1; i < (int)inventory.size(); i++) {
        string key = inventory[i];
        int j = i - 1;

        while (j >= 0 && inventory[j] > key) {
            inventory [j + 1] = inventory[j];
            j = j - 1;
        }
        inventory[j + 1] = key;
    }
}